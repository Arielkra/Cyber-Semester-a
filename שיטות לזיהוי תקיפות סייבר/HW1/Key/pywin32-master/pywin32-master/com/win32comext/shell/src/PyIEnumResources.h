// This file declares the IEnumResources Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIEnumResources : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIEnumResources);
    static IEnumResources *GetI(PyObject *self);
    static PyComEnumTypeObject type;

    // The Python methods
    static PyObject *Next(PyObject *self, PyObject *args);
    static PyObject *Skip(PyObject *self, PyObject *args);
    static PyObject *Reset(PyObject *self, PyObject *args);
    static PyObject *Clone(PyObject *self, PyObject *args);

   protected:
    PyIEnumResources(IUnknown *pdisp);
    ~PyIEnumResources();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGEnumResources : public PyGatewayBase, public IEnumResources {
   protected:
    PyGEnumResources(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGEnumResources, IEnumResources, IID_IEnumResources, PyGatewayBase)

    // IEnumResources
    STDMETHOD(Next)(ULONG celt, SHELL_ITEM_RESOURCE *psir, ULONG *pceltFetched);

    STDMETHOD(Skip)(ULONG celt);

    STDMETHOD(Reset)(void);

    STDMETHOD(Clone)(IEnumResources **ppenumr);
};
