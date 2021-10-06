#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int KMPAlgo();

void bubbleSort(int arrSort[], const int SIZE);

void bubbleSort(int arrSort[], const int SIZE) {
	int buffer = 1;
	int f;
	for (int i = 0; i < SIZE - 1; i++)
	{
		f = 0;
		for (int j = SIZE - 1; j > i; j--)
		{
			if (arrSort[j] < arrSort[j - 1])
			{
				buffer = arrSort[j - 1];
				arrSort[j - 1] = arrSort[j];
				arrSort[j] = buffer;
				f = 1;
			}
		}
		if (f == 0)
			break;
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
			cout << results[i] <<" " <<"Результат вычисления не превышает число 400! " << endl;
		}
		cout << endl;
	}

	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int a;

	const int SIZE = 11;

	int arr[SIZE] = { 1,9,2,5,7,6,4,3,8 };

	cout << "Вывод массива: " << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	cout << " " << endl;

	bubbleSort(arr, SIZE);

	cout << "Вывод отсортированного масива:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "Вывод алгоритма Трабба-Пардо-Кнута: " << endl;
	KMPAlgo();
	cin >> a;

	return 0;
}


