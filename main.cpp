#ifndef DEBUG
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <random>
#include <list>
#include <time.h>
#define DEBUG
#endif
#include "segment.h"
#include "fruit.h"
#include "snake.h"
enum {
    win_w = 800,
    win_h =  500,
    fontsize = 25,
    score_w = 100,
    score_h = 25,
    space = 10
};
void game_update(void *game)
{
    Snake *snake = static_cast<Snake*>(game);
    
    if(!snake->check_dead())
    {
        snake->move();
        snake->check_collision();
        Fl::repeat_timeout(0.1, game_update, game);
    }
    else{
        snake->win->hide();
        Fl_Window *end_game = new Fl_Window(300, 150, "Game Over");
        std::string scr = "Your score: ";
        Fl_Box *score = new Fl_Box(50, 25, 200, 100);
        scr += std::to_string(snake->get_score());
        score->labelsize(25);
        score->labelfont(10);
        score->copy_label(scr.c_str());
        score->box(FL_FLAT_BOX);
        score->show();
        end_game->show();
    }
}

int main(int argc, char* argv[])
{
    Snake *game = new Snake(win_w/2, win_h/2);
    Fl::add_timeout(0.1, game_update, game);
   
    return Fl::run();
}