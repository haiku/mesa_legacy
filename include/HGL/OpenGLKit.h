/*
 * Master include file for the OpenGL Kit.
 *
 */

#include <GL/gl.h>
#if defined(__GNUC__) && __GNUC__ < 3
// glu is only part of libGL for BeOS compatibility
#include <GL/glu.h>
#endif
#include <GLView.h>
