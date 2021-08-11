#include "editor.h"

Editor::Editor(){
	head = new linha;
	head->data = new char[lineSize];
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
		puts("Deletado uma linha!");
		if(aux == nullptr){
			break;
		}
		temp = aux;
	}
}

int Editor::NovaLinha(){
	if(actualLine->next == nullptr){
		actualLine->next = new linha;
		actualLine->next->data = new char[lineSize];
		actualLine->next->prev = actualLine;
		actualLine = actualLine->next;
		puts("Criado nova linha!");
	}
	else{
		//armazena o endereco da proxima linha
		linha *temp = actualLine->next;
		//cria o que vai ser agora a proxima linha
		actualLine->next = new linha;
		actualLine->next->data = new char[lineSize];
		actualLine->next->prev = actualLine;
		//a nova linha deve aponta para o que era a proxima linha anteriormente
		actualLine->next->next = temp;
		temp->prev = actualLine->next;
		actualLine = actualLine->next;
		puts("Criado nova linha!");
	}
	return 0;
}