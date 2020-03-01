#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Example1()
{
    string path = "Default_Name_File.txt";  // Путь и имя открыввемого файла
    ifstream nameFile;  // Для чтения файла 

    nameFile.open(path);
    if (!nameFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        char ch;
        while ( nameFile.get(ch) )  // Метод, если получилось что-то считать, возвращает bool
        {
            cout << ch;
        }
        cout << endl << endl;
    }

    cout << endl;
    nameFile.close();
}

/////////////////////////////////////////////

void Example2()
{
    string path = "Default_Name_File.txt";  // Путь и имя открыввемого файла
    ifstream nameFile;  // Для чтения файла 

    nameFile.open(path);
    if (!nameFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        string str;
        while (!nameFile.eof())  // Метод, если получилось что-то считать, возвращает bool
        {
            str = "";
            nameFile >> str;    // Считывание по слову
            cout << str << endl;
        }
        cout << endl << endl;
    }

    cout << endl;
    nameFile.close();
}

/////////////////////////////////

void Example3()
{
    string path = "Default_Name_File.txt";  // Путь и имя открыввемого файла
    ifstream nameFile;  // Для чтения файла 

    nameFile.open(path);
    if (!nameFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        string str;
        while (!nameFile.eof())  // Метод, если получилось что-то считать, возвращает bool
        {
            str = "";
            // file.getline(str, 50); Аналогично следующему getline, но требуется указать кол-во символов
            getline(nameFile, str);    // Считывание по строчке
            cout << str << endl;
        }
        cout << endl << endl;
    }

    cout << endl;
    nameFile.close();
}



int main()
{
    setlocale(LC_ALL, "ru");

    //Example1();
    //Example2();
    Example3();
    
    return 0;
}
