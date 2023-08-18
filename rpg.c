#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void help();
void commandchk(int *command);
void clrfile();
void save();

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

//properties of room
struct player{
    int healthrn,maxhealth,exprn,maxexp,damage,level;
    char weaponequip[10];
    char shieldequip[10];
};


//main function
int main()
{
    char command[10];
    printf("\t\t\t!! Welcome to Text RPG !!");

    printf("\n\t\t=> use 'help' to check the commands!\n");
    printf("\n\t\t=> use 'start' to start an new game!");
    printf("\n\t\t( !! it will overwrite your previous save !! )\n");
    printf("\n\t\t=> use 'load' to continue from the last save!\n");
    while(1)
    {
        printf("\n\t>");
        scanf("%s",&command);
        if(command != "clear")
        {
            commandchk(&command);
        }
        else
        {
            clrscr();
        }
    }
}

//function to check command
void commandchk(int command)
{
    switch (&command)
    {
    case ("save"): save();
        break;
    case ("help"): help();
        break;
    case ("start"): clrfile();
        break;
    default:
        break;
    }
}

//function to check all commands
void help()
{
    printf("use 'exit' to close the game!");
    printf("use 'save' to save the game!");
    printf("use 'clear' to clear the screen!");
    printf("help command worked");
}

//function to clear the save file
void clrfile()
{
    
}

//function to save the file
void save()
{
    printf("\t\t!! Game Saved !!");
    printf("save command worked");
}
