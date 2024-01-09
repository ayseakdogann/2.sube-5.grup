#include "fonksiyon.h"
const char *kullaniciDosyaAdi = "C:\\Users\\HP\\Desktop\\kullanicilar.txt";
const char *islemDosyaAdi = "C:\\Users\\HP\\Desktop\\hesap_gecmisi.txt";
void kullaniciKaydet(struct Kullanici yeniKullanici) {
    FILE *dosya = fopen(kullaniciDosyaAdi, "a");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    fprintf(dosya, "%s %s\n", yeniKullanici.kullaniciAdi, yeniKullanici.sifre);
    fclose(dosya);
}

int kullaniciGiris(char kullaniciAdi[20], char sifre[20]) {
    FILE *dosya = fopen(kullaniciDosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return -1;
    }
    struct Kullanici okunanKullanici;
    while (fscanf(dosya, "%s %s", okunanKullanici.kullaniciAdi, okunanKullanici.sifre) != EOF) {
        if (strcmp(okunanKullanici.kullaniciAdi, kullaniciAdi) == 0 && strcmp(okunanKullanici.sifre, sifre) == 0) {
            fclose(dosya);
            return 1; // Giriş başarılı
        }
    }
    fclose(dosya);
    return 0; // Kullanıcı adı veya şifre yanlış
}

void islemKaydet(struct Islem islem) {
    FILE *dosya = fopen(islemDosyaAdi, "a");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    fprintf(dosya, "Kullanici: %s, Hesap No: %d, Islem Turu: %c, Miktar: %.2f\n", islem.kullaniciAdi, islem.hesapNo, islem.tur, islem.miktar);
    fclose(dosya);
}

void paraYatir(struct Hesap *hesap, char kullaniciAdi[20]) {
    float miktar;
    printf("Yatirmak istediginiz miktar: ");
    scanf("%f", &miktar);

    hesap->bakiye += miktar;
    struct Islem yatirim = {hesap->hesapNo, 'Y', miktar};
    strcpy(yatirim.kullaniciAdi, kullaniciAdi);
    islemKaydet(yatirim);
    printf("%.2f TL yatirildi. Yeni bakiye: %.2f TL\n", miktar, hesap->bakiye);
}

void paraCek(struct Hesap *hesap, char kullaniciAdi[20]) {
    float miktar;
    printf("Cekmek istediginiz miktar: ");
    scanf("%f", &miktar);

    if (hesap->bakiye >= miktar) {
        hesap->bakiye -= miktar;
        struct Islem cekim = {hesap->hesapNo, 'C', miktar};
        strcpy(cekim.kullaniciAdi, kullaniciAdi);
        islemKaydet(cekim);
        printf("%.2f TL cekildi. Yeni bakiye: %.2f TL\n", miktar, hesap->bakiye);
    } else {
        printf("Yetersiz bakiye.\n");
    }
}

void bakiyeSorgula(struct Hesap hesap) {
    printf("Hesap No: %d, Mevcut Bakiye: %.2f TL\n", hesap.hesapNo, hesap.bakiye);
}