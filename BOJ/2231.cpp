#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int N) {
    int sum;
    
    for (int i=1; i<N; i++) {
        sum = N;
        sum -= i;
        
        string s = to_string(i);
        for (int j=0; j<s.size(); j++) {
            int tmp = s[j] - '0';
            sum -= tmp;
        }
        
        if (sum == 0)
            return i;
    }
    
    return 0;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    // 입력
    cin >> N;
    
    // 출력
    cout << solution(N);
    
    return 0;
}