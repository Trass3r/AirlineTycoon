#include "stdafx.h"

SB_CFont::SB_CFont(void)
    : Surface(NULL)
    , Texture(NULL)
    , VarWidth(NULL)
    , VarHeight(NULL)
    , Hidden(false)
    , Tabulator(NULL)
    , LineSpace(1.5f)
    , Bitmap(NULL)
{
}

SB_CFont::~SB_CFont(void)
{
    if (Texture)
        SDL_DestroyTexture(Texture);

    if (Surface)
        SDL_FreeSurface(Surface);

    if (VarWidth)
        delete [] VarWidth;

    if (VarHeight)
        delete [] VarHeight;
}

bool SB_CFont::Load(SDL_Renderer* renderer, const char* path, struct HPALETTE__*)
{
    SDL_RWops* file = SDL_RWFromFile(path, "rb");
    if (SDL_RWread(file, &Header, sizeof(Header), 1) != 1)
        return false;

    BYTE* pixels = new BYTE[Header.szPixels];
    if (SDL_RWread(file, pixels, 1, Header.szPixels) != Header.szPixels)
        return false;

    SDL_Color* colors = new SDL_Color[Header.NumColors + 1];
    if (SDL_RWread(file, colors, 1, Header.szColors) != Header.szColors)
        return false;

    // Some fonts will refer beyond the palette, set those pixels to transparent
    memset(colors + Header.NumColors, 0, sizeof(SDL_Color));

    VarWidth = new BYTE[0x100];
    if (SDL_RWread(file, VarWidth, 0x100, 1) != 1)
        return false;

    VarHeight = new BYTE[0x100];
    if (SDL_RWread(file, VarHeight, 0x100, 1) != 1)
        return false;

    word chars = Header.HiChar - Header.LoChar + 1;
    SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormatFrom(pixels, Header.Width, Header.Height * chars, 8, Header.Width, SDL_PIXELFORMAT_INDEX8);
    for (int i = 0; i < Header.NumColors; i++)
        Swap(colors[i].r, colors[i].b); // Convert BGR to RGB
    SDL_SetPaletteColors(surf->format->palette, colors, 0, Header.NumColors + 1);
    Surface = SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGB565, 0);
    SDL_SetColorKey(Surface, SDL_TRUE, 0);
    SDL_FreeSurface(surf);
    delete [] colors;
    delete [] pixels;
    return true;
}

long SB_CFont::DrawTextBlock(class SB_CBitmapCore* bmp, RECT* block, const char* str, long length, long offset, bool hidden)
{
    this->Bitmap = bmp;
    this->Hidden = hidden;
    if (length == 0) {
        length = strlen(str);
    }
    if (offset < length) {
        str = str + offset;
        length = length - offset;
        this->Pos.x = block->left;
        this->Start.x = this->Pos.x;
        this->Pos.y = block->top;
        while (length != 0) {
            long i = GetWordLength(str,length);
            if (i > 0) {
                if (block->right < this->Pos.x + GetWidth(str,i)) {
                    this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
                    this->Pos.x = block->left;
                }
                if (block->bottom < this->Pos.y + this->Header.Height) {
                    return offset;
                }
                if (!DrawWord(str,i)) {
                    return offset;
                }
            }
            switch(str[i]) {
            case '\0':
                break;
            case '\n':
                this->Pos.x = this->Start.x;
                i++;
                break;
            case '\r':
                this->Pos.y = this->Pos.y + this->Header.Height;
                i++;
                break;
            case ' ':
                this->Pos.x = this->Pos.x + GetWidth(' ');
                i++;
                break;
            case -0x4b:
                this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
                this->Pos.x = this->Start.x;
                i++;
                break;
            default:
                i++;
            }
            length = length - i;
            if (length < 1) {
                return 0xffff;
            }
            str = str + i;
            offset = offset + i;
        }
    }
    else {
        offset = 0xffff;
    }
    return offset;
}

void SB_CFont::DrawTextWithTabs(class SB_CBitmapCore* bmp, long x, long y, const char* str, long length, bool hidden)
{
    int i = 0;
    this->Bitmap = bmp;
    this->Hidden = hidden;
    this->Pos.x = x;
    this->Start.x = x;
    this->Pos.y = y;
    if (length == 0) {
        length = strlen(str);
    }
    while (0 < length) {
        switch(*str) {
        case '\t':
            if (i < this->NumTabs && this->Tabulator) {
                str++;
                switch(this->Tabulator[i].Style) {
                case 1:
                    this->Pos.x = this->Tabulator[i].Width;
                    break;
                case 2:
                    this->Pos.x = this->Tabulator[i].Width - GetWidthAt(str, length - 1,'.');
                    break;
                case 3:
                    this->Pos.x = this->Tabulator[i].Width - (GetWidthAt(str, length - 1,'\t') / 2);
                    break;
                case 4:
                    this->Pos.x = this->Tabulator[i].Width - GetWidthAt(str, length - 1,'\t');
                    break;
                }
                i++;
            }
            break;
        case '\n':
            this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
            str++;
            break;
        case '\r':
            i = 0;
            this->Pos.x = this->Start.x;
            str++;
            break;
        case -0x4b:
            i = 0;
            this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
            this->Pos.x = this->Start.x;
            str++;
            break;
        default:
            DrawChar(*str++, true);
        }
        length--;
    }
    return;
}

