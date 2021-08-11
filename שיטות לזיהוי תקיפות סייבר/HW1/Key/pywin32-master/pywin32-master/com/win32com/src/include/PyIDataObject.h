// This file declares the IDataObject Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIDataObject : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIDataObject);
    static IDataObject *GetI(PyObject *self);
    static PyComEnumProviderTypeObject type;

    // The Python methods
    static PyObject *GetData(PyObject *self, PyObject *args);
    static PyObject *GetDataHere(PyObject *self, PyObject *args);
    static PyObject *QueryGetData(PyObject *self, PyObject *args);
    static PyObject *GetCanonicalFormatEtc(PyObject *self, PyObject *args);
    static PyObject *SetData(PyObject *self, PyObject *args);
    static PyObject *EnumFormatEtc(PyObject *self, PyObject *args);
    static PyObject *DAdvise(PyObject *self, PyObject *args);
    static PyObject *DUnadvise(PyObject *self, PyObject *args);
    static PyObject *EnumDAdvise(PyObject *self, PyObject *args);

   protected:
    PyIDataObject(IUnknown *pdisp);
    ~PyIDataObject();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGDataObject : public PyGatewayBase, public IDataObject {
   protected:
    PyGDataObject(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGDataObject, IDataObject, IID_IDataObject, PyGatewayBase)

    // IDataObject
    STDMETHOD(GetData)(FORMATETC *pformatetcIn, STGMEDIUM *pmedium);

    STDMETHOD(GetDataHere)(FORMATETC *pformatetc, STGMEDIUM *pmedium);

    STDMETHOD(QueryGetData)(FORMATETC *pformatetc);

    STDMETHOD(GetCanonicalFormatEtc)(FORMATETC *pformatectIn, FORMATETC *pformatetcOut);

    STDMETHOD(SetData)(FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease);

    STDMETHOD(EnumFormatEtc)(DWORD dwDirection, IEnumFORMATETC **ppenumFormatEtc);

    STDMETHOD(DAdvise)(FORMATETC *pformatetc, DWORD advf, IAdviseSink *pAdvSink, DWORD *pdwConnection);

    STDMETHOD(DUnadvise)(DWORD dwConnection);

    STDMETHOD(EnumDAdvise)(IEnumSTATDATA **ppenumAdvise);
};
