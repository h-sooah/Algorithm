#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    vector<int> v;
    map<int, int> m;
    int input;
    while (N--) {
        cin >> input;
        v.push_back(input);
        m.insert({input, 0});
    }
    
    int flag = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        it -> second = flag;
        flag++;
    }
    
    
    for (int i : v)
        cout << m[i] << " ";
    
    
    return 0;
}

