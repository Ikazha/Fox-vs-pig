#include <iostream>
#include <vector>
#include "Header.h"

//#include "Deck.h"
//#include "Player.h"
//#include "Opponent_Bot.h"




using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	

	Deck deck;
	Player bob;
	Bot_Opponent bot;

	deck.shafl();
	while (true)
	{
		bob.take_card(deck);
		bob.zapros_card(bot);
		bot.take_card(deck);
	    cout << endl << bob.score_plus() << "   " << bot.score_plus() << endl;
	}
	

	
	

}


// список требуемых функций:
/*
	1. передача карт из рук в руки
	2. запрос карты игроком
	3. запрос карты опонентом (прописать логику выбора карты)
	4. прописать сробатывание фраз(мейби через выбор рандомной фразы)
	и тд..............
*/