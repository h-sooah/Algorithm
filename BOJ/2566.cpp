#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    // 입력 및 연산 및 출력
    vector<vector<int>> board(9, vector<int>(9, 0));
    int max = -1, row = -1, col = -1;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
            
            if (board[i][j] > max) {
                max = board[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }
    
    cout << max << "\n";
    cout << row << " " << col << "\n";
    
    return 0;
}