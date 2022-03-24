#ifndef SCRCAP_H
#define SCRCAP_H

#include <windows.h>

RGBQUAD* ScreenCapture();
RGBQUAD* RectCapture(int x, int y, int width, int height);

#endif
