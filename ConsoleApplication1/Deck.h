#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "Opponent_Bot.h"



using namespace std;
int GetRandomNumber(int min, int max);
void cout_arrray(vector<int> arr);




//класс отвечающий за колоду карт икарт содержищихс€ в них
class Deck {
private:
	int count_cards = 36;
	//колода карт в неперемешанном состо€нии
	vector<int> test = { 6,6,6,6,
					7,7,7,7,
					8,8,8,8,
					9,9,9,9,
					10,10,10,10,
					11,11,11,11,
					12,12,12,12,
					13,13,13,13,
					14,14,14,14 };
	//—труктура отвечающа€ за имена карт (на вс€кий случай)
	struct Deck_cards
	{
		int six = 6;
		int seven = 7;
		int eight = 8;
		int nine = 9;
		int ten = 10;
		int jack = 11;
		int qeen = 12;
		int king = 13;
		int ace = 14;
	};
	

public:
	

	
	//‘ункци€ дл€ вывода содержани€ колоды
	void Print_Deck() {
		for (int i = 0; i < test.size(); i++)
		{
			cout << test[i] << ' ';

		}
	}

	//‘унци€ дл€ перемешивани€ колоды
	void shafl() {
		cout << "ѕеремешиваем колоду..." << endl;
		for (int i = 0; i < count_cards; i++)
		{
			int rand_num = GetRandomNumber(0, 35);
			int temp = test[rand_num];
			test[rand_num] = test[i];
			test[i] = temp;

			Print_Deck();
			cout << "    - " << rand_num << endl;
		}
		cout << " олода перемешанна" << endl << endl;
	}
	int get_card() {
		int result = test.back();
		test.pop_back();
		return result;
		
	}
};









void cout_arrray(vector<int> arr) {
	for ( int i = 0; i < arr.size(); i++)
	{
		cout << "  |" << arr[i] << "|  ";
	}
}

int GetRandomNumber(int min, int max)
{	
	Sleep(500);
	srand(time(NULL)* rand());
	int num = min + rand() % (max - min + 1);
	
	return num;
	
}

