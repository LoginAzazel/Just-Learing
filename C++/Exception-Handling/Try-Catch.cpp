#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    
    ifstream fin;
	string path = "text.txt"; // Все виды нижепредставленных исключений работают только в случае, если данный файл не выйдет открыть
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "File is openning..." << endl;
		fin.open(path);
		cout << "File is open!" << endl;
	}
	catch (const  exception& ex)	// Стандартный класс исключений
	{
		cout << ex.what() << endl
			<< "Error! The file cannot be opened!" << endl;
	}

	try
	{
		cout << "File is openning..." << endl;
		fin.open(path);
		cout << "File is open!" << endl;
	}
	catch (const ifstream::failure& ex)	// Особы блок исключений класса ifstream
	{		// Дает больше информации об ошибке о данном классе
		cout << ex.what() << endl << ex.code() << endl
			 << "Error! The file cannot be opened!" << endl;
	}
	 
    return 0;
}
