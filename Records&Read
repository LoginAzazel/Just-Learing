#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string path = "Default_Name_File.txt";
    ofstream nameFile;

    nameFile.open(path);    // Открытие файла с именем Default_Name_File. Файл ВСЕГДА пересоздается.
                            // Можно указать полный путь
    if (!nameFile.is_open()) {      // Если файл, по каким либо причинами, не открался, то функция выдаст 1 (Мы используем инверсию(!))
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        nameFile << "Данные в файле!!!";
    }

    nameFile.close();

    ////// --- OR ---///////

    path = "Default_Name_File_2.txt";
    ofstream nameFile2;

    nameFile2.open(path, ofstream::app );    // Второй параметр означает, что если файл уже существует, дозаписать в него данные
                            // Можно указать полный путь
    if (!nameFile2.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        int a;
        cout << "Number: "; cin >> a;
        nameFile2 << "\n" << a;
    }
    cout << endl;
    nameFile2.close();
    
    return 0;
}
