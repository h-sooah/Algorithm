#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    
    for (int i=0; i<N; i++)
        cin >> A[i];
    for (int i=0; i<N; i++)
        cin >> B[i];
    
    // 연산 및 출력
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    int sum = 0;
    for (int i=0; i<N; i++)
        sum += (A[i] * B[i]);
        
    cout << sum << "\n";
    
    return 0;
}
