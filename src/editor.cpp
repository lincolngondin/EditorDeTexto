#include "editor.h"
#include <cstdio>

Editor::Editor(){
	head = new linha;
	head->data = new char[lineSize];
	for(int vat = 0; vat < lineSize; vat++) head->data[vat] = 0;
	actualLine = head;
}
Editor::~Editor(){
	linha* temp = head;
	linha* aux = nullptr;
	if(temp == nullptr) return;
	while(true){
		delete[] temp->data;
		aux = temp->next;
		delete temp;
		if(aux == nullptr){
			break;
		}
		temp = aux;
	}
}

bool Editor::CarregarArquivo(const char* file){
	FILE *arquivo = fopen(file, "rb");
	if(arquivo == nullptr) return false;
	linha *line = head;
	char c;
	int pos = 0;
	while(true){
		c = fgetc(arquivo);
		if(c==EOF) break;
		
		if(c == '\r' or c == '\n'){
			c = fgetc(arquivo);
			if( c == '\n') c = fgetc(arquivo);
			if(line->next == nullptr){
				line->next = new linha;
				line->next->prev = line;
				line->next->data = new char[lineSize];
				for(int vat = 0; vat < lineSize; vat++) line->next->data[vat] = 0;
			}
			line = line->next;
			pos = 0;
		}
		line->data[pos] = c;
		pos++;
	}
	
	fclose(arquivo);
	return true;
}

int Editor::NovaLinha(){
	//armazena o endereco da proxima linha ela existindo ou nao
	linha *temp = actualLine->next;
	//aloca a memoria necessaria da proxima linha
	actualLine->next = new linha;
	actualLine->next->data = new char[lineSize];
	actualLine->next->prev = actualLine;
	//a nova linha deve apontar para o que era a proxima linha anteriormente
	actualLine->next->next = temp;
	if(temp != nullptr) temp->prev = actualLine->next;
	
	actualLine = actualLine->next;
	for(int vat = 0; vat < lineSize; vat++) actualLine->data[vat] = 0;
	
	char *a = actualLine->prev->data+position;
	char *b = actualLine->data;
	while(*a !=0){
		*b = *a;
		*a = 0;
		a++;
		b++;
	}
	position = 0;
	return 0;
}
void Editor::ApagarLinha(){
	if(actualLine->prev == nullptr) return;
	
	linha* temp = actualLine;
	actualLine->prev->next = actualLine->next;
	if(actualLine->next != nullptr) actualLine->next->prev = actualLine->prev;
	actualLine = actualLine->prev;
	
	delete[] temp->data;
	delete temp;
}

linha* Editor::GetHead() const {
	return head;
}

int Editor::GetPos() const {
	return position;
}
linha* Editor::GetActualLine() const {
	return actualLine;
}