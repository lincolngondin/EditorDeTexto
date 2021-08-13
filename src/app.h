#ifndef APP_H_
#define APP_H_

#include "editor.h"

namespace App{
	extern void Init();
	extern bool SalvarArquivo(const char*, const char*, const Editor&);
}

#endif