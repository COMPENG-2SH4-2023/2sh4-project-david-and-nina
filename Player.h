#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "MacUILib.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();
        


    private:
        enum Dir myDir;

        GameMechs* mainGameMechsRef;
        Food* mainFood;
        objPosArrayList* playerPosList;   
};

#endif