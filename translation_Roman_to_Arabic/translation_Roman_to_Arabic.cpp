#pragma warning(disable : 4996)    // исключает ошибку при компиляции
#include <iostream>      // вывода на экран 
#include <Windows.h>     // для вывода русского языка
#include <string>        // использование string что бы преобразовать int в char

void add(char arabic[], const char* add)        // функция для дополнение символов в массив
{
    strcat(arabic, add);                       // передаем массив и элементы которые хотим дополнить массив
}




class Roman_number                            // класс
{
public:
    Roman_number()                          // конструктор по умолчанию
    {

    };


    Roman_number(int arabic)                  // конструктор который принимает арабсике символы
    {
        Roman_number::set_arabic(arabic);     // вызывает метод set_arabic(arabic) -> метод который арабские цифры превращает в римсие и сохраниет их (и римские и арабсике) в классе 
    }

    Roman_number(const char* add)             // конструктор который принимает римские цифры
    {
        Roman_number::set_roman(add);         // вызвывает метод set_roman(add) -> метод который римские цифры превращает в арабские и сохрание их (и римские и арабские) в классе
    }

    ~Roman_number()
    {
        //  strcat при использовании динамическая памть сама почиститься
    }


    char* get_arabic()                               // метод для получения арабских цифр 
    {
        /*
        * пробовал по разному преобразовать int в char только таким способ получилось
        */
        std::string tmp = std::to_string(arab);
        return strcpy(new char[+tmp.length()], tmp.c_str());
    }


    char* get_roman()                                // метод для получения римских цифр 
    {
        return roman;
    }


    void set_roman(const char* add)                 // метод который получет римские цифры преобразует в арабские и сохраняет их (и арбаские и риские) ;
    {
        int arabic = 0;                                                                 // временая переменная
        for (int i = 0; add[i] != 0; i++)                                               // цикол будет выполняться пока не закончиться строка
        {
            if (add[i] + add[i + 1] == *"a" + *"d") { arabic += 900; i++; }             // если есть сочитание цифр "a" и "d" то к временой переменной прибавляем 900 (i++ нужен для того что бы мы не проверяли d 2 раза)
            else if (add[i] == *"C" && add[i + 1] == *"D") { arabic += 400; i++; }
            else if (add[i] == *"X" && add[i + 1] == *"C") { arabic += 90; i++; }
            else if (add[i] == *"X" && add[i + 1] == *"C") { arabic += 90; i++; }
            else if (add[i] == *"I" && add[i + 1] == *"X") { arabic += 9; i++; }
            else if (add[i] == *"I" && add[i + 1] == *"V") { arabic += 4; i++; }
            else if (add[i] == *"M") { arabic += 1000; }
            else if (add[i] == *"D") { arabic += 500; }
            else if (add[i] == *"C") { arabic += 100; }
            else if (add[i] == *"X") { arabic += 10; }
            else if (add[i] == *"L") { arabic += 50; }
            else if (add[i] == *"I") { arabic += 1; }
            else if (add[i] == *"V") { arabic += 5; }
        }
        Roman_number::set_arabic(arabic);

    }

