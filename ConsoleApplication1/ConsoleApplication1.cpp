#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	
	Deck deck;
	Player bob;
	Bot_Opponent bot;

	deck.shafl();
	for (int i = 0; i < 7; i++)
	{
		bob.take_card(deck);
		bot.take_card(deck);
	}
	
	while (true)
	{
		bob.zapros_card(bot);
		bob.take_card(deck);
		bot.take_card(deck);
	    cout << endl << bob.score_plus() << "   " << bot.score_plus() << endl;
	}
	

	
	

}


// список требуемых функций:
/*
	
	1. запрос карты опонентом (прописать логику выбора карты)
	2. прописать сробатывание фраз(мейби через выбор рандомной фразы)
	и тд..............
*/