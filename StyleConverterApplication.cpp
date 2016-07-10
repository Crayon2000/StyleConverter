//---------------------------------------------------------------------------
#pragma hdrstop

#include "StyleConverterApplication.h"
#include <System.Classes.hpp>
#include <FMX.Styles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

/**
 * Callback for supported platform.
 * @param APlatformTarget The platform target to validate. This is not used.
 * @return Always return true.
 */
bool __fastcall SupportedPlatformHook(const System::UnicodeString APlatformTarget)
{
    return true;
}

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
        String Usage = "Copyright (c) 2014-2016 Crayon Application";
        Usage += "\nUsage: StyleConverter.exe file [-f format]";
        Usage += "\nfile\tstyle file to convert";
        Usage += "\n  -f\tformat: 0=Indexed, 1=Binary, 2=Text";
        //Usage += "\n  -o\toutput to file";
        throw(Exception(Usage));
    }

    // This must be called before loading the style
    Fmx::Styles::TStyleStreaming::SetSupportedPlatformHook(SupportedPlatformHook);

    String LOutputFileName;
    const String LInputFileName = ParamStr(1);

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
            LStyleFormat = static_cast<TStyleFormat>(-1); // Undefined
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
        case TStyleFormat::Text:
            LOutputFileName = ChangeFileExt(LInputFileName, ".txt");
            break;
        default:
            throw(Exception("Invalid format specified"));
    }

    TFmxObject* LStyle = NULL;
    TMemoryStream* MemStream = NULL;
    try
    {
        LStyle = Fmx::Styles::TStyleStreaming::LoadFromFile(LInputFileName);
        //RemoveAuthorInfo(LStyle);
        MemStream = new TMemoryStream();
        Fmx::Styles::TStyleStreaming::SaveToStream(
            LStyle, MemStream, LStyleFormat);
        MemStream->SaveToFile(LOutputFileName);
    }
    __finally
    {
        delete LStyle;
        delete MemStream;
    }
}

/**
 * This method will remove author information from the style.
 * @param AObject A style object.
 */
void __fastcall TStyleConverterApplication::RemoveAuthorInfo(Fmx::Types::TFmxObject* AObject)
{
    for(int i = 0; i < AObject->ChildrenCount; ++i)
    {
        TStyleDescription* LDescription = dynamic_cast<TStyleDescription*>(AObject->Children->Items[i]);
        if(LDescription != NULL)
        {
            LDescription->Author = "";
            LDescription->AuthorURL = "";
            LDescription->AuthorEMail = "";
            break;
        }
    }
}
