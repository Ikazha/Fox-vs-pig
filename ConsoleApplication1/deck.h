#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "dop_functions.h"


using namespace std;




class Deck {
private:
	int count_cards = 36;
	//колода карт в неперемешанном состоянии
	vector<int> test = { 6,6,6,6,
					7,7,7,7,
					8,8,8,8,
					9,9,9,9,
					10,10,10,10,
					11,11,11,11,
					12,12,12,12,
					13,13,13,13,
					14,14,14,14 };
	//Структура отвечающая за имена карт (на всякий случай)
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



	//Функция для вывода содержания колоды
	void Print_Deck() {
		for (int i = 0; i < test.size(); i++)
		{
			cout << test[i] << ' ';

		}
	}

	//Фунция для перемешивания колоды
	void shafl() {
		cout << "Перемешиваем колоду";
		for (int i = 0; i < count_cards; i++)
		{
			int rand_num = GetRandomNumber(0, 35);
			int temp = test[rand_num];
			test[rand_num] = test[i];
			test[i] = temp;

			cout << '.';
		}
		cout <<endl<< "Колода перемешанна" << endl << endl;
	}
	int get_card() {
		if (test.size() != 0) {
			int result = test.back();
			test.pop_back();
			return result;
		}
	}
};

class Player {
private:
	//arm Это переменная являющаяся рукой (по дефолту назначать размер в 18 карт!!!)
	vector<int> arm;
	
	vector<int> arm_opponent;
	
public:
	int score_opponent = 0;
	int score = 0;


	void arm_sort_opponent() {
		sort(arm_opponent.begin(), arm_opponent.end());
	}
	void take_card_opponent(Deck& deck)
	{
		arm_opponent.push_back(deck.get_card());
		arm_sort_opponent();
	}
	int get_card_opponent(int card_number) {
		int temp = 0;
		for (int i = 0; i < arm_opponent.size(); i++)
		{
			if (arm_opponent[i] == card_number)
			{
				arm_opponent.erase(arm_opponent.begin() + i);
				temp = card_number;
				cout << endl << "Держите!" << endl;
				break;
			}
		}
		return temp;
	}
	int size_opponent()
	{
		return arm_opponent.size();
	}
	int score_plus_opponent() {
		int temp = arm_opponent.size() - 3;
		if (arm_opponent.size() > 3)
		{
			for (int i = 0; i < temp; i++)
			{
				if (arm_opponent[i] == arm_opponent[i + 3]) {
					score_opponent++;
					removeElements(arm_opponent, arm_opponent[i]);
					break;
				}
			}
		}
		cout<< "Bot score - " << score_opponent;
		return score_opponent;
	}
	void zapros_card_opponent() {
		int random_card = arm_opponent[GetRandomNumber(0, arm.size() - 1)];
		cout << endl << "У вас есть - " << random_card << " ?" << endl;

		if (arm.size() != 0) {
			cout << endl << endl;
			for (int i = 0; i < get_card(random_card); i++)
			{
				arm_opponent.push_back(random_card);
			}

		}
	}
	
	
	
	void cout_arms() {
		cout << "Player   - [";
		cout_arrray(arm);
		cout << "]" << endl<<"Opponent - [";
		cout_arrray(arm_opponent);
		cout << "]";

	}




	// arm_sort() - это функция сортирующая руку по возрастанию значения карт
	void arm_sort() {
		sort(arm.begin(), arm.end());
	}

	// take_card(Deck& deck) - механика для взятия карты из колоды "deck" и перемещения её в руку игрока "arm"
	void take_card(Deck& deck) {

		arm.push_back(deck.get_card());
		arm_sort();
	}

	int get_card(int card_number) {
		
		int temp = 0;
		for (int i = 0; i < arm.size(); i++)
		{
			if (arm[i] == card_number)
			{
				arm.erase(arm.begin() + i);
				temp = card_number;
				cout << endl << "Держите!" << endl;
				break;
			}
		}
		return temp;
	}

	void zapros_card() {
		cout << "Какую карту вы хотите спросить? : ";
		int temp;
		cin >> temp;
		cout << endl << "У вас есть - " << temp << " ?" << endl;

		if (arm_opponent.size() != 0) {
			cout << endl << endl;
			for (int i = 0; i < get_card_opponent(temp); i++)
			{
				arm.push_back(temp);
			}

		}
	}

	int size() {
		return arm.size();
	}

	int score_plus() {
		int temp = arm.size() - 3;
		if (arm.size() > 3)
		{
			for (int i = 0; i < temp; i++)
			{
				if (arm[i] == arm[i + 3]) {
					score++;
					removeElements(arm, arm[i]);
					break;
				}
			}
		}
		cout << "Player score - " << score;
		return score;
	}

	//Opponent chapter------------------------------------------------------------

	
};










