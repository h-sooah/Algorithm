#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, k;
    cin >> n >> k;
    
    vector<bool> check(26, false);
    
    vector<char> v(n, '?');
    int idx = 0, num;
    char c;
    while (k--) {
        cin >> num >> c;
        
        int alpha = c - 'A';
        idx = (idx + num) % n;
        if (v[idx] == '?') {
            if (!check[alpha]) {
                v[idx] = c;
                check[alpha] = true;
            } else {
                cout << "!";
                return 0;
            }
            
        }
        else if (v[idx] == c) {
            continue;
        }
        else {
            cout << "!";
            return 0;
        }
    }
    
    for (int i=0; i<n; i++) {
        cout << v[idx];
        idx = (idx - 1 + n) % n;
    }
    
    return 0;
}
