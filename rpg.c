#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxroom 100
int cmdChk(char *cmdptr);
int help();
int save(FILE *fptr);
int load(FILE *fptr);

//properties of player
struct player{
    int healthrn,maxhealth,exprn,maxexp,damage,level;
    char weaponequip[10];
    char shieldequip[10];
};


//properties of enemy
struct enemy{
    int health,damage,exp,level;
    int dropitem;
    char skill[15];
    char roomtype[15];
};


//properties of weapon
struct weapon{
    int damage,durablilityrn,maxdurability;
};


//properties of room
struct room{
    int noofdoors;
    char canexit;
    char type[10];
};


//main function
int main()
{
    char command[10];
    printf("\t\t\t!! Welcome to Text RPG !!");
    printf("\n\t\t~~~~~~~~~~~ !! MAIN MENU !! ~~~~~~~~~~~");
    printf("\n\t\t=> use 'help' to check the commands!\n");
    printf("\n\t\t=> use 'start' to start an new game!");
    printf("\n\t\t( !! it will overwrite your previous save !! )\n");
    printf("\n\t\t=> use 'load' to continue from the last save!\n");
    printf("\n\t\t=> use 'exit' to close the game!\n");
    while(1)                                                            //this loop will repeatedly check if the user have made any choice
    {
        printf("\n\t>");
        gets(command);
        if(strcmp(command,"exit")==0)
        {
            exit(0);
        }
        else if(strcmp(command,"clear")!=0)                             //this will pass the program control to the cmdChk function to check the commands
        {
            cmdChk(command);
        }
        else
        {
            system("cls");      //you can replace cls with clear if your system is linux or mac
        }
    }
}


//command check function for the main menu
int cmdChk(char *cmdptr)
{
    FILE *fptr;
    fptr = fopen("save.txt","r");
    int done = 0;
    if(strcmp(cmdptr,"help")==0)
    {
        help();
    }
    else if(strcmp(cmdptr,"start")==0)
    {
        printf("you used start command");
    }
    else if(strcmp(cmdptr,"load")==0)
    {
        load();
    }
    else
    {
        printf("command not found");
        done=1;
    }
    if(done!=1)
    {
        fclose("save.txt");
        printf("!! Game started !!");
    }
}

//function to check all commands
int help()
{
    printf("use 'exit' to close the game!");
    printf("use 'save' to save the game!");
    printf("use 'clear' to clear the screen!");
}

//function to clear the save file
int clrfile()
{
    
}

//function to save the file
int save(FILE *fptr)
{
    printf("\t\t!! Game Saved !!");
}

//function to save the file
int load(FILE *fptr)
{
    printf("\t\t!! Game Loaded !!");
}
