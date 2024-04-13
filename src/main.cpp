#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>

int main() {
  GLFWwindow *window;
  if (!glfwInit()) {
    return -1;
  }
  window = glfwCreateWindow(640, 480, "window", NULL, NULL);
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "could not load opengl\n";
    glfwTerminate();
    return -1;
  }
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glfwSwapBuffers(window);
  }
  glfwTerminate();
}