void SB_CFont::SetTabulator(TABS* pTabs, unsigned long szTabs)
{
    if (this->Tabulator) {
        delete [] this->Tabulator;
        this->Tabulator = NULL;
    }
    this->NumTabs = (word)(szTabs / sizeof(TABS));
    this->Tabulator = new TABS[this->NumTabs];
    memcpy(this->Tabulator, pTabs, szTabs);
    return;
}

long SB_CFont::PreviewTextBlock(class SB_CBitmapCore * bmp, RECT * block, const char* str, long length, long offset, bool hidden)
{
    this->Bitmap = bmp;
    this->Hidden = hidden;
    if (length == 0) {
        length = strlen(str);
    }
    if (offset < length) {
        str = str + offset;
        length = length - offset;
        this->Pos.x = block->left;
        this->Start.x = this->Pos.x;
        this->Pos.y = block->top;
        while (length != 0) {
            int i = GetWordLength(str, length);
            if (0 < i) {
                long width = GetWidth(str, i);
                if (block->right < this->Pos.x + width) {
                    this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
                    this->Pos.x = block->left;
                    if (block->right < this->Pos.x + width) {
                        return -1;
                    }
                }
                this->Pos.x += width;
            }
            switch(str[i]) {
            case '\0':
                break;
            case '\n':
                this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
                i++;
                break;
            case '\r':
                this->Pos.x = this->Start.x;
                i++;
                break;
            case ' ':
                this->Pos.x = this->Pos.x + GetWidth(' ');
                i++;
                break;
            case -0x4b:
                this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
                this->Pos.x = this->Start.x;
                i++;
                break;
            default:
                i++;
            }
            length -= i;
            if (length < 1) break;
            str += i;
        }
        return (this->Pos.y + this->Header.Height) - block->top;
    }
    else {
        return 0xffff;
    }
}

long SB_CFont::DrawTextBlock(class SB_CBitmapCore* bmp, long l, long t, long r, long b, const char* str, long length, long offset, bool hidden)
{
   RECT rect{ l, t, r, b };
   return DrawTextBlock(bmp, &rect, str, length, offset, hidden);
}

long SB_CFont::PreviewTextBlock(class SB_CBitmapCore* bmp, long l, long t, long r, long b, const char* str, long length, long offset, bool hidden)
{
   RECT rect{ l, t, r, b };
   return PreviewTextBlock(bmp, &rect, str, length, offset, hidden);
}

long SB_CFont::GetWidthAt(const char* str, long offset, char ch)
{
    int i = 0;
    while( true ) {
        switch(*str) {
        case -0x4b:
        case '\0':
        case '\t':
        case '\n':
        case '\r':
            return i;
        }
        if (*str == ch) break;
        i += GetWidth(*str++);
    }
    return i;
}

long SB_CFont::GetWordLength(const char* str, long offset)
{
    dword length = 0;
    while (offset != 0) {
        switch(str[length]) {
        case -0x4b:
        case '\0':
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            return length;
        default:
            length++;
            offset--;
        }
    }
    return length;
}

long SB_CFont::GetWidth(char ch)
{
    if ((this->Header.Flags & 1) == 1)
        return *(this->VarWidth + ch);
    else
        return this->Header.Width;
}

long SB_CFont::GetWidth(const char* str, long offset)
{
    long width = 0;
    if (offset == 0)
    {
        offset = strlen(str);
    }
    while (offset != 0)
    {
        switch(*str)
        {
        case -0x4b:
        case '\0':
        case '\t':
        case '\n':
        case '\r':
            offset++;
            break;
        default:
            width = width + GetWidth(*str++);
            offset--;
        }
    }
    return width;
}

bool SB_CFont::DrawChar(char ch, bool)
{
    if (this->VarHeight)
    {
        if (this->Bitmap != (SB_CBitmapCore *)0x0)
        {
            RECT srcRect;
            srcRect.left = 0;
            srcRect.top = (*(this->VarHeight + ch) - this->Header.LoChar) * this->Header.Height;
            srcRect.right = this->Header.Width;
            srcRect.bottom = srcRect.top + this->Header.Height;
            if (!this->Hidden)
                this->Bitmap->BlitChar(Surface, Pos.x, Pos.y, srcRect, 1);
        }
        this->Pos.x = this->Pos.x + GetWidth(ch);
        return true;
    }
    return false;
}

bool SB_CFont::DrawWord(const char* str, long offset)
{
    do {
        if (offset == 0) {
            return true;
        }
        if (*str == -0x4b) {
            this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
            this->Pos.x = this->Start.x;
        }
        else {
            if (*str == '\n') {
                this->Pos.y = this->Pos.y + long(this->Header.Height * LineSpace);
            }
            else {
                if (*str == '\r') {
                    this->Pos.x = this->Start.x;
                }
                else {
                    if (!DrawChar(*str, true)) {
                        return false;
                    }
                }
            }
        }
        str++;
        offset--;
    } while( true );
}
