#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char nama[255];
    printf("Masukkan nama Anda : ");
    scanf("%s",&nama);
    char password[255];
    strcpy(password,nama);
    printf("Password : %c%c%c%c%c\n",password[0],toupper(password[1]),password[2],toupper(password[3]),password[4],toupper(password[5]));
    char retype[255];
    printf("Masukkan kembali passwordnya : ");
    scanf("%s",&retype);
    if(strcmp(retype,password)==0)
    {
        printf("Login succeeded\n");
    }
    else
    {
        printf("kamu bodoh\n");
    }
    
    return 0;

}