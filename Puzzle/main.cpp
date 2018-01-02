/*
	Puzzle Algorithm
	 - 학습용
	 - 빈 퍼즐 공간을 L자 모양 퍼즐로 덮을 수 있는 경우의 수
	 - Recursive Function
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, cnt;
int height, width;
char puzzles[50][50], tables[50][50], original[50][50];
const int shapeOfBlock[4][3][2] = 
{
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
}; // Four Types of Block

void read_puzzle(int height, int width);
void init_puzzle();
void delete_negative();
void init_table(int height, int width);
void print_puzzle(int height, int width);
int solvePuzzles(int height, int width);
bool setBlock(int type, int x, int y, int flag);

int main()
{
	cin >> c;
	while(c)
	{
		init_puzzle();

		cin >> height >> width;
		read_puzzle(height, width);
		// print_puzzle(height, width);

		int sum = 0;
		sum = solvePuzzles(height, width);
		cout << sum << endl;
		--c;
	}
	return 0;
}

int solvePuzzles(int height, int width)
{
	if (cnt % 3) return 0;

	int x = -1, y = -1;
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if (tables[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (x != -1 || y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for(int i = 0; i < 4; i++)
	{
		if (setBlock(i, x, y, 1)) {
			ret += solvePuzzles(height, width);
		}
		setBlock(i, x, y, -1);
		delete_negative();
	}
	return ret;
}

bool setBlock(int type, int x, int y, int flag)
{
	bool status = true;
	for(int i = 0; i < 3; i++)
	{
		const int dy = y + shapeOfBlock[type][i][0];
		const int dx = x + shapeOfBlock[type][i][1];

		if (dy < 0 || dx < 0 || dy >= height || dx >= width) status = false;
		else if((tables[dy][dx] += flag) > 1) status = false;
	}
	// print_puzzle(height, width);
	// getchar();
	return status;
}

void delete_negative()
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if (tables[i][j] < 0) tables[i][j] = 0;
		}
	}
	return;
}

void read_puzzle(int height, int width)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			char c;
			cin >> c;
			puzzles[i][j] = c;
			if (c == '.') {
				tables[i][j] = 0;			// Empty : 0
				cnt++;
			}
			else
			{
				tables[i][j] = 1;			// Black Block : 1
			}
		}
	}
}

void init_table(int height, int width)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			tables[i][j] = original[i][j];
		}
	}
	return;
}

void init_puzzle()
{
	cnt = 0;
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			puzzles[i][j] = 0;
		}
	}
	return;
}

void print_puzzle(int height, int width)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			cout << (int)tables[i][j] << " ";
		}
		cout << endl;
	}
}