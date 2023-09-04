#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    int num;
    map<int, int> m;
    while (N--) {
        cin >> num;
        if (m.find(num) == m.end())
            m.insert({num, 1});
        else 
            m[num]++;
    }
    
    // 연산 및 출력
    for (auto it = m.begin(); it != m.end(); it++) {
        int num = it -> second;
        for (int i=0; i<num; i++)
            cout << it -> first << "\n";
    }
    
    return 0;
}