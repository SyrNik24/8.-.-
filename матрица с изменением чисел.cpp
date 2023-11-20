#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
    setlocale(0, "");
    srand(time(0));

    int Size;
    int num1;
    int MinRaws, MinCols, MaxRaws, MaxCols;
    int Min = 101;
    int Max = 0;

    cout << "Введите размер матрицы:";
    cin >> Size;

    int **ArrSize = new int*[Size]; //Выделения памяти для диннам. массива
    for (int i = 0;i < Size;i++)
        ArrSize[i] = new int[Size];

    for (int i = 0;i < Size;i++) { //Заполнение массива и вывод в консоль
        for (int j = 0;j < Size;j++) {
            ArrSize[i][j] = rand() % 100 + 1;
            cout << setw(5) << ArrSize[i][j];
        }
        cout <<endl<< endl;
    }
    for (int i = 0;i < Size;i++) {      //Вычисления наименьшего и большего числа
        for (int j = 0;j < Size;j++) {
            if (ArrSize[i][j] < Min) {
                Min = ArrSize[i][j];
                MinRaws = i;
                MinCols = j;
            }
            if (ArrSize[i][j] > Max) {
                Max = ArrSize[i][j];
                MaxRaws = i;
                MaxCols = j;
            }
        }
    }
    cout << "Измененная Матрица:" << endl; //Изменение матрицы и ее вывод
    ArrSize[MinRaws][MinCols] = Max;
    ArrSize[MaxRaws][MaxCols] = Min;
    for (int i = 0;i < Size;i++) {
        for (int j = 0;j < Size;j++) {
            cout << setw(5) << ArrSize[i][j];
        }
        cout << endl << endl;
    }
    cout << endl << "Индекс минимального значения: "<<MinRaws<<" , " << MinCols << endl;
    cout<< "Индекс максимального значения: " << MaxRaws <<" , " << MaxCols << endl;

    for (int i = 0;i < Size;i++) //Удаление выделенной памяти
        delete[]ArrSize[i];
    delete[]ArrSize;
    return 0;
}