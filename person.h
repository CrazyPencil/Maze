#ifndef PERSON_H
#define PERSON_H

#include<mzae.h>
#include<iostream>

class Mzae;
enum Directions{North,South,East,West};

class Person
{
public:
    Person();
    void savePrePosition();
    void moveSouth();
    void moveNorth();
    void moveWest();
    void moveEast();
    void setPersonPos(int coordX, int coordY);
    void setPersonForwardDirection(Directions myForward);
    void turnLeft();
    void turnRight();
    void goAhead(Mzae M);
    void start(Mzae M);
    bool moveForward(Mzae M);
    void  gotoxy(int x, int y);
    void drawPerson();

private:
    char personchar;
    int currentX;
    int currentY;
    int preX;
    int preY;
    Directions forwasrd;
    bool outOrnot=false;
};

#endif // PERSON_H
