#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, input;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> input;
            
            if (pq.size() < n) {
                pq.push(input);
                //cout << "push: " << input << '\n';
                continue;
            }
            
            if (pq.top() < input) {
                //cout << "pop: " << pq.top() << '\n';
                pq.pop();
                pq.push(input);
                //cout << "push: " << input << '\n';
            }
        }
    }
    
    // 출력
    cout << pq.top() << '\n';
    
    return 0;
}