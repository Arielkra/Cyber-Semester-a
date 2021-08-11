// This file declares the IDebugDocumentTextExternalAuthor Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIDebugDocumentTextExternalAuthor : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIDebugDocumentTextExternalAuthor);
    static IDebugDocumentTextExternalAuthor *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *GetPathName(PyObject *self, PyObject *args);
    static PyObject *GetFileName(PyObject *self, PyObject *args);
    static PyObject *NotifyChanged(PyObject *self, PyObject *args);

   protected:
    PyIDebugDocumentTextExternalAuthor(IUnknown *pdisp);
    ~PyIDebugDocumentTextExternalAuthor();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGDebugDocumentTextExternalAuthor : public PyGatewayBase, public IDebugDocumentTextExternalAuthor {
   protected:
    PyGDebugDocumentTextExternalAuthor(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT(PyGDebugDocumentTextExternalAuthor, IDebugDocumentTextExternalAuthor,
                           IID_IDebugDocumentTextExternalAuthor)

    // IDebugDocumentTextExternalAuthor
    STDMETHOD(GetPathName)(BSTR __RPC_FAR *pbstrLongName, BOOL __RPC_FAR *pfIsOriginalFile);

    STDMETHOD(GetFileName)(BSTR __RPC_FAR *pbstrShortName);

    STDMETHOD(NotifyChanged)(void);
};