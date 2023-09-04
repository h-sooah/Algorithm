#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (const int &a, const int &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s;
    cin >> s;
    
    // 연산 및 출력
    vector<int> v;
    for (int i=0; i<s.size(); i++) {
        int num = s[i] - '0';
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (int i : v)
        cout << i;
    
    return 0;
}