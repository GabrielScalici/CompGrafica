all: compile run clean

compile:
	g++ -o output bibutil.cpp main.cpp -L/System/Library/Frameworks -framework GLUT -framework OpenGL

run:
	./output

clean:
	rm *.o
