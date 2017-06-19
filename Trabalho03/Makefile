all: compile run clean

compile:
	g++ -o output camera.cpp obj.c main.cpp -L/System/Library/Frameworks -framework GLUT -framework OpenGL

run:
	./output

clean:
	rm *.o
