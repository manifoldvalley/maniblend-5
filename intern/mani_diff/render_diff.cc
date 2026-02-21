// #pragma once

#include "render_diff.h"
#include "manidiff_mod.h"

extern "C" {

int saveImageToBuffer(const float *float_buf, const int img_w, const int img_h){
    int NUM_CHANNELS = 4;
        // At present, ImBuf float rects are always 4 channel    
    int size = img_w * img_h * NUM_CHANNELS * sizeof(float);
    return addToImageBufferList((const char *)float_buf, size);
}

int imageBufferListIsNull(void){
    return bufferListIsNull();
}

int clearImageBufferList(void){
    return deleteImageBufferList();
}

}