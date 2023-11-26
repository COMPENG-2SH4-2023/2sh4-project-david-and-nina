#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
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

    while(myGM->getExitFlagStatus() == false)  
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
    myPlayer = new Player(myGM);
    myFood = new Food(myGM);
    
    objPos player_init = {15,7,'a'};

    myFood->generateFood(player_init);

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
    objPos currentPlayPos;
    objPos currentFoodPos;
    myPlayer -> getPlayerPos(currentPlayPos);//get player position
    myFood -> getFoodPos(currentFoodPos);

    for(int r=0; r<myGM->getBoardSizeY(); r++) //number of rows
    {
        for(int c=0; c<myGM->getBoardSizeX(); c++) //number of columns
        {
            
            if (r==0 || r==(myGM->getBoardSizeY()-1) || c==0 || c==(myGM->getBoardSizeX()-1)){
                MacUILib_printf("#");
            }
            else if (r==currentPlayPos.y && c==currentPlayPos.x){
                MacUILib_printf("%c", currentPlayPos.symbol);
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
