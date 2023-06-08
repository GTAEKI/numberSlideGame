#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 게임함수
void Desc002(int* ptr,int gameLevel); 
// 스왑 함수
void swap(int*a,int*b); 

int main()
{
    int gameLevel;
    srand(time(NULL));

    // 유저 입력 gameLevel
    printf("원하시는 게임 난이도를 입력해 주세요(3~6)\n");

    scanf("%d",&gameLevel);

    system("clear");

    //gameLevel에 따른 2차원 배열 설정
    //배열의 경우 미리 설정해놓지 않으면 크기 설정이 다시되지 않기 때문에
    //레벨별로 지역변수설정해주었습니다.
    if(gameLevel == 3)
    {
        int number[3][3] = {0,};
        int* ptr = &number[0][0];
        //이차원배열 number[0][0] 값과 게임 레벨 함수에 입력
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
    //gameLevel에 따른 2차원 배열 설정
}


void Desc002(int* ptr,int gameLevel)
{   
    //매개변수로 받아오 주소값(number[0][0]) 다른 포인터에 저장
    int* ptr2 = ptr; 
    //유저 인풋값 선언 및 초기화(w,a,s,d)
    char userInput = '0'; 

    //random에 필요한 변수 선언
    int random1 = 0,random2 =0, r=0;

    //포인터 위치를 잡아주기 위한 변수 선언(배열 크기 선언)
    int gameLevelSize = gameLevel*gameLevel;

    // 정답 비교를 위한 배열 선언
    int answer3[9] = {0,};
    int answer4[16] = {0,};
    int answer5[25] = {0,};
    int answer6[36] = {0,};
    // 정답 비교를 위한 배열 선언

    // 게임 클리어를 위한 변수
    int gameClear = 0;
    // 게임 클리어를 위한 변수


    // answer에 숫자 배열 입력해주는 구간
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
    // answer에 숫자 배열 입력해주는 구간

    // main함수 내의 number[][]배열에 숫자를 넣어주는 구간
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
    // main함수 내의 number[][]배열에 숫자를 넣어주는 구간


    // 랜덤으로 섞어주는 구간
    while(r < 300)
    {
        random1 = rand()%gameLevelSize;
        random2 = rand()%gameLevelSize;
        r++;
        swap(ptr+random1,ptr+random2);
    }
    // 랜덤으로 섞어주는 구간


    // 포인터를 값 0과 일치시켜 주는 for문
    for(int n = 0; n < gameLevelSize; n++)
    {
        if(*(ptr+n) == 0)
        {
            ptr = (ptr+n);
        }
    }
    // 포인터를 값 0과 일치시켜 주는 for문

    //gameClear점수가 게임 사이즈(배열 사이즈)보다 커지면 게임 종료
    while(gameClear < gameLevelSize)
    {
        //사용자 wasd입력시 0을 상하좌우로 움직여주는 구간
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
        //사용자 wasd입력시 0을 상하좌우로 움직여주는 구간

        //유저 입력값 초기화
        userInput = '0';
        
        //출력장치
        for(int n = 0; n < gameLevelSize; n++)
        {
            printf("%2d  ",*(ptr2+n));
            if((n+1)%gameLevel == 0)
            {
                printf("\n");
            }
        }
        printf("\n");

        //정답 비교구간 배열 사이즈 전체 비교
        for(int n = 0; n < gameLevelSize; n++)
        {   
            //게임 레벨에 따라 answer값이 다름에 따라 if else문 사용
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
            //게임 레벨에 따라 answer값이 다름에 따라 if else문 사용
        
        }
        //정답 비교구간 배열 사이즈 전체 비교


        //gameClear점수 초기화
        if(gameClear < gameLevelSize)
        {
            gameClear = 0;
        }
        //gameClear점수 초기화

        //유저 wasd값 입력
        cin >> userInput;

        //화면 클리어
        system("clear");

    }//while 게임종료

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