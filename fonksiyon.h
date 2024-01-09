#ifndef BANKA
#define BANKA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kullanici {
    char kullaniciAdi[20];
    char sifre[20];
};

// Yapı tanımlamaları
struct Hesap {
    int hesapNo;
    float bakiye;
};

struct Islem {
    int hesapNo;
    char tur; // 'Y' -> Yatırma, 'C' -> Çekme
    float miktar;
    char kullaniciAdi[20];
};

// Fonksiyon prototipleri
void kullaniciKaydet(struct Kullanici yeniKullanici);
int kullaniciGiris(char kullaniciAdi[20], char sifre[20]);
void islemKaydet(struct Islem islem);
void paraYatir(struct Hesap *hesap, char kullaniciAdi[20]);
void paraCek(struct Hesap *hesap, char kullaniciAdi[20]);
void bakiyeSorgula(struct Hesap hesap);
#endif
