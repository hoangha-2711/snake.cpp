#include <iostream>
#include <conio.h>
using namespace std;

const int width = 40;
const int height = 30;

int x, y, fruitX, fruitY , score =0;

int tailX[101], tailY[101],  nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP , DOWN };
eDirection dir;

bool gameOver;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system( "cls");// system("clear");
    for(int i = 0; i <= width+1; i++)
    {
        cout << "o";
    }
        cout << endl;
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0; j < width ;j++)
        {
            if(j == 0)
            {
                cout << "o";
            }

            if(i == y && j == x)
            {
                cout << "O";
            }
            if( i == fruitY && j == fruitX)
            {
                cout << "$";
            }
            else
            {
                bool print = false;
                for(int k = 0; k < nTail ; k++)
                {

                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }

                }
                if(!print)
                cout << " ";
            }
            if( j==width-1 )
            {
                cout << "o";
            }
        }
        cout << endl;
    }

     for(int i = 0; i <= width+1; i++)
     {
        cout << "o";
     }
        cout << endl;
        cout << endl;
        cout << "Score: " << score << endl;

}

void Input()
{
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
     switch(dir)
     {

        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x >= width || x <= 0 || y <= 0 || y >= height)
    {
        gameOver = true;
        cout << "Better luck next time !!!" << endl;
    }
    for( int i = 0; i < nTail; i++)
    {
        if(tailX[i] == x && tailY[i] == y)
       {
            gameOver = true;
            cout << "Better luck next time !!!" << endl;
       }
    }
    if(x == fruitX && y == fruitY)
    {


        score += 10;

        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++ ;
    }
}

int main()
{
    Setup();
    while( !gameOver )
    {
        Draw();
        Input();
        Logic();
        // Sleep(10);
    }

    return 0;

}
