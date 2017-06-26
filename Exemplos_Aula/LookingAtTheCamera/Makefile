all: compile run clean

compile:
	gcc -o output camera.cpp main.cpp -L/System/Library/Frameworks -framework GLUT -framework OpenGL

run:
	./output

clean:
	rm *.o
