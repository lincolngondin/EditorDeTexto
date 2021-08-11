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
		Render::EditorRenderOptions opcoes = {500, 500, 7, 9, 0, 0, 2};
		Window Janela("Lincoln's Editor - v0.01", 500, 500);
		Render::loadFont("img/font.bmp", Janela);
		SDL_Event e;
		
		
		while(running){
			Janela.LimparTela();
			while(SDL_PollEvent(&e)){
				
				if(e.type == SDL_QUIT) running = false;
				
				if(e.type == SDL_KEYDOWN){
					SDL_Keycode tecla = e.key.keysym.sym;
					if(tecla == SDLK_RIGHT or tecla == SDLK_LEFT){
						if(tecla == SDLK_RIGHT) editor.pularLinha();
						if(tecla == SDLK_LEFT) editor.voltarLinha();
					}
					else if(tecla == SDLK_n){
						editor.NovaLinha();
						
					}
					else if(tecla == SDLK_RETURN){
						//editor.getBuffer()[editor.getPos()] = 0x0a;
						//editor.next();
					}
				}
				
				if(e.type == SDL_TEXTINPUT){
					//editor.getBuffer()[editor.getPos()] = e.text.text[0];
					//editor.next();
				}
			}
			//Render::renderEditor(Janela, editor, opcoes);
			
			
			SDL_Delay(1000/30);
			Janela.AtualizarTela();
		}
		Render::unloadFont();
	}
	

}