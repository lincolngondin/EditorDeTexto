INCLUDE = "C:\Users\Lincoln\Desktop\SDL2-devel-2.0.12-mingw\SDL2-2.0.12\x86_64-w64-mingw32\include\SDL2"
LIBS = "C:\Users\Lincoln\Desktop\SDL2-devel-2.0.12-mingw\SDL2-2.0.12\x86_64-w64-mingw32\lib"

FLAGS = -O3 
PROJETO=Editor

all:$(PROJETO)

./obj/window.o:./src/window.cpp ./src/window.h
	g++  $(FLAGS) -c -I $(INCLUDE)  $< -o $@

./obj/editor.o:./src/editor.cpp ./src/editor.h
	g++  $(FLAGS) -c -I $(INCLUDE)  $< -o $@

./obj/main.o:./src/main.cpp ./src/app.h 
	g++  $(FLAGS) -c -I $(INCLUDE)  $< -o $@

./obj/app.o:./src/app.cpp ./src/app.h ./src/window.h ./src/editor.h ./src/renderEditor.h
	g++  $(FLAGS) -c -I $(INCLUDE)  $< -o $@	
	
./obj/renderEditor.o:./src/renderEditor.cpp ./src/renderEditor.h ./src/window.h ./src/editor.h
	g++  $(FLAGS) -c -I $(INCLUDE)  $< -o $@	
	

$(PROJETO):./obj/main.o ./obj/app.o ./obj/window.o ./obj/editor.o ./obj/renderEditor.o
	g++ $(FLAGS) $^ -I $(INCLUDE) -L $(LIBS) -lmingw32 -lSDL2main -lSDL2 -o main.exe