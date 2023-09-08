#include <iostream>

using namespace std;

const int SIZE = 10;

int n, ans;
bool check_row[10][10]; // 행 검사 : x행에 숫자 y가 있으면 true
bool check_col[10][10]; // 열 검사 : x열에 숫자 y가 있으면 true
bool check_square[10][10]; // 작은 정사각형 검사 : x번째 작은 정사각형에 숫자 y가 있으면 true

int sudoku[10][10];

bool backtracking(int num) {
    
    if (num == 81) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++)
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        return true;
    }
    
    int x = num / 9; // x좌표
    int y = num % 9; // y좌표
    
    // 채워져있으면 pass
    if (sudoku[x][y] != 0)
        return backtracking(num+1);
    
    // 안 채워져있으면
    // 채울 숫자 찾기
    int square = 3*(x/3)+y/3;
    for (int i=1; i<=9; i++) {
        // 세 조건 다 충족하는 숫자 찾으면
        if (!check_row[x][i] && !check_col[y][i] && !check_square[square][i]) {
            sudoku[x][y] = i;
            check_row[x][i] = true;
            check_col[y][i] = true;
            check_square[square][i] = true;
            
            // 다시 돌아올 필요 없으니까
            if (backtracking(num+1))
                return true;
            
            sudoku[x][y] = 0;
            check_row[x][i] = false;
            check_col[y][i] = false;
            check_square[square][i] = false;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++)
            cin >> sudoku[i][j];
    }

    // 연산 및 출력
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            int num = sudoku[i][j];
            if (num != 0) {
                check_row[i][num] = true;
                check_col[j][num] = true;
                check_square[3*(i/3)+j/3][num] = true;
            }
        }
    }
    
    backtracking(0);
    
    return 0;
}