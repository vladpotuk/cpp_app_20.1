#include <iostream>
#include <Windows.h>
int main() {
    system("chcp 1251");
    system("cls");
    double distance_AB, distance_BC, cargo_weight;

    std::cout << "������ ������� �� �������� � � � (��): ";
    if (!(std::cin >> distance_AB)) {
        std::cerr << "������� �������� ������ �� �������� � � �." << std::endl;
        return 1;
    }

    std::cout << "������ ������� �� �������� � � � (��): ";
    if (!(std::cin >> distance_BC)) {
        std::cerr << "������� �������� ������ �� �������� � � �." << std::endl;
        return 1;
    }

    std::cout << "������ ���� ������� (��): ";
    if (!(std::cin >> cargo_weight)) {
        std::cerr << "������� �������� ���� �������." << std::endl;
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
        std::cout << "˳��� �� ���� ������ ������ ����� ����� 2000 ��. ������ ����������." << std::endl;
        return 1;
    }

    double fuel_needed_AB = distance_AB * fuel_consumption;
    double fuel_needed_BC = distance_BC * fuel_consumption;

    double total_fuel_needed = fuel_needed_AB + fuel_needed_BC;

    if (total_fuel_needed <= 300.0) {
        std::cout << "������ ��� ����������" << std::endl;
    }
    else {
        double refueling_needed = total_fuel_needed - 300.0;
        std::cout << "��� ��������� �������� ������� " << total_fuel_needed << " ���� ������." << std::endl;
        std::cout << "��������� ����������� " << refueling_needed << " ���� ������ � ����� �." << std::endl;
    }

    return 0;
}
