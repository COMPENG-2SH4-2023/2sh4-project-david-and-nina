#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX =20;
    boardSizeY =10; 

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX =boardX;
    boardSizeY =boardY; 
}

// do you need a destructor?

//do i need to allocate memory for this

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
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

int GameMechs::getScore()
{
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{

}

void GameMechs::incrementScore()
{
    score++;
}

//do i need to make space on memory for this (and destroy after)
//make pointer in main code to this class