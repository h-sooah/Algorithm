#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, input;
    string s;
    queue<int> q;
    cin >> N;
    
    // 연산 및 출력
    while (N--) {
        cin >> s;
        
        if (s == "push") {
            cin >> input;
            q.push(input);
        }
        else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << -1 << "\n";
        }
        else if (s == "size")
            cout << q.size() << "\n";
        else if (s == "empty")
            cout << q.empty() << "\n";
        else if (s == "front") {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << -1 << "\n";
        }
        else if (s == "back") {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << -1 << "\n";
        }
    }
    
    return 0;
}