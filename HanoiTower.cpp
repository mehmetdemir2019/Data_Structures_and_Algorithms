#include <iostream>  // Standart giri�/��k�� k�t�phanesini ekler
using namespace std; // std namespace'ini kullan�r																// 1

// Hanoi kulelerini ��zmek i�in recursive bir fonksiyon
// n: ta��nacak disk say�s�
// kaynak: kaynak s�tun																							
// hedef: hedef s�tun																							
// ara: ara s�tun																								
void hanoi(int n, char kaynak, char hedef, char ara) {															//  1
    // Tek disk varsa, kaynaktan hedefe ta��n�r ve i�lem sonlan�r												//	
    if (n == 1) {																								//	1
        cout << "Disk 1 " << kaynak << " sutunundan " << hedef << " sutununa tasiniyor." << endl;				//	1
        return;																									//	1
    }
    // �stteki n-1 diski ara s�tununa ta��r																		//
    hanoi(n - 1, kaynak, ara, hedef);																			//	2^n
    // En b�y�k disk kaynaktan hedefe ta��n�r																	//	
    cout << "Disk " << n << " " << kaynak << " sutunundan " << hedef << " sutununa tasiniyor." << endl;			//	1
    // Ara s�t�ndeki n-1 diski hedef s�tununa ta��r																//
    hanoi(n - 1, ara, hedef, kaynak);																			//	2^n
}

// Ana fonksiyon
int main() {																									//	1
    int diskSayisi = 8; // Ta��nacak disk say�s�																//	1
    hanoi(diskSayisi, 'A', 'C', 'B'); // Hanoi fonksiyonunu �a��r�r												//	2^n
    return 0; // Program� ba�ar�yla sonland�r�r																	//	1
}																												// Zaman: O(2^n) (Worst Case) Alan: O(n)



