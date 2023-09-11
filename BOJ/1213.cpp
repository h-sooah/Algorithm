#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    string s;
    cin >> s;
    
    // 연산 & 출력
    for (int i=0; i<s.size(); i++)
        alpha[s[i] - 'A']++;
        
    // 홀수 개 count
    int odd = 0;
    string last = "";
    for (int i=0; i<26; i++) {
        if (alpha[i] % 2 != 0) {
            odd++;
            last += (i + 'A');
            alpha[i]--;
        }
    }
    if (odd > 1) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    
    // 펠린드롬 만들기
    string result = "";
    for (int i=0; i<26; i++)
        alpha[i] /= 2;
    for (int i=0; i<26; i++) {
        for (int j=0; j<alpha[i]; j++)
            result += (i + 'A');
    }
    
    string rev = result;
    reverse(rev.begin(), rev.end());
    result += (last + rev);
    
    cout << result << '\n';
    
    return 0;
}
