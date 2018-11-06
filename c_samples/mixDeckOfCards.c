#include <stdio.h>
#include <stdlib.h>

typedef enum suit
{
    CLUB, DIAMOND, HEART, SPADE
} suit;

typedef enum face
{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, 
    QUEEN, KING, ACE
} face;

typedef struct card
{
    suit s;
    face f;
} card;

void mixDeck (card* deck) {
    int i,iRand;
    card tmp;
    for (i = 52; i > 0 ; i--) {
        iRand=rand()%i;
        tmp = deck[i];
        deck[i] = deck[iRand];
        deck[iRand] = tmp;
    }
}

int main()
{
	card* deck = (card*)malloc(sizeof(card)*52);
	int i=0;
	int face=0;
	int suit=0;
    for (i = 52; i > 0 ; i--) {
        deck[i].f=face++;
        deck[i].s=suit;
        if (face==13) {
            face=0;
            suit++;
        }
    }
    mixDeck(deck);
    for (i = 52; i > 0 ; i--) {
        printf("s=%d,f=%d\n",deck[i].s, deck[i].f);
    }

    return 0;
}

