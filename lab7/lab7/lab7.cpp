// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>



using namespace std;

int main()
{
	setlocale(0, "");
	
	int num_of_lab;

	cout << "Введите номер лабораторной: ";
	cin >> num_of_lab;
	cin.ignore();

	if (num_of_lab == 1){

		struct Data1 {
			string FIO;
			string adress;
			int skidka;
		};
		
		vector<Data1>data_vec;


		int koll_client;	

		cout << "Введите кол-во постоянных клиентов: ";
		cin >> koll_client;
		cin.ignore();

		for (int i = 0; i < koll_client; i++) {

			string FIO;
			string adress;
			int skidka;

		
		
			cout << "Введите ФИО покупателя: \n";
			getline(cin, FIO);

			cout << "Введите адрес покупателя: \n";
			getline(cin, adress);

			cout << "Введите скидку покупателя: \n";
			cin >> skidka;
			cin.ignore();



			if (cin.fail()) {
				cout << "Вы ввели значения не того типа" << endl;
				return 1; 
			}
	

			data_vec.push_back({ FIO, adress, skidka });

		}


		for (int i = 0; i < data_vec.size(); i++) {
			for (int j = i + 1; j < data_vec.size(); j++) {
				if (data_vec[i].FIO == data_vec[j].FIO || data_vec[i].adress == data_vec[j].adress) {
					data_vec.erase(data_vec.begin() + j);
					j--;
				}
			}
		}




		for (int i = 0; i < data_vec.size(); i++) {

			cout << "ФИО "  << i+1 << "покупателя   " << data_vec[i].FIO<< "\n";
			cout << "Адрес " << i+1 << "покупателя   " << data_vec[i].adress << "\n";
			cout << "Скидка " << i+1 << "покупателя   " << data_vec[i].skidka << "\n";
		}
	}

	if (num_of_lab == 3) {

		struct Data3 {
			string FIO;
			int group;
			int sr_ball;
			int money_for_one;
		};

		vector <Data3> data_vec;
		int koll_student;
		int min_money;


		cout << "Введите количество студентов и программа выдаст сначала с людей с дохдом меньше двух минимальных на члена семьи, а потом по убыванию баллов \n";
		cin >> koll_student;
		cin.ignore();

		cout << "Введите текущую минимальную заработную плату  \n";
		cin >> min_money;
		cin.ignore();

			for (int i = 0; i < koll_student; i++) {

				string FIO;
				int group;
				int sr_ball;
				int money_for_one;

				cout << "Введите ФИО  " << i + 1 << " студента \n";
				getline(cin, FIO);

				cout << "Введите группу " << i + 1 << " студента \n";
				cin >> group;
				cin.ignore();


				cout << "Введите средний балл " << i + 1 << " студента \n";
				cin >> sr_ball;
				cin.ignore();


				cout << "Введите доход на одного члена семьи " << i + 1 << " студента \n";
				cin >> money_for_one;
				cin.ignore();


				data_vec.push_back({ FIO, group,sr_ball,money_for_one });

			}

			cout << " \n\n";
			cin.ignore();

			vector<int> min_money_ind;

			for (int i = 0; i < koll_student; i++) {
				if (data_vec[i].money_for_one < (2 * min_money)) {
					cout << data_vec[i].FIO  << " проодит из-за маленького дохода семьи \n";
					min_money_ind.push_back(i);
				}

			}

			for (int i = 0; i < koll_student; i++) {
				bool flag = true;
				for (int j = 0; j < min_money_ind.size(); j++) {
					if (i == min_money_ind[j]) { 
						flag = false;
						break;
					}
				}
				if (flag == true) {
					for (int o = 0; o < koll_student; o++) {
						if (data_vec[i].sr_ball > data_vec[o].sr_ball)
							swap(data_vec[i], data_vec[o]);
					}

				}
			}


			for (int i = 0; i < koll_student; i++) {
				bool flag = true;
				for (int j = 0; j < min_money_ind.size(); j++) {
					if (i == j) {
						flag = false;
						break;
					}
				}
				if (flag == true) {
					cout << data_vec[i].FIO << "   " << data_vec[i].sr_ball << "\n";
				}


			}


	}

	if (num_of_lab == 7) {

		struct Data7_people {
			string FIO;
			int high;
			int year;
			int kg;
			int game_number;
		};

		struct Data7_group {
			string country;
			string group_name;
			vector<Data7_people> people;
			int sr_year;
		};

		vector<Data7_group> data_group_vec;
		int koll_group;

		cout << "Введите количество групп: ";
		cin >> koll_group;
		cin.ignore();

		for (int i = 0; i < koll_group; i++) {
			vector<Data7_people> data_people_vec;
			int koll_sportsmen;

			string country;
			string group_name;
			int sr_year = 0;

			cout << "Введите страну команды номер " << i + 1 << ": ";
			getline(cin, country);

			cout << "Введите название группы номер " << i + 1 << ": ";
			getline(cin, group_name);

			cout << "Введите количество спортсменов в группе " << i + 1 << ": ";
			cin >> koll_sportsmen;
			cin.ignore();

			if (cin.fail()) {
				cout << "Вы ввели значения неправильного типа" << endl;
				return 1;
			}

			for (int j = 0; j < koll_sportsmen; j++) {
				string FIO;
				int high;
				int year;
				int kg;
				int game_number;

				cout << "Введите ФИО " << j + 1 << " спортсмена: ";
				getline(cin, FIO);

				cout << "Введите рост " << j + 1 << " спортсмена: ";
				cin >> high;
				cin.ignore();

				cout << "Введите вес " << j + 1 << " спортсмена: ";
				cin >> kg;
				cin.ignore();

				cout << "Введите возраст " << j + 1 << " спортсмена: ";
				cin >> year;
				cin.ignore();

				cout << "Введите игровой номер " << j + 1 << " спортсмена: ";
				cin >> game_number;
				cin.ignore();

				if (cin.fail()) {
					cout << "Вы ввели значения неправильного типа" << endl;
					return 1;
				}

				data_people_vec.push_back({ FIO, high, year, kg, game_number });
				sr_year += year;
			}

			sr_year = sr_year / koll_sportsmen;
			data_group_vec.push_back({ country, group_name, data_people_vec, sr_year });
		}

		int minSrYearIndex = 0;
		int minSrYear = data_group_vec[0].sr_year;

		for (int i = 1; i < data_group_vec.size(); i++) {
			if (data_group_vec[i].sr_year < minSrYear) {
				minSrYear = data_group_vec[i].sr_year;
				minSrYearIndex = i;
			}
		}


		cout << "\n\n" ;
		cout << "Группа с самым маленьким показателем sr_year:" << endl;
		cout << "Страна: " << data_group_vec[minSrYearIndex].country << endl;
		cout << "Название группы: " << data_group_vec[minSrYearIndex].group_name << endl;
		cout << "Средний возраст: " << data_group_vec[minSrYearIndex].sr_year << endl;
		
		






		


	}
	return 0;
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
