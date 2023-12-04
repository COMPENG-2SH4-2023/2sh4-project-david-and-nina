#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"


using namespace std;

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameRef;

    public:
        Food(GameMechs* thisGameRef); //constructor
        ~Food(); //destructor

        void generateFood(objPosArrayList &blockOff);
        void getFoodPos(objPos &returnPos);

};

#endif