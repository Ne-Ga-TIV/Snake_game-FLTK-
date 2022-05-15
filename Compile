
all:
    rm -f *.o
    make


fruit.o: fruit.cpp
g++ -g -Wall fruit.cpp -lfltk -c

segment.o: segment.cpp
g++ -g -Wall segment.cpp -lfltk -c
snake.o: snake.cpp
g++ -g -Wall snake.cpp -lfltk -c

snake: snake.o segment.o fruit.o
g++ -g -Wall main.cpp snake.o fruit.o segment.o -o snake `fltk-config --ldflags`
