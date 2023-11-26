#include "Food.h"
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"


Food:: Food(GameMechs* thisGameRef)
{
    mainGameRef = thisGameRef;
    
    foodPos.setObjPos(-1,-1,'o'); //set initial food position outside game board
}

Food:: ~Food()
{
    //finish this
}

void Food:: generateFood(objPos blockOff)
{
    //generate random x and y coord and make sure they arent border or blockoff position
    srand(time(NULL));
    int randomX=0;
    int randomY=0;

    // check x and y against 0 and bordersize x and y. 
    randomX = (rand()%(mainGameRef->getBoardSizeX()-1))+1;
    randomY = (rand()%(mainGameRef->getBoardSizeY()-1))+1;

    //in objPos class there is a method to see if position is equal. 
    if(!(foodPos.isPosEqual(&blockOff))) //if foodPos doesn't equal the blockoff position
    
    {
        foodPos.setObjPos(randomX, randomY, 'o'); //set to the random coordinate
    }

}

void Food:: getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos); //does it make sense to put this object in brackets
}
