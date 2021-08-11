// This file declares the IBrowserFrameOptions Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

/* It appears this was undocumented, and vanished in MSVC7
   But the Win2k shell always QIs for it - we don't *need* it,
   but everything is happier when we do have it
*/

#ifndef __IBrowserFrameOptions_INTERFACE_DEFINED__
#define __IBrowserFrameOptions_INTERFACE_DEFINED__

typedef DWORD BROWSERFRAMEOPTIONS;
EXTERN_C const IID IID_IBrowserFrameOptions;

MIDL_INTERFACE("10DF43C8-1DBE-11d3-8B34-006097DF5BD4")
#define NEED_IID_IBrowserFrameOptions
IBrowserFrameOptions : public IUnknown
{
   public:
    virtual HRESULT STDMETHODCALLTYPE GetFrameOptions(
        /* [in] */ BROWSERFRAMEOPTIONS dwMask,
        /* [out] */ BROWSERFRAMEOPTIONS * pdwOptions) = 0;
};
#endif /* __IBrowserFrameOptions_INTERFACE_DEFINED__ */

class PyIBrowserFrameOptions : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIBrowserFrameOptions);
    static IBrowserFrameOptions *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *GetFrameOptions(PyObject *self, PyObject *args);

   protected:
    PyIBrowserFrameOptions(IUnknown *pdisp);
    ~PyIBrowserFrameOptions();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGBrowserFrameOptions : public PyGatewayBase, public IBrowserFrameOptions {
   protected:
    PyGBrowserFrameOptions(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGBrowserFrameOptions, IBrowserFrameOptions, IID_IBrowserFrameOptions, PyGatewayBase)

    // IBrowserFrameOptions
    STDMETHOD(GetFrameOptions)(BROWSERFRAMEOPTIONS dwMask, BROWSERFRAMEOPTIONS *pdwOptions);
};
