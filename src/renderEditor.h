#ifndef _RENDER_EDITOR_H_
#define _RENDER_EDITOR_H_

#include "editor.h"
#include "window.h"
#include <SDL.h>

namespace Render{
	extern int comprimentoTela;
	extern int alturaTela;
	extern int comprimentoLetra;
	extern int larguraLetra;
	extern int espacoEntreLinhas;
	
	void renderEditor(const Window&, Editor&);
	void loadFont(const char*, const Window&);
	void unloadFont();
}

#endif //_RENDER_EDITOR_H_