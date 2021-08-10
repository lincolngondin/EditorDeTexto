#ifndef _EDITOR_H_
#define _EDITOR_H_

class Editor{
	private:
		char* data = nullptr;
		unsigned int size = 0;
		unsigned int position = 0;
	public:
		Editor();
		~Editor();
		Editor(const Editor& ) = delete;
		Editor(const Editor&& ) = delete;
	public:
		int getSize(){return size;}
		int getPos(){return position;}
		void setPos(int i){position = i;}
		void next(){
			if(position!=size) position++;
		}
		void before(){
			if(position!=0) position--;
		}
		char* getBuffer(){return data;}
};

#endif