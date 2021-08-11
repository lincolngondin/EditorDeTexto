#ifndef _RENDER_EDITOR_H_
#define _RENDER_EDITOR_H_

#include "editor.h"
#include "window.h"
#include <SDL.h>

namespace Render{
	
	struct EditorRenderOptions{
		int widthTela = 0;
		int heightTela = 0;
		int widthLetra = 0;
		int heightLetra = 0;
		int offsetX = 0;
		int offsetY = 0;
		int espacoEntreLinhas = 0;	
	};
	
	void renderEditor(const Window&, Editor&, const EditorRenderOptions&);
	void loadFont(const char*, const Window&);
	void unloadFont();
}

#endif //_RENDER_EDITOR_H_