    void set_arabic(int arabic)                                                               // метод который получает арабские цифры преобразует изз в римские и сохраняет их ( и арабаские и римские)
    {
        this->arab = arabic;                                                                   // временная переменная
        ZeroMemory(this->roman, 10);                                                                     // стираем стрые данные о римских символах (передаем переменую и на что хотим заменить данные)
        while (arabic != 0)                                                                   // пока переменная не равна 0
        {
            if (arabic >= 1000) { arabic = arabic - 1000; add(roman, "M"); }                  // если переменная большо 1000 то используем функцию add -> добавляет символы в переменую (roman переменная а "M" символ
            else {
                if (arabic >= 900) { arabic = arabic - 900;   add(roman, "ad"); }
                else if (arabic >= 500) { arabic = arabic - 500; add(roman, "D"); }
                else if (arabic >= 400) { arabic = arabic - 400; add(roman, "CD"); }
                else if (arabic >= 100) { arabic = arabic - 100; add(roman, "C"); }
                else if (arabic >= 90) { arabic = arabic - 90; add(roman, "XC"); }
                else if (arabic >= 50) { arabic = arabic - 50; add(roman, "L"); }
                else if (arabic >= 10) { arabic = arabic - 10; add(roman, "X"); }
                else if (arabic >= 9) { arabic = arabic - 9; add(roman, "IX"); }
                else if (arabic >= 5) { arabic = arabic - 5; add(roman, "V"); }
                else if (arabic >= 4) { arabic = arabic - 4; add(roman, "IV"); }
                else if (arabic >= 1) { arabic = arabic - 1; add(roman, "I"); }
            }
        }
    }


