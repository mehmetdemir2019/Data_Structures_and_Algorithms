#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;

void addFoot(int sayi) {
    struct node* willbeadded;
    willbeadded = (struct node*)malloc(sizeof(struct node));
    willbeadded->data = sayi;
    willbeadded->next = NULL;

    if (head == NULL) {
        head = willbeadded;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = willbeadded;
    }
}

void addBetween(int n, int veri) {
    struct node* willbeadded;
    willbeadded = (struct node*)malloc(sizeof(struct node));
    willbeadded->data = veri;

    temp = head;
    while (temp->next != NULL && temp->data != n) {
        temp = temp->next;
    }

    struct node* temp2 = temp->next;
    temp->next = willbeadded;
    willbeadded->next = temp2;
}

void yazdir() {
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void listeinfo(struct node* head) {
    int i = 1;
    while (head != NULL) {
        printf("%d. Dugumunun Adresi = %p\n", i, head);
        printf("%d. Dugumunun verisi =%d\n", i, head->data);
        printf("%d. Dugumunun Bagli oldugu Durumun Adresi= %p\n\n", i, head->next);
        i++;
        head = head->next;
    }	
}

void print_reversestruct(struct node *head) {
    struct node* head2 = NULL; // Yeni listenin baþýný tutacak adres deðiþkeni
    struct node* temp = head;
    while (temp != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = temp->data;
        newNode->next = head2;
        head2 = newNode;
        temp = temp->next;
    }
    yazdir(head2); // Ters sýralanmýþ listeyi yazdýr
}

int main() {
    int sayi, count = 0, sec, n;
    while (count != 6) {
        printf("\n liste olusturmak icin 1, Araya deger eklemek icin 2, Ters sýralanmýþ listeyi yazdýrmak için 3: \n");
        scanf("%d", &sec);
        switch (sec) {
            case 1:
                printf("\n bir sayi giriniz: \n");
                scanf("%d", &sayi);
                addFoot(sayi);
                count++;
                yazdir();
                break;
            case 2:
                printf("\n hangi dugumden once : \n");
                scanf("%d", &n);
                printf("\n araya eklenecek node degeri : \n");
                scanf("%d", &sayi);
                addBetween(n, sayi);
                yazdir();
                break;
            case 3:
                printf("\nTers sýralanmýþ liste:\n");
                print_reversestruct(head);
                break;
        }
    }
    return 0;
}

