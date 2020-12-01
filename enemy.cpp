#include "enemy.h"

enemy::enemy(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}
int enemy::getR() const
{
    return r;
}

void enemy::setR(int value)
{
    r = value;
}

int enemy::getPosx() const
{
    return posx;
}

void enemy::setPosx(int value)
{
    posx = value;
}

int enemy::getPosy() const
{
    return posy;
}

void enemy::setPosy(int value)
{
    posy = value;
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());

}

void enemy::up()
{
    posy -= 1;
    setPos(posx, posy);
}

void enemy::down()
{
    posy += 1;
    setPos(posx, posy);
}

void enemy::left()
{
    posx -= 1;
    setPos(posx, posy);
}

void enemy::right()
{
    posx += 1;
    setPos(posx, posy);
}
