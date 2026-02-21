#pragma once
#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif
// PyObject *create_manidiff_module(void);
// int setErrorsMani(const char *errors, int size);
int deleteImageBufferList(void);
int addToImageBufferList(const char *image, int size);
int bufferListIsNull(void);

PyObject *MD_manidiff_module(void);

#ifdef __cplusplus
}
#endif