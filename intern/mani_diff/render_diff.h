#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int saveImageToBuffer(const float *float_buf, const int img_w, const int img_h);
int imageBufferListIsNull(void);
int clearImageBufferList(void);

#ifdef __cplusplus
}
#endif