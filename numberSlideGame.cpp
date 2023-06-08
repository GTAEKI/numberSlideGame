#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Desc002(int* ptr,int gameLevel);
void swap(int*a,int*b);

int main()
{
    int gameLevel;
    srand(time(NULL));

    printf("원하시는 게임 난이도를 입력해 주세요(3~6)\n");
    cin >> gameLevel;

    system("clear");

    if(gameLevel == 3)
    {
        int number[3][3] = {0,};
        int* ptr = &number[0][0];
        Desc002(ptr,gameLevel);
    }
    else if(gameLevel == 4)
    {
        int number[4][4] = {0,};
        int* ptr = &number[0][0];
        Desc002(ptr,gameLevel);
    }
    else if(gameLevel == 5)
    {
        int number[5][5] = {0,};
        int* ptr = &number[0][0];
        Desc002(ptr,gameLevel);
    }
    else if(gameLevel == 6)
    {
        int number[6][6] = {0,};
        int* ptr = &number[0][0];
        Desc002(ptr,gameLevel);
    }
    else
    {
        printf("잘못입력했습니다. 게임을 다시 시작하세요.\n");
    }

    
}


void Desc002(int* ptr,int gameLevel)
{   
    int* ptr2 = ptr; //매개변수로 받아오 주소값(number[0][0]) 다른 포인터에 저장
    char userInput = '0'; //유저 인풋값 선언 및 초기화(w,a,s,d)
    int random1 = 0,random2 =0, r=0;
    int gameLevelSize = gameLevel*gameLevel;

    int answer3[9] = {0,};
    int answer4[16] = {0,};
    int answer5[25] = {0,};
    int answer6[36] = {0,};

    int gameClear = 0;

    if(gameLevel == 3)
    {
        for(int n = 0; n < gameLevelSize; n++)
        {
            if(n == gameLevelSize-1)
            {
                answer3[n] = 0;
            }
            else
            {
                answer3[n] = n+1;
            }
        }
    }
    else if(gameLevel == 4)
    {
        for(int n = 0; n < gameLevelSize; n++)
        {
            if(n == gameLevelSize-1)
            {
                answer4[n] = 0;
            }
            else
            {
                answer4[n] = n+1;
            }
        }
    }
    else if(gameLevel == 5)
    {
        for(int n = 0; n < gameLevelSize; n++)
        {
            if(n == gameLevelSize-1)
            {
                answer5[n] = 0;
            }
            else
            {
                answer5[n] = n+1;
            }
        }
    }
    else if(gameLevel == 6)
    {
        for(int n = 0; n < gameLevelSize; n++)
        {
            if(n == gameLevelSize-1)
            {
                answer6[n] = 0;
            }
            else
            {
                answer6[n] = n+1;
            }
        }
    }



    // int answer3[9] = {1,2,3,4,5,6,7,8,0};
    // int answer4[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    // int answer5[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,0};
    // int answer6[36] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,};

    for(int n = 0; n < gameLevelSize; n++)
    {
        if(n == gameLevelSize-1)
        {
            *(ptr+n) = 0;
        }
        else
        {
            *(ptr+n) = n+1;
        }
    }

    // 랜덤으로 섞어주는 구간
    while(r < 300)
    {
        random1 = rand()%gameLevelSize;
        random2 = rand()%gameLevelSize;
        r++;
        swap(ptr+random1,ptr+random2);
    }


    // 포인터를 값 0과 일치시켜 주는 for문
    for(int n = 0; n < gameLevelSize; n++)
    {
        if(*(ptr+n) == 0)
        {
            ptr = ptr+n;
        }
    }
    // 포인터를 값 0과 일치시켜 주는 for문

    

    while(gameClear < gameLevelSize)
    {
        if(userInput == 'w'||userInput == 'W')
        {
            swap(ptr-gameLevel,ptr);
            ptr = (ptr-gameLevel);       
        }
        else if(userInput == 's'||userInput == 'S')
        {
            swap(ptr+gameLevel,ptr);
            ptr = (ptr+gameLevel);
        }
        else if(userInput == 'a'||userInput == 'A')
        {
           swap(ptr-1,ptr);
            ptr = (ptr-1);
        }
        else if(userInput == 'd'||userInput == 'D')
        {
            swap(ptr+1,ptr);
            ptr = (ptr+1);
        }
        else
        {
            ptr = ptr;
        }

        userInput = '0';
        
        //출력장치
        for(int n = 0; n < gameLevelSize; n++)
        {
            printf("%d      ",*(ptr2+n));
            if((n+1)%gameLevel == 0)
            {
                printf("\n");
            }
        }
        printf("\n");

        for(int n = 0; n < gameLevelSize; n++)
        {   
            if(gameLevel == 3)
            {
                if(*(ptr2+n)==answer3[n])
                {
                    gameClear++;
                }
            }
            else if(gameLevel == 4)
            {
                if(*(ptr2+n)==answer4[n])
                {
                    gameClear++;
                }
            }
            else if(gameLevel == 5)
            {
                if(*(ptr2+n)==answer5[n])
                {
                    gameClear++;
                }
            }
            else if(gameLevel == 6)
            {
                if(*(ptr2+n)==answer6[n])
                {
                    gameClear++;
                }
            }
        }

        if(gameClear < gameLevelSize)
        {
            gameClear = 0;
        }

        cin >> userInput;
        system("clear");
    }

    system("clear");
    printf("축하합니다. 게임을 클리어 하셨습니다.\n");
}

void swap(int*a,int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}