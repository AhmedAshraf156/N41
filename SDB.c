#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"
extern student* list_1;

bool SDB_IsFull (){

int Record=0;
    student*ptr1 = list_1;
while(ptr1!=NULL){
    ptr1=ptr1->link;
    Record++;
}
if(Record>10)
return true;
else
return false;

}

uint8 SDB_GetUsedSize(){

int Record=0;
    student*ptr1 = list_1;
while(ptr1!=NULL){
    ptr1=ptr1->link;
    Record++;
}
return Record;
}


bool SDB_AddEntry(){


}

void SDB_DeletEntry (uint32 id){

}



bool SDB_ReadEntry (uint32 id){


}

void SDB_GetList (uint8 * count, uint32 * list){


}

bool SDB_IsIdExist (uint32 id){
    char flag;
 student*ptr1 = list_1;
while(ptr1!=NULL){
 if(ptr1->Student_ID==id)
    flag=1;
 else {
    flag=0;
 }
    ptr1=ptr1->link;
}
if(flag==0)
{
return false;}

else if (flag==1)
{
return true;
}
}
