#include <Python.h>
#include <frameobject.h>
#include <stdbool.h>

bool looking = false;

static PyObject* getitem(PyObject* self, PyObject* arg) {
    PySliceObject* slice = (PySliceObject*) arg;

    looking = true;
    PyObject* attribute = PyObject_GetAttr(
        self,
        slice->step
    );
    looking = false;

    Py_XINCREF(attribute);
    return attribute;
}


getattrofunc preserved = NULL;

static PyObject* getattr(PyObject* self, PyObject* key) {
    PyFrameObject* f = PyEval_GetFrame();
    if (f && (self != (PyObject*) &PyType_Type) && !looking) {
        PyErr_WarnEx(
            PyExc_UserWarning,
            "you must be fun at parties",
            1
        );
    }
    return preserved(
        self,
        key
    );
}

static PyMappingMethods mappings = {
    .mp_subscript = getitem
};

static PyObject* inject(PyObject* self, PyObject* args) {
    PyType_Type.tp_as_mapping = &mappings;
    preserved = PyType_Type.tp_getattro;
    PyType_Type.tp_getattro = getattr;
    PyType_Modified(&PyType_Type);
    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"inject", inject, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "namespaces",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_namespaces(void) {
    return PyModule_Create(&module);
}
