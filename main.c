#include"method.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[]){
    int op;
    FILE *w_file,*r_file;

    do
    {
        switch (menu())
        {
            case 1:{
                w_file = fopen("Phonebook.bin","ab");
                printf("\t\t\t\tEnter the number of data: ");scanf("%d",&n);
                for(i=0;i<n;i++){
                    add();
                    fwrite(&pbook,sizeof(struct Phonebook),1,w_file);
                }
                fclose(w_file);
            }break;
            case 2:{
                r_file = fopen("Phonebook.bin","rb");
                int check=0;
                //check data
                if(r_file == NULL){
                    printf("\t\t\t\tFile opening is error!!!\a\a\a\n");
                    exit(0);
                }
                while(1==fread(&pbook,sizeof(struct Phonebook),1,r_file)){
                    if(check==0){
                        Header();
                    }
                    displayData();
                    check++;
                }
                if(check==0){
                    printf("\n\t\t\t\t\t\tNo data!");
                }
                else printf("\n\t\t\t\t\t\tHere is your data!");
                fclose(r_file);
            }break;
            case 3:{
                r_file = fopen("Phonebook.bin","rb");
                //check
                if(r_file==NULL){
                    printf("\t\t\t\tError!!!\a\a\a\a");
                    exit(0);
                }
                char search[20];
                int check=0;
                printf("\t\t\t\tEnter the name to search: ");fflush(stdin);gets(search);
                
                while(1==fread(&pbook,sizeof(struct Phonebook),1,r_file)){
                    if(stricmp(pbook.name,search)==0){
                        if(check==0){
                        printf("\n\t\t\t\tDetail Information About %s",search);
                            Header();
                        }
                        displayData();
                        check++;
                    }
                }
                fclose(r_file);
            }break;
            case 4:{
                char nameModify[20];
                int check=0;
                w_file = fopen("Modify.bin","wb");
                r_file = fopen("Phonebook.bin","rb");
                printf("\t\t\t\tEnter the contact's name to modify: ");
                fflush(stdin);gets(nameModify);
                while(1==fread(&pbook,sizeof(struct Phonebook),1,r_file)){
                    if(strcmp(nameModify,pbook.name)==0){
                        Modify();
                        check=1;
                        fwrite(&pbookModify,sizeof(struct Phonebook),1,w_file);
                        
                    }
                    else{
                        fwrite(&pbook,sizeof(struct Phonebook),1,w_file);
                        check = 0;
                    }
                }
                if(check==1){
                    printf("\t\t\t\tModify successfull\a\a\a\n");
                }
                else printf("\t\t\t\tModify is not successfull\a\a\a\n");
                fclose(w_file);
                fclose(r_file);
                remove("Phonebook.bin");
                rename("Modify.bin","Phonebook.bin");
            }break;
            case 5:{
                w_file = fopen("DeleteContact.bin","wb");
                r_file = fopen("Phonebook.bin","rb");
                char nameDelete[20];
                int check=0;
                printf("\t\t\t\tEnter the name to delete: ");fflush(stdin);gets(&nameDelete);
                while(1==fread(&pbook,sizeof(struct Phonebook),1,r_file)){
                    if(strcmp(nameDelete,pbook.name)==0){
                        check=1;
                    }
                    else fwrite(&pbook,sizeof(struct Phonebook),1,w_file);
                }
                if(check==1){
                    printf("\t\t\t\tDelete successfull\n");
                }
                else printf("\t\t\t\tDelete is not successfull\n");
                fclose(w_file);
                fclose(r_file);
                remove("Phonebook.bin");
                rename("DeleteContact.bin","Phonebook.bin");
            }break;
            case 6:{
                w_file = fopen("Insert.bin","wb");
                r_file = fopen("Phonebook.bin","rb");
                char nameInsert[20];
                printf("\t\t\t\tEnter the contact's name to insert: ");fflush(stdin);gets(nameInsert);
                while(1==fread(&pbook,sizeof(struct Phonebook),1,r_file)){
                    if(strcmp(nameInsert,pbook.name)==0){
                        Modify();
                        fwrite(&pbookModify,sizeof(struct Phonebook),1,w_file);
                        fwrite(&pbook,sizeof(struct Phonebook),1,w_file);
                    }
                    else fwrite(&pbook,sizeof(struct Phonebook),1,w_file);
                }
                fclose(w_file);
                fclose(r_file);
                remove("Phonebook.bin");
                rename("Insert.bin","Phonebook.bin");
            }break;
            case 7:{
                exit(0);
            }break;
            default:{
                if(menu()>7){
                    puts("\t\t\t\tInvalid option");
                }
            }
        }
        

        printf("\n\n\t\t\t\t\t\tDo you want to continue [Yes/No] >> ");scanf("%s",&ans);
    } while (stricmp(ans,"yes")==0 || stricmp(ans,"y")==0);
    
    return 0;
}

