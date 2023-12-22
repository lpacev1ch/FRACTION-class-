#include <iostream>

using namespace std;

class drob{
    //public:
private:
    int chislitel; // =n
    int znamenatel; // =d

    // Нахождение НОД
    int NOD(int a, int b) {
        if (b == 0)
            return a;
        return NOD(b, a % b);
    }

    /// Приведение дроби к каноническому виду
    void simplify() {
        int common = NOD(chislitel, znamenatel);
        chislitel /= common;
        znamenatel /= common;

        if (znamenatel < 0) {  // знаменатель > 0
            chislitel = -chislitel;
            znamenatel = -znamenatel;
        }
    }



public:
    // Конструкторы
    drob() : chislitel(0), znamenatel(1) {}
    drob(int n, int d) : chislitel(n), znamenatel(d) { simplify(); }

    /// Арифметические операторы

    drob operator+(const drob& other) const; //Cложение
    drob operator-(const drob& other) const; //разность
    drob operator*(const drob& other) const; //Умножение
    drob operator/(const drob& other) const; //Деление




    /// Операторы сравнения

    bool operator==(const drob& other) const; // Равенство
    bool operator!=(const drob& other) const; // Не равно
    bool operator<(const drob& other) const;  // Меньше
    bool operator<=(const drob& other) const; //Меньше/равно
    bool operator>(const drob& other) const;  // Больше
    bool operator>=(const drob& other) const; // больше/равно




    /// Операторы инкремента и декремента

    drob& operator++();   // Префиксный инкремент
    drob operator++(int); // Постфиксный инкремент
    drob& operator--();   // Префиксный декремент
    drob operator--(int); // Постфиксный декремент




    /// Унарный минус

    /*Унарный минус - это минус, который не является арифметическим действием,
    а лишь указывает на отрицательное число*/

    drob operator-() const;




    /// Оператор отрицания для получения обратной дроби
    drob operator!() const;




    /// Операторы ввода и вывода
    friend ostream& operator<<(ostream& out, const drob& frac);
    friend istream& operator>>(istream& in, drob& frac);




    /// Приведение к вещественному типу
    operator double() const;




    /// Оператор присваивания
    drob& operator=(const drob& other);




    /// Составные операторы присваивания

    drob& operator+=(const drob& other);
    drob& operator-=(const drob& other);
    drob& operator*=(const drob& other);
    drob& operator/=(const drob& other);
};

//#endif