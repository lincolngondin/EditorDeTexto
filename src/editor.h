#ifndef _EDITOR_H_
#define _EDITOR_H_

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
		linha* GetHead() const;
		linha* GetActualLine() const;
		int GetPos() const;
		int NovaLinha();
		void ApagarLinha();
		void MoverParaDireita(){
			if(actualLine->data[position] != 0) position++;
			else{
				if(actualLine->next != nullptr){
					actualLine = actualLine->next;
					position = 0;
				}
			}
		}
		void MoverParaEsquerda(){
			if(position!=0) position--;
			else{
				if(actualLine->prev != nullptr){
					actualLine = actualLine->prev;
					position = this->CalcularPosicao();
				}
			}
		}
		void pularLinha(){
			if(actualLine->next != nullptr){
				actualLine = actualLine->next;
				int temp = this->CalcularPosicao();
				if(temp < position ) position = temp;
			}
		};
		void voltarLinha(){
			if(actualLine->prev != nullptr){
				actualLine = actualLine->prev;
				int temp = this->CalcularPosicao();
				if(temp < position ) position = temp;
			}
		};
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
		void ApagarLetra(){
			if(position != 0){
				char *a = actualLine->data+position-1;
				while(*a != 0){
					*a = *(a+1);
					a++;
				}
				position--;
			}
			else{
				if(actualLine->prev != nullptr){
					int txtLength = this->CalcularPosicao();
					this->MoverParaEsquerda();
					for(int letra = 0; letra<txtLength; letra++){
						actualLine->data[position+letra] = actualLine->next->data[letra];
					}
					actualLine = actualLine->next;
					this->ApagarLinha();
				}
			}
		}
		
		int CalcularPosicao(){
			char* a = actualLine->data;
			while(*a != 0) a++;
			return a - actualLine->data;
		}
};
#endif
