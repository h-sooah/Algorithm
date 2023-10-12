#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> isPrime(int n) {
    vector<bool> arr(n+1, true);
    
    arr[0] = arr[1] = false; // 0하고 1은 소수 아님
    for (int i=2; i*i<=n; i++) {
        if (!arr[i])
            continue;
            
        for (int j=i*i; j<=n; j+=i) {
            arr[j] = false;
        }
    }
    
    return arr;
}

vector<int> primeList(int n, vector<bool> &arr) {
    vector<int> prime;
    for (int i=2; i<=n; i++) {
        if (arr[i])
            prime.push_back(i);
    }
    
    return prime;
}

int primeSum(int left, int right, int target, vector<int> &primes) {
    int cnt = 0;
    int sum = primes[left], size = primes.size() - 1; // 더미 데이터 때문에
    while (left <= right && right < size) {
        if (sum == target) {
            cnt++;
            sum -= primes[left++]; // left를 오른쪽으로 한 칸 옮겨주기
            sum += primes[++right]; // right를 오른쪽으로 한 칸 옮겨주기
        } else if (sum < target) {
            sum += primes[++right];
        } else {
            sum -= primes[left++];
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    // 소수 배열 만들기
    vector<bool> arr = isPrime(n);
    vector<int> primes = primeList(n, arr);
    primes.push_back(0); // 인덱스 에러 방지 위해 더미 데이터 추가
    
    // 연산 및 출력
    cout << primeSum(0, 0, n, primes);
    
    return 0;
}