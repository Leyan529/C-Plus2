#include "DeckOfCard1.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iomanip>



DeckOfCard1::DeckOfCard1():deck(numberOfCards)
{
	static string suit[suits] = { "Hearts","Diamonds","Clubs","Spades" };
	static string face[faces] = { "Ace","Deuce","Three","Four","Five",
	"Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	for (int i = 0; i < numberOfCards; i++) {
		deck[i].face = face[i % faces];
		deck[i].suit = suit[i / faces];
	}
	srand(time(0));
}

void DeckOfCard1::shuffle() //¬~µP
{
	for (int i = 0; i < numberOfCards; i++) {
		int j = rand() % numberOfCards;
		/*Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;*/
		swap(deck[i], deck[j]);
	}
}

void DeckOfCard1::deal() const
{
	for (int i = 0; i < numberOfCards; i++)
		cout << right << setw(5) << deck[i].face << " of "
		<< left << setw(8) << deck[i].suit
		<< ((i + 1) % 2 ? '\t' : '\n');
}


