#include <iostream>
#include <clocale>

// Функция быстрого возведения в степень
long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        // Если младший бит степени равен 1, умножаем результат на текущее основание
        if (exp % 2 == 1) {
            result *= base;
        }
        // Возводим основание в квадрат для следующего бита
        base *= base;
        // Делим степень на 2 (сдвиг вправо)
        exp /= 2;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    long long a, n;
    std::cout << "Введите основание и степень: ";
    std::cin >> a >> n;
    std::cout << a << "^" << n << " = " << fastPow(a, n) << std::endl;
    return 0;
}

#include <iostream>
#include <clocale>

// Рекурсивная функция для вычисления НОД (алгоритм Евклида)
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Базовый случай
    }
    return gcd(b, a % b); // Рекурсивный шаг
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;
    std::cout << "НОД: " << gcd(a, b) << std::endl;
    return 0;
}

#include <iostream>
#include <clocale>

// Рекурсивная функция для перемещения n ингредиентов
// from — откуда, to — куда, aux — вспомогательная салфетка
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return; // Базовый случай: нечего перемещать

    // Перемещаем n-1 ингредиентов на вспомогательную салфетку
    hanoi(n - 1, from, aux, to);

    // Перемещаем самый большой ингредиент на целевую салфетку
    std::cout << "Ingredient " << n << " move from " << from << " to " << to << std::endl;

    // Перемещаем n-1 ингредиентов с вспомогательной на целевую
    hanoi(n - 1, aux, to, from);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество ингредиентов: ";
    std::cin >> n;

    // Перекладываем все n ингредиентов с салфетки 1 на салфетку 3
    hanoi(n, 1, 3, 2);
    return 0;
}

#include <iostream>
#include <clocale>

// Рекурсивная функция быстрого возведения в степень
long long fastPowRecursive(long long base, long long exp) {
    if (exp == 0) return 1; // Любое число в 0 степени = 1

    // Если степень четная, возводим в половину степени и умножаем само на себя
    if (exp % 2 == 0) {
        long long half = fastPowRecursive(base, exp / 2);
        return half * half;
    }
    // Если нечетная, то то же самое, но еще умножаем на основание
    else {
        return base * fastPowRecursive(base, exp - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    long long a, n;
    std::cout << "Введите основание и степень: ";
    std::cin >> a >> n;

    std::cout << a << "^" << n << " = " << fastPowRecursive(a, n) << std::endl;
    return 0;
}