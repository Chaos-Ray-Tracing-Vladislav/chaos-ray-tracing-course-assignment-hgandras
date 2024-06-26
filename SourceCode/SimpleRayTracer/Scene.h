#pragma once
#include "Camera.h"
#include "Geometry.h"
#include "Ray.h"
#include "Image.h"
#include "Vector.h"
#include <vector>
#include <algorithm>
#include <string>

struct Scene {
	Camera cam;
	Color bg;
	std::vector<Geometry::Triangle> geometry;

	//scene without geometry
	Scene():cam(Camera()), bg(Color(128, 128, 128))
	{
			
	}

	Scene(Camera& cam, std::vector<Geometry::Triangle> geometryList) :cam(cam), bg(Color(128, 128, 128))
	{
		geometry.reserve(geometryList.size());
		geometry.insert(geometry.begin(), geometryList.begin(),geometryList.end());
	}

	void Render(std::string imgName) {
		for (int i = 0; i < cam.image.w * cam.image.h; i++)
		{
			Geometry::Intersection closestIntersection;
			bool intersected = false;
			int x = i % cam.image.w;
			int y = i / cam.image.w;
			Ray ray = cam.CastRay(x, y);

			for (int j = 0; j < geometry.size(); j++)
			{
				auto intersection = geometry[j].Intersect(ray);
				if (intersection.value().t<closestIntersection.t)
				{
					closestIntersection = intersection.value();
					intersected = true;
				}
			}

			//Sort intersections, and get material
			if (!intersected)
			{
				cam.image.setPixel(x, y, bg);
			}
			else {
				cam.image.setPixel(x, y, closestIntersection.material.color);
			}
		}
		cam.image.writePPM(imgName);
	}
};
