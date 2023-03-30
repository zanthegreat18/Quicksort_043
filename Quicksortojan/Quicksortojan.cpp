#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n=====================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n=====================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
} 

void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;


	pivot = arr[low];

	i = low + 1;
	j = high; 


	while ((arr[1] <= pivot) && (i <= high))
	{
		i++;
		cmp_count++;
	}
	cmp_count++;
}