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
		bool CreateWindow(int width, int height); 

		void Render(Canvas& canvas, Scene& scene, Camera& camera);

		void CopyCanvas(const Canvas& canvas);
		void Present();

	private:
		color3 GetBackgroundFromRay(const Ray& ray);

		friend class Canvas;

	private: 
		SDL_Window* m_window{ nullptr }; 
		SDL_Renderer* m_renderer{ nullptr }; 
};