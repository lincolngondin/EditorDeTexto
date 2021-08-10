#include "editor.h"

Editor::Editor(){
	data = new char[1024]{' '};
	size = 1024;
}
Editor::~Editor(){
	delete[] data;
}