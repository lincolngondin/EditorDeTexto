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
			if(SDL_GetTicks()%2==0)
				editor.LogTree();
			while(SDL_PollEvent(&e)){
				
				if(e.type == SDL_QUIT) running = false;
				
				if(e.type == SDL_KEYDOWN){
					SDL_Keycode tecla = e.key.keysym.sym;
					if(tecla == SDLK_DOWN) 
						editor.pularLinha();
					else if(tecla == SDLK_UP) 
						editor.voltarLinha();
					else if(tecla == SDLK_RIGHT){
						editor.MoverParaDireita();
					}
					else if(tecla == SDLK_LEFT){
						editor.MoverParaEsquerda();
					}
					else if(tecla == SDLK_RETURN){
						editor.NovaLinha();
					}
					else if(tecla == SDLK_F2){
						editor.LogTree();
					}
					else if(tecla == SDLK_RETURN){
						//editor.getBuffer()[editor.getPos()] = 0x0a;
						//editor.next();
					}
					else if(tecla == SDLK_BACKSPACE){
						editor.ApagarLetra();
					}
				}
				
				if(e.type == SDL_TEXTINPUT){
					editor.AdicionarLetra(e.text.text[0]);
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