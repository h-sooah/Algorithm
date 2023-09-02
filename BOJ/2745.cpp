#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    int B;
    
    // 입력
    cin >> N >> B;
    
    //연산 및 출력
    int size = N.size();
    int num, result = 0, multi = 1;
    for (int i=size-1; i>=0; i--) {
        char c = N[i];
        
        if (isalpha(c))
            num = c - 'A' + 10;
        else
            num = c - '0';
        
        result += (num * multi);
        multi *= B;
    }
    
    cout << result;
    
    return 0;
}