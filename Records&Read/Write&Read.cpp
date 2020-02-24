#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Point
{
public:
    Point()
    {
        x = y = z = 0;
    }

    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Print()
    {
        cout << "\tX = " << x << "\tY = " << y << "\tZ = " << z << endl;
    }

//private:
    int x, y, z;
};

void Record_Class_Obgect( Point point )
{
    string path = "Default_File_Name.txt";
    ofstream file;
    file.open(path, ofstream::app);

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла! " << endl;
    }
    else {
        cout << "Файл открыт! " << endl;
        file.write((char*)&point, sizeof(Point));
    }

    file.close();
}

void Read_Object_in_File(Point point)
{
    string path = "Default_File_Name.txt";
    ifstream file;
    file.open(path, ofstream::app);

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла! " << endl;
    }
    else {
        cout << "Файл открыт! " << endl;
        Point pnt;  // Объект, в который помещаются данные из файла

        while (file.read((char*)&pnt, sizeof(Point)))
        {
            pnt.Print();
        }
    }

    file.close();
}

int main()
{
    setlocale(LC_ALL, "ru");
    Point point(666, 66, 666);

    Record_Class_Obgect(point);
    Read_Object_in_File(point);

    return 0;
}
