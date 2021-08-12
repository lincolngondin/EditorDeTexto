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
		void pularLinha(){
			if(actualLine->next != nullptr) actualLine = actualLine->next;
			puts("Pulou uma linha!");
		};
		void voltarLinha(){
			if(actualLine->prev != nullptr) actualLine = actualLine->prev;
			puts("Voltou uma linha!");
		};
		void LogTree(){
			linha *temp = head;
			printf("Linhas:\n---------------\n");
			while(temp != nullptr){
				if(temp == actualLine)
					printf("*%x\n", temp);
				else
					printf(" %x\n", temp);
				temp = temp->next;
			}
			printf("---------------\n");
		}
};

#endif