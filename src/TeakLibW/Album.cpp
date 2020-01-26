#include "stdafx.h"

const char* ExcAlbumInsert      = "Album: %s += failed!";
const char* ExcAlbumFind        = "Album: %s [] failed!";
const char* ExcAlbumDelete      = "Album: %s -= failed!";
const char* ExcXIDUnrecoverable = "XID-Access for %li (%s) failed (unrecoverable)!";

XID::XID()
    : Value(0)
    , Index(0)
{
}

void XID::SetValue(unsigned long val)
{
    if (val >= 0x1000000)
    {
        Value = val;
        Index = 0;
    }
    else
    {
        Value = 0;
        Index = val;
    }
}

TEAKFILE& operator<<(TEAKFILE& file, XID const& id)
{
    file << id.Value << id.Index;
    return file;
}

TEAKFILE& operator>>(TEAKFILE& file, XID& id)
{
    file >> id.Value >> id.Index;
    return file;
}

void TeakAlbumRemoveT(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, unsigned long id)
{
    if (id >= 0x1000000)
    {
        TeakAlbumRefresh(ids, anz);
        for (int i = ids.AnzEntries() - 1; i >= 0; --i)
        {
            if (ids[i] == id)
            {
                ids[i] = 0;
                return;
            }
        }
    }
    else if (ids.AnzEntries() > id && ids[id])
    {
        ids[id] = 0;
        return;
    }
    TeakLibW_Exception(0, 0, ExcAlbumDelete, name.c_str());
}

void TeakAlbumRefresh(FBUFFER<unsigned long>& ids, unsigned long anz)
{
    unsigned long cur = ids.AnzEntries();
    if (anz != cur)
    {
        ids.ReSize(anz);
        if ( anz > cur )
        {
            for (int i = 0; i < anz - cur; ++i)
                ids[i + cur] = 0;
        }
    }
}

long TeakAlbumSearchT(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, unsigned long id)
{
    if (id >= 0x1000000)
    {
        TeakAlbumRefresh(ids, anz);
        for (int i = ids.AnzEntries() - 1; i >= 0; --i)
        {
            if (ids[i] == id)
                return i;
        }
    }
    else if (ids.AnzEntries() > id && ids[id])
    {
        return id;
    }
    TeakLibW_Exception(0, 0, ExcAlbumFind, name.c_str());
    return 0;
}

long TeakAlbumXIdSearchT(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, XID& id)
{
    TeakAlbumRefresh(ids, anz);
    if (id.Index < ids.AnzEntries() && ids[id.Index] == id.Value)
        return id.Index;
    if (id.Value >= 0x1000000u)
    {
        id.Index = TeakAlbumSearchT(ids, anz, name, id.Value);
        return id.Index;
    }
    else if (ids[id.Index] >= 0x1000000u)
    {
        TeakLibW_Exception(0, 0, ExcXIDUnrecoverable, name.c_str());
        return 0;
    }
    else
    {
        id.Value = ids[id.Index];
        return id.Index;
    }
}

int TeakAlbumIsInAlbum(FBUFFER<unsigned long>& ids, unsigned long anz, unsigned long id)
{
    if (id >= 0x1000000)
    {
        TeakAlbumRefresh(ids, anz);
        for (int i = ids.AnzEntries() - 1; i >= 0; --i)
        {
            if (ids[i] == id)
                return true;
        }
    }
    else if (ids.AnzEntries() > id && ids[id])
    {
        return true;
    }
    return false;
}

unsigned long TeakAlbumAddT(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, unsigned long id)
{
    TeakAlbumRefresh(ids, anz);
    for (int i = ids.AnzEntries() - 1; i >= 0; --i)
    {
        if (!ids[i])
        {
            ids[i] = id;
            return id;
        }
    }
    TeakLibW_Exception(0, 0, ExcAlbumInsert, name.c_str());
    return 0;
}

unsigned long TeakAlbumFrontAddT(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, unsigned long id)
{
    TeakAlbumRefresh(ids, anz);
    for (int i = 0; i < ids.AnzEntries(); ++i)
    {
        if (!ids[i])
        {
            ids[i] = id;
            return id;
        }
    }
    TeakLibW_Exception(0, 0, ExcAlbumInsert, name.c_str());
    return 0;
}

unsigned long TeakAlbumGetNumFree(FBUFFER<unsigned long>& ids, unsigned long anz)
{
    unsigned long num = 0;
    TeakAlbumRefresh(ids, anz);
    for (int i = ids.AnzEntries() - 1; i >= 0; --i)
    {
        if (!ids[i])
            ++num;
    }
    return num;
}

unsigned long TeakAlbumGetNumUsed(FBUFFER<unsigned long>& ids, unsigned long anz)
{
    unsigned long num = 0;
    TeakAlbumRefresh(ids, anz);
    for (int i = ids.AnzEntries() - 1; i >= 0; --i)
    {
        if (ids[i])
            ++num;
    }
    return num;
}

unsigned long TeakAlbumRandom(FBUFFER<unsigned long>& ids, unsigned long anz, CString const& name, TEAKRAND* random)
{
    TeakAlbumRefresh(ids, anz);
    unsigned long used = TeakAlbumGetNumUsed(ids, anz);
    if (!used)
        TeakLibW_Exception(0, 0, ExcAlbumFind, name.c_str());

    long target = random ? random->Rand(used) : rand() % 5;
    long index = 0;
    for (int i = ids.AnzEntries() - 1; i >= 0; --i)
    {
        if (++index > target)
            return ids[i];
    }
    TeakLibW_Exception(0, 0, ExcAlbumFind, name.c_str());
    return 0;
}
