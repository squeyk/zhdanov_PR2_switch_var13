#include <iostream>
#include <cmath>

int main() {
    // Настройка вывода русского языка в консоли
    setlocale(LC_ALL, "Russian");

    int choice;
    std::cout << "ГЛАВНОЕ МЕНЮ" << std::endl;
    std::cout << "1. Найти второй катет треугольника" << std::endl;
    std::cout << "2. Расчет стоимости поездки на дачу" << std::endl;
    std::cout << "3. Тест: дата основания Санкт-Петербурга" << std::endl;
    std::cout << "4. Проверка попадания точки в область" << std::endl;
    std::cout << "5. Перевод математического знака в текст" << std::endl;
    std::cout << "Введите номер задания (1-5): ";
    std::cin >> choice;

    std::cout << "-----------------------------------" << std::endl;

    switch (choice) {
        case 1: {
            double c, a;
            std::cout << "Введите гипотенузу: ";
            std::cin >> c;
            std::cout << "Введите известный катет: ";
            std::cin >> a;

            
            if (c <= 0 || a <= 0) {
                std::cout << "Ошибка ввода данных: длины сторон должны быть больше нуля!" << std::endl;
            } else if (c <= a) {
                std::cout << "Ошибка ввода данных: гипотенуза должна быть строго больше катета!" << std::endl;
            } else {
                double b = std::sqrt(c * c - a * a);
                std::cout << "Второй катет равен: " << b << std::endl;
            }
            break;
        }
        case 2: {
            double distance, consumption, price;
            std::cout << "Введите расстояние до дачи (км): ";
            std::cin >> distance;
            std::cout << "Введите расход бензина (л на 100 км пробега): ";
            std::cin >> consumption;
            std::cout << "Введите цену одного литра бензина: ";
            std::cin >> price;

            
            if (distance <= 0 || consumption <= 0 || price <= 0) {
                std::cout << "Ошибка ввода данных: все параметры должны быть больше нуля!" << std::endl;
            } else {
                double total_distance = distance * 2;
                double total_liters = (total_distance * consumption) / 100.0;
                double total_cost = total_liters * price;
                std::cout << "Стоимость поездки на дачу составит: " << total_cost << " руб." << std::endl;
            }
            break;
        }
        case 3: {
            int answer;
            std::cout << "В каком году был основан Санкт-Петербург? ";
            std::cin >> answer;

            // Валидация и проверка ответа
            if (answer <= 0) {
                std::cout << "Ошибка ввода данных: год не может быть отрицательным или нулевым!" << std::endl;
            } else if (answer == 1703) {
                std::cout << "Вы ответили правильно" << std::endl;
            } else {
                std::cout << "Неверно. Правильный ответ: 1703 год." << std::endl;
            }
            break;
        }
        case 4: {
            double x, y, r;
            std::cout << "Введите координату X: ";
            std::cin >> x;
            std::cout << "Введите координату Y: ";
            std::cin >> y;
            std::cout << "Введите радиус R: ";
            std::cin >> r;

            // Валидация: геометрический радиус не может быть отрицательным или нулевым
            if (r <= 0) {
                std::cout << "Ошибка ввода данных: радиус должен быть больше нуля!" << std::endl;
            } else if (x * x + y * y <= r * r) {
                std::cout << "Точка принадлежит заштрихованной части плоскости." << std::endl;
            } else {
                std::cout << "Точка НЕ принадлежит заштрихованной части плоскости." << std::endl;
            }
            break;
        }
        case 5: {
            char op;
            std::cout << "Введите символьное обозначение операции (+, -, *, /): ";
            std::cin >> op;

            // Валидация реализована через секцию default оператора switch
            switch (op) {
                case '+':
                    std::cout << "Сложение" << std::endl;
                    break;
                case '-':
                    std::cout << "Вычитание" << std::endl;
                    break;
                case '*':
                    std::cout << "Умножение" << std::endl;
                    break;
                case '/':
                    std::cout << "Деление" << std::endl;
                    break;
                default:
                    std::cout << "Ошибка ввода данных" << std::endl;
                    break;
            }
            break;
        }
        default:
            std::cout << "Ошибка ввода данных: выбран несуществующий пункт меню!" << std::endl;
            break;
    }

    return 0;
}
