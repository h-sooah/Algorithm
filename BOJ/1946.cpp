#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int T, N, score1, score2;
    cin >> T;
    
    // 연산 및 출력
    while (T--) {
        vector<pair<int, int>> v;
        
        cin >> N;
        
        for (int i=0; i<N; i++) {
            cin >> score1 >> score2;
            v.push_back({score1, score2});
        }
        
        sort(v.begin(), v.end());
        
        int before_score = v[0].second;
        int max = N;
        
        for (int i=1; i<N; i++) {
            if (v[i].second > before_score) {
                max--;
                continue;
            }
            before_score = v[i].second;
        }
        
        cout << max << "\n";
    }
    return 0;
}
