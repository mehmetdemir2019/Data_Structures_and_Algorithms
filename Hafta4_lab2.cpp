#include <stdio.h>
#include <stdlib.h> // malloc ve free i�in
#include <string.h>

// Personel tipi tan�m�
struct Personel {
    char adSoyad[50];
    int sicilNo;
    float maas;
    struct Personel* next;
};

// Ba�l� liste i�lemleri s�n�f�
struct BagliListe {
    struct Personel* head;
};

// Ba�l� liste ba�latma fonksiyonu
void BagliListeBaslat(struct BagliListe* liste) {
    liste->head = NULL;
}

// Personel ekleme fonksiyonu
void personelEkle(struct BagliListe* liste, char* adSoyad, int sicilNo, float maas) {
    struct Personel* yeniPersonel = (struct Personel*)malloc(sizeof(struct Personel)); // Malloc ile bellek tahsisi
    strcpy(yeniPersonel->adSoyad, adSoyad);
    yeniPersonel->sicilNo = sicilNo;
    yeniPersonel->maas = maas;
    yeniPersonel->next = NULL;

    if (liste->head == NULL) {
        liste->head = yeniPersonel;
    } else {
        struct Personel* temp = liste->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = yeniPersonel;
    }
}

// Personel arama fonksiyonu (sicil numaras�na g�re)
struct Personel* sicilNoAra(struct BagliListe* liste, int sicilNo) {
    struct Personel* temp = liste->head;
    while (temp != NULL) {
        if (temp->sicilNo == sicilNo) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Personel arama fonksiyonu (ad-soyada g�re)
void adSoyadAra(struct BagliListe* liste, char* adSoyad) {
    struct Personel* temp = liste->head;
    while (temp != NULL) {
        if (strcmp(temp->adSoyad, adSoyad) == 0) {
            printf("Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", temp->adSoyad, temp->sicilNo, temp->maas);
        }
        temp = temp->next;
    }
}

// Liste ekrana yazd�rma fonksiyonu
void listele(struct BagliListe* liste) {
    struct Personel* temp = liste->head;
    while (temp != NULL) {
        printf("Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", temp->adSoyad, temp->sicilNo, temp->maas);
        temp = temp->next;
    }
}

// Belle�i serbest b�rakma fonksiyonu
void bellekBosalt(struct BagliListe* liste) {
    struct Personel* temp = liste->head;
    while (temp != NULL) {
        struct Personel* gecici = temp;
        temp = temp->next;
        free(gecici); // Malloc ile tahsis edilen belle�i serbest b�rakma
    }
    liste->head = NULL;
}

// Yeni personel ekleme fonksiyonu
void yeniPersonelEkle(struct BagliListe* liste) {
    char adSoyad[50];
    int sicilNo;
    float maas;
    char devam;

    do {
        printf("Yeni personel bilgilerini girin:\n");
        printf("Ad-Soyad: ");
        getchar(); // Bo�luk karakterini temizle
        fgets(adSoyad, sizeof(adSoyad), stdin);
        printf("Sicil No: ");
        scanf("%d", &sicilNo);
        printf("Maas: ");
        scanf("%f", &maas);

        personelEkle(liste, adSoyad, sicilNo, maas);

        printf("\nEkleme islemine devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');
}

int main() {
    struct BagliListe liste;

    // Ba�lang��ta haz�r personel bilgileri ekleniyor
    BagliListeBaslat(&liste);
    personelEkle(&liste, "Ahmet Yilmaz", 123456, 5000);
    personelEkle(&liste, "Ayse Kaya", 234567, 6000);
    personelEkle(&liste, "Mehmet Demir", 345678, 7000);
    personelEkle(&liste, "Fatma Yildiz", 456789, 8000);

    // Listeyi ekrana yazd�rma
    printf("\nEklemeden Onceki Liste:\n");
    listele(&liste);

    // Klavyeden yeni personel ekleme fonksiyonunu �a��rma
    yeniPersonelEkle(&liste);

    // Sicil numaras�na g�re personel arama
    int arananSicilNo = 123456;
    printf("Sicil No %d olan personel: ", arananSicilNo);
    struct Personel* arananPersonel = sicilNoAra(&liste, arananSicilNo);
    if (arananPersonel != NULL) {
        printf("Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", arananPersonel->adSoyad, arananPersonel->sicilNo, arananPersonel->maas);
    } else {
        printf("Personel bulunamadi.\n");
    }

    // Ad-soyada g�re personel arama
    printf("\nAd-Soyad arama sonuclari:\n");
    adSoyadAra(&liste, "Mehmet Demir");

    // Listeyi ekrana yazd�rma
    printf("\nTum personeller:\n");
    listele(&liste);

    // Belle�i temizle
    bellekBosalt(&liste);

    return 0;
}

