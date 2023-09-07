#include <iostream>
#include <stack>

using namespace std;

bool isBalance(string s) {
    bool result = true;
    stack<char> st;
    
    for (int i=0; i<s.size(); i++) {
        // 괄호 아니면 pass
        if (s[i] != '[' && s[i] != ']' && s[i] != '(' && s[i] != ')')
            continue;
        
        if (s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ']') {
            
            if (st.empty()) {
                result = false;
                break;
            }
            
            if (st.top() == '[')
                st.pop();
            else if (st.top() == '(') {
                result = false;
                break;
            }
            
            
        } else if (s[i] == ')') {
            
            if (st.empty()) {
                result = false;
                break;
            }
            
            if (st.top() == '(')
                st.pop();
            else if (st.top() == '[') {
                result = false;
                break;
            }
        }
        
    }
    
    if (result == true && !st.empty())
        result = false;
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string input;
    
    // 입력 및 연산
    while (true) {
        getline(cin, input);
        
        if (input == ".")
            break;
            
        if (isBalance(input))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    
    return 0;
}