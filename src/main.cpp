#include <iostream>
#include <GLFW/glfw3.h>

int main() {
    GLFWwindow *window;
    if (!glfwInit()) {
        return -1;
    }
    window = glfwCreateWindow(640, 480, "Window!", NULL, NULL);
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glfwSwapBuffers(window);
    }
    glfwTerminate();
}
