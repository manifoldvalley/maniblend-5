#include <Python.h>
#include "manidiff_mod.h"

#ifdef __cplusplus
extern "C" {
#endif
static PyObject *imageBufferList = NULL;
static PyObject *imageBuffer = NULL;

PyObject *get_image_list(void){
    if (!imageBufferList){
        Py_RETURN_NONE;
    }
    else{
        Py_INCREF(imageBufferList);
            // This should not be necessary, but weird memory behavior occurs when an extra reference is not added here.
        return imageBufferList;
    }
}

PyObject *clear_image_list(void){
    if (deleteImageBufferList()){
        PyErr_SetString(PyExc_RuntimeError, "Failed to delete to list.\n");
        return NULL;
    }
    else{
        Py_RETURN_NONE;
    }
}

PyObject *get_maniblend_version(void){
    // Returns the current maniblend version
    return PyUnicode_FromString("4.2.3.1");
}

int createImageBufferList(){
    PyGILState_STATE gstate = PyGILState_Ensure();
    imageBufferList = PyList_New(0);
    if (imageBufferList){
        PyGILState_Release(gstate);
        return 0;
    }
    else{
        // Failed to create list
        printf("Failed to create list\n");
        imageBufferList = NULL;
        PyGILState_Release(gstate);
        return 1;
    }
}

int deleteImageBufferList(){
    PyGILState_STATE gstate = PyGILState_Ensure();
    if (!imageBufferList){
        PyGILState_Release(gstate);
        return 1;
    }
    PyObject *first = PyList_GetItem(imageBufferList, 0);
    Py_DECREF(imageBufferList);

    imageBufferList = NULL;
    PyGILState_Release(gstate);
    return 0;
}

int bufferListIsNull(void){
    return imageBufferList == NULL;
}

int addToImageBufferList(const char *image, int size){
    if (!imageBufferList){
        if (createImageBufferList()){
            return 1;
        }
    }
    PyGILState_STATE gstate = PyGILState_Ensure();
    PyObject *temp = PyByteArray_FromStringAndSize(image, size);
    if (PyByteArray_Check(temp)){
        if (PyList_Append(imageBufferList, temp)){
            printf("List append failed.\n");
            Py_DECREF(temp);
            PyGILState_Release(gstate);
            return 1;
        }
        Py_DECREF(temp);
        PyGILState_Release(gstate);
        return 0;
    }
    else {
        PyGILState_Release(gstate);
        return 1;
    }
}

static struct PyMethodDef manidiff_methods[] = {
    {"get_image_list",        (PyCFunction)get_image_list,   METH_NOARGS, NULL},
    {"clear_image_list",      (PyCFunction)clear_image_list, METH_NOARGS, NULL},
    {"get_maniblend_version", (PyCFunction)get_maniblend_version,   METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef manidiff_module = {
    PyModuleDef_HEAD_INIT,
    "_bpy.manidiff",
    NULL,
    -1, /* multiple "initialization" just copies the module dict. */
    manidiff_methods,
    NULL,
    NULL,
    NULL,
    NULL,
};

PyObject *MD_manidiff_module(void)
{
  PyObject *submodule;

  submodule = PyModule_Create(&manidiff_module);

  return submodule;
}

#ifdef __cplusplus
}
#endif