
#all 
#build 
#clean


INCLUDES= -I ./include # -I = includes
FLAGS= -g # -g= debugging
LIBS= -L ./lib -lmingw32 -lSDL2main -lSDL2 
OBJECTS= ./build/chip8memory.o ./build/chip8stack.o
# tell the compiler to rely on these object files [link with the object files]
all: ${OBJECTS}
	gcc ${FLAGS}${INCLUDES}./src/main.c ${OBJECTS} ${LIBS}-o ./bin/main

#build object files that we rely on
build/chip8memory.o:src/chip8memory.c
	gcc ${FLAGS}${INCLUDES} ./src/chip8memory.c -c -o ./build/chip8memory.o

build/chip8stack.o:src/chip8stack.c
	gcc ${FLAGS}${INCLUDES} ./src/chip8stack.c -c -o ./build/chip8stack.o

clean:
#for windows 
	del build\*