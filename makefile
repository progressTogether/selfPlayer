SOURCE  := $(wildcard *.c) $(wildcard *.cpp)


TARGET = test

GCC = gcc

#INCLUDE := -I /home/xiaohui/learnProject/selfPlayer/SDL2-2.0.5/sdlResult/include/SDL2/
#LIBS    := -L /home/xiaohui/learnProject/selfPlayer/SDL2-2.0.5/sdlResult/lib/

INCLUDE := -I ../SDL2-2.0.5/sdlResult/include/SDL2/
LIBS    := -L ../SDL2-2.0.5/sdlResult/lib/

CFLAGS  := -o 

$(TARGET):
	$(GCC) $(SOURCE) -lSDL2-2 $(LIBS) $(CFLAGS) $@ $(INCLUDE) 
	
clean :
	@rm -f *.o $(TARGET)/home/xiaohui/learnProject/selfPlayer/SDL2
