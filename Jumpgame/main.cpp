#include <iostream>
#include <algorithm>

using namespace std;
int puzzles[100][100] = { 0 };
int cache[100][100] = { 0 };
int n = 0;

bool solve(int y, int x);
int cache_solve(int y, int x);
void init_cache();

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> puzzles[i][j];
		}
	}

	init_cache();

	/* First Case */
	if (solve(0, 0))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	/* Second Case */
	if (cache_solve(0, 0))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

bool solve(int y, int x)
{
	int dx = x + puzzles[y][x];
	int dy = y + puzzles[y][x];

	if ((y == (n - 1)) && (x == (n - 1))) return true;
	if ((y >= n) || (x >= n)) return false;
	
	return solve(y, dx) || solve(dy, x);
}

int cache_solve(int y, int x)
{
	if ( (y == (n - 1)) && (x == (n - 1)) ) return 1;
	if ( (x >= n) || (y >= n) ) return 0;

	int dy = y + puzzles[y][x];
	int dx = x + puzzles[y][x];

	if (cache[y][x] != -1) return cache[y][x];

	return (cache[y][x] = (cache_solve(dy, x) || cache_solve(y, dx)));
}

void init_cache()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cache[i][j] = -1;
		}
	}
	return;
}