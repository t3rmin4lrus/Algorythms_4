#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>


#define X 3
#define Y 3

using namespace std;

int KMPAlgo();

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print_arr(size_t const x, size_t const y, int arr[][Y])
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cout << setw(3) << arr[i][j];
		cout << '\n';
	}
}

void BubbleSort(size_t const x, size_t const y, int arr[][Y])
{
	
	size_t const arr_len = x * y;
	
	for (size_t i = 0; i < arr_len; i++) {
		
		for (size_t j = 0; j < x; j++) {
			
			for (size_t k = 0; k < y; k++) {
				size_t next_j = j;
				size_t next_k = k + 1;
				if (k == y - 1) {
					if (j < x - 1) {
						next_j++;
						next_k = 0;
					}
					else if (j == x - 1) {
						// В случае, если элемент последний, то выходим из цикла
						break;
					}
				}
				if (arr[next_j][next_k] < arr[j][k])
					swap(arr[j][k], arr[next_j][next_k]);
			}
		}
	}
}

// алгоритм Трабба-Прадо-Кнута

int KMPAlgo() {

	setlocale(LC_ALL, "Russian");

	vector<double> input(11), results(11);

	cout << "Введите  11 чисел, в одну строку не переходя на следующую строку!" << endl;
	for (int i = 0; i < input.size(); i++) {
		cin >> input[i];
	}

	transform(input.begin(), input.end(), results.begin(),
		[](double n)-> double { return sqrt(abs(n)) + 5 * pow(n, 3); });
	for (int i = 10; i > -1; i--) {
		cout << "f( " << setw(3) << input[i] << " ) : ";

		if (results[i] > 400) {
			cout << "Очень большое число, превышает число 400!" << endl;
		}
		else
		{
			cout << results[i] << " " << "Результат вычисления не превышает число 400! " << endl;
		}
		cout << endl;
	}

	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int arr[X][Y] = {
	{ 1, 9, 2 },
	{ 5, 7, 6 },
	{ 4, 3, 8 }
};
	
	print_arr(X, Y, arr);
	BubbleSort(X, Y, arr);
	cout << "Вывод отсортированного масива:\n";
	print_arr(X, Y, arr);

	int a;
	cout << "Вывод алгоритма Трабба-Пардо-Кнута: " << endl;
	KMPAlgo();
	cin >> a;

	return 0;
}
