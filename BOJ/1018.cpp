#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string black_board[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

const string white_board[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int getBlackSquare(vector<string> &board, int x, int y) {
    int num = 0;
    for (int i=x; i<x+8; i++) {
        for (int j=y; j<y+8;j++) {
            if (board[i][j] != black_board[i-x][j-y])
                num++;
        }   
    }
    return num;
}

int getWhiteSquare(vector<string> &board, int x, int y) {
    int num = 0;
    for (int i=x; i<x+8; i++) {
        for (int j=y; j<y+8;j++) {
            if (board[i][j] != white_board[i-x][j-y])
                num++;
        }   
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    vector<string> board;
    cin >> N >> M;
    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        board.push_back(s);
    }
    
    // 연산 및 출력
    int result = N * M, white, black;
    for (int i=0; i<N-7; i++) {
        for (int j=0; j<M-7; j++) {
            black = getBlackSquare(board, i, j);
            white = getWhiteSquare(board, i, j);
            result = min({result, black, white});
        }
    }
    
    cout << result;
    
    return 0;
}