#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    string input;
    set<string> s;
    vector<string> v;
    cin >> N >> M;
    while (N--) {
        cin >> input;
        s.insert(input);
    }
    
    while (M--) {
        cin >> input;
        if (s.find(input) != s.end())
            v.push_back(input);
    }
    
    // 연산 및 출력
    sort(v.begin(), v.end());
    
    cout << v.size() << "\n";
    for (string str : v)
        cout << str << "\n";
    
    return 0;
}

