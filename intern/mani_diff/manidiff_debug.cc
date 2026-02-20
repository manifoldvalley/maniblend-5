
#include "manidiff_debug.h"
#include <chrono>

#ifdef __cplusplus
extern "C" {
#endif

int64_t start_timer(){
    auto tp = std::chrono::high_resolution_clock::now() ;
    return tp.time_since_epoch().count();
}

void fprint_time_elapsed(FILE *f, int64_t start, char *message){
    std::chrono::high_resolution_clock::duration dur(start);
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::high_resolution_clock::duration> tic(dur);
    auto toc = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> (toc- tic);
    fprintf(f, "TIME ELAPSED: %1.08f seconds -- %s\n", duration.count() / 1000000.0, message);
}

void print_time_elapsed(int64_t start, char *message){
    fprint_time_elapsed(stdout, start, message);
}

void print_time_elapsed_stderr(int64_t start, char *message){
    fprint_time_elapsed(stderr, start, message);
}

#ifdef __cplusplus
}
#endif