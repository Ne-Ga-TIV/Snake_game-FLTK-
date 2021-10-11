#include "fruit.h"

Fruit::Fruit(int x, int y) : Fl_Box(x, y, 20, 20)
{
    this->box(FL_OFLAT_BOX);
    this->color(FL_RED);
    this->x = x;
    this->y = y;
    this->show();
}
void Fruit::move(int next_x, int next_y)
{
    this->hide();
    this->position(next_x, next_y);
    this->x = next_x;
    this->y = next_y;
    this->show();

}
int Fruit::get_x()
{
    return x;
}
int Fruit::get_y()
{
    return y;
}























