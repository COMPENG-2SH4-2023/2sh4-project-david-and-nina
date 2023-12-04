#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    
    boardSizeX =30;
    boardSizeY =15;
    score =0; 

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
   
    boardSizeX =boardX;
    boardSizeY =boardY; 
    score=0;
}






//Getters:
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar(); //storing the input in this variable
    }
    return input;
    
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs:: getScore()
{
    return score;
}






//Setters:
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag(){
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}






void GameMechs::clearInput()
{
    setInput(0);
}

void GameMechs::incrementScore()
{
    score++;
}
