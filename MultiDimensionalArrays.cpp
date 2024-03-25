#include <iostream>
   		//  21181617001 Mehmet Demir 1. sube
// Tek boyutlu diziyi döngüsel olarak birer birer döndüren fonksiyon
void tekBoyutluDondur(int dizi[], int boyut) {
    int temp;
    for (int i = 0; i < boyut / 2; ++i) {
        temp = dizi[i];
        dizi[i] = dizi[boyut - i - 1];
        dizi[boyut - i - 1] = temp;
    }
}

// Ýki boyutlu diziyi hem satýr hem de sütun bazýnda döngüsel olarak birer birer döndüren fonksiyon
void ikiBoyutluDondur(int dizi[][3], int satir, int sutun) {
    int temp;
    // Satýrlarý döngüsel olarak döndürme
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun / 2; ++j) {
            temp = dizi[i][j];
            dizi[i][j] = dizi[i][sutun - j - 1];
            dizi[i][sutun - j - 1] = temp;
        }
    }
    // Sütunlarý döngüsel olarak döndürme
    for (int j = 0; j < sutun; ++j) {
        for (int i = 0; i < satir / 2; ++i) {
            temp = dizi[i][j];
            dizi[i][j] = dizi[satir - i - 1][j];
            dizi[satir - i - 1][j] = temp;
        }
    }
}

// Diziyi ekrana yazdýran fonksiyon
void diziYazdir(int dizi[][3], int satir, int sutun) {
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            std::cout << dizi[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Tek boyutlu dizi
    int tekBoyutluDizi[] = {1, 5, 8, 3, 27};
    int tekBoyutluBoyut = sizeof(tekBoyutluDizi) / sizeof(tekBoyutluDizi[0]);

    std::cout << "Tek boyutlu dizi orijinal hali: ";
    for (int i = 0; i < tekBoyutluBoyut; ++i) {
        std::cout << tekBoyutluDizi[i] << " ";
    }
    std::cout << std::endl;

    // Tek boyutlu diziyi döndürme
    tekBoyutluDondur(tekBoyutluDizi, tekBoyutluBoyut);

    std::cout << "Tek boyutlu dizi dondurulmus hali: ";
    for (int i = 0; i < tekBoyutluBoyut; ++i) {
        std::cout << tekBoyutluDizi[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Ýki boyutlu dizi
    int ikiBoyutluDizi[3][3] = {{1, 3, 2}, {1, 4, 5}, {3, 4, 2}};
    int satir = sizeof(ikiBoyutluDizi) / sizeof(ikiBoyutluDizi[0]);
    int sutun = sizeof(ikiBoyutluDizi[0]) / sizeof(ikiBoyutluDizi[0][0]);

    std::cout << "Iki boyutlu dizi orijinal hali:" << std::endl;
    diziYazdir(ikiBoyutluDizi, satir, sutun);
    std::cout << std::endl;

    // Ýki boyutlu diziyi döndürme
    ikiBoyutluDondur(ikiBoyutluDizi, satir, sutun);

    std::cout << "Iki boyutlu dizi dondurulmus hali:" << std::endl;
    diziYazdir(ikiBoyutluDizi, satir, sutun);

    return 0;
}

