#pragma once
#include <SDL.h> 
#include "Canvas.h"
#include "Ray.h"
#include "Object.h"
#include "Scene.h"
#include "Camera.h"

class Renderer { 
	public: 
		Renderer() = default;

		bool Initialize();
		void Shutdown();

		void Render(Canvas& canvas, Scene& scene, Camera& camera, int samples = 5);

		bool CreateWindow(int width, int height);

		void CopyCanvas(const Canvas& canvas);
		void Present();

		friend class Canvas;

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };

private:
	color3 GetBackgroundFromRay(const Ray& ray);
};