# selfPlayer
First: Make sure unbuntu environment.
Make sure that you have installed SDL,if not please refer to the following steps.
	sudo apt-get install libsdl1.2-dev
	sudo apt-get install libsdl-image1.2-dev
	sudo apt-get install libsdl-mixer1.2-dev
	sudo apt-get install libsdl-ttf2.0-dev
	sudo apt-get install libsdl-gfx1.2-dev

Second:complie SDL2-2.0.5 
	cd SDL2-2.0.5
	./configure --prefix=./sdlResult
	make
	make install
third:
	export PATH=$PATH:/home/xiaohui/learnProject/SDL2-2.0.5/sdlResult/lib/libSDL2-2.0.so.0
end:
	./test
