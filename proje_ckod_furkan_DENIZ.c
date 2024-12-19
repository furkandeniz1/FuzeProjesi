#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DENEME 3  
#define FUZE_SAYISI 100  

const char gecerli_id[] = "121252";  
const char gecerli_sifre[] = "121252";  


int kimlikKontrol();
void fuzeSecimi();
void fuzeAtis(char fuzeTuru);
void hedefSecimi(char fuzeTuru);
void kendiniImhaEt();
void alarmVeKapan();


int main() 
{
    if (kimlikKontrol()) {
        fuzeSecimi();
    } else {
        alarmVeKapan();
    }
    return 0;
}


int kimlikKontrol() 
{
    char id[20];
    char sifre[20];
    int denemeSayisi = 0;

    while (denemeSayisi < MAX_DENEME) {
        printf("Lutfen askeri kimlik numaranizi girin: ");
        scanf("%s", id);
        printf("Lutfen sifrenizi girin: ");
        scanf("%s", sifre);

        
        if (strcmp(id, gecerli_id) == 0 && strcmp(sifre, gecerli_sifre) == 0)
         {
            printf("Kimlik dogrulandi!\n");
            return 1; 
        } else 
        
        {
            denemeSayisi++;
            printf("\033[1;31mGecersiz kimlik bilgileri! Kalan deneme hakkiniz: %d\033[0m\n", MAX_DENEME - denemeSayisi);
        }
    }
    return 0;  
}


void fuzeSecimi() 
{
    char secim;
    while (1) {
        printf("\nFuze Secimi\n");
        printf("a) Seyir Fuzesi-X\n");
        printf("b) Seyir Fuzesi-Y\n");
        printf("c) Seyir Fuzesi-Z\n");
        printf("Cikmak icin d tusuna basiniz.\n");
        printf("Bir fuze secin: ");
        scanf(" %c", &secim);

        switch (secim) 
        {
            case 'a':
            case 'b':
            case 'c':
                fuzeAtis(secim);
                break;
            case 'd':
                printf("Programdan cikiliyor...\n");
                return;
            default:
                printf("Gecersiz secim! Lutfen a, b, c veya d girin.\n");
        }
    }
}


void fuzeAtis(char fuzeTuru) 
{
    char atisSecimi;
    printf("\nSecilen fuze turu: %c\n", fuzeTuru);
    printf("Fuze atis yapmak ister misiniz? (Evet: e / Hayir: h): ");
    scanf(" %c", &atisSecimi);

    if (atisSecimi == 'e' || atisSecimi == 'E') 
    {
        printf("Fuze atildi!\n");
        sleep(1);  
        hedefSecimi(fuzeTuru);
     } 
     else 
     
     {
        printf("Hicbir islem yapilmadi.\n");
        fuzeSecimi();  
    }
       }


void hedefSecimi(char fuzeTuru) 

{
    char hedefSecim;
    printf("\nFuze havada 50 metreye ulasti.\n");
    printf("Vurmak istediginiz hedefi secin:\n");
    printf("1) Hedefi manuel sec\n");
    printf("2) Hedefi otomatik yonelt ve imha et\n");
    printf("3) Fuze kendini imha etsin\n");
    printf("Bir secenek girin: ");
    scanf(" %c", &hedefSecim);

    switch (hedefSecim)
     {
        case '1':            printf("Hedef secildi. Hedef imha edilsin mi? (Evet: e / Hayir: h): ");
            char imhaSecimi;
            scanf(" %c", &imhaSecimi);
            if (imhaSecimi == 'e' || imhaSecimi == 'E') 
            {
                printf("Hedefe dogru fuze hareketlendi. Hedef imha edildi!\n");
            
        }
         else 
         {
                printf("Baska bir hedef secin.\n");
            }
            fuzeSecimi();  
            break;
        case '2':
            printf("Hedef imha edilsin mi? (Evet: e / Hayir: h): ");
            scanf(" %c", &imhaSecimi);
            if (imhaSecimi == 'e' || imhaSecimi == 'E') 
            {
                printf("Hedef imha edildi!\n");
            }
             else
              {
                printf("Hedefe yoneltildi.\n");
            }
            fuzeSecimi();  
            break;
        case '3':
            kendiniImhaEt();  
            break;
        default:
            printf("Gecersiz secim! Lutfen 1, 2 veya 3 girin.\n");
            hedefSecimi(fuzeTuru);  
    }
}


void kendiniImhaEt() 
{
    char imhaSecimi;
    printf("Fuze kendini imha etsin mi? (Evet: e / Hayir: h): ");
    scanf(" %c", &imhaSecimi);

    if (imhaSecimi == 'e' || imhaSecimi == 'E') 
    {
        printf("Fuze imha edildi.\n");
    } 
    else
     {
        printf("Fuze imha edilmedi.\n");
    }
    fuzeSecimi();  
}


void alarmVeKapan() 

{
    printf("\033[1;31mUc kez yanlis giris yaptiniz! Sistem kapaniyor...\033[0m\n");
    sleep(2);
    printf("\a");  
    exit(0);  
}

