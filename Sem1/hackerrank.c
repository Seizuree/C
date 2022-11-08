// #include <stdio.h>

// int main(){
//     int a;
//     scanf("%d", a);
//     if(a==1){
//         printf("one");
//     }
//     else if(a==2){
//         printf("two");
//     }
//     else if(a==3){
//         printf("three");
//     }
//     else if(a==4){
//         printf("four");
//     }
//     else if(a==5){

//     }
#include <stdio.h>

static const char *strings[] = {"one","two","three","four","five",
                                "six","seven","eight","nine"};
int main()
{
    int n = 0;
    if (scanf("%d",&n) < 1)
        return 1;

    if (n >= 1 && n <= 9)
        printf("%s",strings[n-1]);
    else
        printf("Greater than 9");

    return 0;
}