#include <iostream>
#include <cmath>

using namespace std;

long long findGCD(long long a, long long b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    long long gcd, lcm;
    cin >> gcd >> lcm;
    
    long long mul = gcd * lcm;
    long long ans1 = gcd, ans2 = lcm;
    for (long long i=2*gcd; i*i<=mul; i+=gcd) {
        if (mul % i != 0)
            continue;
        
        long long tmp = mul / i;
        if (findGCD(i, tmp) != gcd)
            continue;
            
        if (ans1 + ans2 > i + tmp) {
            ans1 = i;
            ans2 = tmp;
        }
    }
    
    cout << ans1 << " " << ans2 << '\n';
    
    return 0;
}


// A, B
// l, g
// l * g = a * b