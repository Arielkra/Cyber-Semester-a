// This file implements the IViewObject Interface and Gateway for Python.
// Generated by makegw.py

#include "axcontrol_pch.h"
#include "PyIViewObject.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIViewObject::PyIViewObject(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIViewObject::~PyIViewObject() {}

/* static */ IViewObject *PyIViewObject::GetI(PyObject *self) { return (IViewObject *)PyIUnknown::GetI(self); }

// @pymethod |PyIViewObject|Draw|Description of Draw.
PyObject *PyIViewObject::Draw(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    // @pyparm int|dwDrawAspect||Description for dwDrawAspect
    // @pyparm int|lindex||Description for lindex
    DVASPECTINFO aspect;
    aspect.cb = sizeof(aspect);

    // @pyparm int|aspectFlags||Integer value for the dwFlags item of the DVASPECTINFO structure.
    DVTARGETDEVICE *ptd;
    PyObject *obptd;
    // @pyparm HDC|hdcTargetDev||Description for hdcTargetDev
    // @pyparm HDC|hdcDraw||Description for hdcDraw

    // @pyparm int, int, int, int|left, top, right, bottom||Bounds rectangle.
    // @pyparm int, int, int, int|left, top, right, bottom||WBounds rectangle.

    PyObject *obfuncContinue;
    PyObject *obContinue;
    // @pyparm object|funcContinue||A continue function.
    // @pyparm object|obContinue||Value passed to the function.
    DWORD dwDrawAspect;
    LONG lindex;
    HDC hdcTargetDev;
    HDC hdcDraw;
    RECTL rcBounds;
    RECTL rcWBounds;
    if (!PyArg_ParseTuple(args, "lllOll(llll)(llll)OO:Draw", &dwDrawAspect, &lindex, &aspect.dwFlags, &obptd,
                          &hdcTargetDev, &hdcDraw, &rcBounds.left, &rcBounds.right, &rcBounds.top, &rcBounds.bottom,
                          &rcWBounds.left, &rcWBounds.right, &rcWBounds.top, &rcWBounds.bottom, &obfuncContinue,
                          &obContinue))
        return NULL;
    if (obfuncContinue != Py_None) {
        PyErr_SetString(PyExc_TypeError, "The function pointer argument is not supported");
        return NULL;
    }
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyObject_AsDVTARGETDEVICE(obptd, &ptd))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIVO->Draw(dwDrawAspect, lindex, &aspect, ptd, hdcTargetDev, hdcDraw, &rcBounds, &rcWBounds, NULL, 0);
    PY_INTERFACE_POSTCALL;

    PyObject_FreeDVTARGETDEVICE(ptd);

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIViewObject|GetColorSet|Description of GetColorSet.
PyObject *PyIViewObject::GetColorSet(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    // @pyparm int|dwDrawAspect||Description for dwDrawAspect
    // @pyparm int|lindex||Description for lindex

    // @pyparm int|aspectFlags||Integer value for the dwFlags item of the DVASPECTINFO structure.
    DVASPECTINFO aspect;
    aspect.cb = sizeof(aspect);

    DVTARGETDEVICE *ptd;
    PyObject *obptd;
    // @pyparm HDC|hicTargetDev||Description for hicTargetDev
    DWORD dwDrawAspect;
    LONG lindex;
    HDC hicTargetDev;
    if (!PyArg_ParseTuple(args, "lllOi:GetColorSet", &dwDrawAspect, &lindex, &aspect.dwFlags, &obptd, &hicTargetDev))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyObject_AsDVTARGETDEVICE(obptd, &ptd))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    LOGPALETTE *ppColorSet;
    PY_INTERFACE_PRECALL;
    hr = pIVO->GetColorSet(dwDrawAspect, lindex, &aspect, ptd, hicTargetDev, &ppColorSet);
    PY_INTERFACE_POSTCALL;

    PyObject_FreeDVTARGETDEVICE(ptd);
    if (FAILED(hr))
        return OleSetOleError(hr);
    return PyObject_FromLOGPALETTE(ppColorSet);
}

