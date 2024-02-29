#pragma once
#include <iostream>
#include <vector>
#include "Deck.h"
#include "Opponent_Bot.h"

using namespace std;

class Player {
private:
	//arm ��� ���������� ���������� ����� (�� ������� ��������� ������ � 18 ����!!!)
	vector<int> arm;

public:

	// arm_sort() - ��� ������� ����������� ���� �� ����������� �������� ����
	void arm_sort() {
		sort(arm.begin(), arm.end());
	}

	// take_card(Deck& deck) - �������� ��� ������ ����� �� ������ "deck" � ����������� � � ���� ������ "arm"
	void take_card(Deck& deck) {

		arm.push_back(deck.get_card());
		arm_sort();
		cout << "PLAYER  - ";
		cout << " [ ";
		cout_arrray(arm);
		cout << " ] " << endl;
	}

	void zapros_card(Bot_Opponent& oponent) {
		cout << "����� ����� �� ������ ��������? : ";
		int temp;
		cin >> temp;
		cout << endl << "� ��� ���� - " << temp << " ?" << endl;
		
		if (oponent.size() != 0) {
			arm.push_back(oponent.get_card(temp));
		}
	}

	int get_card(int card_number) {
		if (arm.size() != 0) {
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

			int result = arm.back();
			arm.pop_back();
			return result;
		}
	}

	int size() {
		return arm.size();
	}
};