#include "renderEditor.h"

namespace Render{
	#define quebrarLinha true

	int comprimentoTela = 500;
	int alturaTela = 500;
	int comprimentoLetra = 7;
	int alturaLetra = 9;
	int espacoEntreLinhas = 10;
	
	
	static SDL_Rect srcRect = {0, 0, 7, 9};
	static SDL_Rect dstRect = {0, 0, 7, 9};
	static SDL_Texture* fonte_texture = nullptr;
	


	void renderEditor(const Window& janela, Editor& editor){
		dstRect.x = 0;
		dstRect.y = 0;
		for(int i = 0; i < 1024; i++){
				
				int caractere = editor.getBuffer()[i];
				
				/*quebra de linha*/
				if(quebrarLinha)
					if(dstRect.x > comprimentoTela-comprimentoLetra){
						dstRect.y+=alturaLetra+espacoEntreLinhas;
						dstRect.x = 0;
					}
				/*caractere return pula uma linha*/
				if(caractere == 0x0a){
					dstRect.y+=alturaLetra+espacoEntreLinhas;
					dstRect.x = 0;
				}
					
				else{
					
					if(caractere == ' ') dstRect.x += comprimentoLetra;
					else{
						srcRect.x = caractere*comprimentoLetra;
						SDL_RenderCopy(janela.render, fonte_texture, &srcRect, &dstRect);
						dstRect.x += comprimentoLetra;
					}
				}
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