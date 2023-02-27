// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <time.h>
using namespace std;
typedef double* pDouble;
const int MAX = 200;

//Задано одновимірний масив А розміру N.Знайти кількість нульових елементів.
void Task1(int n, double A[]) {
    int i, g = 0;

    for (i = 0; i < n; i++) {
        if (A[i] == 0) {
            g++;
        }
    }
    if (g == 0) {
        cout << "No null elements" << endl;
    }
    else {
        cout << "\n" << endl;
        cout << "Result " << g << endl;
    }
}

//Знайти номер останнього максимального значення серед від’ємних елементів,
//розташованих правіше елемента, рівного Т.
void Task2(int n, double A[]) {
    int i, T, index = -1, index2 = -1, max = 0;

    cout << "Enter the number T" << endl;
    cin >> T;

    for (i = 0; i < n; i++) {
        if (A[i] == T) {
            index = i;
        }
    }

    if (index < 0) {
        cout << "No T element in the array" << endl;
    }
    else {
        for (i = index; i < n; i++) {
            if (A[i] < 0) {
                if (max == 0 || A[i] > max) {
                    max = A[i];
                    index2 = i;
                }
            }
        }
        if (index2 < 0) {
            cout << "No negative elements in the array" << endl;
        }
        else {
            cout << "\n" << endl;
            cout << "Result: " << index2 << endl;
        }
    }

}

//Задано масив дійсних чисел A[2n].Розробити програму, яка будує масив B[n], за првилом: b[i] є середнім 
// арифметиччним значенням чисел а1, а2,..., аn, крім ai, ai = 1, 2,..., n.
void Task3(int n, double A[]) {
    double B[MAX];
    int i, b = 0;

    for (i = 0; i < n; i++) {
        b = b + A[i];
    }
    for (i = 0; i < n; i++) {
        B[i] = (b - A[i]) / (n - 1);
    }
    cout << "Result " << endl;
    cout << "B: " << endl;
   for (i = 0; i < n; i++) {
        cout << B[i] << "\t";
    }
}

int MainMenu() {
    int mainchoice;
    cout << " Main Menu \n";
    cout << " 1. Task 1 \n";
    cout << " 2. Task 2 \n";
    cout << " 3. Task 3 \n";
    cout << "Enter your choice" << endl;
    cin >> mainchoice;
    system("cls");
    return mainchoice;
}

int TaskMenu(){
    int taskchoice;
    cout << " Menu Task \n";
    cout << " 1.  From console into text file \n";
    cout << " 2.  Random array into binary file \n";
    cout << " 3.  Dynamic array from file into file \n";
    cout << " 4.  From file into container into console \n";
    cout << " 5.  Exit \n";
    cout << "Enter your choice" << endl;
    cin >> taskchoice;
    system("cls");
    return taskchoice;
}

void ConsoleInputIntoTextFile(int mainchoice) {
    double A[MAX];
    int i, n = 0;
    cout << "Enter the number of elements < " << MAX << endl;
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "A[" << i << "]=";
        cin >> A[i];
    }
    if (mainchoice == 1) {
        Task1(n, A);
    } if (mainchoice == 2) {
        Task2(n, A);
    } if (mainchoice == 3) {
        Task3(n, A);
    }
    ofstream tfile("Txt_File.txt");
    if (tfile.fail()) return;
    tfile << n << endl;
    for (int i = 0; i < n; i++)
        tfile << A[i] << "   ";
    tfile.close();
}

int InputSizeOfArray() {
    int n = 0;
    cout << "Enter the number of elements < " << MAX << endl;
    cin >> n;
    return n;
}

double* InputRandomArray(int n) {
    double A[MAX];
    int i;
    for (i = 0; i < n; i++) {
        A[i] = rand();
        cout << "A[" << i << "]=" << A[i] << "\n";
    }
    return A;
}

void IntoBinaryFile(int mainchoice) {
    int i, n = InputSizeOfArray();
    double* A = InputRandomArray(n);
    if (mainchoice == 1) {
        Task1(n, A);
    } if (mainchoice == 2) {
        Task2(n, A);
    } if (mainchoice == 3) {
        Task3(n, A);
    }
    ofstream bfile("Bin_File.bin", ios::out | ios::binary);
    if (bfile.fail()) return;
    for (i = 0; i < n; i++) {
        bfile.write((char*)&A[i], sizeof(A[i]));
    }
    bfile.close();
}

void DynamicArrayFromFileToFile(int mainchoice) {
    double* A = new double[MAX];

    ofstream finwritefile("WTxt_File.txt");
    ifstream readfile("Txt_File.txt");
    if (readfile.is_open()) {
        double A;
        while (readfile >> A) {
            finwritefile << A << endl;
        }
    }
    else {
        cout << "Error" << endl;
    }
    finwritefile.close();
    readfile.close();
}

//void DynamicArrayFromFileToFile(int mainchoice) {
//    double* A = new double[MAX];
//    double m;
//    int i, n = 0;
//    ifstream tfile("Txt_File.txt");
//    if (!tfile.is_open())return;
//    if (tfile.is_open())return;
//    tfile >> n;
//    for (i = 0; i < n; i++) {
//        tfile >> m;
//        A[i] = m;
//        cout << A[i];
//    }
//    if (mainchoice == 1) {
//        Task1(n, A);
//    } if (mainchoice == 2) {
//        Task2(n, A);
//    } if (mainchoice == 3) {
//        Task3(n, A);
//    }
//    tfile.close();
//    ofstream ntfile("New_Text_File.txt");
//    for (i = 0; i < n; i++) {
//        ntfile << A[i] << " ";
//    }
//    ntfile.close();
//}

//void FromFileToContainer(int mainchoice) {
//    vector<double> A_vector;
//    double A[MAX], m;
//    int i, n;
//    ifstream tfile("Txt_File.txt");
//    if (!tfile.is_open())return;
//    if (tfile.is_open())return;
//    tfile >> n;
//    for (i = 0; i < n; i++) {
//        tfile >> m;
//        A[i] = m;
//        cout << A_vector[i];
//    }
//    if (mainchoice == 1) {
//        Task1(n, A);
//    } if (mainchoice == 2) {
//        Task2(n, A);
//    } if (mainchoice == 3) {
//        Task3(n, A);
//    }
//    tfile.close();
//}

void FromFileToContainer(int mainchoice) {
    ifstream readfile("Txt_File.txt");
    if (readfile.is_open()) {
        vector <double> data;
        double A;
        while (readfile >> A) {
            data.push_back(A);
        }
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Error" << endl;
    }
    readfile.close();
}

int main()
{
    int mainchoice = MainMenu();
    if (mainchoice > 3 || mainchoice < 1) {
        cout << "Please choose task";
    }
    int taskchoice = TaskMenu();
   
    switch (taskchoice) {
        case 1:
            ConsoleInputIntoTextFile(mainchoice);
            break;
        case 2:
            IntoBinaryFile(mainchoice);
            break;
        case 3:
            ConsoleInputIntoTextFile(mainchoice);
            DynamicArrayFromFileToFile(mainchoice);
            break;
        case 4:
            ConsoleInputIntoTextFile(mainchoice);
            FromFileToContainer(mainchoice);
            break;
        case 5:
            cout << "Bye";
            break;
        default:
            break;
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
