#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    vector<string> v;
    string s;
    while (N--) {
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (int i=0; i<v.size(); i++) {
        if (i != 0 && v[i] == v[i-1])
            continue;
        cout << v[i] << "\n";
    }
    
    return 0;
}