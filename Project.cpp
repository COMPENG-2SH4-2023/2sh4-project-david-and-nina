#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWMAX 10
#define COLMAX 20

GameMechs* myGM;
Player* myPlayer;
Food* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false || myGM->getLoseFlagStatus() == false)  
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

    myGM = new GameMechs(30,15);
    myFood = new Food(myGM);
    myPlayer = new Player(myGM, myFood);

    objPos blockOff;
    objPosArrayList *playerbody = myPlayer->getPlayerPos();

    myFood->generateFood(*playerbody);//how to turn it into array list operation NEED TO DO

}

void GetInput(void)
{
    myGM -> getInput();
}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();

    myGM -> clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;
    
    objPosArrayList* playBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos currentFoodPos;
    myFood -> getFoodPos(currentFoodPos);

    for(int r=0; r<myGM->getBoardSizeY(); r++) //number of rows
    {
        for(int c=0; c<myGM->getBoardSizeX(); c++) //number of columns
        {
            drawn = false;

            for (int a=0; a<playBody->getSize(); a++){
                playBody->getElement(tempBody,a);
                if (tempBody.x==c && tempBody.y==r){
                    MacUILib_printf("%c",tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn) continue;
            //if player body was drawn, do not draw anything below

            if (r==0 || r==(myGM->getBoardSizeY()-1) || c==0 || c==(myGM->getBoardSizeX()-1)){
                MacUILib_printf("#");
            }
            else if (r==currentFoodPos.y && c==currentFoodPos.x){
                MacUILib_printf("%c", currentFoodPos.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n",myGM->getScore());

    if(myGM->getLoseFlagStatus())
    {
        
        MacUILib_printf("Oh No, you lost!\n");
        MacUILib_printf("Click ESC to exit.\n");
    }

    if(myGM->getExitFlagStatus())
    {
        MacUILib_printf("Game was shut down\n");
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

    delete myGM;
    delete myPlayer;
    delete myFood;
}
