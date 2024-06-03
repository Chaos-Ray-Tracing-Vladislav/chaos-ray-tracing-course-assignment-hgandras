#include <iostream>
#include "Image.h"


int main()
{
	int h = 100;
	int w = 100;
	Image image(100, 100);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			Color pixel(255, 128, 0);
			image.setPixel(x, y, pixel);
		}
	}
	image.writePPM("Gazsy.ppm");
}

