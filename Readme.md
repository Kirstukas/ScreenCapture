# ScreenCapture (scrcap)

A simple library to take screenshots on windows operating system

```C
// Capture the entire screen
RGBQUAD ScreenCapture();

// Capture a selected rectangle
RGBQUAD RectCapture(int x, int y, int w, int h);
```

```
// To get the monitor resolution you
// can use windows function GetSystemMetrics
int width = GetSystemMetrics(SM_CXSCREEN);
int width = GetSystemMetrics(SM_CYSCREEN);
```
