#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T;
    cin >> T;
    
    // 연산 및 출력
    string input;
    bool flag = false;
    while (T--) {
        cin >> input;
        stack<char> st;
        flag = false;
        
        for (int i=0; i<input.size(); i++) {
            if (input[i] == '(')
                st.push(input[i]);
            else  {
                if (!st.empty())
                    st.pop();
                else {
                    cout << "NO\n";
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag)
            continue;
            
        if (!st.empty())
            cout << "NO";
        else
            cout << "YES";
        
        cout << "\n";
    }
    
    return 0;
}