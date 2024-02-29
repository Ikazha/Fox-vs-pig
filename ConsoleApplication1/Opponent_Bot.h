#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Deck.h"
#include "Player.h"

using namespace std;

class Bot_Opponent
{
private:
    vector<int> arm;

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

    
    int get_card(int card_number)
    {
        if (arm.size() != 0)
        {
            for (int i = 0; i < arm.size(); i++)
            {
                if (arm[i] == card_number)
                {
                    int a = arm.back();
                    arm[arm.size() - 1] = arm[i];
                    arm[i] = a;
                }
            }

            int result = arm.back();
            arm.pop_back();
            return result;
        }
    }

    int size()
    {
        return arm.size();
    }
};