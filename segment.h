#ifndef DEBUG
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <random>
#include <list>
#define DEBUG
#endif
class Segment : public Fl_Box
{
    int x, y;
public:
    Segment(int x, int y);
    void move(int new_x, int new_y);
    int get_x();
    int get_y();

};
