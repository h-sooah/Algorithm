#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSushi(int d, int k, int c, vector<int> &sushi) {
    vector<int> check(d+1, 0);
    int kind = 0;
    for (int i=0; i<k; i++) {
        if (!check[sushi[i]])
            kind++;
        check[sushi[i]]++;
    }
    // 쿠폰 적용
    if (!check[c])
        kind++;
    check[c]++;
    
    int ans = kind;
    int size = sushi.size();
    for (int i=k; i<size; i++) {
        check[sushi[i-k]]--;
        if (!check[sushi[i-k]])
            kind--;
        
        if (!check[sushi[i]])
            kind++;
        check[sushi[i]]++;
        
        ans = max(ans, kind);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    
    vector<int> sushi(N, 0);
    for (int i=0; i<N; i++) {
        cin >> sushi[i];
    }
    
    // 회전 위해 맨 앞 k-1개 초밥 뒤에도 추가
    for (int i=0; i<k; i++)
        sushi.push_back(sushi[i]);
    
    cout << maxSushi(d, k, c, sushi);
    
    return 0;
}