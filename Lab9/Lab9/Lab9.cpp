

#include <iostream>
#include <sstream>
#include <string>



int count(const std::string& number) {
    int count = 0;
    for (char c : number) {
        if (c != '.' && std::isdigit(c)) {
            count++;
        }
    }
    return count;
}

int countr(const std::string& str) {
    if (str.empty()) {
        return 0;
    }
    if (str[0] == '.') {
        return countr(str.substr(1));
    }
    return 1 + countr(str.substr(1));
}

int main() {

    setlocale(LC_ALL, "rus");

    std:: string number;
    std::cout << "Введите число: ";
    std::cin >> number;

    std::cout << "Количество цифр в числе с помощью цикла: " << count(number) << std::endl;
    std::cout << "Количество цифр в числе с помощью рекурсии: " << countr(number) << std::endl;

    return 0;
}
