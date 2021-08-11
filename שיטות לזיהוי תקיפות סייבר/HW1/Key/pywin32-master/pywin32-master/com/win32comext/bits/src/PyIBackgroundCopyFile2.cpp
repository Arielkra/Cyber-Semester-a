// This file implements the IBackgroundCopyFile2 Interface for Python.
// Generated by makegw.py

#include "bits_pch.h"
#include "PyIBackgroundCopyFile.h"
#include "PyIBackgroundCopyFile2.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIBackgroundCopyFile2::PyIBackgroundCopyFile2(IUnknown *pdisp) : PyIBackgroundCopyFile(pdisp) { ob_type = &type; }

PyIBackgroundCopyFile2::~PyIBackgroundCopyFile2() {}

/* static */ IBackgroundCopyFile2 *PyIBackgroundCopyFile2::GetI(PyObject *self)
{
    return (IBackgroundCopyFile2 *)PyIBackgroundCopyFile::GetI(self);
}

// @pymethod |PyIBackgroundCopyFile2|GetFileRanges|Description of GetFileRanges.
PyObject *PyIBackgroundCopyFile2::GetFileRanges(PyObject *self, PyObject *args)
{
    IBackgroundCopyFile2 *pIBCF2 = GetI(self);
    if (pIBCF2 == NULL)
        return NULL;
    DWORD RangeCount;
    BG_FILE_RANGE *Ranges;
    if (!PyArg_ParseTuple(args, ":GetFileRanges"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCF2->GetFileRanges(&RangeCount, &Ranges);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCF2, IID_IBackgroundCopyFile2);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIBackgroundCopyFile2|SetRemoteName|Description of SetRemoteName.
PyObject *PyIBackgroundCopyFile2::SetRemoteName(PyObject *self, PyObject *args)
{
    IBackgroundCopyFile2 *pIBCF2 = GetI(self);
    if (pIBCF2 == NULL)
        return NULL;
    PyObject *obpRemoteName;
    if (!PyArg_ParseTuple(args, "O:SetRemoteName", &obpRemoteName))
        return NULL;
    WCHAR *pRemoteName;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyWinObject_AsWCHAR(obpRemoteName, &pRemoteName))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;

    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCF2->SetRemoteName(pRemoteName);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCF2, IID_IBackgroundCopyFile2);
    Py_INCREF(Py_None);
    return Py_None;
}

// @object PyIBackgroundCopyFile2|Description of the interface
static struct PyMethodDef PyIBackgroundCopyFile2_methods[] = {
    {"GetFileRanges", PyIBackgroundCopyFile2::GetFileRanges, 1},  // @pymeth GetFileRanges|Description of GetFileRanges
    {"SetRemoteName", PyIBackgroundCopyFile2::SetRemoteName, 1},  // @pymeth SetRemoteName|Description of SetRemoteName
    {NULL}};

PyComTypeObject PyIBackgroundCopyFile2::type("PyIBackgroundCopyFile2", &PyIBackgroundCopyFile::type,
                                             sizeof(PyIBackgroundCopyFile2), PyIBackgroundCopyFile2_methods,
                                             GET_PYCOM_CTOR(PyIBackgroundCopyFile2));
