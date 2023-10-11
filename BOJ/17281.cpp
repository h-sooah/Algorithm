#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int play(int n, vector<int> &cur_seq, vector<vector<int>> &games) {
    
    int score = 0, out = 0; // score: 총 점수, out: 각 이닝별 아웃 횟수
    int first = 0, second = 0, third = 0; // 1루, 2루, 3루별 사람 수 (0 or 1)
    int idx = 0; // 현재 타자의 index
    for (int i=0; i<n; i++) {
        // 3 out 시 이닝 종료
        while (out != 3) {
            int num = cur_seq[idx] - 1; // 현재 타자의 번호
            //cout << "idx = " << idx << ", num = " << num << '\n';
            idx = (idx + 1) % 9;
            
            // 아웃
            if (games[i][num] == 0) {
                out++;
                continue;
            }
            // 안타
            if (games[i][num] == 1) {
                score += third; // 3루 -> 홈
                third = second; // 2루 -> 3루
                second = first; // 1루 -> 2루
                first = 1; // 타자 -> 1루
                continue;
            }
            // 2안타
            if (games[i][num] == 2) {
                score += (third + second); // 2루, 3루 -> 홈
                third = first; // 1루 -> 3루 
                second = 1; // 타자 -> 2루 
                first = 0;
                continue;
            }
            // 3안타
            if (games[i][num] == 3) {
                score += (third + second + first); // 1루, 2루, 3루 -> 홈 
                third = 1; // 타자 -> 3루
                second = first = 0;
                continue;
            }
            // 홈런
            score += (third + second + first + 1); // 1루, 2루, 3루, 타자 -> 홈 
            third = second = first = 0;
        }
        // 초기화
        third = second = first = 0;
        out = 0;
    }
    
    return score;
}

int maxScore(int n, vector<vector<int>> &games) {
    
    vector<int> seq; // 타순
    for (int i=2; i<=9; i++) {
        seq.push_back(i);
    }
    
    int ans = -1;
    do {
        
        vector<int> cur_seq = seq;
        cur_seq.insert(cur_seq.begin() + 3, 1);
        
        ans = max(ans, play(n, cur_seq, games));
        
    } while (next_permutation(seq.begin(), seq.end()));
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    vector<vector<int>> games(n, vector<int>(9, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<9; j++)
            cin >> games[i][j];
    }
    
    cout << maxScore(n, games);
    
    return 0;
}