#include <iostream>
#include <algorithm>

int n, m;
const int MAX_SIZE = 100;
int cache[MAX_SIZE][MAX_SIZE * 2];
int solve_noCache(int day, int height);
int solve_Cache(int day, int height);
void init_buffer();

using namespace std;
int main()
{
	cin >> m;
	cin >> n;

	init_buffer();

	cout << solve_noCache(0, 0) << endl;
	cout << solve_Cache(0, 0) << endl;

	return 0;
}

void init_buffer()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 200; j++)
		{
			cache[i][j] = -1;
		}
	}
	return;
}

int solve_noCache(int day, int height)
{
	if (day == m)
	{
		if (height >= n) return 1;
		else return 0;
	}
	int ret = solve_noCache(day + 1, height + 1) + 
		solve_noCache(day + 1, height + 2);
	return ret;
}

int solve_Cache(int day, int height)
{
	if (day == m)
	{
		if (height >= n) return 1;
		else return 0;
	}
	int& ret = cache[day][height];
	if (ret != -1) return ret;

	return ret = (solve_Cache(day + 1, height + 1),
				  solve_Cache(day + 1, height + 2)
				);
}