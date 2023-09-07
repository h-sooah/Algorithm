#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int K, input;
    cin >> K;
    
    stack<int> s;
    
    // 연산 및 출력
    while (K--) {
        cin >> input;
        
        if (input == 0) {
            if (!s.empty())
                s.pop();
        } else {
            s.push(input);
        }
    }
    
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum << "\n";
    
    return 0;
}