INCLUDES= -I ./include # -I = includes
FLAGS= -g # -g= debugging
LIBS= -L ./lib -lmingw32 -lSDL2main -lSDL2 
all:
	gcc ${FLAGS}${INCLUDES} ./src/main.c ${LIBS}-o ./bin/main