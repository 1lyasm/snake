#include "glad.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include <math.h>
#include <thread>

#define STEPS 100
#define ANGLE 3.1415926 * 2.f / STEPS

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
  float x = 0, y = 0, radius = 1 / 20.0;
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    float oldx = x;
    float oldy = y - radius;
    for (int i = 0; i <= STEPS; ++i) {
      float newx = x + radius * sin(ANGLE * i);
      float newy = -radius * cos(ANGLE * i);
      glBegin(GL_TRIANGLES);
      glColor3f(1.0, 0.0, 0.0);
      glVertex3f(x, 0.0f, 0.0f);
      glVertex3f(oldx, oldy, 0.0f);
      glVertex3f(newx, newy, 0.0f);
      glEnd();
      oldx = newx;
      oldy = newy;
    }
    x += 2 * radius;
    std::chrono::milliseconds span((int)1e3);
    std::this_thread::sleep_for(span);
    glfwSwapBuffers(window);
  }
  glfwTerminate();
}
