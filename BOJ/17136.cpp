#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

vector<vector<int>> paper;
int paper_cnt[6] = { 0, 5, 5, 5, 5, 5 };
int ans = 0;
bool flag = false;

bool checkSize(int size, int row, int col) {
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (paper[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool fillPaper(int cur, int cnt) {
    
    //cout << "cur = " << cur << '\n';
    
    if (cur == SIZE * SIZE) {
        ans = min(ans, cnt);
        flag = true;
        return true;
    }
    
    int row = cur / SIZE;
    int col = cur % SIZE;
    
    if (paper[row][col] == 0)
        return fillPaper(cur + 1, cnt);
    
    for (int n = 5; n > 0; n--) {
        
        // 범위 내에 있는지
        if (row + n > SIZE || col + n > SIZE)
            continue;
        
        // 종이가 남아 있어야
        if (paper_cnt[n] == 0)
            continue;
        
        if (!checkSize(n, row, col))
            continue;
        
        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++)
                paper[i][j] = 0;
        }
        
        paper_cnt[n]--;
        
        fillPaper(cur + 1, cnt + 1);
        
        // 원상복구
        paper_cnt[n]++;
        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++)
                paper[i][j] = 1;
        }
    }
    
    return false;
}

bool checkPaper() {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (paper[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    paper.assign(SIZE, vector<int>(SIZE, 0));
    ans = SIZE * SIZE + 1;
    
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++)
            cin >> paper[i][j];
    }
    
    fillPaper(0, 0);
    if (flag)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
    
    return 0;
}