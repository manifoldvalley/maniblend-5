set(INC
  .
  ../../source/blender/imbuf
  ../../source/blender/makesdna
  ../../source/blender/blenlib
  ../../source/blender/blenkernel
)

set(INC_SYS
    ${PYTHON_INCLUDE_DIRS}
)

set(SRC
    render_diff.cc
    render_diff.h
    manidiff_mod.c
    manidiff_mod.h
    manidiff_debug.cc
    manidiff_debug.h

)

set(LIB
    ${PYTHON_LINKFLAGS}
    ${PYTHON_LIBRARIES}
)


blender_add_lib(intern_mani_diff "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")