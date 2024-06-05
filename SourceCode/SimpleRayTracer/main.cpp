#include <iostream>
#include "Image.h"
#include "Vector.h"


void RandomImage()
{
	int w = 1920;
	int h = 1080;

	int n_small_x = 4;
	int n_small_y = 4;

	int stepX = w / n_small_x;
	int stepY = h / n_small_y;
	Image image(w,h);
	for (int small_i = 0; small_i < n_small_x*n_small_y; small_i++)
	{
		int small_x = small_i % n_small_x;
		int small_y = small_i / n_small_x;
		for (int i = 0; i < stepX*stepY; i++)
		{
			int x =small_x * stepX + i % stepX;
			int y =small_y * stepY + i / stepX;
			
			int r = small_i == 0 ? 0 : 255 / small_i;
			int g = small_i * 16;
			int b = small_i * small_i * 4;
			image.setPixel(x, y, Color(r, g, b));
		}
	}
	image.writePPM("Gazsi.ppm");
}

void CircleImage()
{
	int w = 1920;
	int h = 1080;

	int n_small_x = 4;
	int n_small_y = 4;

	int stepX = w / n_small_x;
	int stepY = h / n_small_y;

	int cx = w / 2;
	int cy = h / 2;

	Image image(w, h);
	Color circleCol(255, 0, 0);
	Color bg(128, 128, 128);

	for (int small_i = 0; small_i < n_small_x * n_small_y; small_i++)
	{
		int small_x = small_i % n_small_x;
		int small_y = small_i / n_small_x;
		for (int i = 0; i < stepX * stepY; i++)
		{
			int x = small_x * stepX + i % stepX;
			int y = small_y * stepY + i / stepX;

			int r = small_i == 0 ? 0 : 255 / small_i;
			int g = small_i * 16;
			int b = small_i * small_i * 4;
			image.setPixel(x, y, Color(r, g, b));
		}
	}
	image.writePPM("Gazsi.ppm");
}

int main()
{
	RandomImage();
	//CircleImage();
}

