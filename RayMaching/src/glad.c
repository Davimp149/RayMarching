#include <glad/glad.h>
#include <GLFW/glfw3.h>

static void* get_proc(const char* namez) {
    return (void*)glfwGetProcAddress(namez);
}

int gladLoadGLLoader(GLADloadproc load) {
    return gladLoadGL();
}
