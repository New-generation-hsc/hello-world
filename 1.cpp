#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 30
void Usereg();
void Login();
void Update();
struct
{
	char username[SIZE];
	char password[SIZE];
}user;
int main ()
{
    FILE *fp;
    struct user;

     fp=fopen("C:\\Users\\杨斐斐\\Desktop\\新建文件夹\\cool.txt","ab");
     system("cls");
     int number;
     system ("color 8B");
     printf("*************************\n");
     printf("Welcome to use the system\n");
     printf("*************************\n");
     printf("1 Usereg\n");
     printf("2 Login\n");
     printf("3 Update");
     printf("\n please input number\n");
     scanf("%d",&number);
    switch (number)
    {
      case 1:Usereg ();
      break;
      case 2:Login ();
      break;
      case 3:Update ();
      break;
    }
    fclose(fp);
    return 0;
    }

void Usereg()
{
    FILE*fp;
    struct user;
	fopen("C:\\Users\\杨斐斐\\Desktop\\新建文件夹\\cool.txt","w");
	 if (fp==NULL)
	 {
	    printf ("cannot open the file\n");
        exit (1);
     }
     else
     {
        printf("successfully open the file\n");
        printf ("Please input your username ");
        scanf ("%s",&user.username);
        gets(user.username);
        printf ("Please input your password");
        scanf ("%s",&user.password);
        gets(user.password);
        fflush(stdin);
        fwrite(&user,sizeof(user),1,fp);
        printf("Registered Success!\n");
     }
     fclose(fp);
}
void Login()
{
	FILE*fp;
    struct user;
    char username[SIZE];
    char password[SIZE];
     fopen("C:\\Users\\杨斐斐\\Desktop\\新建文件夹\\cool.txt","r");
      if (fp==NULL)
	  {
	     printf ("cannot open the file\n");
         exit (1);
     }
     else
     {
       printf("successfully open the file\n");
        printf("please input your username and password\n");
         scanf("%s %s",username,password);
          if(strcmp(user.username,username)==0)
           {
             if(strcmp(user.password,password)==0)
              {
                printf("OK!Login Success\n");
                 /* printf ("1:     ");
                   printf ("2:     ");
                    printf ("3:     ");
                     printf ("4:     ");
                      printf ("5:     ");
                       scanf ("%d",&number);*/
              }
                else
          {
           printf("please input correct password\n");
           }}
       else
        {
        printf("sorry,please input correct username\n");
       }
        }
     fclose(fp);
     return 0;}

void Update()
{
	FILE*fp;
    struct user;
    char username[SIZE];
    char password[SIZE];
	fopen("C:\\Users\\杨斐斐\\Desktop\\新建文件夹\\cool.txt","w+");
	  if (fp==NULL)
	   {
	    printf ("cannot open the file\n");
        exit (1);
       }
       else
       {printf("successfully open the file\n");
        printf("please input your username\n");
        scanf ("%s",username);
        gets(username);
        printf ("Please input your password");
        gets(user.password);
         if(strcmp(user.password,password)==0)
         {printf("please input new password\n");
           scanf("%s",password);
            fwrite(&user,sizeof(&user),1,fp);}
            else
             {
             printf("the password is wrong\n");
             }
       }
       fclose(fp);
}
