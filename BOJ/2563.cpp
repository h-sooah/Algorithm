#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    vector<vector<int>> board(100, vector<int>(100, 0));
    
    // 입력
    cin >> N;
    
    //연산 및 출력
    int a, b;
    while (N--) {
        cin >> a >> b;
        
        for (int i=b; i<b+10; i++) {
            for (int j=a; j<a+10; j++) {
                if (board[i][j] == 1)
                    continue;
                board[i][j] = 1;
            }
        }
    }
    
    int cnt = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (board[i][j] == 1)
                cnt++;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}