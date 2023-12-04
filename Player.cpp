#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef; //pointer to game mechanics class 
    mainFood = thisFood; //pointer to food class
    myDir = STOP;
    
    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');
    
    playerPosList = new objPosArrayList();
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
        
        case 27:
            mainGameMechsRef->setExitTrue();
            break;

        default:
            break;
    }    
}

void Player::movePlayer()
{

    objPos currentHead; //holding position information of current head
    playerPosList->getHeadElement(currentHead);
    
    objPos currentFood;
    mainFood->getFoodPos(currentFood);

    //food collision: if the position of the snake head is at a food it will enter this if statement
    if (currentHead.x == currentFood.x && currentHead.y == currentFood.y){
        playerPosList->insertHead(currentHead); //still inserts a head, but doesn't delete the tail 
        mainFood->generateFood(*playerPosList); // calls generate food function
        mainGameMechsRef->incrementScore(); //adds to the score
    }

    
    else{

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

    if (checkSelfCollision()){
        mainGameMechsRef->setExitTrue();
       // MacUILib_printf("Exit Flag Status: %d\n", mainGameMechsRef-> getExitFlagStatus());
    }
    
}

 bool Player::checkSelfCollision(){
    objPos currentHead; //holding position information of current head
    playerPosList->getHeadElement(currentHead);
    
    objPos bodyElement; //holding position information of current head

    for(int i=1; i<playerPosList->getSize(); i++){
        
        playerPosList->getElement(bodyElement,i); //checking if the player head intersects any of the player body elements
        if(currentHead.isPosEqual(&bodyElement)){
            mainGameMechsRef->setLoseFlag();
            return true; //return true if there is a self collision
        }

    }
    return false; //returns false if there isn't a self collision
 }