    char* increase()                                                         // метод который возрощает строку всех цифр по возростанию
    {
        int temp = this->arab;                      // временная переменная
        int a[10];                                  // массив для разбития на отдельные цифры
        int size = 0;                               // переменная для знаний сколько у нас цифр
        for (int i = 0; i < 10; i++)                // заполняем массив цифрами
        {
            a[i] = temp % 10;                       // отделяем последнию цифру от числа и присваеивем к массиву
            temp /= 10;
            if (temp != 0)                           // если есть еще цифры то size++
            {
                size++;
            }
        }
        for (int i = 9; i >= 1; i--)                  // делаем цифры по убыванию в массиве
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[j + 1])
                {
                    int foo = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = foo;
                }
            }

        for (int i = 0; i < size + 1; i++)                // теперь вытаскиваем из массива все цифры и заполняем их в переменную
        {
            temp = temp * 10 + a[i];
        }

        std::string tmp = std::to_string(temp);                                 // меняем int на char (другие способы не работают)
        return strcpy(new char[+tmp.length()], tmp.c_str());
    }


    Roman_number& operator+ (const Roman_number& copy)                                    // перегруженый оператор сложения          
    {
        this->arab += copy.arab;                                                        // сумируем арабские цифры 
        int temp = this->arab;                                                         // врменная переменная для сложение римских цифр
        ZeroMemory(this->roman, 10);                                                   // очищаем старые данные ( риские цифры)

        // запоняем новые данные о римских цифрах прежде этот цикл рассмотрен 
        while (temp != 0)
        {
            if (temp >= 1000) { temp = temp - 1000; add(this->roman, "M"); }
            else {
                if (temp >= 900) { temp = temp - 900;   add(this->roman, "ad"); }
                else if (temp >= 500) { temp = temp - 500; add(this->roman, "D"); }
                else if (temp >= 400) { temp = temp - 400; add(this->roman, "CD"); }
                else if (temp >= 100) { temp = temp - 100; add(this->roman, "C"); }
                else if (temp >= 90) { temp = temp - 90; add(this->roman, "XC"); }
                else if (temp >= 50) { temp = temp - 50; add(this->roman, "L"); }
                else if (temp >= 10) { temp = temp - 10; add(this->roman, "X"); }
                else if (temp >= 9) { temp = temp - 9; add(this->roman, "IX"); }
                else if (temp >= 5) { temp = temp - 5; add(this->roman, "V"); }
                else if (temp >= 4) { temp = temp - 4; add(this->roman, "IV"); }
                else if (temp >= 1) { temp = temp - 1; add(this->roman, "I"); }
            }
        }
        return *this;                                                                     // возращаю класс
    }

    Roman_number& operator- (const Roman_number& copy)                                         // перегруженный оператор вычитание 
    {
        this->arab -= copy.arab;                                                         // вычитаем арабсккие цифры
        int temp = this->arab;                                                           // временная переменная для вычитаний римксих цифр
        ZeroMemory(this->roman, 10);                                                     // очищаем старые данные (римские цифры) 

        // заполняем новые данные о римских цифрах прежде этот цикл рассмотрен
        while (temp != 0)
        {
            if (temp >= 1000) { temp = temp - 1000; add(this->roman, "M"); }
            else {
                if (temp >= 900) { temp = temp - 900;   add(this->roman, "ad"); }
                else if (temp >= 500) { temp = temp - 500; add(this->roman, "D"); }
                else if (temp >= 400) { temp = temp - 400; add(this->roman, "CD"); }
                else if (temp >= 100) { temp = temp - 100; add(this->roman, "C"); }
                else if (temp >= 90) { temp = temp - 90; add(this->roman, "XC"); }
                else if (temp >= 50) { temp = temp - 50; add(this->roman, "L"); }
                else if (temp >= 10) { temp = temp - 10; add(this->roman, "X"); }
                else if (temp >= 9) { temp = temp - 9; add(this->roman, "IX"); }
                else if (temp >= 5) { temp = temp - 5; add(this->roman, "V"); }
                else if (temp >= 4) { temp = temp - 4; add(this->roman, "IV"); }
                else if (temp >= 1) { temp = temp - 1; add(this->roman, "I"); }
            }
        }
        return *this;
    }


    // все тоже самое что и перегруженый оперптор - и + только теперь арабские цифры умножаем а с римскими я работаю через арабские  ( см оператор + и -)
    Roman_number& operator* (const Roman_number& copy)
    {
        this->arab *= copy.arab;
        int temp = this->arab;
        ZeroMemory(this->roman, 10);
        while (temp != 0)
        {
            if (temp >= 1000) { temp = temp - 1000; add(this->roman, "M"); }
            else {
                if (temp >= 900) { temp = temp - 900;   add(this->roman, "ad"); }
                else if (temp >= 500) { temp = temp - 500; add(this->roman, "D"); }
                else if (temp >= 400) { temp = temp - 400; add(this->roman, "CD"); }
                else if (temp >= 100) { temp = temp - 100; add(this->roman, "C"); }
                else if (temp >= 90) { temp = temp - 90; add(this->roman, "XC"); }
                else if (temp >= 50) { temp = temp - 50; add(this->roman, "L"); }
                else if (temp >= 10) { temp = temp - 10; add(this->roman, "X"); }
                else if (temp >= 9) { temp = temp - 9; add(this->roman, "IX"); }
                else if (temp >= 5) { temp = temp - 5; add(this->roman, "V"); }
                else if (temp >= 4) { temp = temp - 4; add(this->roman, "IV"); }
                else if (temp >= 1) { temp = temp - 1; add(this->roman, "I"); }
            }
        }
        return *this;
    }

    // все тоже самое что и перегруженый оперптор - и + только теперь арабские цифры делим а с римскими я работаю через арабские  ( см оператор + и -)
    Roman_number& operator/ (const Roman_number& copy)
    {
        this->arab /= copy.arab;
        int temp = this->arab;
        ZeroMemory(this->roman, 10);
        while (temp != 0)
        {
            if (temp >= 1000) { temp = temp - 1000; add(this->roman, "M"); }
            else {
                if (temp >= 900) { temp = temp - 900;   add(this->roman, "ad"); }
                else if (temp >= 500) { temp = temp - 500; add(this->roman, "D"); }
                else if (temp >= 400) { temp = temp - 400; add(this->roman, "CD"); }
                else if (temp >= 100) { temp = temp - 100; add(this->roman, "C"); }
                else if (temp >= 90) { temp = temp - 90; add(this->roman, "XC"); }
                else if (temp >= 50) { temp = temp - 50; add(this->roman, "L"); }
                else if (temp >= 10) { temp = temp - 10; add(this->roman, "X"); }
                else if (temp >= 9) { temp = temp - 9; add(this->roman, "IX"); }
                else if (temp >= 5) { temp = temp - 5; add(this->roman, "V"); }
                else if (temp >= 4) { temp = temp - 4; add(this->roman, "IV"); }
                else if (temp >= 1) { temp = temp - 1; add(this->roman, "I"); }
            }
        }
        return *this;
    }

    // все тоже самое что и перегруженый оперптор - и + только теперь арабские цифры присваивем а с римскими я работаю через арабские  ( см оператор + и -)
    Roman_number& operator= (const Roman_number& copy)
    {
        this->arab = copy.arab;
        this->roman = copy.roman;
        return *this;
    }




    bool operator== (const Roman_number& copy)          // перегруженный оператор сравнивание 
    {
        return (arab == copy.arab);         // если арабские цифры оденаковые то выводим 1:
    }

    bool operator != (const Roman_number& copy)          // перегруженый опертор сравниваение
    {
        return !(arab == copy.arab);        // если арабсике цифры оденаковые то выводим !1 (то есть 0)
    }

    bool operator < (const Roman_number& copy)
    {
        return (arab < copy.arab);
    }
    bool operator > (const Roman_number& copy)
    {
        return (arab > copy.arab);
    }

