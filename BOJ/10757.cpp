#include <iostream>
#include <string>
#include <stack>

using namespace std;

void addAAndB(string a, string b) {
    
    if (a.size() < b.size())
        swap(a, b);
    
    int diff = a.size() - b.size();
    for (int i=0; i<diff; i++)
        b = "0" + b;
    
    stack<int> result;
    int flag = 0;
    for (int i=a.size()-1; i>=0; i--) {
        
        int num1 = a[i] - '0';
        int num2 = b[i] - '0';
        
        int sum = num1 + num2 + flag;
        if (sum >= 10)
            flag = 1;
        else
            flag = 0;
            
        result.push(sum % 10);
    }
    
    if (flag)
        result.push(1);
    
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string a, b;
    cin >> a >> b;
    
    addAAndB(a, b);
    
    return 0;
}
