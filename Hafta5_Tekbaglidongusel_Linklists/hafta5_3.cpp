#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct n{
	int x;
	n *next;
};typedef n node;

void printOneWayList(node *r){
	while(r!=NULL){
		printf("%d ", r->x);
		r=r->next;
	}
}

node *nodeRemove(node *r, int x){
	node *temp;
	node *iter = r;
	
	if(r->x == x){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while(iter->next!=NULL && iter->next->x != x){
		iter = iter->next;
	}
	
	if(iter->next == NULL){
		printf("Sayi Bulunamadi");
		return r;
	}
	
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main(int argc, char** argv) {
	
	node *root;
	root = (node*)malloc(sizeof(node));
	node *iter;
	iter = root;
	
	int i;
	
	for(i=1; i<=15; i++){
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;
		iter->x = i*10;
		iter->next = NULL;
	}
	
	printf("\nBagli Liste\n");
	printOneWayList(root);
	int key;
	printf("\nSilmek istediginiz dugum : \n");
	scanf("%d", &key);
	nodeRemove(root, key);
	printf("\nBagli Liste\n");
	printOneWayList(root);
	
}
