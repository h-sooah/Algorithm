#include <iostream>
#include <stack>

using namespace std;

int valueOfStr(string s) {
    
    stack<char> st;
    
    int tmp = 1, result = 0;
    
    for (int i=0; i<s.size(); i++) {
        
        if (s[i] == '(') {
            st.push(s[i]);
            tmp *= 2;
            continue;
        }
        
        if ( s[i] == '[') {
            st.push(s[i]);
            tmp *= 3;
            continue;
        }
        
        if (s[i] == ')') {
            if (st.empty() || st.top() == '[')
                return 0;
                
            if (s[i-1] == '(')
                result += tmp;
            
            tmp /= 2;
            st.pop();
        }
        
        if (s[i] == ']') {
            if (st.empty() || st.top() == '(')
                return 0;
                
            if (s[i-1] == '[')
                result += tmp;
            
            tmp /= 3;
            st.pop();
        }
    }
    
    if (!st.empty())
        return 0;
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s;
    cin >> s;
    
    // 연산 & 출력
    cout << valueOfStr(s);

    return 0;
}