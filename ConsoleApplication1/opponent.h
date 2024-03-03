#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "dop_functions.h"


using namespace std;
class Player;



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
		cout << "Перемешиваем колоду..." << endl;
		for (int i = 0; i < count_cards; i++)
		{
			int rand_num = GetRandomNumber(0, 35);
			int temp = test[rand_num];
			test[rand_num] = test[i];
			test[i] = temp;

			Print_Deck();
			cout << "    - " << rand_num << endl;
		}
		cout << "Колода перемешанна" << endl << endl;
	}
	int get_card() {
		int result = test.back();
		test.pop_back();
		return result;

	}
};

class Bot_Opponent
{
private:
	vector<int> arm;
	int score = 0;

public:
	void arm_sort()
	{
		sort(arm.begin(), arm.end());
	}

	void take_card(Deck& deck)
	{
		arm.push_back(deck.get_card());
		arm_sort();
		cout << "OPONENT - ";
		cout << " [ ";
		for (int i = 0; i < arm.size(); i++)
		{
			cout << arm[i] << " ";
		}
		cout << " ] " << endl;
	}

	int get_card(int card_number) {
		int temp = 0;
		cout << "size - " << arm.size() << endl;
		for (int i = 0; i < arm.size(); i++)
		{
			cout << "chek position arm - " << i << endl;
			if (arm[i] == card_number)
			{
				cout << "FIND" << endl;
				arm.erase(arm.begin() + i);
				temp = card_number;
				cout_arrray(arm);
				break;
			}
			else
			{
				cout << "Not FIND" << endl;

			}
		}
		return temp;
	}

	int check_card(int card_number) {
		int temp = 0;
		cout << "Check size - " << arm.size() << endl;
		for (int i = 0; i < arm.size(); i++)
		{
			cout << i << endl;
			if (arm[i] == card_number)
			{
				cout << "FIND" << endl;
				temp++;
				break;
			}
			else
			{
				cout << "Not FIND" << endl;

			}
		}
		return temp;
	}

	int size()
	{
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
					cout << endl << arm[i] << endl;
					removeElements(arm, arm[i]);
					break;
				}
			}
		}
		cout << endl << "Bot score - " << score << endl;
		return score;
	}

	void zapros_card(Player& layer) {
		int random_num_card = GetRandomNumber(0, arm.size() - 1);
		cout << endl << "У вас есть - " << random_num_card << " ?" << endl;

		if (layer.size() != 0) {
			cout << endl << endl;
			for (int i = 0; i < layer.get_card(random_num_card); i++)
			{
				arm.push_back(random_num_card);
			}

		}
	}
};

class Player {
private:
	//arm Это переменная являющаяся рукой (по дефолту назначать размер в 18 карт!!!)
	vector<int> arm;
	int score = 0;

public:

	// arm_sort() - это функция сортирующая руку по возрастанию значения карт

	void arm_sort() {
		sort(arm.begin(), arm.end());
	}

	// take_card(Deck& deck) - механика для взятия карты из колоды "deck" и перемещения её в руку игрока "arm"
	void take_card(Deck& deck) {

		arm.push_back(deck.get_card());
		arm_sort();
		cout << "PLAYER  - ";
		cout << " [ ";
		cout_arrray(arm);
		cout << " ] " << endl;
	}



	int get_card(int card_number) {
		for (int i = 0; i < arm.size(); i++)
		{
			if (arm[i] == card_number)
			{
				int a = arm.back();
				arm[arm.size() - 1] = arm[i];
				arm[i] = a;
				break;
			}
		}
		if (arm.back() == card_number)
		{
			int result = arm.back();
			arm.pop_back();
			return result;
		}
	}

	void zapros_card(Bot_Opponent& oponent) {
		cout << "Какую карту вы хотите спросить? : ";
		int temp;
		cin >> temp;
		cout << endl << "У вас есть - " << temp << " ?" << endl;

		if (oponent.size() != 0) {
			cout << endl << endl;
			for (int i = 0; i < oponent.get_card(temp); i++)
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
					cout << endl << arm[i] << endl;
					removeElements(arm, arm[i]);
					break;
				}
			}
		}
		cout << endl << "Player score - " << score << endl;
		return score;
	}
};