// @pymethod |PyIViewObject|Freeze|Description of Freeze.
PyObject *PyIViewObject::Freeze(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    // @pyparm int|dwDrawAspect||Description for dwDrawAspect
    // @pyparm int|lindex||Description for lindex
    DVASPECTINFO aspect;
    aspect.cb = sizeof(aspect);
    // @pyparm int|aspectFlags||Integer value for the dwFlags item of the DVASPECTINFO structure.
    DWORD dwDrawAspect;
    LONG lindex;
    DWORD pdwFreeze;
    if (!PyArg_ParseTuple(args, "iiO:Freeze", &dwDrawAspect, &lindex, &aspect.dwFlags))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIVO->Freeze(dwDrawAspect, lindex, &aspect, &pdwFreeze);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);

    PyObject *pyretval = Py_BuildValue("i", pdwFreeze);
    return pyretval;
}

// @pymethod |PyIViewObject|Unfreeze|Description of Unfreeze.
PyObject *PyIViewObject::Unfreeze(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    // @pyparm int|dwFreeze||Description for dwFreeze
    DWORD dwFreeze;
    if (!PyArg_ParseTuple(args, "i:Unfreeze", &dwFreeze))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIVO->Unfreeze(dwFreeze);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIViewObject|SetAdvise|Description of SetAdvise.
PyObject *PyIViewObject::SetAdvise(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    // @pyparm int|aspects||Description for aspects
    // @pyparm int|advf||Description for advf
    // @pyparm <o PyIAdviseSink>|pAdvSink||Description for pAdvSink
    PyObject *obpAdvSink;
    DWORD aspects;
    DWORD advf;
    IAdviseSink *pAdvSink;
    if (!PyArg_ParseTuple(args, "iiO:SetAdvise", &aspects, &advf, &obpAdvSink))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpAdvSink, IID_IAdviseSink, (void **)&pAdvSink, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIVO->SetAdvise(aspects, advf, pAdvSink);
    if (pAdvSink)
        pAdvSink->Release();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIViewObject|GetAdvise|Description of GetAdvise.
PyObject *PyIViewObject::GetAdvise(PyObject *self, PyObject *args)
{
    IViewObject *pIVO = GetI(self);
    if (pIVO == NULL)
        return NULL;
    DWORD pAspects;
    DWORD pAdvf;
    IAdviseSink *ppAdvSink;
    if (!PyArg_ParseTuple(args, ":GetAdvise"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIVO->GetAdvise(&pAspects, &pAdvf, &ppAdvSink);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    PyObject *obppAdvSink = PyCom_PyObjectFromIUnknown(ppAdvSink, IID_IAdviseSink, FALSE);
    return Py_BuildValue("iiN", pAspects, pAdvf, obppAdvSink);
}

// @object PyIViewObject|Description of the interface
static struct PyMethodDef PyIViewObject_methods[] = {
    {"Draw", PyIViewObject::Draw, 1},                // @pymeth Draw|Description of Draw
    {"GetColorSet", PyIViewObject::GetColorSet, 1},  // @pymeth GetColorSet|Description of GetColorSet
    {"Freeze", PyIViewObject::Freeze, 1},            // @pymeth Freeze|Description of Freeze
    {"Unfreeze", PyIViewObject::Unfreeze, 1},        // @pymeth Unfreeze|Description of Unfreeze
    {"SetAdvise", PyIViewObject::SetAdvise, 1},      // @pymeth SetAdvise|Description of SetAdvise
    {"GetAdvise", PyIViewObject::GetAdvise, 1},      // @pymeth GetAdvise|Description of GetAdvise
    {NULL}};

PyComTypeObject PyIViewObject::type("PyIViewObject", &PyIUnknown::type, sizeof(PyIViewObject), PyIViewObject_methods,
                                    GET_PYCOM_CTOR(PyIViewObject));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGViewObject::Draw(
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void __RPC_FAR *pvAspect,
    /* [unique][in] */ DVTARGETDEVICE __RPC_FAR *ptd,
    /* [in] */ HDC hdcTargetDev,
    /* [in] */ HDC hdcDraw,
    /* [in] */ LPCRECTL lprcBounds,
    /* [unique][in] */ LPCRECTL lprcWBounds,
    /* [in] */ BOOL(STDMETHODCALLTYPE __RPC_FAR *pfnContinue)(ULONG_PTR dwContinueArg),
    /* [in] */ ULONG_PTR dwContinue)
{
    PY_GATEWAY_METHOD;
    PyObject *obpvAspect = PyInt_FromLong(((DVASPECTINFO *)pvAspect)->dwFlags);
    if (obpvAspect == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *obptd = PyObject_FromDVTARGETDEVICE(ptd);
    if (obptd == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *oblprcBounds =
        Py_BuildValue("llll", lprcBounds->left, lprcBounds->top, lprcBounds->right, lprcBounds->bottom);
    if (oblprcBounds == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *oblprcWBounds =
        Py_BuildValue("llll", lprcWBounds->left, lprcWBounds->top, lprcWBounds->right, lprcWBounds->bottom);
    if (oblprcWBounds == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *obFuncContinue = PyLong_FromVoidPtr(pfnContinue);
    if (obFuncContinue == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *obContinue = PyWinObject_FromULONG_PTR(dwContinue);
    HRESULT hr = InvokeViaPolicy("Draw", NULL, "iiOOiiOOOO", dwDrawAspect, lindex, obpvAspect, obptd, hdcTargetDev,
                                 hdcDraw, oblprcBounds, oblprcWBounds, obFuncContinue, obContinue);
    Py_XDECREF(obpvAspect);
    Py_XDECREF(obptd);
    Py_XDECREF(oblprcBounds);
    Py_XDECREF(oblprcWBounds);
    Py_XDECREF(obFuncContinue);
    Py_XDECREF(obContinue);
    return hr;
}

STDMETHODIMP PyGViewObject::GetColorSet(
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void __RPC_FAR *pvAspect,
    /* [unique][in] */ DVTARGETDEVICE __RPC_FAR *ptd,
    /* [in] */ HDC hicTargetDev,
    /* [out] */ LOGPALETTE __RPC_FAR *__RPC_FAR *ppColorSet)
{
    return E_NOTIMPL;
    /**
        if (ppColorSet==NULL) return E_POINTER;
        PY_GATEWAY_METHOD;
        PyObject *obpvAspect = PyInt_FromLong(((DVASPECTINFO *)pvAspect)->dwFlags);
        if (obpvAspect==NULL) return PyCom_HandlePythonFailureToCOM();

        PyObject *obptd = PyObject_FromDVTARGETDEVICE(ptd);
        if (obptd==NULL) return PyCom_HandlePythonFailureToCOM();

        PyObject *result;
        HRESULT hr=InvokeViaPolicy("GetColorSet", &result, "iiOOi", dwDrawAspect, lindex, obpvAspect, obptd,
    hicTargetDev); Py_DECREF(obpvAspect); Py_DECREF(obptd); if (FAILED(hr)) return hr;

        // What to do with the output!
        PyObject_AsLOGPALETTE
    ***/
}

STDMETHODIMP PyGViewObject::Freeze(
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void __RPC_FAR *pvAspect,
    /* [out] */ DWORD __RPC_FAR *pdwFreeze)
{
    PY_GATEWAY_METHOD;
    PyObject *obpvAspect = PyInt_FromLong(((DVASPECTINFO *)pvAspect)->dwFlags);
    if (obpvAspect == NULL)
        return PyCom_HandlePythonFailureToCOM();
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("Freeze", &result, "iiO", dwDrawAspect, lindex, obpvAspect);
    Py_DECREF(obpvAspect);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyArg_Parse(result, "i", pdwFreeze))
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGViewObject::Unfreeze(
    /* [in] */ DWORD dwFreeze)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("Unfreeze", NULL, "i", dwFreeze);
    return hr;
}

STDMETHODIMP PyGViewObject::SetAdvise(
    /* [in] */ DWORD aspects,
    /* [in] */ DWORD advf,
    /* [unique][in] */ IAdviseSink __RPC_FAR *pAdvSink)
{
    PY_GATEWAY_METHOD;
    PyObject *obpAdvSink;
    obpAdvSink = PyCom_PyObjectFromIUnknown(pAdvSink, IID_IAdviseSink, TRUE);
    HRESULT hr = InvokeViaPolicy("SetAdvise", NULL, "iiO", aspects, advf, obpAdvSink);
    Py_XDECREF(obpAdvSink);
    return hr;
}

STDMETHODIMP PyGViewObject::GetAdvise(
    /* [out] */ DWORD __RPC_FAR *pAspects,
    /* [out] */ DWORD __RPC_FAR *pAdvf,
    /* [out] */ IAdviseSink __RPC_FAR *__RPC_FAR *ppAdvSink)
{
    PY_GATEWAY_METHOD;
    if (ppAdvSink == NULL)
        return E_POINTER;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetAdvise", &result);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppAdvSink;
    if (!PyArg_ParseTuple(result, "iiO", pAspects, pAdvf, &obppAdvSink))
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obppAdvSink, IID_IAdviseSink, (void **)ppAdvSink, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    Py_DECREF(result);
    return hr;
}
