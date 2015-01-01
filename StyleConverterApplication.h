//---------------------------------------------------------------------------
#ifndef StyleConverterApplicationH
#define StyleConverterApplicationH
//---------------------------------------------------------------------------
#include <System.hpp>
//---------------------------------------------------------------------------
class PACKAGE TStyleConverterApplication : public System::TObject
{
    typedef System::TObject inherited; /**< Our parent's definition. */

private:

protected:

public:
    __fastcall TStyleConverterApplication();
    __fastcall ~TStyleConverterApplication();

    void __fastcall Run();
};
//---------------------------------------------------------------------------
#endif
