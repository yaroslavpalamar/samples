#include <stdio.h>
#include <stdlib.h>

#define CARD_AMOUNT 52

typedef enum suit
{
 	CLUB, DIAMOND, HEART, SPADE
} suit;

typedef enum face
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
	JACK, QUEEN, KING, ACE
} face;

typedef struct card
{
	suit s;
	face f;
} card;

void mixDeck (card* deck) {
	int i,iRand;
	card tmp;
	for (i = CARD_AMOUNT; i > 0 ; i--) {
		iRand=rand()%i;
		tmp = deck[i];
		deck[i] = deck[iRand];
		deck[iRand] = tmp;
	}
}

void printDeck(const card* deck) {
	for (int i = CARD_AMOUNT; i > 0 ; i--) {
		printf("s=%d,f=%d\n",deck[i].s, deck[i].f);
	} 
}

int main()
{
	card* deck = (card*)malloc(sizeof(card)*CARD_AMOUNT);
	int i=0;
	int face=0;
	int suit=0;
	const int FACE_COUNT = ACE - TWO + 1; // 13 different faces
	for (i = CARD_AMOUNT; i > 0 ; i--) {
		deck[i].f=face++;
		deck[i].s=suit;
		if (face==FACE_COUNT) {
			// if finished with one suit for every face (13) then change suit
			face=0;
			suit++;
		}
	}
	printf("pirnt NOT mixed Deck: \n");
	printDeck(deck);
	
	mixDeck(deck);
	printf("pirnt mixed Deck: \n");
	printDeck(deck);

	return 0;
}

