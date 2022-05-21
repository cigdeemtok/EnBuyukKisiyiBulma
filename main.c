#include <stdio.h>
#include <stdlib.h>
//200201105-Cigdem Tok
struct DTarih
{
    int gun;
    int ay;
    int yil;
};
struct sahis_bilgileri
{
    char adSoyad[50];
    struct DTarih dogum_tarihi;
};

void buyukbul(struct sahis_bilgileri sahis[],int sayi)
{
    int i,j;
    for (i=0; i<sayi-1; i++)
    {
        for(j=0; j<sayi-i-1; j++)
        {
            if(sahis[j].dogum_tarihi.yil>sahis[j+1].dogum_tarihi.yil)
            {
                struct sahis_bilgileri temp;
                temp=sahis[j];
                sahis[j]=sahis[j+1];
                sahis[j+1]=temp;

            }
        }
    }

}

int main()
{
    int sayi,i,j;
    printf("Kisi sayisi giriniz: ");
    scanf("%d",&sayi);
    struct sahis_bilgileri sahis[sayi];
    puts("Bilgileri giriniz: ");
    for(i=0; i<sayi; i++)
    {
        printf("Adi:");
        scanf("%s",sahis[i].adSoyad);
        printf("Dogdugu gun: ");
        scanf("%d",&sahis[i].dogum_tarihi.gun);
        printf("Dogdugu ay: ");
        scanf("%d",&sahis[i].dogum_tarihi.ay);
        printf("Dogdugu yil: ");
        scanf("%d",&sahis[i].dogum_tarihi.yil);
    }

    printf("\nKayitlar yazdiriliyor...\n");

    for (i = 0 ; i < sayi ; i++)
    {
        printf("\nAdi : %s \n", sahis[i].adSoyad);
        printf("Dogum tarihi: %d.%d.%d\n", sahis[i].dogum_tarihi.gun,sahis[i].dogum_tarihi.ay,sahis[i].dogum_tarihi.yil);
    }

    buyukbul(sahis,sayi);
    printf("\n\nYasi en buyuk kisi: %s %d.%d.%d",sahis[0].adSoyad,sahis[0].dogum_tarihi.gun,sahis[0].dogum_tarihi.ay,sahis[0].dogum_tarihi.yil);

    return 0;
}
