#ifndef DECKCARD1
#define DECKCARD1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
	string face;
	string suit;
};

class DeckOfCard1
{
public:
	static const int numberOfCards = 52;
	static const int faces = 13;
	static const int suits = 4;
	DeckOfCard1();
	void shuffle();
	void deal() const;
private:
	vector <Card> deck;
};
#endif 