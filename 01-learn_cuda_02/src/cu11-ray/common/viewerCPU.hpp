#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <vector>
#include <functional>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "check.hpp"
#include "fs.hpp"
#include "spriteRenderer.hpp"
static void glfwErrorPrint(int code, const char *info);
class CPUViewer
{
public:
  void init(int width, int height);
  unsigned char *getPixelsPtr() { return pixels_.data(); }
  long getPixelsDataSize() { return width_ * height_ * 4; }
  int w() { return width_; }
  int h() { return height_; }
  static CPUViewer &getInstance()
  {
    static CPUViewer instance_{};
    return instance_;
  }
  void displayAndExit(std::function<void(unsigned char *, int, int)> updateFunc = nullptr);
  ~CPUViewer();

private:
  void initWindowAndOpengGL();
  void registeCallback();
  static void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                          int mods);
  void draw(void);

  void initTexture();
  void copyToTexture();
  void buildeShader();
  CPUViewer() {}
  std::vector<unsigned char> pixels_;
  int width_;
  int height_;
  GLFWwindow *window_{nullptr};
  std::unique_ptr<SpriteRenderer> renderer_{nullptr};
  Texture2D textureToShow_{};
};
#endif