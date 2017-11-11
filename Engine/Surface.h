#pragma once
#include "Colors.h"
#include <string>
#include "ChiliWin.h"
#include <fstream>

class Surface {
public:
	Surface(int width, int height);
	Surface(const std::string& filename);
	Surface(const Surface&);
	Surface& operator=(const Surface&);
	~Surface();
	void LoadBitmap(const std::string & filename);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

private:
	Color* pPixels = nullptr;
	int width;
	int height;
	int bitCount;
};
