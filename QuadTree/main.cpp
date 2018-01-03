#include <iostream>
#include <algorithm>

int pointer = 0;
int count_t = 0;
char data[1000] = { 0 };
char reverse_data[1000] = { 0 };

void reverse_plate(int idx);
void getPointer(int point, int data2[4])	;
void init_buffer();

using namespace std;
int main()
{
	int c = 0;

	cin >> c;
	if (c <= 50)
	{
		while(c--)
		{
			init_buffer();
			cin >> data;
			reverse_plate(0);
			cout << reverse_data << endl;
		}
	}
	return 0;
}
// xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
void getPointer(int point, int data2[4])	
{
	int dx = 0;
	for(int i = point, j = 0; j < 4; i++)
	{
		if (dx != 0)
		{
			dx--;
		}
		else
		{
			data2[j] = i;
			j++;
		}
		if (data[i] == 'x') dx += 4;
	}
}

void reverse_plate(int idx)
{
	int point[4] = { 0 };

	if (data[idx] == 'x')
	{
		reverse_data[count_t] = data[idx];
		count_t++;

		getPointer(idx + 1, point);
		/* for(int i = 0; i < 4; i++)
		{
			cout << (int)point[i] << endl;
		}*/
		reverse_plate(point[2]);
		reverse_plate(point[3]);
		reverse_plate(point[0]);
		reverse_plate(point[1]);
	}
	else
	{
		reverse_data[count_t] = data[idx];
		count_t++;
	}
}

void init_buffer()
{
	for(int i = 0; i < 1000; i++)
	{
		count_t = 0;
		data[i] = 0;
		reverse_data[i] = 0;
	}
	return;
}