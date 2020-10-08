#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int width = 20;
int height = 20;
int x, y, snackX, snackY, score, gameOver,flag;
int tailX[100],tailY[100];
int countTail=0;

void setup()
{
    gameOver = 0;
    x = width / 2;
    y = height / 2;
label1:
    snackX = rand() % 20;
    if (snackX == 0 || snackX>=19)
    {
        goto label1;
    }
label2:
    snackY = rand() % 20;
    if (snackY == 0 || snackY>=19)
    {
        goto label2;
    }
    score = 0;
}

void draw()
{
    system("cls");
    int i, j;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if ((i == 0 || i == 19) || (j == 0 || j == 19))
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }
                else if (i == snackX && j == snackY)
                {
                    printf("F");
                }
                else
                {
                    int ch=0;
                    for (int k = 1; k < countTail; k++)
                    {
                        if (i==tailX[k] && j==tailY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                        
                    }
                    if(ch==0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
printf("Your score is %d\n", score);
}

void input(){
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'z':
            flag=3;
            break;
        case 'w':
            flag=4;
            break;
        case 'x':
            gameOver=1;
            break;
        }
    }
    
}

void MakeLogic()
{
    int e;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0] = y; 

    for (int i = 0; i < countTail; i++)
    {
        prev2X=tailX[i]; 
        prev2Y = tailY[i]; 
        tailX[i]=prevX; 
        tailY[i]=prevY;  
        prevX=prev2X; 
        prevY=prev2Y;   

    }
    







    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x++;
        break;
    case 4:
        x--;
        break;
    }
    if (x<0 || x>width || y<0 || y > height)
    {
        gameOver=1;
    }

    for ( e = 0; e < countTail; e++)
    {
        if (x==tailX[e] && y==tailY[e])
        {
            gameOver=1;
        }
        
    }
    

    if (x==snackX && y==snackY)
    {
    label3:
        snackX = rand() % 20;
        if (snackX == 0)
        {
            goto label3;
        }
    label4:
        snackY = rand() % 20;
        if (snackY == 0)
        {
            goto label4;
        }
        score=score+10;
        countTail++;
    }
    
    
}

int main()
{
    char c;

    label5:
    setup();

    while (!gameOver)
    {
        draw();
        input();
        MakeLogic();
        for (int p = 0; p < 1000; p++)
        {
            for (int t = 0; t < 10000; t++)
            {
            }
        }
        for (int p = 0; p < 1000; p++)
        {
            for (int t = 0; t < 10000; t++)
            {
            }
        }
        
    }
    printf("\npress y to continue again!\n");

    scanf("%c",&c);
    if (c=='y' || c=='Y')
    {
        goto label5;
    }
    
    

    return 0;
}