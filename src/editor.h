#ifndef _EDITOR_H_
#define _EDITOR_H_

#include <cstdio>
struct linha{
	char* data = nullptr;
	linha* prev = nullptr;
	linha* next = nullptr;
};

class Editor{
	private:
		linha* head = nullptr;
		linha* actualLine = nullptr;
		unsigned int position = 0;
		const int lineSize = 256;
	public:
		Editor();
		~Editor();
		Editor(const Editor& ) = delete;
		Editor(const Editor&& ) = delete;
	public:
		int NovaLinha();
		void MoverParaDireita(){
			position++;
			if(position==lineSize){
				position = 0;
				this->pularLinha();
			}
		}
		void MoverParaEsquerda(){
			position--;
			if(position==-1){
				position = lineSize-1;
				this->voltarLinha();
			}
		}
		void pularLinha(){
			if(actualLine->next != nullptr){
				actualLine = actualLine->next;
				position = 0;
			}
			puts("Pulou uma linha!");
		};
		void voltarLinha(){
			if(actualLine->prev != nullptr){
				actualLine = actualLine->prev;
				position = 0;
			}
			puts("Voltou uma linha!");
		};
		void LogTree(){
			linha *temp = head;
			printf("Linhas (%i):\n---------------\n", position);
			while(temp != nullptr){
				if(temp == actualLine)
					printf("*%x: %s\n", temp, temp->data);
				else
					printf(" %x: %s\n", temp, temp->data);
				temp = temp->next;
			}
			printf("---------------\n");
		}
		void PrintText(){
			puts(actualLine->data);
		}
		void AdicionarLetra(char letra){
			//capturo o endereco do caractere atual
			char *a = actualLine->data+position;
			//salvo temporariamente o valor do caractere atual e crio uma variavel auxiliar
			char temp = *a, aux;
			//seto a posicao atual para a letra desejada
			*a = letra;
			while(temp != 0){
				a++;
				aux = *a;
				*a = temp;
				temp = aux;
			}
			
			position++;
		}
		int CalcularPosicao(){
			char* a = actualLine->data;
			while(*a != 0){
				a++;
			}
			return a - actualLine->data;
		}
};
#endif
