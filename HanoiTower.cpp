#include <iostream>  // Standart giriþ/çýkýþ kütüphanesini ekler
using namespace std; // std namespace'ini kullanýr																// 1

// Hanoi kulelerini çözmek için recursive bir fonksiyon
// n: taþýnacak disk sayýsý
// kaynak: kaynak sütun																							
// hedef: hedef sütun																							
// ara: ara sütun																								
void hanoi(int n, char kaynak, char hedef, char ara) {															//  1
    // Tek disk varsa, kaynaktan hedefe taþýnýr ve iþlem sonlanýr												//	
    if (n == 1) {																								//	1
        cout << "Disk 1 " << kaynak << " sutunundan " << hedef << " sutununa tasiniyor." << endl;				//	1
        return;																									//	1
    }
    // Üstteki n-1 diski ara sütununa taþýr																		//
    hanoi(n - 1, kaynak, ara, hedef);																			//	2^n
    // En büyük disk kaynaktan hedefe taþýnýr																	//	
    cout << "Disk " << n << " " << kaynak << " sutunundan " << hedef << " sutununa tasiniyor." << endl;			//	1
    // Ara sütündeki n-1 diski hedef sütununa taþýr																//
    hanoi(n - 1, ara, hedef, kaynak);																			//	2^n
}

// Ana fonksiyon
int main() {																									//	1
    int diskSayisi = 8; // Taþýnacak disk sayýsý																//	1
    hanoi(diskSayisi, 'A', 'C', 'B'); // Hanoi fonksiyonunu çaðýrýr												//	2^n
    return 0; // Programý baþarýyla sonlandýrýr																	//	1
}																												// Zaman: O(2^n) (Worst Case) Alan: O(n)



