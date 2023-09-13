#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, K;
    cin >> N >> K;
    
    queue<int> queue;
    for (int i=1; i<=N; i++)
        queue.push(i);
    
    // 연산 & 출력
    vector<int> v;
    while (!queue.empty()) {
        int num;
        for (int i=0; i<K-1; i++) {
            num = queue.front();
            queue.pop();
            queue.push(num);
        }
        
        num = queue.front();
        queue.pop();
        v.push_back(num);
    }
    
    cout << "<";
    for (int i=0; i<v.size(); i++) {
        if (i == v.size() - 1)
            cout << v[i] << ">";
        else
            cout << v[i] << ", ";
    }

    return 0;
}