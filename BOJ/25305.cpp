#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const int &a, const int &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, k;
    cin >> N >> k;
    
    int num;
    vector<int> v;
    while (N--) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    // 연산 및 출력
    cout << v[k - 1];
    
    return 0;
}