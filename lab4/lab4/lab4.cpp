// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите номер задания из 4 лабораторной  ";
	cin >> n;

	if (n == 1) 
	{
		int koll = 0;
		const int z = 20;
		char new_elem;
		char not_converted_array[z]{}, converted_array[z]{};
		


		for (int i = 0; i < z; i++)
		{
			cout << "Ведите элементы массива  " << i << "\n ";
			cin >> new_elem;
			not_converted_array[i] = new_elem;
		}

		for (int w = 0; w < z; w++)
		{
			if (isdigit(not_converted_array[w]))
			{
				converted_array[koll] = not_converted_array[w];
				koll += 1;
			}
		}
		for (int w = 0; w < z; w++)
		{
			if (!isdigit(not_converted_array[w]))
			{
				converted_array[koll] = not_converted_array[w];
				koll += 1;
			}
		}
		for (int q = 0; q < z; q++)  cout << converted_array[q] << " ";

		return 0;

	}

	if (n == 3)
	{
		const int n = 20; 
		int count[256] = { 0 }; 
		int arr[n];
		int new_elem;
		int max_znach[256] = {};
		int max = 0, max_chislo = 0;

		for (int i = 0; i < n ; i++)
		{
			cout << "Ведите элементы массива  " << i << "\n ";
			cin >> new_elem;
			arr[i] = new_elem;
		}

		for (int i = 0; i < n; i++) {
			count[arr[i]]++;
		}

		for (int i = 0; i < 256; i++) {
			if (count[i] > 0) {
				cout << "Символ '" << int(i) << "' число " << count[i] << " колличество ." << endl;
				if (count[i] > max) {
					max = count[i];
					max_chislo = int(i);
				}
			}
		}

		cout << "Максимальное значение =   '" << max_chislo << endl;

		return 0;

	}

	if (n == 7)
	{
		int koll = 0;
		const int z = 20;
		int new_elem,m=0;
		int not_converted_array[z]{}, converted_array[z]{};

		cout << "Ведите шаг смещения  " << "\n ";
		cin >> m;

		m = z - m;

		for (int i = 0; i < z; i++)
		{
			cout << "Ведите элементы массива  " << i << "\n ";
			cin >> new_elem;
			not_converted_array[i] = new_elem;
		}

		for (int i = m; i < z; i++)
		{
			converted_array[koll] = not_converted_array[i];
			koll++;
		}


		for (int i = 0; i < m; i++)
		{
			converted_array[koll] = not_converted_array[i];
			koll++;
		}

		
		for (int q = 0; q < z; q++)  cout << converted_array[q] << " ";
		cout << "\n";

		return 0;

	}

	if (n == 9 )
	{
		const int n = 10;
		char array[n];
		char new_el;
		char number[n] = {};
		char sim[n] = {};
		int k1 = 0;
		int k2 = 0;

		for (int i = 0; i < n; i++)
		{
			cout << "Введите эл массива " << i << endl;
			cin >> new_el;
			array[i] = new_el;
		}

		for (int i = 0; i < n; i++)
		{
			if (isdigit(array[i]))
			{
				number[k1] = array[i];
				k1++;
			}
			else
			{
				sim[k2] = array[i];
				k2++;
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++)

			cout << "Элемент массива из чисел " << i << " = " << number[i] << setw(50) << " Элемент массива из символов " << i << " = " << sim[i] << endl;
	}

	if (n == 10 )
	{
		
		int j = 0;
		char new_el;
		int n = 20;


		cout << "Введите колл эл  " << endl;
		cin >> n;
		int* array = new int[n];
		int* array_swap = new int[n];

		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент массива: " << i << endl;
			cin >> new_el;
			array[i] = new_el;
			array_swap[i] = new_el;
		}

		for (int i = 0; i < n / 2; i++)
		{
			swap(array_swap[i], array_swap[(n - i) - 1]);
		}


		for (int i = 0; i < n; i++) cout << "Элемент массива array " << array[i] << setw(50) << " Элемент массива swap " << array_swap[i] << endl;

		cout << "\n";

		for (int i = 0; i < n; i++)
		{
			if (array[i] == array_swap[i]) j++;
		}
		if (j == n) cout << "Массив симметричен" << endl;
		else cout << "Массив несимметричен" << endl;

		return 0;

	}


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
