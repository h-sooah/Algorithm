#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, B;
    vector<char> result;
    
    // 입력
    cin >> N >> B;
    
    // 연산 및 출력
    int num;
    char c;
    while (N != 0) {
        num = N % B;
        
        if (num >= 10) {
            num -= 10;
            c = num + 'A';
        }
        else {
            c = num + '0';
        }
        
        result.push_back(c);
        
        N /= B;
    }
    
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    
    return 0;
}