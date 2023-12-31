#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];  //space for 200 elements on the heap
    listSize = 0;                       //nothing in the list at the start
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    if (listSize != arrayCapacity){

        for (int i=listSize; i>0; i--){
        aList[i].setObjPos(aList[i-1]); //shifts all elements of the list one element towards the tail
    }

    aList[0].setObjPos(thisPos);
    listSize++;
    
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize != arrayCapacity){
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize != 0){
        for (int i=listSize-1; i>=0; i--){
            aList[i-1].setObjPos(aList[i]); //shifts all elements of the list one element towards the tail 
        }

        listSize--; //lazy delete, but saves processing time
    }
}

void objPosArrayList::removeTail()
{
    if(listSize != 0){
        listSize--; //lazy delete, but saves processing time
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}