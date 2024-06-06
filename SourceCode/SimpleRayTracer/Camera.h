#pragma once
#include "Vector.h"
#include "Frame.h"
#include "Image.h"
#include "Ray.h"

class Camera {
private:
	float planeW;
	float planeH;
	float pixelStep;

public:

	Frame frame;
	float FOV;
	Image image;

	Camera() : FOV(45)
	{
		float alpha = FOV / 2.f;
		planeW = tanf(alpha) * 2;
		planeH = planeW * image.h / image.w;
		pixelStep = planeW / image.w;
	}

	Camera(Image& img, Frame frame, float FOV) :frame(frame), image(img), FOV(FOV)
	{
		float alpha = FOV / 2.f;
		planeW = tanf(alpha) * 2;
		planeH = planeW * image.h / image.w;
		pixelStep = planeW / image.w;
	}

	//Casts a ray through a pixel of the image. The image plane is distance 1 from the camera
	//and the camera faces the -z direction. The returned ray is in the world coordinate system.
	Ray CastRay(int x, int y)
	{
		if (x > image.w || x<0 || y>image.h || y < 0)
			throw std::invalid_argument("The pixel index was outside of the image range");
		
		//NDC space (Not really, because these are the real world dimensions measured from the corner of the 
		// image)
		float x = (x + 0.5f) * pixelStep;
		float y = (y + 0.5f) * pixelStep;

		//Screen space
		x = x - planeW / 2;
		y = planeH / 2 - y;

		//Determine dicrection and origin
		Vector3 origin = Vector3::zero();
		Vector3 dir(x,y,-1);

		//Transform to world
		origin = frame.ToWorld(origin);
		dir = frame.ToWorld(dir);

		return Ray(origin, dir);
	}
	
};
