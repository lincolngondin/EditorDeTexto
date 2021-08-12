#include "renderEditor.h"

namespace Render{
	#define quebrarLinha true

	static SDL_Rect srcRect = {0, 0, 7, 9};
	static SDL_Rect dstRect = {0, 0, 7, 9};
	static SDL_Texture* fonte_texture = nullptr;

	void renderEditor(const Window& janela, Editor& editor, const EditorRenderOptions& options){
		dstRect.x = options.offsetX;
		dstRect.y = options.offsetY;
		dstRect.w = options.widthLetra;
		dstRect.h = options.heightLetra;
		
		linha* linhas = editor.GetHead();
		linha* linhaAtual = editor.GetActualLine();
		char* letraNoMomento = nullptr;
		int caractere = 0;
		
		while(linhas != nullptr){
			letraNoMomento = linhas->data;
			while(*letraNoMomento != 0){
				caractere = *letraNoMomento;
				srcRect.x = caractere*srcRect.w;
				if(caractere != ' ') 
					SDL_RenderCopy(janela.render, fonte_texture, &srcRect, &dstRect);
				
				dstRect.x += options.widthLetra;
				letraNoMomento++;
			}
			if(linhas == linhaAtual){
				SDL_SetRenderDrawColor(janela.render, 150, 0, 120, 1);
				SDL_RenderDrawLine(janela.render, editor.GetPos()*dstRect.w+1, dstRect.y-2, editor.GetPos()*dstRect.w+1, dstRect.y+options.heightLetra+2);
			}
			dstRect.y += options.heightLetra+options.espacoEntreLinhas;
			dstRect.x = options.offsetX;
			
			linhas = linhas->next;
		}
	}

	void loadFont(const char* filename, const Window& Janela){
		SDL_Surface* surfc = SDL_LoadBMP(filename);
		fonte_texture = SDL_CreateTextureFromSurface(Janela.render, surfc);
		SDL_FreeSurface(surfc);
	}
	void unloadFont(){
		SDL_DestroyTexture(fonte_texture);
	}

}