#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWMAX 10
#define COLMAX 20

bool exitFlag;

objPos user;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
    user.setObjPos(10,5,'@');
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos currentPos;

    for(int r=0; r<ROWMAX;r++) //number of rows, maybe change
    {
        for(int c=0; c<COLMAX; c++) //number of columns
        {
            objPos currentPos(c,r,0); // position right now

            if(currentPos.y==0||currentPos.y==(ROWMAX-1)||currentPos.x==0||currentPos.x==(COLMAX-1)) //draw boundary
{
                MacUILib_printf("#");
            }
            else if(currentPos.isPosEqual(&user)){
                char symbol = user.getSymbol();
                MacUILib_printf("%c", symbol);
            }
            else{
                MacUILib_printf(" ");
            }
            
           
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
