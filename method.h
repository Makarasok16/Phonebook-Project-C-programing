#include"model.h"
#include<stdio.h>
#include<conio.h>
int i,n;
char ans[10];
void line()
{
	printf("\t\t\t\t\t______________________________________________________________________\n");
}
int menu(){
    int op;
    system("cls"); 
    line();
    puts("\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|MENU|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
    puts("\t\t\t\t\t\t1. Add Contact");
    puts("\t\t\t\t\t\t2. Display Data");
    puts("\t\t\t\t\t\t3. Search contact");
    puts("\t\t\t\t\t\t4. Modify");//the same as update
    puts("\t\t\t\t\t\t5. Delete");
    puts("\t\t\t\t\t\t6. Insert");
    puts("\t\t\t\t\t\t7. Exit the program");
    printf("\t\t\t\t\t\tWhat Option do you want to choese: ");scanf("%d",&op);
	return op;
}

void add(){
    printf("\t\t\t\tEnter the phone number      : ");
    scanf("%s",&pbook.number);
    printf("\t\t\t\tEnter the name of contact   : ");
    fflush(stdin);
    //stdin is the input stream that takes the input from the user
    //fflush used for output stream to move the data to store in a file
    gets(pbook.name);
    printf("\t\t\t\tEnter the gender            : ");
    gets(pbook.sex);
    printf("\t\t\t\tEnter occupation            : ");
    fflush(stdin);
    gets(pbook.occupation);
    
}

void displayData(){
    printf("\t\t\t\t\t\t%s\t%s\t%s\t%s\n",pbook.number, pbook.name,pbook.sex, pbook.occupation);
}

void Header(){
    puts("\n\n\t\t\t\t\t\tPhone Number\tName Of contact\tGender\tOccupation");
}

void Modify(){
    printf("\t\t\t\tEnter the phone number      : ");
    scanf("%s",&pbookModify.number);
    printf("\t\t\t\tEnter the contact's name    : ");
    fflush(stdin);gets(pbookModify.name);
    printf("\t\t\t\tEnter the gender            : ");
    gets(pbookModify.sex);
    printf("\t\t\t\tEnter occupation            : ");
    fflush(stdin);gets(pbookModify.occupation);
}
