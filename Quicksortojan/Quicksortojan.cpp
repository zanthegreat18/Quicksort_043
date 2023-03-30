#include <iostream>
using namespace std;

//membuat array
int arr[20];
int cmp_count = 0; //number of comparison
int mov_count = 0; //number of data movements
int n;

//prosedur input
void input() {

	while (true)
	{
		cout << "Masukkan Panjang Element Array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum Panjang Array Adalah 20" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

//prosedur menukar element di index x dengan index y
void swap(int x, int y) {
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

//prosedur quicksort
void q_sort(int low, int high) {
	int pivot, i, j;
	if (low > high)										//langkah 1
		return;

	//pisah list menjadi dua bagian
	//1 bagian mengandung elemen yang lebih kecil atau sama dengan pivot
	//bagian lain mengandung elemen yang lebih besar dari pivot

	pivot = arr[low];									//langkah 2

	i = low + 1;										//langkah 3
	j = high;											//langkah 4

	while (i <= j) {									//langkah 10
		//mencari elemen yang lebih besar dari pivot
		while ((arr[i] <= pivot) && (i <= high)) {		//langkah 5
			i++;
			cmp_count++;								//langkah 6
		}
		//mencari elemen yang lebih kecil dari pivot
		while ((arr[j] > pivot) && (j >= low)) {		//langkah 7
			j--;
			cmp_count++;								//langkah 8
		}
		cmp_count++;

		if (i < j) { //jika elemen lebih besar di kiri elemen		//langkah 9
			//ubah elemen di indeks 1 dengan elemen indeks j
			swap(i, j);
			mov_count++;
		}
	}
	//j menganduk indeks dari elemen terakhir sorted list
	if (low < j) {													//langkah 11
		//ubah pivot ke posisi yang benar dari list
		swap(low, j);
		mov_count++;
	}
	//urutkan list di kiri menggunakan quick sort
	q_sort(low, j - 1);												//langkah 12

}

//prosedur display
void display() {
	cout << "\n----------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n----------" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of Comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}