/*
	Problem : CLOCKSYNC
	 - 12시에 시계 바늘 맞추기
	 - Optimization Problem
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

int n = 0;
unsigned int clock_status[16] = { 0 };
unsigned int orig_status[16] = { 0 };
const int switch_clock[10][5] = 
{
	{0, 1, 2, -1, -1}, {3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1}, {0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12}, {0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1}, {4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};

void init_clock();
bool checkAllStatus();
void return_orig();
void clock_sync();
void print_clock();
bool push_status(const int currentStatus[5]);
int recursiveClock(int swit);

using namespace std;
int main()
{
	cin >> n;
	while(n--)
	{
		clock_sync();
		int minimal = recursiveClock(0);
		cout << (int)minimal << endl;
	}
	return 0;
}

bool checkAllStatus()
{
	for(int i = 0; i < 16; i++)
	{
		if (clock_status[i] != 12) return false;
	}
	return true;
}

int recursiveClock(int swit)
{
	int ret = 9999;

	if (checkAllStatus()) return 0;
	if (swit == 10) return ret;

	for(int i = 0; i < 4; i++)
	{
		ret = min(ret, i + recursiveClock(swit + 1));
		// print_clock();
		push_status(switch_clock[swit]);
	}
	return ret;
}

bool push_status(const int currentStatus[5])
{
	for(int i = 0; i < 5; i++)
	{
		int currentType = currentStatus[i];
		if (currentType == -1) continue;
		if (clock_status[currentType] == 12) clock_status[currentType] = 0;
		clock_status[currentType] += 3;
	}
	return true;
}

void print_clock()
{
	for(int i = 0; i < 16; i++)
	{
		cout << (int)clock_status[i] << " ";
	}
	cout << endl;
	return;
}

void return_orig()
{
	for(int i = 0; i < 16; i++)
	{
		clock_status[i] = orig_status[i];
	}
	return;
}

void clock_sync()
{
	init_clock();
	for(int i = 0; i < 16; i++)
	{
		cin >> clock_status[i];
		orig_status[i] = clock_status[i];
	}
	return;
}

void init_clock()
{
	for(int i = 0; i < 16; i++)
		clock_status[i] = 0;
	return;
}