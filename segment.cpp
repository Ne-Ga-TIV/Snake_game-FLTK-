#include "segment.h"
Segment::Segment(int x, int y) : Fl_Box(x, y, 20, 20)
{
    this->box(FL_FLAT_BOX);
    this->color(FL_GREEN);
    this->x = x;
    this->y = y;
    this->show();
}
void Segment::move(int new_x, int new_y)
{
    this->hide();
    this->position(new_x, new_y);
    this->x = new_x;
    this->y = new_y;
    this->show();
}
int Segment::get_x()
{
    return this->x;
}
int Segment::get_y()
{
    return this->y;
}
