//---------------------------------------------------------------------------
#pragma hdrstop

#include "StyleConverterApplication.h"
#include <System.Classes.hpp>
#include <FMX.Styles.hpp>
#include <memory>
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
 * Run.
 */
void __fastcall TStyleConverterApplication::Run()
{
    if(ParamCount() < 1)
    {
        const String Usage = "Copyright (c) 2014-2024 Crayon Application" \
            "\nUsage: StyleConverter.exe file [-f format]" \
            "\nfile\tstyle file to convert" \
            "\n  -f\tformat: 0=Indexed, 1=Binary, 2=Text";
        // "\n  -o\toutput to file";
        throw(Exception(Usage));
    }

    // This must be called before loading the style
    Fmx::Styles::TStyleStreaming::SetSupportedPlatformHook(SupportedPlatformHook);

    String LOutputFileName;
    const String LInputFileName = ParamStr(1);

    TStyleFormat LStyleFormat = TStyleFormat::Binary; // Default value
    String LFormatString;
    if(FindCmdLineSwitch("f", LFormatString) == true)
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

    TFmxObject* LStyle = nullptr;
    try
    {
        LStyle = Fmx::Styles::TStyleStreaming::LoadFromFile(LInputFileName);
        //RemoveAuthorInfo(LStyle);
        auto MemStream = std::make_unique<TMemoryStream>();
        Fmx::Styles::TStyleStreaming::SaveToStream(
            LStyle, MemStream.get(), LStyleFormat);
        MemStream->SaveToFile(LOutputFileName);
    }
    __finally
    {
        delete LStyle;
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
        auto LDescription = dynamic_cast<TStyleDescription*>(AObject->Children->Items[i]);
        if(LDescription != nullptr)
        {
            LDescription->Author = "";
            LDescription->AuthorURL = "";
            LDescription->AuthorEMail = "";
            break;
        }
    }
}
