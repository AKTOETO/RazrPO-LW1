#include "../file.h" // Тестируем нашу функцию
#include <iostream>

// Простая функция для проверки теста
// Возвращает 0, если тест пройден, 1 в противном случае
int run_test(int a, int b, int expected, const char *test_name)
{
    int result = my_sum(a, b);
    if (result == expected)
    {
        std::cout << "[PASSED] " << test_name << ": " << a << " + " << b << " = " << result << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "[FAILED] " << test_name << ": " << a << " + " << b << " = " << result
                  << ", Expected: " << expected << std::endl;
        return 1;
    }
}

int main()
{
    int failures = 0;

    // Тест 1: Положительные числа
    failures += run_test(2, 3, 5, "Positive Sum Test");

    // Тест 2: Ноль
    failures += run_test(0, 5, 5, "Zero Test");

    // Тест 3: Отрицательные числа
    failures += run_test(-1, -4, -5, "Negative Sum Test");

    // Тест 4: Положительное + Отрицательное
    failures += run_test(10, -3, 7, "Mixed Sign Test");

    if (failures > 0)
    {
        std::cerr << "--- " << failures << " TEST(S) FAILED ---" << std::endl;
        return 1; // Возвращаем ненулевой код для обозначения ошибки в CI
    }

    std::cout << "--- ALL TESTS PASSED ---" << std::endl;
    return 0;
}