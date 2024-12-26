#include <iostream>
#include <vector>
#include <cmath>

class Algorithms {
public:
    // Метод 1: Пошук мінімального елементу масиву позитивних чисел
    static int findMinPositive(const std::vector<int>& arr) {
        int min = arr[0];
        for (int num : arr) {
            if (num < min && num > 0) {
                min = num;
            }
        }
        return min;
    }

    // Метод 2: Розрахунок суми елементів масиву з від'ємними числами
    static int sumNegative(const std::vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            if (num < 0) {
                sum += num;
            }
        }
        return sum;
    }

    // Метод 3: Алгоритм розрахунку N-го елементу послідовності Фібоначчі
    static int fibonacci(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    // Метод 4: Алгоритм розрахунку сили струму на ділянці кола (I = V/R)
    static double currentStrength(double voltage, double resistance) {
        if (resistance == 0) {
            std::cerr << "Resistance cannot be zero." << std::endl;
            return -1;
        }
        return voltage / resistance;
    }
};
// Позитивні тести
void testFindMinPositive() {
    std::vector<int> arr = {4, 2, 7, 1, 3};
    int result = Algorithms::findMinPositive(arr);
    std::cout << "Min positive: " << result << std::endl;  // Очікується: 1
}

void testSumNegative() {
    std::vector<int> arr = {-1, -3, 5, 7, -2};
    int result = Algorithms::sumNegative(arr);
    std::cout << "Sum negative: " << result << std::endl;  // Очікується: -6
}

void testFibonacci() {
    int result = Algorithms::fibonacci(5);
    std::cout << "Fibonacci: " << result << std::endl;  // Очікується: 5
}

void testCurrentStrength() {
    double result = Algorithms::currentStrength(10.0, 2.0);
    std::cout << "Current Strength: " << result << " A" << std::endl;  // Очікується: 5 A
}

// Негативні тести
void testNegativeCases() {
    std::vector<int> arr = {1, 2, 3, 4};
    int result = Algorithms::findMinPositive(arr);
    std::cout << "Min positive: " << result << std::endl;  // Очікується: 1

    arr = {-1, -2, -3};
    result = Algorithms::sumNegative(arr);
    std::cout << "Sum negative: " << result << std::endl;  // Очікується: -6

    result = Algorithms::fibonacci(-1);
    std::cout << "Fibonacci: " << result << std::endl;  // Очікується: негативне значення

    result = Algorithms::currentStrength(10.0, 0.0);
    std::cout << "Current Strength: " << result << std::endl;  // Очікується: помилка
}

int main() {
    testFindMinPositive();
    testSumNegative();
    testFibonacci();
    testCurrentStrength();
    testNegativeCases();
    return 0;
}
