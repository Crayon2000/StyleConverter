//---------------------------------------------------------------------------
#include <fmx.h>

#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <System.SysUtils.hpp>
#include "StyleConverterApplication.h"
//---------------------------------------------------------------------------
 int _tmain(int argc, _TCHAR* argv[]) 
{
    int Result = 0;

    TStyleConverterApplication *Application = new TStyleConverterApplication();
    try
    {
        Application->Run();
    }
    catch(Exception &exception)
    {
        std::wcerr << exception.Message.c_str() << std::endl;
        Result = 1; // Error
    }
    delete Application;

    return Result;
}
//---------------------------------------------------------------------------
