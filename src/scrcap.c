// Thanks to Lonami and Ben Voigt
// https://stackoverflow.com/a/64524067

#include <windows.h>

RGBQUAD* ScreenCapture(){
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HDC hdc = GetDC(NULL);
	HDC hdcmem = CreateCompatibleDC(NULL);
	HBITMAP hbmp = CreateCompatibleBitmap(hdc, width, height);
	HBITMAP holdbmp = SelectObject(hdcmem, hbmp);

	BITMAPINFO bmi;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);

	RGBQUAD* pixels = malloc(sizeof(RGBQUAD)*height*width);
	BitBlt(hdcmem, 0, 0, width, height, hdc, 0, 0, SRCCOPY);
	GetDIBits(hdcmem, hbmp, 0, height, pixels, &bmi, DIB_RGB_COLORS);

	DeleteObject(hbmp);
	DeleteDC(hdcmem);
	ReleaseDC(NULL, hdc);

	return pixels;
}

RGBQUAD* RectCapture(int x, int y, int width, int height){
	HDC hdc = GetDC(NULL);
	HDC hdcmem = CreateCompatibleDC(NULL);
	HBITMAP hbmp = CreateCompatibleBitmap(hdc, width, height);
	HBITMAP holdbmp = SelectObject(hdcmem, hbmp);

	BITMAPINFO bmi;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);

	RGBQUAD* pixels = malloc(sizeof(RGBQUAD)*height*width);
	BitBlt(hdcmem, 0, 0, width, height, hdc, x, y, SRCCOPY);
	GetDIBits(hdcmem, hbmp, 0, height, pixels, &bmi, DIB_RGB_COLORS);

	DeleteObject(hbmp);
	DeleteDC(hdcmem);
	ReleaseDC(NULL, hdc);

	return pixels;
}
