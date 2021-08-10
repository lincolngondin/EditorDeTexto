#ifndef WINDOW_H_
#define WINDOW_H_
#include <SDL.h>

class Window{
	public:
		SDL_Renderer* render = nullptr;
		SDL_Window* window = nullptr;
	public:
		Window(const char*, int, int);
		~Window();
	public:
		void LimparTela();
		void AtualizarTela();
};

#endif
