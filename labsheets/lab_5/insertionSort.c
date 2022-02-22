#include "insertionSort.h"

void InsertInOrder(CreditCard * cards, int n, CreditCard newcard);
void InsertionSort(CreditCard * cards,int n);

void InsertionSort(CreditCard * cards, int n) {
    if(n==0) {
		top_of_stack = &n;
		return;
	}
	InsertionSort(cards,n-1);
	InsertInOrder(cards,n,cards[n-1]);
}

void InsertInOrder(CreditCard * cards, int n, CreditCard newcard){
	CreditCard card = newcard;
	CreditCard tempcard;
	for(int i=0;i<n;i++){
		if(card.cno < cards[i].cno || i==n-1){
			tempcard = card;
			card = cards[i];
			cards[i] = tempcard;
		}
	}
}