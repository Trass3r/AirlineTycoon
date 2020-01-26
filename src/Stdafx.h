// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#ifdef WIN32
#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */
#include <Windows.h>
#endif
#include <math.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Defines.h"
#include "stdstring.h"
typedef CStdStringA CString;

#include "TeakLibW.H"
#include "sbl.h"
#include "sbbm.h"
#include "SSE.h"
#include "Colorfx.h"

#include "glstd.h"
#include "glbasis.h"

#include "res\Resource.h"

#include "class.h"         //Eigene Klassen
#include "Proto.h"
#include "TakeOff.h"
#include "Gameframe.h"     //Rahmenfenster mit PrimarySurface

//R�ume:
#include "Smackprs.h"
#include "Stdraum.h"
#include "Planer.h"        //Die Basisklasse f�r Laptop/Globe
#include "AirportView.h"   //Die Isometrische Sicht auf den Flughafen
#include "Globe.h"         //Der Nachfolger des Schedulers
#include "Laptop.h"        //Der Schleppable
#include "LastMin.h"       //Das LastMinute Reiseb�ro
#include "Options.h"       //Das Optionsfenster
#include "Personal.h"      //Das Personalb�ro
#include "Schedule.h"      //Der Scheduler Bildschirm
#include "Werkstat.h"      //Die Werkstatthalle

#include "global.h"        //Deklarationen der globalen Variablen
#pragma hdrstop