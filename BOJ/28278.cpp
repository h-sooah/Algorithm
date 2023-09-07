#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, input, num;
    cin >> N;
    
    stack<int> s;
    // 연산 및 출력
    while (N--) {
        cin >> input;
        
        if (input == 1) {
            cin >> num;
            s.push(num);
        } else if (input == 2) {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }
            else
                cout << -1 << "\n";
        } else if (input == 3) {
            cout << s.size() << "\n";
        } else if (input == 4) {
            cout << s.empty() << "\n";
        } else {
            if (!s.empty())
                cout << s.top() << "\n";
            else
                cout << -1 << "\n";
        }
    }
    
    return 0;
}