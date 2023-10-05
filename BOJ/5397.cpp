#include <iostream>
#include <string>
#include <deque>

using namespace std;

string dqToString(deque<char> dq) {
    string result = "";
    while (!dq.empty()) {
        result += dq.front();
        dq.pop_front();
    }
    return result;
}

string getPassword(string s) {
    
    deque<char> cursor_left;
    deque<char> cursor_right;
    
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == '<') {
            if (!cursor_left.empty()) {
                cursor_right.push_front(cursor_left.back());
                cursor_left.pop_back();
            }
            continue;
        }
        
        if (s[i] == '>') {
            if (!cursor_right.empty()) {
                cursor_left.push_back(cursor_right.front());
                cursor_right.pop_front();
            }
            continue;
        }
        
        if (s[i] == '-') {
            if (!cursor_left.empty())
                cursor_left.pop_back();
            continue;
        }
        
        cursor_left.push_back(s[i]);
    }
    
    string ans = "";
    ans += dqToString(cursor_left);
    ans += dqToString(cursor_right);
    
    return ans;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int T;
    cin >> T;
    
    string s;
    while (T--) {
        cin >> s;
        
        cout << getPassword(s) << '\n';
    }
    
    return 0;
}