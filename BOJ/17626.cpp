#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> square;
int n;

bool isPossible(int cnt, int sum, int m) {
    bool check = false; // m개의 제곱수 합 표현 가능한지
    
    if (cnt == m) {
        if (sum == n)
            return true;
        return false;
    }
    
    for (int i=square.size()-1; i>=0; i--) {
        if (sum + square[i] <= n) {
            check = isPossible(cnt+1, sum+square[i], m);
            if (check)
                return true;
        }
        
    }
    return check;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> n;
    
    // 제곱수 미리 저장
    for (int i=1; i<=sqrt(n); i++)
        square.push_back(i*i);
    
    // 3개의 조합까지만 구함
    int ans = 4; // 우선 4로 초기화
    for (int i=1; i<=3; i++) {
        if (isPossible(0, 0, i)) {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
