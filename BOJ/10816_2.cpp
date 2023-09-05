#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M, input;
    map<int, int> m;
    cin >> N;
    while (N--) {
        cin >> input;
        if (m.find(input) != m.end())
            m[input]++;
        else
            m.insert({input, 1});
    }
    
    // 연산 및 출력
    cin >> M;
    while (M--) {
        cin >> input;
        if (m.find(input) != m.end())
            cout << m[input] << " ";
        else
            cout << 0 << " ";
    }
    
    return 0;
}

