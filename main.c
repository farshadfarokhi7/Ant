#include <stdio.h>
#include <stdlib.h>

#define FIX 10

#define UP 5
#define DOWN 6
#define LEFT 7
#define RIGHT 8

struct point
{
    int x;
    int y;
    int dir;
};

void printArr(char arr[FIX][FIX])
{
    int r,c;
    for (r = 0; r < FIX; r++)
    {
        for (c = 0; c < FIX; c++)
        {
            printf("%c", arr[r][c]);
        }
        printf("\n");
    }
}

int changeDirWhite(int d)
{
    if(d == UP)
        return RIGHT;
    else if(d == RIGHT)
        return DOWN;
    else if(d == DOWN)
        return LEFT;
    else if(d == LEFT)
        return UP;
}

int changeDirBlack(int d)
{
    if(d == UP)
        return LEFT;
    else if(d == LEFT)
        return DOWN;
    else if(d == DOWN)
        return RIGHT;
    else if(d == RIGHT)
        return UP;
}

int isColor(struct point p , char arr[FIX][FIX])
{
    if (arr[p.x][p.y] == '.')
        return 0; //white
    else if(arr[p.x][p.y] == '#')
        return 1; //black
}

struct point changePos(struct point current, struct point next, char arr2[FIX][FIX])
{

    int nexDir;
    if (isColor(current, arr2) == 0 )
    {

        nexDir = changeDirWhite(current.dir);
        arr2[current.x][current.y] = '#';

        if(nexDir == UP)
        {
            next.x = current.x - 1;
            next.y = current.y ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == DOWN)
        {
            next.x = current.x + 1;
            next.y = current.y ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == LEFT)
        {
            next.x = current.x ;
            next.y = current.y - 1 ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == RIGHT)
        {
            next.x = current.x ;
            next.y = current.y + 1 ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        return next;
    }

    else if(isColor(current, arr2) == 1)
    {
        nexDir = changeDirBlack(current.dir);
        arr2[current.x][current.y] = '.';

        if(nexDir == UP)
        {
            next.x = current.x - 1;
            next.y = current.y ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == DOWN)
        {
            next.x = current.x + 1;
            next.y = current.y ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == LEFT)
        {
            next.x = current.x ;
            next.y = current.y - 1 ;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        else if(nexDir == RIGHT)
        {
            next.x = current.x ;
            next.y = current.y + 1;
            next.dir = nexDir;
            if(next.x == 10 || next.y == 10 || next.x == -1 || next.y == -1 )
            {
                next.dir = -1;
                next.x = -1;
                next.y = -1;
                return next;
            }
        }
        return next;
    }

}

int main()
{
    int turn,x,y,i,j;
    char board[FIX][FIX];

    for ( i = 0; i < FIX; i++ )
        {
        for ( j = 0; j < FIX; j++ )
            {
            board[i][j] = '.';
            }
        }


    printf("Enter number of turns: ");
    scanf("%d", &turn);
    printf("Enter start position: ");
    scanf("%d %d", &x, &y);

    struct point pos;
    struct point temp;
    struct point next;
    pos.x = y;
    pos.y = x;
    pos.dir = 7;

    //printArr(board);
    //printf("\n \n \n");

    while( turn != 0)
    {

        next = changePos(pos, temp, board);
        pos = next;

        if (next.dir == -1)
            break;
        turn--;
    }
    if(isColor(pos, board) == 0)
    {
        board[pos.x][pos.y] = 'a';
    }
    else if(isColor(pos, board) == 1)
    {
        board[pos.x][pos.y] = 'A';
    }
    printArr(board);

    return 0;
}
