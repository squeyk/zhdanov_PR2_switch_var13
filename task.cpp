#include <iostream>
#include <cmath> // Dlya std::sqrt v pervom zadanii

int main() {
    // Ne ispolzuem setlocale, tak kak tekst vyveden latinicey

    int choice;
    std::cout << "=== GLAVNOE MENU ===" << std::endl;
    std::cout << "1. Nayti vtoroy katet treugolnika" << std::endl;
    std::cout << "2. Raschet stoimosti poezdki na dachu" << std::endl;
    std::cout << "3. Test: data osnovaniya Sankt-Peterburga" << std::endl;
    std::cout << "4. Proverka popadaniya tochki v oblast" << std::endl;
    std::cout << "5. Perevod matematicheskogo znaka v tekst" << std::endl;
    std::cout << "Vvedite nomer zadaniya (1-5): ";
    std::cin >> choice;

    std::cout << "-----------------------------------" << std::endl;

    switch (choice) {
        case 1: {
            double c, a;
            std::cout << "Vvedite gipotenuza: ";
            std::cin >> c;
            std::cout << "Vvedite izvestniy katet: ";
            std::cin >> a;

            // Validaciya: storony > 0 i gipotenuza > katet
            if (c <= 0 || a <= 0) {
                std::cout << "Oshibka vvoda: dliny storon dolzhny byt bolshe nulya!" << std::endl;
            } else if (c <= a) {
                std::cout << "Oshibka vvoda: gipotenuza dolzhna byt strogo bolshe kateta!" << std::endl;
            } else {
                double b = std::sqrt(c * c - a * a);
                std::cout << "Vtoroy katet raven: " << b << std::endl;
            }
            break;
        }
        case 2: {
            double distance, consumption, price;
            std::cout << "Vvedite rasstoyanie do dachi (km): ";
            std::cin >> distance;
            std::cout << "Vvedite rashod benzina (l na 100 km): ";
            std::cin >> consumption;
            std::cout << "Vvedite cenu odnogo litra benzina: ";
            std::cin >> price;

            // Validaciya: vse parametry dolzhny byt polozhitelnymi
            if (distance <= 0 || consumption <= 0 || price <= 0) {
                std::cout << "Oshibka vvoda: vse parametry dolzhny byt bolshe nulya!" << std::endl;
            } else {
                double total_distance = distance * 2;
                double total_liters = (total_distance * consumption) / 100.0;
                double total_cost = total_liters * price;
                std::cout << "Stoimost poezdki sostavit: " << total_cost << " rub." << std::endl;
            }
            break;
        }
        case 3: {
            int answer;
            std::cout << "V kakom godu byl osnovan Sankt-Peterburg? ";
            std::cin >> answer;

            if (answer <= 0) {
                std::cout << "Oshibka vvoda: god dolzhen byt bolshe nulya!" << std::endl;
            } else if (answer == 1703) {
                std::cout << "Vy otvetili pravilno" << std::endl;
            } else {
                std::cout << "Neverno. Pravilniy otvet: 1703 god." << std::endl;
            }
            break;
        }
        case 4: {
            double x, y, r;
            std::cout << "Vvedite koordinatu X: ";
            std::cin >> x;
            std::cout << "Vvedite koordinatu Y: ";
            std::cin >> y;
            std::cout << "Vvedite radius R: ";
            std::cin >> r;

            // Validaciya: radius dolzhen byt strogo polozhitelnym
            if (r <= 0) {
                std::cout << "Oshibka vvoda: radius dolzhen byt bolshe nulya!" << std::endl;
            } else if (x * x + y * y <= r * r) {
                std::cout << "Tochka prinadlezhit zashtrihovannoy oblasti." << std::endl;
            } else {
                std::cout << "Tochka NE prinadlezhit zashtrihovannoy oblasti." << std::endl;
            }
            break;
        }
        case 5: {
            char op;
            std::cout << "Vvedite simvol operacii (+, -, *, /): ";
            std::cin >> op;

            switch (op) {
                case '+':
                    std::cout << "Slozhenie" << std::endl;
                    break;
                case '-':
                    std::cout << "Vychitanie" << std::endl;
                    break;
                case '*':
                    std::cout << "Umnozhenie" << std::endl;
                    break;
                case '/':
                    std::cout << "Delenie" << std::endl;
                    break;
                default:
                    std::cout << "Oshibka vvoda dannyh" << std::endl;
                    break;
            }
            break;
        }
        default:
            std::cout << "Oshibka vvoda: vybran nesushestvuyushiy punkt menu!" << std::endl;
            break;
    }

    return 0;
}
