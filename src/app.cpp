#include "app.h"
#include "window.h"
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
		Render::EditorRenderOptions opcoes = {500, 500, 14, 18, 0, 0, 2};
		Window Janela("Lincoln's Editor - v0.01", 500, 500);
		Render::loadFont("img/font.bmp", Janela);
		SDL_Event e;
		
		
		while(running){
			Janela.LimparTela();
			
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
					else if(tecla == SDLK_BACKSPACE){
						editor.ApagarLetra();
					}
					else if(tecla == SDLK_LCTRL){
						SalvarArquivo("teste.cpp", "\r\n",editor);
					}
				}
				
				if(e.type == SDL_TEXTINPUT) editor.AdicionarLetra(e.text.text[0]);
			}
			Render::renderEditor(Janela, editor, opcoes);
			
			
			SDL_Delay(1000/30);
			Janela.AtualizarTela();
		}
		Render::unloadFont();
	}
	
	bool SalvarArquivo(const char* file_name, const char* EOL, const Editor& editor){
		FILE *file = fopen(file_name, "wb");
		linha *Linha = editor.GetHead();
		while(Linha!=nullptr){
			fprintf(file, "%s", Linha->data);
			fprintf(file, EOL);
			Linha = Linha->next;
		}
		fclose(file);
		return true;
	}
	
}