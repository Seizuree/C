#include <stdio.h>

struct soalB
{
    long long int banyak = 0;
    char nama[101];
    long long int harga = 0;
};


int main()
{
    FILE *fp;
    fp = fopen("testdata.in","r"); // buka file
    int x;
    fscanf(fp,"%d\n",&x); // scan bilangan pertama yaitu banyaknya perulangan program
    soalB arr1[101]; // struct karena dalam testcase ada lebih dari 1 alat musik yang dipesan oleh 1 cust
    for (int c = 0; c < x; c++) // perulangan program
    {
        int count;
        fscanf(fp,"%d\n",&count); // scan untuk banyak barang yang dibeli oleh customer
        for (int i = 0; i < count; i++)
        {
            fscanf(fp,"%lld#%[^@]@%lld\n",&arr1[i].banyak,&arr1[i].nama,&arr1[i].harga); // scan untuk mengetahui data customer
        }
        long long int sum = 0; // variabel untuk jumlah penambahan
        long long int disc = 0; // variabel untuk menaruh diskon 15%
        for (int i = 0; i < count; i++)
        {
            sum += arr1[i].harga * arr1[i].banyak; // menambahkan apabila customer membeli lebih dari 1 barang
        }
        disc = sum * 15/100; // diskon 15% yang ada disoal
        sum = sum - disc; // jumlah harga setelah didiskon
        printf("Customer #%d: Rp %lld\n",c+1,sum); // print customer dan hasilnya 
    }
    fclose(fp);
    return 0;
}