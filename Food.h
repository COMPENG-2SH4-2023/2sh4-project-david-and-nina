#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

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

        void generateFood(objPosArrayList &blockOff);//NEED TO DO
        //need to accept player bpdy array list and go through each element to make
        //sure they are all blocked off from random food generation

        void getFoodPos(objPos &returnPos);


};

#endif