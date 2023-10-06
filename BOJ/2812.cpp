#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

string maxNumber(int n, int k, string s) {
    
    int del = 0;
    deque<char> dq;
    
    for (int i=0; i<n; i++) {
        char c = s[i];
        
        while (!dq.empty()) {
            if (del == k)
                break;
            if (dq.back() >= c)
                break;
            dq.pop_back();
            del++;
        }
        
        dq.push_back(c);
    }
    
    string ans = "";
    // n-k자리만 출력
    for (int i=0; i<n-k; i++) {
        ans += dq[i];
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    cout << maxNumber(n, k, s);
    
    return 0;
}
