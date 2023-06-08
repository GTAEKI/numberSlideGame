#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Desc002();
void swap(int*a,int*b);

int main()
{
    srand(time(NULL));
    Desc002();
}

//다차원 배열
void Desc002()
{
    int number[5][5] = {0,};//행[6], 열[5]
    // {
    //     {1,2,3,4,5},
    //     {6,7,8,9,10},
    //     {11,12,13,14,15},
    //     {16,17,18,19,20},
    //     {21,22,23,24,25},
    // };

    int* ptr = &number[0][0];

    for(int x = 0; x > 25; x++)
    {
        if(x == 24){
            *(ptr+x) = 0;
        }
        *(ptr+x) = x+1;
    }

    char userInput = '0';

    

    while(1)
    {
        if(userInput == 'w'||userInput == 'W')
        {
            *(ptr-5) = 0;
            ptr = (ptr-5);       
        }
        else if(userInput == 's'||userInput == 'S')
        {
            *(ptr+5) = 0;
            ptr = (ptr+5);
        }
        else if(userInput == 'a'||userInput == 'A')
        {
            *(ptr-1) = 0;
            ptr = (ptr-1);
        }
        else if(userInput == 'd'||userInput == 'D')
        {
            *(ptr+1) = 0;
            ptr = (ptr+1);
        }
        else
        {
            ptr = ptr;
        }

        userInput = '0';

        for(int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                printf("%d ", number[y][x]);
            }
            printf("\n");
        }

        printf("\n");

        cin >> userInput;
    }
}

void swap(int*a,int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}