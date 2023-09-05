#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M, input;
    cin >> N;
    
    set<int> s;
    while (N--) {
        cin >> input;
        s.insert(input);
    }
    
    // 연산 및 출력
    cin >> M;
    while (M--) {
        cin >> input;
        if (s.find(input) != s.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    
    return 0;
}

