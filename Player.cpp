#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    
    // more actions to be included
    playerPos.setObjPos(15,7,'@');
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

        default:
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

    if (playerPos.x == (mainGameMechsRef -> getBoardSizeX()-1)){
        playerPos.x = 1;
    }

    if (playerPos.x == 0){
        playerPos.x = (mainGameMechsRef -> getBoardSizeX()-2);
    }
    
    if (playerPos.y == (mainGameMechsRef -> getBoardSizeY()-1)){
        playerPos.y = 1;
    }

    if (playerPos.y == 0){
        playerPos.y = (mainGameMechsRef -> getBoardSizeY()-2);
    }
}

