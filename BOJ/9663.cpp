#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 15;

int n, ans;
vector<bool> check_col(SIZE);
vector<bool> check_left(SIZE * 2);
vector<bool> check_right(SIZE * 2);


void backtracking(int row) {
    if (row == n) {
        ans++;
        return;
    }
    
    for (int i = 0; i < n; i++) { //i: 열
        //세로, 좌하향 대각선, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
        if (!check_col[i] && !check_left[row + i] && !check_right[row - i + n]) {
            //(row, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true;
            check_left[row + i] = true;
            check_right[row - i + n] = true;
            backtracking(row + 1); //다음 행 호출
            //재탐색이 가능하도록 원래 상태로 돌려주어야 함
            check_col[i] = false;
            check_left[row + i] = false;
            check_right[row - i + n] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n;

    // 출력
    backtracking(0);
    cout << ans;
    
    return 0;
}