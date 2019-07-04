#include "mzae.h"


 Mzae::Mzae(char map[Row][Column])
{
    setMazeMap(map);
}




 void Mzae::setMazeMap(char map[Row][Column])
 {
     for(int i=0;i<Row;i++)
     {
         for(int j=0;j<Column;j++)
         {
             MazeMap[i][j]= map[i][j];
         }
     }
 }




 void Mzae::drawMap()
 {
     for(int i=0;i<Row;i++)
     {
         for(int j=0;j<Column;j++)
         {
             cout<<MazeMap[i][j];
         }
         cout<<endl;
     }
 }



 bool Mzae::checkWallOrNot(int mazeX, int mazeY)
 {
     if(MazeMap[mazeY][mazeX] == Wall)
     {
         return true;
     }
     else
     {
         return false;
     }
 }






bool Mzae::cheakMazeDoor(int x,int y)
{
    if(x==0||x==(Column-1))
    {
        if(MazeMap[y][x]==Road)
        {
            return true;
        }
    }
    else
    if(y==0||y==(Row-1))
    {
        if(MazeMap[y][x]==Road)
        {
         return true;
        }
    }
        return false;
}





