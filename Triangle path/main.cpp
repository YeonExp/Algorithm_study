#include <iostream>
#include <algorithm>

int n = 0;
int inputPath[100][100] = { 0 };
int cache_buf[100][100];

void init_buffer();
int triangle_1(int y, int x);
int triangle_2(int y, int x);

using namespace std;
int main()
{
	cin >> n;
	init_buffer();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> inputPath[i][j];
		}
	}
	cout << triangle_1(0, 0) << endl;
	cout << triangle_2(0, 0) << endl;

	return 0;
}

void init_buffer()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			inputPath[i][j] = 0;
			cache_buf[i][j] = -1;
		}
	}
	return;
}

int triangle_1(int y, int x)
{
	int dx = x + 1, dy = y + 1;

	if (y == (n - 1)) return inputPath[y][x];
	int ret = inputPath[y][x];
	ret += max(triangle_1(dy, x), triangle_1(dy, dx));

	return ret;
}

int triangle_2(int y, int x)
{
	if (cache_buf[y][x] != -1) return cache_buf[y][x];
	if (y == (n - 1)) return inputPath[y][x];

	int dx = x + 1, dy = y + 1;
	cache_buf[y][x] = max(triangle_2(dy, x), triangle_2(dy, dx))
		+ inputPath[y][x];

	// cout << (int)y << ", " << (int)x << ", " << (int)cache_buf[y][x] << endl;
	return cache_buf[y][x];
}