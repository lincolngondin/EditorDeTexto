#include "app.h"
#include "window.h"
#include "editor.h"
#include "renderEditor.h"
#include <cstdio>

#include "SDL.h"
namespace App{
	
	static void Run();
	
	void Init(){
		Run();
	}
	
	
	static void Run(){
		bool running = true;
		Editor editor;
		Window Janela("Lincoln's Editor - v0.01", 500, 500);
		Render::loadFont("img/font.bmp", Janela);
		SDL_Event e;
		 
		
		while(running){
			Janela.LimparTela();
			while(SDL_PollEvent(&e)){
				if(e.type == SDL_QUIT) running = false;
				if(e.type == SDL_KEYDOWN){
					SDL_Keycode tecla = e.key.keysym.sym;
					if(tecla == SDLK_LCTRL){
						FILE* file = fopen("texto.txt", "wb");
						fwrite(editor.getBuffer(), sizeof(char), 1024, file);
						fclose(file);
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Arquivo salvo!", "Seu arquivo foi salvo com sucesso!", Janela.window);
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Arquivo salvo!", "Seu arquivo foi salvo com sucesso!", Janela.window);
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Arquivo salvo!", "Seu arquivo foi salvo com sucesso!", Janela.window);
					}
					if(tecla == SDLK_p){SDL_Log(editor.getBuffer());}
					if(tecla == SDLK_BACKSPACE){
						editor.before();
						editor.getBuffer()[editor.getPos()] = ' ';
						
					}
					else if(tecla == SDLK_RIGHT or tecla == SDLK_LEFT){
						if(tecla == SDLK_RIGHT) editor.next();
						if(tecla == SDLK_LEFT) editor.before();
					}
					else if(tecla == SDLK_RETURN){
						editor.getBuffer()[editor.getPos()] = 0x0a;
						editor.next();
					}
				}
				if(e.type == SDL_TEXTINPUT){
					editor.getBuffer()[editor.getPos()] = e.text.text[0];
					editor.next();
				}
			}
			Render::renderEditor(Janela, editor);
			
			
			SDL_Delay(1000/30);
			Janela.AtualizarTela();
		}
		Render::unloadFont();
	}
	

}