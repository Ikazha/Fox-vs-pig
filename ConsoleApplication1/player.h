#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "dop_functions.h"
#include "opponent.h"

using namespace std;
class Deck;
class Bot_Opponent;


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