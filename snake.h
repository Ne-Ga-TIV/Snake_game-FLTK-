#ifndef DEBUG
#include "fruit.h"
#include "segment.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <random>
#include <list>
#define DEBUG
#endif

class Snake
{
    std::list<Segment*> body;
    friend class Segment;
    Segment *head;
    Fruit *food;
    char comand;
    bool dead = false;

public:
    Fl_Window *win = new Fl_Window(800, 500, "Snake");
    Snake(int start_x, int start_y);
    bool check_dead();
    void move();
    void check_collision();
    void add_segment();
    void tail();
    int get_score();
    bool hit(int x, int y);

};

