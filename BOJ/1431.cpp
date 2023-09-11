#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
        
    int a_sum = 0, b_sum = 0;
    for (int i=0; i<a.size(); i++) {
        int c = a[i] - '0';
        // 숫자면
        if (c >= 0 && c <=9)
            a_sum += c;
    }
    for (int i=0; i<b.size(); i++) {
        int c = b[i] - '0';
        if (c >= 0 && c <=9)
            b_sum += c;
    }
    
    if (a_sum != b_sum)
        return a_sum < b_sum;
    
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N;
    cin >> N;
    
    vector<string> guitars(N);
    
    // 연산 및 출력
    for (int i=0; i<N; i++) {
        cin >> guitars[i];
    }
    
    sort(guitars.begin(), guitars.end(), cmp);
    
    for (string s : guitars)
        cout << s << "\n";
    
    return 0;
}
