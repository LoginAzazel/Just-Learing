using System;
using System.Globalization;

namespace LearningProg
{
    class Program
    {
        void Lession1()
        {
            //  -- Конвертация --
            // 1. Класс "Convert.To..."
            string Numb1 = "1.3";
            NumberFormatInfo numberFormatInfo1 = new NumberFormatInfo()
            {   // Принадлежит к пространству имен Globalization
                NumberDecimalSeparator = ".",   // Если какая-то операционная система, к примеру, 
            };               // Использует как разделитель точку, а не запятую ("," по умолчанию)
            double b = Convert.ToDouble(Numb1, numberFormatInfo1);    // Конвортация в Double
            Console.WriteLine(b);

            // 2. Методы конвертации базовоых типов данных (double.Parse || int.Parse e.c.t.)
            string Numb2 = "1.3";
            NumberFormatInfo numberFormatInfo2 = new NumberFormatInfo()
            {   // Принадлежит к пространству имен Globalization
                NumberDecimalSeparator = ".",   // Если какая-то операционная система, к примеру, 
            };               // Использует как разделитель точку, а не запятую ("," по умолчанию)
            double a = double.Parse(Numb2, numberFormatInfo2);    // Конвортация в Double
            // b = double.Parse(Console.ReadLine()); // Пример ввода с консоли
            Console.WriteLine(a);

            // 3. Обработка исключений при конвертации
            string Numb3 = "33i";
            int N;
            bool result = int.TryParse(Numb3, out N);
            if (result)
            {
                Console.WriteLine("Значение = " + N);
            }
            else
            {
                Console.WriteLine("ERROR!");
            }
        }
        static void Main(string[] args)
        {
            
        }
    }
}
