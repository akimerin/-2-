#include <iostream>
#include <vector>
using namespace std;
// ������� ��� ���������� ��������� � �������
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


// ������� ��� ������� ������ "��������� �����"
void hanoiTowers(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "����������� ���� 1 �� ������� " << from_rod << " �� �������� " << to_rod << endl;
        return;
    }
    hanoiTowers(n - 1, from_rod, aux_rod, to_rod);
    cout << "����������� ���� " << n << " �� ������� " << from_rod << " �� �������� " << to_rod << endl;
    hanoiTowers(n - 1, aux_rod, to_rod, from_rod);
}

//�������� "��� ����"

int boardSize;// ������ �����

vector<vector<int>> knightMoves;// ������� ������� ����� ����

// ��������, ��� ������� (row, col) ��������� �� �����
bool isValidMove(int row, int col) {
    return (row >= 0 && row < boardSize&& col >= 0 && col < boardSize);
}

// ����������� ������� ��� ������ ����� � ��������� ������� ����� ����
void generateKnightMoves(int row, int col, int moveNumber) {
    // ���� ������� (row, col) ��� ��������, ������������
    if (knightMoves[row][col] != 0) {
        return;
    }

    // ������������� ����� ���� ��� ������� �������
    knightMoves[row][col] = moveNumber;

    // ������� ��� �������� �� ����������� � ���������
    int rowOffsets[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // ���������� ��� ��������� ���� ����
    for (int i = 0; i < 8; i++) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        // ���������, ��� ����� ������� ��������� �� �����
        // � ��� �� ��������
        if (isValidMove(newRow, newCol) && knightMoves[newRow][newCol] == 0) {
            // ������ ����������� ����� ��� ����� �������
            generateKnightMoves(newRow, newCol, moveNumber + 1);
        }
    }
}
//�������� "����������� ������"
// ������� ��� ��������, ����� �� ����� ���� ���������� �� ������ �������
bool canPlaceQueen(vector<vector<int>>& board, int row, int col, int n) {
    // ��������� ������������ �����
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // ��������� ����� ������� ���������
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // ��������� ������ ������� ���������
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// ����������� ������� ��� ����������� ������
void placeQueens(vector<vector<int>>& board, int row, int n) {
    // ������� ������: ���� ��� ����� �����������
    if (row == n) {
        // ������� �����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // ���������� ��� ������� � ������� ������
    for (int col = 0; col < n; col++) {
        // ���������, ����� �� ���������� ����� � ������ �������
        if (canPlaceQueen(board, row, col, n)) {
            // ��������� ����� �� �����
            board[row][col] = 1;

            // ���������� �������� ������� ��� ��������� ������
            placeQueens(board, row + 1, n);

            // ������������ ����� � ������� ����� � �����
            board[row][col] = 0;
        }
    }
}



int main() {
    setlocale(LC_ALL, "RUS");
    int x;
    int m;
    cout << "1.����� ��������� � ������� " << endl;
    cout << "2.��������� �����" << endl;
    cout << "3.��� ���� " << endl;
    cout << "4.���������� ������ " << endl;
    cout << endl;
    cout << "������� ����������� ������(�� 1 �� 4): " ;
    cin >> x;
    cout << endl;


    // ������ 1: ����������� ������� ������ ��������� �������
    if (x == 1) {
        int arr[] = { 3, 6, 2, 8, 1, 5 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int max = findMax(arr, size);
        cout << "�������� � �������: " << max << endl;
        cout << endl;
        cout << "������� ����� ����?      1.<��>  2.<���>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    // ������ 2: ����������� ���������� "��������� �����"
    if (x == 2) {
        cout << "������� ����� ������ �����: ";
        int n;
        cin >> n;
        // ���������� ������
        cout << "����������� ���������� X�������� �����: " << endl;
        cout << endl;
        hanoiTowers(n, 'A', 'C', 'B');
        cout << endl;
        cout << "������� ����� ����?      1.<��>  2.<���>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    //������ 3: �������� "��� ����"
    if (x == 3) {
        cout << "�������� ��� ����: " << endl;
        cout << std::endl;
        // ���� ������� �����
        cout << "���� ������� �����: ";
        cin >> boardSize;

        // ���� ���������� ��������� ����
        int startRow, startCol;
        cout << "���� ���������� ��������� ���� (����� ������ � ����� ������� ����� ����� ������): ";
        cin >> startRow >> startCol;
        cout << endl;

        // ������������� ������� ������� ����� ����
        knightMoves.resize(boardSize, vector<int>(boardSize, 0));

        // ��������� ������� ����� ����
        generateKnightMoves(startRow, startCol, 1);

        // ����� ������� ������� ����� ����
        cout << "������� �����: " << endl;
        for (int row = 0; row < boardSize; row++) {
            for (int col = 0; col < boardSize; col++) {
                cout << knightMoves[row][col] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << "������� ����� ����?      1.<��>  2.<���>      ";
        cin >> m;
        if (m == 1) {
            cout << endl;
            return main();
        }
        else {
            return 0;
        }
    }


    //������ 4: ���������� ������
    if (x == 4) {
        int n;
        cout << "������� ���������� ����� (��������) �����: ";
        cin >> n;
        cout << endl;

        vector<vector<int>> board(n, vector<int>(n, 0));

        placeQueens(board, 0, n);

        cout << endl;
        cout << "������� ����� ����?      1.<��>  2.<���>      ";
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
    