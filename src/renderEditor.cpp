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
		
		for(int i = 0; i < 1024; i++){
				
				int caractere = editor.getBuffer()[i];
				
				/*quebra de linha*/
				if(quebrarLinha)
					if((dstRect.x + options.offsetX) > (options.widthTela-options.widthLetra+options.offsetX)){
						dstRect.y += options.heightLetra+options.espacoEntreLinhas;
						dstRect.x = options.offsetX;
					}
				/*caractere return pula uma linha*/
				if(caractere == 0x0a){
					dstRect.y += options.heightLetra+options.espacoEntreLinhas;
					dstRect.x = options.offsetX;
				}
					
				else{
					
					if(caractere == ' ') dstRect.x += options.widthLetra;
					else{
						srcRect.x = caractere*srcRect.w;
						SDL_RenderCopy(janela.render, fonte_texture, &srcRect, &dstRect);
						dstRect.x += options.widthLetra;
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