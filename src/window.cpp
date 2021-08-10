#include "window.h"

Window::Window(const char* title, int w, int h){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
Window::~Window(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
}
void Window::LimparTela(){
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);
}
void Window::AtualizarTela(){
	SDL_RenderPresent(render);
}