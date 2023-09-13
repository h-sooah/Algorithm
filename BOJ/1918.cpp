#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) {
    switch(ch) {
        case '*': case '/':
            return 1;
        case '+': case '-':
            return 2;
        case '(': case ')':
            return 3;
    }
}

string translate(string s) {
    string ans = "";
    stack<char> oper;
    
    for (int i=0; i<s.size(); i++) {
        // +, -, *, /
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            
            while (!oper.empty() && priority(oper.top()) <= priority(s[i])) {
                ans += oper.top();
                oper.pop();
            }
            
            oper.push(s[i]);
        }
        // 여는 괄호
        else if (s[i] == '(') {
            oper.push(s[i]);
        }
        // 닫는 괄호
        else if (s[i] == ')') {
            while (!oper.empty() && oper.top() != '(') {
                ans += oper.top();
                //cout << "ans: " << ans << '\n';
                oper.pop();
            }
            oper.pop();
        }
        // 알파벳
        else {
            ans += s[i];
        }
    }
    
    while (!oper.empty()) {
        ans += oper.top();
        oper.pop();
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s;
    cin >> s;
    
    // 연산 & 출력
    cout << translate(s);
    
    return 0;
}
