#ifndef MZAE_H
#define MZAE_H

#include<iostream>
using namespace std;

const int Row=12;
const int Column=6;
const char Wall='#';
const char Road=' ';

class Mzae
{
public:
    Mzae(char map[Row][Column]);
    void setMazeMap(char map[Row][Column]);
    void drawMap();
    bool cheakMazeDoor(int x,int y);
    bool checkWallOrNot(int mazeX, int mazeY);

private:
    char MazeMap[Row][Column];

};

#endif // MZAE_H
