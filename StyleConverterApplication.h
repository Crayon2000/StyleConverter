//---------------------------------------------------------------------------
#ifndef StyleConverterApplicationH
#define StyleConverterApplicationH
//---------------------------------------------------------------------------
#include <System.hpp>
//---------------------------------------------------------------------------
namespace Fmx
{
    namespace Types
    {
        class TFmxObject;
    }
}

class PACKAGE TStyleConverterApplication : public System::TObject
{
private:
    void __fastcall RemoveAuthorInfo(Fmx::Types::TFmxObject* AObject);
protected:

public:
    __fastcall TStyleConverterApplication();
    __fastcall ~TStyleConverterApplication();

    void __fastcall Run();
};
//---------------------------------------------------------------------------
#endif
