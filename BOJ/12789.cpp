#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, input;
    cin >> N;
    
    stack<int> st;
    queue<int> q;
    vector<int> original;
    vector<int> result;
    
    // 연산 및 출력
    while (N--) {
        cin >> input;
        q.push(input);
        original.push_back(input);
    }
    
    int cur = 1; // 현재 순서
    // 큐가 빌 때까지
    while (!q.empty()) {
        // 큐의 첫 번째 원소가 현재 순서가 맞으면
        if (q.front() == cur) {
            result.push_back(cur);
            cur++;
            q.pop();
        }
        
        // 현재 순서가 아니면
        else {
            // 스택 비었으면 그냥 넣기
            if (st.empty()) {
                st.push(q.front());
                q.pop();
            }
            // 스택 안 비었을 때
            else {
                // 스택의 첫 번째 원소가 현재 순서일 때
                if (st.top() == cur) {
                    result.push_back(cur);
                    cur++;
                    st.pop();
                }
                else {
                    st.push(q.front());
                    q.pop();
                }
            }
        }
    }
    
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    sort(original.begin(), original.end());
    
    // 순서 비교
    for (int i=0; i<result.size(); i++) {
        if (original[i] != result[i]) {
            cout << "Sad";
            return 0;
        }
    }
    
    cout << "Nice";
    
    return 0;
}