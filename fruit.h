#ifndef DEBUG
#include "segment.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <random>
#define DEBUG
#endif

class Fruit : public Fl_Box
{
    int x, y;
public:
    Fruit(int x, int y);
    void move(int next_x, int next_y);
    int get_x();
    int get_y();
};