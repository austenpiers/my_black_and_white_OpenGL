all: main.cpp
	@echo This may take a minute.
	g++ main.cpp
	./a.out
	convert -delay 20 -loop 1 *.ppm scene.gif
	rm *.ppm
	rm a.out
	animate scene.gif
clean:
	rm *.gif