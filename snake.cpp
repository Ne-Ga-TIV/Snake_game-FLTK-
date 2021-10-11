#include "main.h"
Snake::Snake(int start_x, int start_y)
{
    win->color(FL_BLACK);
    head = new Segment(start_x, start_x);
    food = new Fruit((rand() % win_w/10)*10, (rand() % win_h/10)*10);
    body.push_back(head);
    win->show();
}
void Snake::tail()
{
    auto second = body.begin();
    auto first = body.end();
    first--;
    second = body.end();
    second--;
    second--;
    for(; first != body.begin(); second--, first--)
        (*first)->move((*second)->get_x(), (*second)->get_y());

}
void Snake::add_segment()
{
    Segment *tmp;
    tmp = new Segment(body.back()->get_x(), body.back()->get_y());
    win->add(tmp);
    body.push_back(tmp);
}
void Snake::move()
{
    switch (Fl::event_key())
    {
    case FL_Up:
        this->tail();
        if(comand != 'D'){
            head->move(head->get_x(), head->get_y() - 10);
            comand = 'U';
        }
        else
            head->move(head->get_x(), head->get_y() + 10);
        break;
    case FL_Down:
        this->tail();
        if(comand != 'U'){
            head->move(head->get_x(), head->get_y() + 10);
            comand = 'D';
        }
        else
            head->move(head->get_x(), head->get_y() - 10);
        break;
    case FL_Right:
        this->tail();
        if(comand != 'L'){
            head->move(head->get_x() + 10, head->get_y());
            comand = 'R';
        }
        else
            head->move(head->get_x() - 10, head->get_y());
        break;
    case FL_Left:
        this->tail();
        if(comand != 'R'){
            head->move(head->get_x() - 10, head->get_y());
            comand = 'L';
        }
        else
            head->move(head->get_x() + 10, head->get_y());
        break;
    default:
        break;
    }
}
void Snake::check_collision()
{
    srand(time(NULL));
    int x = head->get_x(), y = head->get_y();
    auto i = body.begin();
    i++;
    for(; i != body.end(); i++)
            dead = hit((*i)->get_x(), (*i)->get_y());

    if(hit(food->get_x(), food->get_y())){
        add_segment();
        food->move((rand() % win_w/10)*10, (rand() % win_h/10)*10);
    }

    if(x == -10)
        head->move(win_w, y);
    if(x == win_w + 10)
        head->move(0, y);
    if(y == -10)
        head->move(x, win_h);
    if(y == win_h + 10)
        head->move(x, 0);
}
bool Snake::hit(int x, int y)
{
    int sx = head->get_x(), sy = head->get_y();
    if(this->comand == 'D' || this->comand == 'U')
        if(((sx + 20 > x && x + 20 >= sx + 20) || (sx >= x && sx < x + 20)) && (sy == y))
            return true;
    if(this->comand == 'R' || this->comand == 'L')
        if(((sy + 20 > y && y + 20 >= sy + 20) || (sy >= y && sy < y + 20)) && (sx == x))
            return true;
    return false;
}
bool Snake::check_dead()
{
    return dead;
}
int Snake::get_score()
{
    return body.size()*10 - 10;
}