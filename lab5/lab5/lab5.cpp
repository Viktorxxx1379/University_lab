#include <iostream>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;





int main()
{
    setlocale(0, "");
    int a = 0;

    cout << "Введите номер задания  ";
    cin >> a;

    
    if (a == 1) {
    
    
        int col = 0, str = 0;
        cout << "Размеры матрицы col и str ";
        cin >> col >> str;

        vector<int> vivod(0);
        vector<vector<int>> matrix(str, vector<int>(col));

        srand(time(0));

        for (int i = 0; i < str; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = rand() % 2;
            }
        }

        for (int i = 0; i < str; i++) {
            cout << "\n";
            for (int j = 0; j < col; j++) {
                cout << matrix[i][j] << setw(3);
            }
        }


        for (int j = 0; j < col; j++) {
            bool flag = true;
            for (int i = 0; i < str; i++) {
                if (matrix[i][j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) vivod.push_back(0);
            else vivod.push_back(1);
        }

        cout << endl;

        for (int i = 0; i < vivod.size(); i++) {
            cout << vivod[i];
        }

        cout << endl;


        return  0;

    }

    if (a == 3) {

        int col = 0, str = 0;
        cout << "Размеры матрицы col и str ";
        cin >> col >> str;

        vector<vector<int>> matrix(str, vector<int>(col));

        vector<int> vivod(0);

        srand(time(0));

        for (int i = 0; i < str; i++) {
            cout << "\n";
            for (int j = 0; j < col; j++) {
                matrix[i][j] = rand() % 2;
                cout << matrix[i][j] << setw(3);
            }
        }


        for (int i = 0; i < str; i++) {
            bool flag = true;
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] != (matrix[i][((col-1) - j)])) {
                    flag = false;
                }
            }
            if (flag == true) vivod.push_back(1);
            else vivod.push_back(0);
        }

        cout << endl;

        for (int i = 0; i < vivod.size(); i++) {
            cout << vivod[i];
        }

        cout << endl;


        return  0;
    }


    if (a == 7) {

        srand(time(0));


        int col = 0, str = 0;

        cout << "Введите уолличество столбцов и строк \n";
        cin >> col >> str;


        vector<vector<int>> matrix(str, vector<int>(col));

        for (int i = 0; i < str; i++) {
            cout << "\n";
            for (int j = 0; j < col; j++) {
                matrix[i][j] = rand() % 50;
                cout << matrix[i][j] << setw(7);
            }
        }

        for (int i = 0; i < str; i++) {
            for (int k = 0; k < pow(col, 2); k++) {
                for (int j = 1; j < col; j++) {
                    if (matrix[i][j] > matrix[i][j - 1]) {
                        swap(matrix[i][j], matrix[(i)][j - 1]);
                    }
                }

            }

        }

        cout << endl << endl;


        for (int i = 0; i < str; i++) {
            cout << "\n";
            for (int j = 0; j < col; j++) {
                cout << matrix[i][j] << setw(7);
            }
        }

    }


    else cout << "\n" << "Я не решил"<< endl ;

}