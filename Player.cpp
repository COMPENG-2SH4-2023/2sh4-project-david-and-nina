#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    
    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');

    
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    
    switch(input){

        case 'a': //ASCI for "a"
                
            if (myDir != RIGHT && myDir != LEFT){
                myDir = LEFT;
            }
            break;

        case 'd': //ASCI for "d"
            if (myDir != LEFT && myDir != RIGHT){
                myDir = RIGHT;
            }
            break;

        case 'w': //ASCI for "w" 
            if (myDir != DOWN && myDir != UP){
                myDir = UP;
            }
            break;
        
        case 's': //ASCI for "s"
            if (myDir != UP && myDir != DOWN){
                myDir = DOWN;
            }
            break;

        default:
            break;
    }    
}

void Player::movePlayer()
{
    
    objPos currentHead; //holding position information of current head
    playerPosList->getHeadElement(currentHead);

    
    if(myDir == LEFT){
        currentHead.x--;
    }
    else if(myDir == RIGHT){
        currentHead.x++;
    }
    else if(myDir == UP){
        currentHead.y--;
    }
    else if(myDir == DOWN){
        currentHead.y++;
    }
    

    //Wrap around once the "@" symbol reaches the boarder

    if (currentHead.x == (mainGameMechsRef -> getBoardSizeX()-1)){
        currentHead.x = 1;
    }

    if (currentHead.x == 0){
        currentHead.x = (mainGameMechsRef -> getBoardSizeX()-2);
    }
    
    if (currentHead.y == (mainGameMechsRef -> getBoardSizeY()-1)){
        currentHead.y = 1;
    }

    if (currentHead.y == 0){
        currentHead.y = (mainGameMechsRef -> getBoardSizeY()-2);
    }

    playerPosList->insertHead(currentHead);
    playerPosList->removeTail();

}




