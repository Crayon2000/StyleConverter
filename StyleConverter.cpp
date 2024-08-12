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
#include <memory>
#include <System.SysUtils.hpp>
#include "StyleConverterApplication.h"
//---------------------------------------------------------------------------
 int _tmain(int argc, _TCHAR* argv[]) 
{
    int Result = 0;

    try
    {
        auto Application = std::make_unique<TStyleConverterApplication>();
        Application->Run();
    }
    catch(Exception &exception)
    {
        std::wcerr << exception.Message.c_str() << std::endl;
        Result = 1; // Error
    }

    return Result;
}
//---------------------------------------------------------------------------
