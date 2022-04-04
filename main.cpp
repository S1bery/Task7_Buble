#include <iostream>
#include <vector>

void full_bubbles (bool a[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            a[i][j] = true;
        }
    }
} // функция первичного заполнения

bool check_coordinates(bool a[][12], int y1, int x1, int y2, int x2) {

    if (y1 < 0 || y1 > 11 ||
        x1 < 0 || x1 > 11 ||
        y2 < 0 || y2 > 11 ||
        x2 < 0 || x2 > 11) {
        return false;
        }

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j < x2; j++) {
            if (!a[i][j]) {
                return false;
            }
        }
    }
    return true;
} // проверяет корректность ввода координат

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

    int y1, x1, y2, x2 = 0;
    int endgame = 144; // общее количество пузырьков

    while(endgame != 0) {
        std::cout << "Enter the first and second coordinates:" << std::endl;
        std::cout << "Y X Y X" << std::endl;
        std::cin >> y1 >> x1 >> y2 >> x2;
        while (!check_coordinates(bubble, y1, x1, y2, x2)) {
            std::cout << "Error! Enter the coordinates:" << std::endl;
            std::cout << "Y X Y X" << std::endl;
            std::cin >> y1 >> x1 >> y2 >> x2;
        }

        for (int i = y1; i <= y2; i++) {
            for (int j = x1; j <= x2; j++) {
                bubble[i][j] = false;
                endgame -= 1;
            }
        }
        std::cout << "Pop!" << std::endl;
        game_board(bubble);
    }

    return 0;
}
