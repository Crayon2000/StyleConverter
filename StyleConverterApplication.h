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
    typedef System::TObject inherited; /**< Our parent's definition. */

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
