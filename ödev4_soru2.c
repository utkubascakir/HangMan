#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void harf_ara(char *pword, char letter, int *pcheck, int *pcheck_all);

int main() {

    srand(time(0));

    char *kelimeler[50] = {"araba", "tahteravalli", "oyuncak", "futbol", 
    "kalemlik", "telefon", "defter", "bilgisayar", "klavye", "sandalye", 
    "kitap", "kablo", "perde", "makas", "laboratuvar", "tuvalet", "koltuk",
    "komodin", "ceket", "biyoloji"};

    int indis = rand()%20;
    int deneme_hakki = (int)strlen(kelimeler[indis])*2;
    int check_all = 0, x = 0;
    char harf;
    char harfler[50];

    int *check = malloc((int)strlen(kelimeler[indis])*sizeof(int));
    for (int i=0;i<strlen(kelimeler[indis]);i++) {
        check[i] = 0;
    }

    for (int i=deneme_hakki;i>0;i--) {
        printf("\nHarf giriniz: ");
        scanf(" %c", &harf);
        int harf_tekrar = 0;
        for (int j = 0; j < x; j++) {
            if (harf == harfler[j]) {
                harf_tekrar = 1;
                break;
            }
        }
        if (harf_tekrar) {
            printf("Ayni harfi girdiniz!\n");
            printf("\n%d hakkiniz kaldi.", i-1);
            continue;
        }
        harfler[x] = harf;
        x++;
        harf_ara(kelimeler[indis], harf, check, &check_all);
        if (!check_all) {
            printf("\nKelimeyi dogru tahmin ettiniz!\nKelime: %s", kelimeler[indis]);
            break;
        }
        printf("\n%d hakkiniz kaldi.", i-1);
    }
    if (check_all == 1) {
        printf("\nHakkiniz bitti, kelimeyi tahmin edemediniz.\nKelime: %s", kelimeler[indis]);
    }

    free(check);

    return 0;
}

void harf_ara(char *pword, char letter, int *pcheck, int *pcheck_all) {

    int length = strlen(pword);

    for (int i=0;i<length;i++) {
        if (letter == pword[i]) {
            pcheck[i] = 1;
        }
    }
    for (int i=0;i<length;i++) {
        if (pcheck[i] == 1) {
            printf("%c", pword[i]);
        } 
        else {
            printf("_");
        }
    }
    for (int i=0;i<length;i++) {
        if (pcheck[i] == 0) {
            *pcheck_all = 1;
            break;
        }
        else *pcheck_all = 0;
    }
}

