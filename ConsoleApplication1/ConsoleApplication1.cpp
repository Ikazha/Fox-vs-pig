#include <iostream>
#include <vector>
//#include "opponent.h"
#include "deck.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	
	Deck deck;
	Player bob;
	/*
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
		bot.zapros_card(bob);
		bob.take_card(deck);
		bot.take_card(deck);
	    cout << endl << bob.score_plus() << "   " << bot.score_plus() << endl;
	}*/
	
	deck.shafl();
	for (int i = 0; i < 7; i++)
	{
		bob.take_card(deck);
		bob.take_card_opponent(deck);
	}
	while (bob.score != 4 and bob.score_opponent != 4)
	{
		cout << endl << "ваши карты" << endl;
		bob.cout_arms();

		cout << endl << "Выбор карты" << endl;
		
		bob.zapros_card();
		bob.zapros_card_opponent();

		cout << endl << "Взятие карты" << endl;

		bob.take_card(deck);
		bob.take_card_opponent(deck);

		cout << endl << "ваши карты" << endl;
		bob.cout_arms();

		cout << endl << "      Счёт :" << endl;
		bob.score_plus();
		cout << "   ";
		bob.score_plus_opponent();
		cout << endl;
		
	}
	if (bob.score_plus() == 4)
	{
		cout << "Победил Игрок!" << endl;
	}
	else
	{
		cout << "Победил Оппонент!" << endl;
	}


	
	

}


// список требуемых функций:
/*
* в данной версии актуальны только файлы: deck.h ,
										  dop_functions.h , 
										  ConsoleApplication1.cpp
	
	1. оптимизация процессов 
	2. прописать сробатывание фраз(мейби через выбор рандомной фразы)
	3. подключить графику
	4. допрописать логигу выбора карты (карты должны браться только когда игрок 
	                                    или опонентне угадывает карту, а когда 
										угодает - делает ещё один ход)
	и тд..............
*/