#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

void cout_arrray(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "  |" << arr[i] << "|  ";
	}
}
void removeElements(vector<int>& vec, int valueToDelete) {
	vec.erase(remove(vec.begin(), vec.end(), valueToDelete), vec.end());
}

int GetRandomNumber(int min, int max)
{
	Sleep(500);
	srand(time(NULL) * rand());
	int num = min + rand() % (max - min + 1);

	return num;

}
/*
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
}*/