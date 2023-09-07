#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    deque<int> dq;
    vector<int> v;
    int N, K, tmp;
    cin >> N >> K;
    
    for (int i=1; i<=N; i++)
        dq.push_back(i);
        
    // 연산 및 출력
    while (!dq.empty()) {
        
        for (int i=0; i<K-1; i++) {
            tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
        
        tmp = dq.front();
        dq.pop_front();
        v.push_back(tmp);
    }
    
    cout << "<";
    for (int i=0; i<v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << ">";
    
    return 0;
}