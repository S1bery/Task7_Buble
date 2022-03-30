#include <iostream>
#include <vector>

void full_bubbles (bool a[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            a[i][j] = true;
        }
    }
} // функция первичного заполнения

bool check_coordinates(bool a[][12], int y, int x) {

    if (y < 0 || y > 11 ||
        x < 0 || x > 11) {
        return false;
        }
    if (!a[y][x]) {
        return false;
        } else {
        a[y][x] = false;
        return true;
        }
} // проверяет корректность ввода координат и лопает пузырик

void game_board(bool a[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (a[i][j]) {
                std::cout << "o" << " ";
            } else {
                std::cout << "x" << " ";
            }
        }
        std::cout << std::endl;
    }
} // выводит актуальное поле

int main() {
    bool bubble[12][12];
    full_bubbles(bubble);

    game_board(bubble); // первыичный вывод поля

    int y = 0; // столбец
    int x = 0; // строка
    int endgame = 144; // общее количество пузырьков

    while(endgame != 0) {
        std::cout << "Enter the coordinates:" << std::endl;
        std::cin >> y >> x;
        while (!check_coordinates(bubble, y, x)) {
            std::cout << "Error! Enter the coordinates:" << std::endl;
            std::cin >> y >> x;
        }

        if (endgame == 0) {
            break;
        } else {
            std::cout << "Pop!" << std::endl;
            endgame -= 1;
            game_board(bubble);
        }
    }

    return 0;
}
