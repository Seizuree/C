#include <stdio.h>

float opsiA(float beratBarang, int ongkosTunai, int ongkosKirim)
{
    printf("Nilai diskon yang didapat = 0%%\n");
    if(beratBarang <= 2)
    {
        beratBarang = 2;
        ongkosTunai = ongkosKirim * beratBarang;
    }
    else
    {
        ongkosTunai = ongkosKirim * beratBarang;
    }
    printf("Ongkos kirim setelah diskon = %d",ongkosTunai);
    return ongkosTunai;
}

float opsiB(int ongkosKirim, float beratBarang, int ongkosBT, float diskonBT)
{
    printf("Nilai diskon yang didapat = 2,5%%\n");
    if(beratBarang <= 2)
    {
        beratBarang = 2;
        ongkosBT = ongkosKirim * beratBarang * diskonBT;
    }
    else
    {
        ongkosBT = ongkosKirim * beratBarang * diskonBT;
    }
    printf("Ongkos kirim setelah diskon = %d",ongkosBT);
    return ongkosBT;
}

float opsiC(int ongkosKirim, float beratBarang, int ongkosOVO, float diskonOVO)
{
    printf("Nilai diskon yang didapat = 5%%\n");
    if(beratBarang <= 2)
    {
        beratBarang = 2;
        ongkosOVO = ongkosKirim * beratBarang * diskonOVO;                                                                                                                 
    }
    else
    {
        ongkosOVO = ongkosKirim * beratBarang * diskonOVO;
    }
    printf("Ongkos kirim setelah diskon = %d",ongkosOVO);
    return ongkosOVO;
}

float opsiD(int ongkosKirim, float beratBarang, int ongkosGopay, float diskonGopay)
{
    printf("Nilai diskon yang didapat = 6%%\n");
    if(beratBarang <= 2)
    {
        beratBarang = 2;
        ongkosGopay = ongkosKirim * beratBarang * diskonGopay;
    }
    else
    {
        ongkosGopay = ongkosKirim * beratBarang * diskonGopay;
    }
    printf("Ongkos kirim setelah diskon = %d",ongkosGopay);
    return ongkosGopay;
}

float opsiE(int ongkosKirim, float beratBarang, int ongkosSP, float diskonSP)
{
    printf("Nilai diskon yang didapat = 7%%\n");
    if(beratBarang <= 2)
    {
        beratBarang = 2;
        ongkosSP = ongkosKirim * beratBarang * diskonSP;
    }
    else
    {
        ongkosSP = ongkosKirim * beratBarang * diskonSP;
    }
    printf("Ongkos kirim setelah diskon = %d",ongkosSP);
    return ongkosSP;
}

int main()
{
    char namaPengirim[255], namaPenerima[255];
    char alamatPengirim[255], alamatPenerima[255];
    float beratBarang;
    char opsiPembayaran;
    int ongkosKirim;
    float diskonBT, diskonOVO, diskonGopay, diskonSP;
    int ongkosTunai, ongkosBT, ongkosOVO, ongkosGopay, ongkosSP;

    ongkosKirim = 9000;
    diskonBT = 0.975;
    diskonOVO = 0.95;
    diskonGopay = 0.94;
    diskonSP = 0.93;

    printf("Masukkan nama pengirim : ");
    scanf("%[^\n]",&namaPengirim); getchar();
    printf("Masukkan alamat pengirim : ");
    scanf("%[^\n]",&alamatPengirim); getchar();

    printf("Masukkan nama penerima : ");
    scanf("%[^\n]",&namaPenerima); getchar();
    printf("Masukkan alamat penerima : ");
    scanf("%[^\n]",&alamatPenerima); getchar();
    
    printf("Masukkan berat barang : ");
    scanf("%f",&beratBarang); getchar();

    while(opsiPembayaran != 'A' || opsiPembayaran != 'B' || opsiPembayaran != 'C' || opsiPembayaran != 'D' || opsiPembayaran != 'E')
    {
        printf("Masukkan opsi pembayaran yang diinginkan\nA: Tunai, B: Bank Transfer, C: OVO, D: Gopay, E: Shopeepay\n");
        scanf("%c",&opsiPembayaran); getchar();

        if(opsiPembayaran == 'A')
        {
            opsiA(beratBarang, ongkosTunai, ongkosKirim);
            break;
        }
        else if (opsiPembayaran == 'B')
        {
            opsiB(ongkosKirim, beratBarang, ongkosBT, diskonBT);
            break;
        }
        else if (opsiPembayaran == 'C')
        {
            opsiC(ongkosKirim, beratBarang, ongkosOVO, diskonOVO);
            break;
        }
        else if (opsiPembayaran == 'D')
        {
            opsiD(ongkosKirim, beratBarang, ongkosGopay, diskonGopay);
            break;
        }
        else if(opsiPembayaran == 'E')
        {
            opsiE(ongkosKirim, beratBarang, ongkosSP, diskonSP);
            break;
        }
        else if(opsiPembayaran != 'A' || opsiPembayaran != 'B' || opsiPembayaran != 'C' || opsiPembayaran != 'D' || opsiPembayaran != 'E')
        {
            printf("Input tidak tersedia dalam sistem.\n\n");
        }
    }
    
    return 0;
}