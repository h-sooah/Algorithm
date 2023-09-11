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
    vector<int> tips(N);
    // 연산 및 출력
    for (int i=0; i<N; i++) {
        cin >> tips[i];
    }
    
    sort(tips.begin(), tips.end(), greater<>());
    
    long long sum = 0;
    for (int i=0; i<N; i++) {
        int tip = tips[i] - i;
        if (tip < 0)
            break;
        sum += tip;
    }
    
    cout << sum << "\n";
    
    return 0;
}
