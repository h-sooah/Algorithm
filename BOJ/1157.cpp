#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    int count[26] = { 0 };
    
    // 입력
    cin >> s;
    
    // 연산 및 출력
    int size = s.size();
    
    char c;
    for (int i=0; i<size; i++) {
        c = toupper(s[i]);
        count[c - 'A']++;
    }
    
    bool flag = true;
    int max_num = 0;
    int max_index = -1;
    for (int i=0; i<26; i++) {
        if (count[i] > max_num) {
            flag = true;
            max_num = count[i];
            max_index = i;
        }
        else if (count[i] == max_num) {
            flag = false;
        }
    }
    
    if (flag == false)
        cout << "?" << "\n";
    else {
        char result = max_index + 'A';
        cout << result << "\n";
    }
        
        
    return 0;
}