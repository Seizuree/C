// #include <stdio.h>

// int main(){
// //     int num;
// //     char chr;
// //     // output
// //     // string -> petik dua 
// //     // escape sequence (\)
// //     // \n -> enter (new line)
// // //  printf("Welcome to BINUS");
// // //  printf("Hello");
// //     printf("Isi angka yang kamu sukai :\n");
// //     scanf("%d", &num); while(getchar() != '\n');
// //     scanf("%c", &chr); getchar ();
// //     printf("Integer : %d\n", num); 
// //     printf("Float : %f \n", flt);
// //     printf("Ini karakternya : %s", &chr);
// // string -> array of character (diakhiri dengan character NULL (' \0'))
     
//     char nim[101];
//     char name[101];
//     printf("Masukkan Nama Anda : \n");
//     scanf("%[^\n]", &name); getchar();
//     printf("Masukkan NIM anda : \n");
//     scanf("%[^\n]", &nim); getchar();

//     printf("Nama anda : %s \n", &name);
//     printf("NIM anda : %s \n", nim);

//     return 0;

// }
#include <stdio.h>
int main() 
{
  float angka, jumlah = 0;
  do 
  {
    printf("Masukkan angka yang mau dihitung : ");
    scanf("%f", &angka);
    jumlah = jumlah + angka;
  }
  while(angka != 0.0);

  printf("Hasil total = %.2f",jumlah);

  return 0;
}