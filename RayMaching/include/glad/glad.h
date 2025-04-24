/*
    Glad loader - automatically generated and adapted for minimal OpenGL 3.3
    NOTE: For a full-featured loader, it's better to generate at https://gen.glad.sh
*/

#ifndef GLAD_GLAD_H_
#define GLAD_GLAD_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*GLADloadproc)(const char *name);
int gladLoadGLLoader(GLADloadproc load);

#include <KHR/khrplatform.h>

/* OpenGL types */
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;

/* Add here only the function pointer for glClear (minimal example) */
extern void (*glClear)(GLbitfield mask);
extern void (*glClearColor)(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

/* Optional: add more OpenGL functions you need */

#ifdef __cplusplus
}
#endif

#endif
