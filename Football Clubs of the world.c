#include<stdio.h>
#include<string.h>
#include<windows.h>
int main_exit;

void menu();
void add_club();
void edit_club();
void erase();
void view_list();
void close();//prototypes//
void fordelay(int j)//this will consume a little time.
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

struct date{
    int day,month,year;

    };
struct
{
    struct date dates;
    int club_no;
    int NOP;
    char name[100];
} add,check,upd,dlt;

int main()//Main Function of the Program
{
    char pass[10],password[10]="MFS171";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(50000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;

}

void menu(void)//This is the main menu of the program! YOu will chose an option to go to which panel you want to.
{
    int choice;
    system("cls");
    system("color F0");
    printf("\n\n\t\t\t\tFootball Club Management System");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1. Add Club.\n\t\t2. Edit Club.\n\t\t3. Delete club data.\n\t\t4. Club data.\n\t\t5. Close Program.\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
    case 1:
        add_club();
        break;
    case 2:
        edit_club();
        break;
    case 3:
        erase();
        break;
    case 4:
        view_list();
        break;
    case 5:
        close();
        break;
    default:
        printf("Error! -_- restart again and make sure you press the correct number.");
        close();
        break;
    }
}

void add_club()//club adding function
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.txt","a+");
    club_no:
    system("cls");
    printf("\n\n\nEnter today's date(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.dates.day,&add.dates.month,&add.dates.year);
    printf("\nEnter the club no: ");
    scanf("%d",&check.club_no);
    while(fscanf(ptr,"%d %s %d %d %d %d\n",&add.club_no,&add.name,&add.NOP,&add.dates.day,&add.dates.month,&add.dates.year)!=EOF)
    {
        if (check.club_no==add.club_no)
        {
            printf("This club no. is in use");
            fordelay(1000000000);
            goto club_no;
        }
    }
    add.club_no=check.club_no;
    printf("\nEnter the Club name: ");
    scanf("%s",add.name);
    fflush(stdin);
    printf("\nEnter the number of players: ");
    scanf("%d",&add.NOP);
    fprintf(ptr,"%d %s %d %d %d %d\n",add.club_no,add.name,add.NOP,add.dates.day,add.dates.month,add.dates.year);
    fclose(ptr);
    printf("\nClub Added!");

invalid:
    printf("\n\n\nEnter 1 for main menu \n   or 0 for exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid input!\a");
        goto invalid;
    }

}

void edit_club()//editing function
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the team registration no. that info you want to change: ");
    scanf("%d",&upd.club_no);
    while(fscanf(old,"%d %s %d %d %d %d\n",&add.club_no,&add.name,&add.NOP,&add.dates.day,&add.dates.month,&add.dates.year)!=EOF)
    {
        if (add.club_no==upd.club_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Club Name\n2.Number of Player\n\nEnter your choice(1 for NAME and 2 for N.O.P):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                printf("Enter the new name: ");
                scanf("%s",upd.name);
                fprintf(newrec,"%d %s %d %d %d %d\n",add.club_no,upd.name,add.NOP,add.dates.day,add.dates.month,add.dates.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new Number Of Player:");
                scanf("%d",&upd.NOP);
                fprintf(newrec,"%d %s %d %d %d %d\n",add.club_no,add.name,upd.NOP,add.dates.day,add.dates.month,add.dates.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d %d %d %d\n",add.club_no,add.name,add.NOP,add.dates.day,add.dates.month,add.dates.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.dat","record.txt");
    printf("\n\n\nEnter 1 for main menu \n   or 0 for exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            printf("\n\n\nEnter 1 for main menu \n   or 0 for exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
        }
}
void view_list()//this section will print the file
{
    FILE *fptr;
    fptr=fopen("record.txt","r");
    int test=0;
    system("cls");
    while(fscanf(fptr,"%d %s %d %d %d %d\n",&add.club_no,&add.name,&add.NOP,&add.dates.day,&add.dates.month,&add.dates.year)!=EOF)
    {
        printf("Registration No: %d.\tClub Name: %s.\t\tNumber of Players: %d.\tRegistration date: %d/%d/%d\n",add.club_no,add.name,add.NOP,add.dates.day,add.dates.month,add.dates.year);
        test++;
    }

    fclose(fptr);
    printf("\n\n\nEnter 1 for main menu \n   or 0 for exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();


}
void erase(void)//deleting section
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the Registration number of the club that you want to delete:");
    scanf("%d",&dlt.club_no);
    while(fscanf(old,"%d %s %d %d %d %d\n",&add.club_no,&add.name,&add.NOP,&add.dates.day,&add.dates.month,&add.dates.year)!=EOF)
   {
        if(add.club_no!=dlt.club_no)
            fprintf(newrec,"%d %s %d %d %d %d\n",add.club_no,add.name,add.NOP,add.dates.day,add.dates.month,add.dates.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.dat","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
        }
    printf("\n\n\nEnter 1 for main menu \n   or 0 for exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
}

void close(void)
{
    printf("\n\n\n\nThis project was created by Group 7.  Good Bye.\n\n\n\n\n\nTeam 7 members: Mushfiq Uddin Ahmed, Azmee Sheikh, Hasib Zaman\n\n\n");
}

