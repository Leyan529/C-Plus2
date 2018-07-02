#include <iostream>
#include <iomanip>
#include <string>

#include "StructTest\DeckOfCard1.h"

#include "StructTest\DeckOfCard2.h"
using namespace std;

void CardByTypedef();

void displayBits(unsigned); // prototype
void BitWiseTest1();
void BitWiseTest2();

void CardByBitField();


void StructTest() {
	//CardByTypedef();
	//BitWiseTest1();
	//BitWiseTest2();
	CardByBitField();
	system("pause");
}

void CardByTypedef()
{
	DeckOfCard1 cards;
	cards.shuffle();
	cards.deal();
}

void displayBits(unsigned value)
{
	// SHIFT : �n�첾������
	// sizeof(unsigned) : �ƭȩҦ�����byte��
	// 8 * sizeof(unsigned) : �ƭȩҦ�����bit��
	const int SHIFT = 8 * sizeof(unsigned) - 1; 
	const unsigned MASK = 1 << SHIFT; //����SHIFT�Ӧ줸

	cout << setw(10) << value << " = ";

	// display bits
	for (unsigned i = 1; i <= SHIFT + 1; i++)
	{
		// value & MASK : �q���|�۰ʧ�value�ର�G�i��A��&
		cout << (value & MASK ? '1' : '0');
		value <<= 1; // �G�i��value�C�������A�H�K�U����X��@�Ӧ줸

		if (i % 8 == 0) // output a space after 8 bits
			cout << ' ';
	} // end for

	cout << endl;
} // end function displayBits
void BitWiseTest1()
{
	unsigned inputValue; // integral value to print in binary

	cout << "Enter an unsigned integer: ";
	cin >> inputValue;
	displayBits(inputValue);
}
void BitWiseTest2()
{
	unsigned number1;
	unsigned number2;
	unsigned mask;
	unsigned setBits;

	// demonstrate bitwise &
	number1 = 2179876355u;  //�d����
	mask = 1;
	cout << "The result of combining the following\n";
	displayBits(number1);
	displayBits(mask);
	cout << "using the bitwise AND operator & is\n";
	displayBits(number1 & mask);

	// demonstrate bitwise |
	number1 = 15;
	setBits = 241;
	cout << "\nThe result of combining the following\n";
	displayBits(number1);
	displayBits(setBits);
	cout << "using the bitwise inclusive OR operator | is\n";
	displayBits(number1 | setBits);

	// demonstrate bitwise exclusive OR
	number1 = 139;
	number2 = 199;
	cout << "\nThe result of combining the following\n";
	displayBits(number1);
	displayBits(number2);
	cout << "using the bitwise exclusive OR operator ^ is\n";
	displayBits(number1 ^ number2);

	// demonstrate bitwise complement
	number1 = 21845;
	cout << "\nThe one's complement of\n";
	displayBits(number1);
	cout << "is" << endl;
	displayBits(~number1);
}

void CardByBitField()
{
	DeckOfCards deckOfCards; // create DeckOfCards object
	deckOfCards.deal(); // deal the cards in the deck
}
