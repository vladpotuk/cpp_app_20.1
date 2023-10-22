#include <iostream>
#include <Windows.h>
int main() {
    system("chcp 1251");
    system("cls");
    double distance_AB, distance_BC, cargo_weight;

    std::cout << "Введіть відстань між пунктами А і В (км): ";
    if (!(std::cin >> distance_AB)) {
        std::cerr << "Помилка введення відстані між пунктами А і В." << std::endl;
        return 1;
    }

    std::cout << "Введіть відстань між пунктами В і С (км): ";
    if (!(std::cin >> distance_BC)) {
        std::cerr << "Помилка введення відстані між пунктами В і С." << std::endl;
        return 1;
    }

    std::cout << "Введіть вагу вантажу (кг): ";
    if (!(std::cin >> cargo_weight)) {
        std::cerr << "Помилка введення ваги вантажу." << std::endl;
        return 1;
    }

    double fuel_consumption = 0.0;

    if (cargo_weight <= 500) {
        fuel_consumption = 1.0;
    }
    else if (cargo_weight <= 1000) {
        fuel_consumption = 4.0;
    }
    else if (cargo_weight <= 1500) {
        fuel_consumption = 7.0;
    }
    else if (cargo_weight <= 2000) {
        fuel_consumption = 9.0;
    }
    else {
        std::cout << "Літак не може підняти вантаж вагою понад 2000 кг. Польот неможливий." << std::endl;
        return 1;
    }

    double fuel_needed_AB = distance_AB * fuel_consumption;
    double fuel_needed_BC = distance_BC * fuel_consumption;

    double total_fuel_needed = fuel_needed_AB + fuel_needed_BC;

    if (total_fuel_needed <= 300.0) {
        std::cout << "Польот без дозаправки" << std::endl;
    }
    else {
        double refueling_needed = total_fuel_needed - 300.0;
        std::cout << "Для подолання відстаней потрібно " << total_fuel_needed << " літрів палива." << std::endl;
        std::cout << "Необхідно дозаправити " << refueling_needed << " літрів палива в пункті В." << std::endl;
    }

    return 0;
}
