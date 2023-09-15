#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1e6;

vector<bool> prime(MAX+1, true);

void isPrime() {
    
    prime[0] = prime[1] = false;
    
    for (int i=2; i*i<=MAX; i++) {
        if (prime[i] == false)
            continue;
        for (int j=i*i; j<=MAX; j+=i) {
            if (prime[j] == true)
                prime[j] = false;
        }
    }
}

string calGoldbach(int n) {
    string result = "";
    for (int i=3; i<=n/2; i+=2) {
        if (prime[i] && prime[n-i]) {
            result += to_string(n);
            result += " = ";
            result += to_string(i);
            result += " + ";
            result += to_string(n-i);
            return result;
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    isPrime();
    
    // 입력
    int num;
    while (true) {
        cin >> num;
        
        if (num == 0)
            return 0;
        
        cout << calGoldbach(num) << "\n";
    }
    
    
    return 0;
}