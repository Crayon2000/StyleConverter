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

public:
    /**
     * Constructor.
     */
    __fastcall TStyleConverterApplication() : System::TObject() { }

    /**
     * Destructor.
     */
    inline __fastcall virtual ~TStyleConverterApplication() { }

    void __fastcall Run();
};
//---------------------------------------------------------------------------
#endif
