#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    cin >> N >> M;
    
    string input;
    set<string> s;
    while (N--) {
        cin >> input;
        s.insert(input);
    }
    
    // 연산 및 출력
    int cnt = 0;
    while (M--) {
        cin >> input;
        if (s.find(input) != s.end())
            cnt++;
    }
    
    cout << cnt;
    
    return 0;
}

