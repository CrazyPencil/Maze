#include <iostream>
#include"mzae.h"
#include"person.h"


int main()
{
    char map[12][6]{
        Wall,Wall,Road,Wall,Wall,Wall,
        Wall,Wall,Road,Wall,Wall,Wall,
        Wall,Road,Road,Wall,Wall,Wall,
        Wall,Road,Road,Road,Road,Wall,
        Wall,Wall,Wall,Road,Wall,Wall,
        Wall,Wall,Road,Road,Road,Wall,
        Wall,Road,Wall,Wall,Road,Wall,
        Wall,Road,Road,Road,Road,Wall,
        Wall,Wall,Road,Wall,Wall,Wall,
    };

    Mzae mymap(map);
    mymap.drawMap();

    Person myperson;
    myperson.setPersonForwardDirection(North);
    myperson.setPersonPos(2,8);
    myperson.drawPerson();
    myperson.start(mymap);
}
