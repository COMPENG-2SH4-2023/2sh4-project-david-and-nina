#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    
    // more actions to be included
    playerPos.setObjPos(5,5,'@');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
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
    }    
}

void Player::movePlayer()
{
    if(myDir == LEFT){
        playerPos.x--;
    }
    else if(myDir == RIGHT){
        playerPos.x++;
    }
    else if(myDir == UP){
        playerPos.y--;
    }
    else if(myDir == DOWN){
        playerPos.y++;
    }
    

    //Wrap around once the "@" symbol reaches the boarder

    if (playerPos.x == (getBoardSizeX()-1)){
        playerPos.x = 1;
    }

    if (playerPos.x == 0){
        playerPos.x = (getBoardSizeX()-2);
    }
    
    if (playerPos.y == (getBoardSizeY()-1)){
        playerPos.y = 1;
    }

    if (playerPos.y == 0){
        playerPos.y = (getBoardSizeY()-2);
    }
}

