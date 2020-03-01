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

    private:
    int x, y, z;

    // Разрешаем доступ операторам к приватным полям класса Point делая класс дружественным, для операторов, классом
    friend ostream& operator << (ostream& os, const Point& point);
    friend istream& operator >> (istream& is, Point& point);
};

// Выполняя перегрузку
// В данной перегрузке оператора, первый параметр, это левая часть выражения (cout << poшnt), соответственно второй параметр является правой частью 
ostream& operator << (ostream& os, const Point& point)   // Родительски класс для всех классов stream и метода cout 
{   // Класс ostream принадлежик к стандартному пространству имен (std)
    os << point.x << " " << point.y << " " << point.z;
    return os;  // Возврат строчного литерала. 
}

istream& operator >> (istream& is, Point& point)
{
    is >> point.x >> point.y >> point.z;
    return is;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Point point(777, 77, 49);

    cout << point << endl; // Вывод в консоль 
    
    fstream fs;
    string path = "Default_File_Name.txt";
    fs.open( path, fstream::in | fstream::out | fstream::app );

    if (!fs.is_open())
    {
        cout << "ERROR!" << endl;
    }   
    else {
        cout << "Record in the file - 1 | Read in the file - 2" << endl;
        int value; cin >> value;
        if ( value == 1 ) fs << point << "\n";
        if (value == 2)
        {
            while ( true )
            {
                Point cash;
                fs >> cash;
                if ( fs.eof() ) break;
                cout << cash << endl;
            }
        }
    } 
    return 0;
}
