#include "../file.h" // Подключаем нашу функцию умножения
#include <iostream>

// Функция для запуска теста умножения
// Возвращает 0, если тест пройден, 1 в противном случае
int run_mult_test(int a, int b, int expected, const char *test_name)
{
    int result = my_mult(a, b);
    if (result == expected)
    {
        std::cout << "[PASSED] " << test_name << ": " << a << " * " << b << " = " << result << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "[FAILED] " << test_name << ": " << a << " * " << b << " = " << result
                  << ", Expected: " << expected << std::endl;
        return 1;
    }
}

int main()
{
    int failures = 0;

    // Тест 1: Положительные числа
    failures += run_mult_test(2, 3, 6, "Positive Multiplication Test");

    // Тест 2: Умножение на ноль
    failures += run_mult_test(0, 5, 0, "Zero Multiplication Test 1");
    failures += run_mult_test(7, 0, 0, "Zero Multiplication Test 2");

    // Тест 3: Отрицательные числа
    failures += run_mult_test(-2, -3, 6, "Negative Multiplication Test");
    failures += run_mult_test(-4, 5, -20, "Mixed Negative-Positive Test");
    failures += run_mult_test(3, -4, -12, "Positive-Negative Test");

    // Тест 4: Большие числа
    failures += run_mult_test(100, 50, 5000, "Large Numbers Test");

    // Тест 5: Единица (нейтральный элемент)
    failures += run_mult_test(1, 42, 42, "Identity Test 1");
    failures += run_mult_test(15, 1, 15, "Identity Test 2");

    if (failures > 0)
    {
        std::cerr << "--- " << failures << " MULTIPLICATION TEST(S) FAILED ---" << std::endl;
        return 1; // Возвращаем ненулевой код для обозначения ошибки в CI
    }

    std::cout << "--- ALL MULTIPLICATION TESTS PASSED ---" << std::endl;
    return 0;
}