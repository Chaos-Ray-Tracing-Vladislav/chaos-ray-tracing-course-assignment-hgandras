#pragma once
#include "Vector.h"
#include "Frame.h"
#include "Image.h"
#include "Ray.h"

const double PI = acos(-1);

//TODO: Maybe just passing the image dimensions is enough instead of the whole image
class Camera {
private:
	float planeW;
	float planeH;
	float pixelStep;

	void update_params()
	{
		float alpha = FOV / 2.f;
		planeW = tanf(alpha/180*PI) * 2;
		planeH = planeW * image.h / image.w;
		pixelStep = planeW / image.w;
	}

public:
	Frame frame;
	float FOV;
	Image image;

	Camera() 
	{
		setFOV(90);
	}

	Camera(Image& img, Frame frame, float FOV) :frame(frame), image(img), FOV(FOV)
	{
		update_params();
	}

	//Casts a ray through a pixel of the image. The image plane is distance 1 from the camera
	//and the camera faces the -z direction. The returned ray is in the world coordinate system.
	Ray CastRay(int x, int y)
	{
		if (x > image.w || x<0 || y>image.h || y < 0)
			throw std::invalid_argument("The pixel index was outside of the image range");
		
		//NDC space (Not really, because these are the real world dimensions measured from the corner of the 
		// image)
		float xS = (x + 0.5f) * pixelStep;
		float yS = (y + 0.5f) * pixelStep;

		//Screen space
		xS = xS - planeW / 2;
		yS = planeH / 2 - yS;

		//Determine dicrection and origin
		Vector3 origin = Vector3::zero();
		Vector3 dir(xS,yS,-1);

		//Transform to world
		origin = frame.ToWorld(origin);
		dir = frame.ToWorld(dir);

		return Ray(origin, dir);
	}

	void setFOV(float fov)
	{
		FOV = fov;
		update_params();
	}

	//These will all just rotate or translate the camera frame
	void Dolly()
	{

	}

	void Truck()
	{

	}

	void Pedestal()
	{

	}

	void Pan()
	{

	}

	void Tilt()
	{

	}

	void Roll()
	{

	}
};
