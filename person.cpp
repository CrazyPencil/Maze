#include "person.h"
#include<windows.h>
#include<mzae.h>

Person::Person()
{
   personchar='T';
   currentX=0;
   currentY=0;
   preX=10000;
   preY=10000;
   forwasrd=North;
}


void Person::savePrePosition()
{
    preX=currentX;
    preY=currentY;
}


void Person::moveSouth()
{
    savePrePosition();
    currentX=currentX;
    currentY=currentY+1;
}


void Person::moveNorth()
{
    savePrePosition();
    currentX=currentX;
    currentY=currentY-1;
}


void Person::moveWest()
{
    savePrePosition();
    currentX=currentX-1;
    currentY=currentY;
}


 void Person::moveEast()
 {
     savePrePosition();
     currentX=currentX+1;
     currentY=currentY;
 }

 void Person::setPersonPos(int coordX, int coordY)
 {
     currentX=coordX;
     currentY=coordY;
 }


 void Person::setPersonForwardDirection(Directions myForward)
 {
      forwasrd=myForward;
 }





/*
 * 函数名称：gotoxy
 * 函数功能：确定控制台中字符的输出位置
 * 函数列表：
 *		x：横坐标
 *		y：纵坐标
 */
void  Person::gotoxy(int x, int y)
{
    COORD cd;
    cd.X   =   x;
    cd.Y   =   y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cd);
};

/*
 * 函数名称：drawPerson
 * 函数功能：绘制走迷宫者的行走动画
 * 返回内容：无
 */

void Person::drawPerson()
{
    //在当前位置上绘制人
    gotoxy(preX,preY);
    cout << ' ';
    gotoxy(currentX,currentY);
    cout << personchar;
    //为制作动画效果使用时间延迟
    Sleep(1000);
}


 void Person::turnLeft()
 {
     switch(forwasrd)
     {
         case North:  forwasrd=West;break;
         case South:  forwasrd=East;break;
         case East:  forwasrd=North;break;
         case West:  forwasrd=South;break;
     }
 }


void Person::turnRight()
{
    switch(forwasrd)
    {
        case North:  forwasrd=East;break;
        case South:  forwasrd=West;break;
        case East:  forwasrd=South;break;
        case West:  forwasrd=North;break;
    }
}


void Person::goAhead(Mzae M)
{
    switch(forwasrd)
    {
        case North:  moveNorth();break;
        case South:  moveSouth();break;
        case East:   moveEast();break;
        case West:   moveWest();break;
    }

    drawPerson();
    if(M.cheakMazeDoor(currentX,currentY)==1)
    {
         gotoxy(0,24);
        cout<<"good!";
        outOrnot=true;
    }
}


void Person::start(Mzae M)
{
    int i=0;
    while(!outOrnot)
    {
        gotoxy(0,20);
        cout<<i;
        i++;
        moveForward(M);
    }
}



bool Person::moveForward(Mzae M)
 {
     if(preX==10000 && preY==10000)
     {
         gotoxy(currentX,currentY);
         cout << personchar;
         Sleep(1000);
     }


     int rightX;
     int rightY;

     int forwardX;
     int forwardY;

     switch(forwasrd)
     {
     case South: rightX = currentX - 1; rightY = currentY;
         forwardX = currentX; forwardY = currentY + 1; break;
     case North: rightX = currentX + 1; rightY = currentY;
         forwardX = currentX; forwardY = currentY- 1;	break;
     case West:  rightX = currentX; rightY = currentY - 1;
         forwardX =currentX- 1; forwardY = currentY;	break;
     case East:  rightX = currentX; rightY = currentY + 1;
         forwardX = currentX + 1; forwardY = currentY;	break;
     }


     //如果右侧是墙


     if(M.checkWallOrNot(rightX,rightY))
     {

         //检测前方也是墙壁
         if(M.checkWallOrNot(forwardX,forwardY))
         {
             //按逆时针换一个方向
             turnLeft();
             return false;
         }
         //检测前方是通路
         else
         {
             //向前移动
             goAhead(M);
             return true;
         }
     }
     //如果右侧是通路
     else
     {
         Sleep(1000);
         turnRight();
         goAhead(M);
         return true;
     }

 }


















