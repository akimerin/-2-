#include <iostream>
#include <vector>
using namespace std;



// Функция для нахождения максимума в массиве
int findMax(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    else {
        int max = findMax(arr, size - 1);
        if (arr[size - 1] > max) {
            return arr[size - 1];
        }
        else {
            return max;
        }
    }
}


// Функция для решения задачи "ханойские башни"
void hanoiTowers(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Переместить диск 1 со стержня " << from_rod << " на стержень " << to_rod << endl;
        return;
    }
    hanoiTowers(n - 1, from_rod, aux_rod, to_rod);
    cout << "Переместить диск " << n << " со стержня " << from_rod << " на стержень " << to_rod << endl;
    hanoiTowers(n - 1, aux_rod, to_rod, from_rod);
}




//Алгоритм "Ход коня"

int boardSize;// Размер доски

vector<vector<int>> knightMoves;// Матрица номеров ходов коня

// Проверка, что позиция (row, col) находится на доске
bool isValidMove(int row, int col) {
    return (row >= 0 && row < boardSize&& col >= 0 && col < boardSize);
}

// Рекурсивная функция для обхода доски и генерации номеров ходов коня
void generateKnightMoves(int row, int col, int moveNumber) {
    // Если позиция (row, col) уже посещена, возвращаемся
    if (knightMoves[row][col] != 0) {
        return;
    }

    // Устанавливаем номер хода для текущей позиции
    knightMoves[row][col] = moveNumber;

    // Массивы для смещений по горизонтали и вертикали
    int rowOffsets[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Перебираем все возможные ходы коня
    for (int i = 0; i < 8; i++) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        // Проверяем, что новая позиция находится на доске
        // и еще не посещена
        if (isValidMove(newRow, newCol) && knightMoves[newRow][newCol] == 0) {
            // Делаем рекурсивный вызов для новой позиции
            generateKnightMoves(newRow, newCol, moveNumber + 1);
        }
    }
}




//Алгоритм "Расстановки ферзей"
// Функция для проверки, может ли ферзь быть расположен на данной позиции
bool canPlaceQueen(vector<vector<int>>& board, int row, int col, int n) {
    // Проверяем вертикальные линии
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Проверяем левую верхнюю диагональ
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Проверяем правую верхнюю диагональ
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Рекурсивная функция для расстановки ферзей
void placeQueens(vector<vector<int>>& board, int row, int n) {
    // Базовый случай: если все ферзи расставлены
    if (row == n) {
        // Выводим доску
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Перебираем все столбцы в текущей строке
    for (int col = 0; col < n; col++) {
        // Проверяем, можно ли разместить ферзя в данной позиции
        if (canPlaceQueen(board, row, col, n)) {
            // Размещаем ферзя на доске
            board[row][col] = 1;

            // Рекурсивно вызываем функцию для следующей строки
            placeQueens(board, row + 1, n);

            // Возвращаемся назад и удаляем ферзя с доски
            board[row][col] = 0;
        }
    }
}




int main() {
    setlocale(LC_ALL, "RUS");
    int x;
    int m;
    cout << "1.Поиск максимума в массиве " << endl;
    cout << "2.Ханойские башни" << endl;
    cout << "3.Ход коня " << endl;
    cout << "4.Растановки ферзей " << endl;
    cout << endl;
    cout << "Введите необходимый запрос(от 1 до 4): " ;
    cin >> x;
    cout << endl;


    // Запрос 1: Рекурсивный вариант поиска максимума массива
    if (x == 1) {
        int arr[] = { 3, 6, 2, 8, 1, 5 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int max = findMax(arr, size);
        cout << "Максимум в массиве: " << max << endl;
        cout << endl;
        cout << "Вывести снова меню?      1.<да>  2.<нет>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    // Запрос 2: Программная реализация "ханойских башен"
    if (x == 2) {
        cout << "Введите число высоту башни: ";
        int n;
        cin >> n;
        // Количество дисков
        cout << "Программная реализация Xанойских башен: " << endl;
        cout << endl;
        hanoiTowers(n, 'A', 'C', 'B');
        cout << endl;
        cout << "Вывести снова меню?      1.<да>  2.<нет>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    //Запрос 3: Алгоритм "Ход коня"
    if (x == 3) {
        cout << "Алгоритм Ход коня: " << endl;
        cout << endl;
        // Ввод размера доски
        cout << "Ввод размера доски: ";
        cin >> boardSize;

        // Ввод начального положения коня
        int startRow, startCol;
        cout << "Ввод начального положения коня (номер строки и номер столбца доски ЧЕРЕЗ ПРОБЕЛ): ";
        cin >> startRow >> startCol;
        cout << endl;

        // Инициализация матрицы номеров ходов коня
        knightMoves.resize(boardSize, vector<int>(boardSize, 0));

        // Генерация номеров ходов коня
        generateKnightMoves(startRow, startCol, 1);

        // Вывод матрицы номеров ходов коня
        cout << "Матрица ходов: " << endl;
        for (int row = 0; row < boardSize; row++) {
            for (int col = 0; col < boardSize; col++) {
                cout << knightMoves[row][col] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Вывести снова меню?      1.<да>  2.<нет>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    //Запрос 4: Растановки ферзей
    if (x == 4) {
        int n;
        cout << "Введите количество строк (столбцов) доски: ";
        cin >> n;
        cout << endl;

        vector<vector<int>> board(n, vector<int>(n, 0));

        placeQueens(board, 0, n);

        cout << endl;
        cout << "Вывести снова меню?      1.<да>  2.<нет>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }
}
    
