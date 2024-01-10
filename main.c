#include <stdio.h>
#include "fonksiyon.h"
#define MAX_USERS 100
int main() {
    int secim;
    char kullaniciAdi[20];
    char sifre[20];
    struct Kullanici kullaniciVeritabani[MAX_USERS];
    int kayitliKullaniciSayisi = 0;

    printf("Kayit olmak icin kullanici adi ve sifre belirleyin:\n");
    printf("Kullanici adi: ");
    scanf("%s", kullaniciVeritabani[kayitliKullaniciSayisi].kullaniciAdi);
    printf("Sifre: ");
    scanf("%s", kullaniciVeritabani[kayitliKullaniciSayisi].sifre);

    kullaniciKaydet(kullaniciVeritabani[kayitliKullaniciSayisi]);
    kayitliKullaniciSayisi++;

    printf("Lutfen giris yapin:\n");
    printf("Kullanici adi: ");
    scanf("%s", kullaniciAdi);
    printf("Sifre: ");
    scanf("%s", sifre);

    int girisDurumu = kullaniciGiris(kullaniciAdi, sifre);
    if (girisDurumu == 1) {
        printf("Giris basarili.\n");
        struct Hesap yeniHesap = {123456, 0.00};

        do {
            printf("\n1. Para Yatirma\n2. Para Cekme\n3. Bakiye Sorgulama\n4. Cikis\nSeciminiz: ");
            scanf("%d", &secim);

            switch (secim) {
                case 1:
                    paraYatir(&yeniHesap, kullaniciAdi);
                    break;
                case 2:
                    paraCek(&yeniHesap, kullaniciAdi);
                    break;
                case 3:
                    bakiyeSorgula(yeniHesap);
                    break;
                case 4:
                    printf("Programdan cikis yapildi.\n");
                    break;
                default:
                    printf("Gecersiz secim. Tekrar deneyin.\n");
            }
        } while (secim != 4);
    } else if (girisDurumu == 0) {
        printf("Kullanici adi veya sifre yanlis.\n");
    }
    return 0;
}
