
#include "Renderer.h"
#include "Sphere.h"
#include "Scene.h"
//#include "Plane.h"
#include "Camera.h"
#include <iostream>

int main(int i, char** p)
{
	Renderer renderer; 
	renderer.Initialize(); 
	renderer.CreateWindow(600, 300);

	Canvas canvas(600, 300, renderer);
	Camera camera({ 0, 1, 2 }, { 0, 0, 0 }, { 0, 1, 0 }, 70.0f, 600 / (float)300);
	//auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);

	Scene scene;

	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, .5f, 1 }, 0.5f, std::make_unique<Lambertian>(color3{ 1, 1, 0.01f })));

	bool quit = false;
	while (!quit) 
	{ 
		SDL_Event event; 
		SDL_PollEvent(&event); 
		switch (event.type) 
		{ 
		case SDL_QUIT: 
			quit = true; 
			break; 
		} 

		canvas.Clear({ 0, 0, 0, 1 });
		renderer.Render(canvas, scene, camera); 
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();

	} 
	renderer.Shutdown(); 
	return 0;
}
