#include "Food.h"

Food:: Food(GameMechs* thisGameRef)
{
    mainGameRef = thisGameRef;
    
    foodPos.setObjPos(-1,-1,'o'); //set initial food position outside game board
}

Food:: ~Food()
{
    
}

void Food:: generateFood(objPosArrayList &blockOff)
{
    //generate random x and y coord and make sure they arent border or blockoff position
    srand(time(NULL));
    int randomX=0;
    int randomY=0;

    objPos checker;
    bool flag = true;

    // check x and y against 0 and bordersize x and y. 
    while(flag){
        flag = false;

        randomX = (rand()%(mainGameRef->getBoardSizeX()-2))+1;
        randomY = (rand()%(mainGameRef->getBoardSizeY()-2))+1;

        objPos random (randomX,randomY,'o');

        //in objPos class there is a method to see if position is equal. 
        for (int i=0; i<blockOff.getSize(); i++){
            blockOff.getElement(checker,i);
            if(random.isPosEqual(&checker)) //if foodPos doesn't equal the blockoff position
            {
                flag=true;
            }
        }
        
        if (!flag){
            foodPos.setObjPos(random); //set to the random coordinate
        }
    }
}

void Food:: getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos); //does it make sense to put this object in brackets
}
