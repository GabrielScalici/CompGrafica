TEX = ./SOIL/image_DXT.c ./SOIL/image_helper.c ./SOIL/stb_image_aug.c ./SOIL/SOIL.c

TEX_IN = ./SOIL

all: compile run clean

compile:
	g++ -o output camera.cpp obj.c main.cpp -L/System/Library/Frameworks -framework GLUT -framework OpenGL

run:
	./output

clean:
	rm *.o
