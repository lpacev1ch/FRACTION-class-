#include "drob.h"

// Арифметические операторы
drob drob::operator+(const drob& other) const {
    return drob(chislitel * other.znamenatel + other.chislitel * znamenatel,
                znamenatel * other.znamenatel);
}

drob drob::operator-(const drob& other) const {
    return drob(chislitel * other.znamenatel - other.chislitel * znamenatel,
                znamenatel * other.znamenatel);
}

drob drob::operator*(const drob& other) const {
    return drob(chislitel * other.chislitel, znamenatel * other.znamenatel);
}

drob drob::operator/(const drob& other) const {
    return drob(chislitel * other.znamenatel, znamenatel * other.chislitel);
}

// Операторы сравнения
bool drob::operator==(const drob& other) const {
    return chislitel * other.znamenatel == other.chislitel * znamenatel;
}

bool drob::operator!=(const drob& other) const {
    return !(*this == other);
}

bool drob::operator<(const drob& other) const {
    return chislitel * other.znamenatel < other.chislitel * znamenatel;
}

bool drob::operator<=(const drob& other) const {
    return *this < other || *this == other;
}

bool drob::operator>(const drob& other) const {
    return !(*this <= other);
}

bool drob::operator>=(const drob& other) const {
    return !(*this < other);
}

// Операторы инкремента и декремента
drob& drob::operator++() {
    chislitel += znamenatel;
    return *this;
}

drob drob::operator++(int) {
    drob temp = *this;
    ++(*this);
    return temp;
}

drob& drob::operator--() {
    chislitel -= znamenatel;
    return *this;
}

drob drob::operator--(int) {
    drob temp = *this;
    --(*this);
    return temp;
}

// Унарный минус
drob drob::operator-() const {
    return drob(-chislitel, znamenatel);
}

// Оператор отрицания для получения обратной дроби
drob drob::operator!() const {
    return drob(znamenatel, chislitel);
}

// Оператор вывода
std::ostream& operator<<(std::ostream& out, const drob& d) {
    out << d.chislitel << "/" << d.znamenatel;
    return out;
}

// Оператор ввода
std::istream& operator>>(std::istream& in, drob& d) {
    in >> d.chislitel;
    in.ignore(); // Пропускаем знак '/'
    in >> d.znamenatel;
    d.simplify(); // Приводим каноническому виду
    return in;
}

// Приведение к вещественному типу
drob::operator double() const {
    return static_cast<double>(chislitel) / znamenatel;
}

// Оператор присваивания
drob& drob::operator=(const drob& other) {
    if (this != &other) {
        chislitel = other.chislitel;
        znamenatel = other.znamenatel;
    }
    return *this;
}

// Составные операторы присваивания
drob& drob::operator+=(const drob& other) {
    *this = *this + other;
    return *this;
}

drob& drob::operator-=(const drob& other) {
    *this = *this - other;
    return *this;
}

drob& drob::operator*=(const drob& other) {
    *this = *this * other;
    return *this;
}

drob& drob::operator/=(const drob& other) {
    *this = *this / other;
    return *this;
}
