#include <iostream>
#include <algorithm>

int c = 0, n = 0;
int h[20000] = { 0 };

int bruteforce();
void init_buffer();
int solve(int left, int right);

using namespace std;
int main()
{
	cin >> c;
	while(c--)
	{
		init_buffer();
		cin >> n;
		for(int i = 0; i < n; i++) cin >> h[i];

		/* We can't use this function in range (20000~~) O(N^2) */
		// cout << (int)bruteforce() << endl; 

		cout << solve(0, n - 1) << endl;
	}
	return 0;
}

void init_buffer()
{
	c = 0, n = 0;
	for(int i = 0; i < 20000; i++)
	{
		h[i] = 0;
	}
	return;
}

int bruteforce()
{
	int ret = 0;

	for(int i = 0; i < n; i++)
	{
		int height = h[i];
		for(int j = i; j < n; j++)
		{
			height = min(height, h[j]);
			ret = max(ret, (j - i + 1) * height);
		}
	}
	return ret;
}

/*
	Recursive Calling Result
	-- Input
	1
	7
	7 1 5 9 6 7 3

	-- Output
	0, 1
	2, 3
	0, 3
	4, 5
	4, 6
	0, 6
*/
int solve(int left, int right)
{
	if (left == right) return h[left];
	// Divide Two Sections, left and right.
	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));

	// cout << (int)left << ", " << (int)right << endl;
	int lower = mid, higher = mid + 1; // If 0, 1 : lower = 0, higher = 1
	int minHeight = min(h[lower], h[higher]);
	
	ret = max(ret, minHeight * 2);
	while (left < lower || higher < right)
	{
		if ((higher != right) && ((lower == left) || (h[higher + 1] > h[lower - 1])))
		{
			higher++;
			minHeight = min(minHeight, h[higher]);
		}
		else
		{
			lower--;
			minHeight = min(minHeight, h[lower]);
		}
		ret = max(ret, minHeight * (higher - lower + 1));
	}
	return ret;
}