#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s;
    cin >> s;
    
    int n = stoi(s.substr(0, s.find(":")));
    int m = stoi(s.substr(s.find(":")+1));
    
    // 최대공약수 찾기
    int gcd = findGCD(max(n, m), min(n, m));
    
    cout << n/gcd << ":" << m/gcd << "\n";
    
    return 0;
}