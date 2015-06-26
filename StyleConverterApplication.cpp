//---------------------------------------------------------------------------
#pragma hdrstop

#include "StyleConverterApplication.h"
#include <System.Classes.hpp>
#include <FMX.Styles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

/**
 * Constructor.
 */
__fastcall TStyleConverterApplication::TStyleConverterApplication() :
    System::TObject()
{

}

/**
 * Destructor.
 */
__fastcall TStyleConverterApplication::~TStyleConverterApplication()
{

}

/**
 * Run.
 */
void __fastcall TStyleConverterApplication::Run()
{
    if(ParamCount() < 1)
    {
        String Usage = "Copyright (c) 2014-2015 Crayon Application";
        Usage += "\nUsage: StyleConverter.exe file [-f format]";
        Usage += "\nfile\tstyle file to convert";
        Usage += "\n  -f\tformat: 0=Indexed, 1=Binary, 2=Text";
        //Usage += "\n  -o\toutput to file";
        throw(Exception(Usage));
    }

    String LOutputFileName;
    const String LInputFileName = ParamStr(1);
    TStyleManager::SetStyle(TStyleStreaming::LoadFromFile(LInputFileName));

    TStyleFormat LStyleFormat = TStyleFormat::Binary; // Default value
    String LFormatString;
    if(FindCmdLineSwitch("f", LFormatString))
    {
        try
        {
            LStyleFormat = TStyleFormat(LFormatString.ToInt());
        }
        catch(...)
        {
        }
    }

    switch(LStyleFormat)
    {
        case TStyleFormat::Indexed:
            LOutputFileName = ChangeFileExt(LInputFileName, ".idx");
            break;
        case TStyleFormat::Binary:
            LOutputFileName = ChangeFileExt(LInputFileName, ".bin");
            break;
        default:
            LOutputFileName = ChangeFileExt(LInputFileName, ".txt");
    }

    TMemoryStream* MemStream = NULL;
    try
    {
        MemStream = new TMemoryStream();
        TStyleStreaming::SaveToStream(TStyleManager::ActiveStyle(NULL), MemStream, LStyleFormat);
        MemStream->SaveToFile(LOutputFileName);
    }
    __finally
    {
        delete MemStream;
    }
}