#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t start_timer();
void print_time_elapsed(int64_t start, char *message);
void fprint_time_elapsed(FILE *file, int64_t start, char *message);
void print_time_elapsed_stderr(int64_t start, char *message);

#ifdef __cplusplus
}
#endif