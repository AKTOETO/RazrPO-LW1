#include "file.h"
#include <iostream>
#include <pqxx/pqxx>

int main(int argc, char *argv[])
{
    pqxx::connection C("dbname=postgres user=postgres password=2811 host=localhost port=5432");
    double sum = 0.0;
    int sum_int = my_sum(2, 3);
    std::cout << "Сумма из файла file.h:" << sum_int << std::endl;

    // Проверяем, есть ли вообще аргументы для суммирования
    if (argc <= 1)
    {
        std::cout << "person2 хочет рассказать про использование: " << argv[0] << " число1 число2 ..." << std::endl;
        std::cout << "Так, person2 говорит: Пожалуйста, предоставьте числа в качестве аргументов командной строки."
                  << std::endl;
        return 1;
    }

    // Проходим по всем аргументам, начиная с первого (argv[0] - это имя программы)
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        try
        {
            // Пытаемся преобразовать аргумент в число (double для поддержки дробных чисел)
            double num = std::stod(arg);
            sum += num;
        }
        catch (const std::invalid_argument &ia)
        {
            std::cerr << "Ошибка: '" << arg << "' не является числом и будет проигнорирован." << std::endl;
        }
        catch (const std::out_of_range &oor)
        {
            std::cerr << "Ошибка: '" << arg << "' слишком большое число." << std::endl;
        }
    }

    std::cout << "Сумма: " << sum << std::endl;

    return 0;
}
