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
#include "segment.h"
#include "fruit.h"
#include "snake.h"
enum {
    win_w = 800,
    win_h = 500,
    fontsize = 25,
    score_w = 100,
    score_h = 25,
    space = 10
};
void game_update(void *snake);
int main();