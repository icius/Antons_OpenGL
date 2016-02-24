// Std. Includes
#include <stdio.h>

// glLoadGen
#include "gl_core_4_3.h"

// GLFW
#include <GLFW/glfw3.h>

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

GLuint screenWidth = 1024, screenHeight = 768;

int main()
{

    // Init GLFW

    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight,
                                          "LearnOpenGL", nullptr, nullptr);

    if(!window)
    {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    int loaded = ogl_LoadFunctions();
    if(loaded == ogl_LOAD_FAILED) {
        return 0;
    }
    int num_failed = loaded - ogl_LOAD_SUCCEEDED;
    printf("Number of functions that failed to load: %i.\n",num_failed);

    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    glfwTerminate();


    return 0;
}
