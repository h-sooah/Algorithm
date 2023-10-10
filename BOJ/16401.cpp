#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cntChildren(int mid, vector<int> &snack) {
    ll sum = 0;
    for (int i=0; i<snack.size(); i++) {
        if (snack[i] < mid)
            return sum;
        sum += (snack[i] / mid);
    }
    return sum;
}

int upperLength(int left, int right, int target, vector<int> &snack) {
    while (left <= right) {
        int mid = (left + right) / 2;
        // 과자의 길이를 mid로 할 때, 과자를 받을 수 있는 아이들 수
        ll cnt = cntChildren(mid, snack);
        
        // M명의 아이들이 다 과자를 받지 못 하면 -> 과자 길이 줄이기
        if (cnt < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left - 1;
}

/*
  모든 조카에게 같은 길이의 과자 나눠주기.
  M명의 조카와 N개의 과자가 있을 때, 1명에게 줄 수 있는 최대 길이 구하기
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int m, n;
    cin >> m >> n;
    
    vector<int> snack(n, 0);
    for (int i=0; i<n; i++)
        cin >> snack[i];
        
    sort(snack.begin(), snack.end(), greater<>());
    
    cout << upperLength(1, snack[0], m, snack);
    
    return 0;
}