private:
    int arab = 1017;                                   // добавил свойство о арабских цифрах (значение)
    char* roman = new char[] {"MXVII"};                // свойство о римских цифрах по умолчанию оно заполнено "MXVII"
};




int main()
{
    SetConsoleCP(1251);                          // для выведения русского языка
    SetConsoleOutputCP(1251);                    // для выведения русского языка

    Roman_number a, b, c;
    int N, R;
    std::string dey;

    std::cout << "Выберите один из вариантов:" << std::endl;
    std::cout << "1 - Ввод римских цифр" << std::endl;
    std::cout << "2 - Ввод арабских цифр" << std::endl;
    std::cin >> N;

    if (N == 1)
    {
        char rim[10];
        char rim1[10];
        std::cout << "Введите первое римское число: ";
        std::cin >> rim;
        std::cout << "Введите второе римское число: ";
        std::cin >> rim1;
        a.set_roman(rim);
        b.set_roman(rim1);
    }
    else if (N == 2)
    {
        int arab;
        int arab1;
        std::cout << "Введите первое арабское число: ";
        std::cin >> arab;
        std::cout << "Введите второе арабское число: ";
        std::cin >> arab1;
        a.set_arabic(arab);
        b.set_arabic(arab1);
    }
    else
        std::cout << "\n\t\tОшибка" << std::endl;




    std::cout << "Введите действие: ";
    std::cin >> dey;

    if (dey == "+")
        a + b;
    else if (dey == "-")
        a - b;
    else if (dey == "*")
        a* b;
    else if (dey == "/")
        a / b;
    else if (dey == "==")
        if (a == b)
            std::cout << "Числа одинаковые" << std::endl;
        else
            std::cout << "Числа разные" << std::endl;
    else if (dey == "<")
        if (a < b)
            std::cout << "Второе число больше чем первое" << std::endl;
        else if (a > b)
            std::cout << "Первое число больше чем первое" << std::endl;
        else
            std::cout << "Числа одинаковые" << std::endl;
    else if (dey == ">")
        if (a < b)
            std::cout << "Второе число больше чем первое" << std::endl;
        else if (a > b)
            std::cout << "Первое число больше чем первое" << std::endl;
        else
            std::cout << "Числа одинаковые" << std::endl;
    else
        std::cout << "Error!" << std::endl;


    if (dey != "==" & dey != "<" & dey != ">")
    {
        std::cout << "Выберите один из вариантов:" << std::endl;
        std::cout << "1 - Вывод римских цифр" << std::endl;
        std::cout << "2 - Вывод арабских цифр" << std::endl;
        std::cin >> N;


        if (N == 1)
            std::cout << "Римское число - " << a.get_roman() << std::endl;
        else if (N == 2)
            std::cout << "Арабское число - " << a.get_arabic() << std::endl;
        else
            std::cout << "\n\t\tОшибка" << std::endl;
    }

    return 0;
}