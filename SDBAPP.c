#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"


void Enter_Data(student* in){
printf("Enter Student Id : ");
scanf("%d",&in->Student_ID);
printf("Enter Student Year : ");
scanf("%d",&in->Student_year);
printf("Enter Course_ID : ");
scanf("%d",&in->Course1_ID);
printf("Enter Course_Grade : ");
scanf("%d",&in->Course1_grade);
printf("Enter Course2_ID : ");
scanf("%d",&in->Course2_ID);
printf("Enter Course2_Grade : ");
scanf("%d",&in->Course2_grade);
printf("Enter Course3_ID : ");
scanf("%d",&in->Course3_ID);
printf("Enter Course3_Grade : ");
scanf("%d",&in->Course3_grade);
printf(" \n");
}

void Create_Database(){
//1st Node
int iter;
list_1=NULL;
printf("Enter Four Records at first : \n");

student* temp = (student*)malloc(sizeof(student));
Enter_Data(temp);

temp->link=list_1;
    list_1=temp;
//Other Three Nodes

for(iter=0;iter<3;iter++){
student*temp1 = (student*)malloc(sizeof(student));
Enter_Data(temp1);
student* ptr2=list_1;
    while(ptr2->link!=NULL){
    ptr2=ptr2->link;
    }
    ptr2->link=temp1;
    temp1->link=NULL;
}
//Display Nodes
    student*ptr1 = list_1;
while(ptr1!=NULL){
        printf("%d ",ptr1->Student_ID);
    printf("%d \n",ptr1->Student_year);
    ptr1=ptr1->link;
}
}


void SDB_APP (){
uint8 user_choise;

printf("To add entry, enter 1\n");
printf("To get used size in database, enter 2\n");
printf("To read student data, enter 3\n");
printf("To get the list of all student IDs, enter 4\n");
printf("To check is ID is existed, enter 5 \n");
printf("To delete student data, enter 6\n");
printf("To check is database is full, enter 7\n");
printf("To exit enter 0\n");
scanf("%d",&user_choise);
printf("\n");
SDB_action(user_choise);
}

void SDB_action (uint8 choice){
    uint32 IfIdExist;
while(choice!=0){
switch(choice){
case(1):SDB_AddEntry;break;

case(2):printf(" %d ",SDB_GetUsedSize());break;//------done

case(3):printf("%d",SDB_ReadEntry);break;

case(4):printf("%d",SDB_GetList);break;
case(5)://--------------------------------------------not yet
    printf("\n Enter The Id Needed To Be Scanned :");
    scanf("%d",&IfIdExist);
    if(SDB_IsIdExist(IfIdExist)==1)
    printf("Found\n");
    else if(SDB_IsIdExist(IfIdExist)==0)
        printf("Not Found\n");
    break;

case(6):SDB_DeletEntry();break;

case(7)://---------------------------------------------done
    if(SDB_IsFull()==1)
        printf("DataBase is Full\n");
    else if(SDB_IsFull()==0)
        printf("There Is a place\n");break;

default:printf("Wrong Entry ! ");
}
printf(" \n");
SDB_APP();
}
}
