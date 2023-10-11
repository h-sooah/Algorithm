#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll finalChildren(ll t, vector<int> &ride) {
    ll child = 0;
    for (int i=1; i<ride.size(); i++) {
        child += (t / ride[i] + 1);
    }
    return child;
}

ll lowerSearch(ll left, ll right, ll target, vector<int> &ride) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll child = finalChildren(mid, ride);
        
        // n번째 아이보다 앞에 있는 아이라면, 시간 더 늘리기
        if (child < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

int lastRide(int n, int m, vector<int> &ride) {
    // t = n번째 아이가 놀이기구를 타게 되는 시간 
    ll t = lowerSearch(0, (ll) ride[1] * n, n, ride);
    // t번째 시간에 놀이기구를 타는 마지막 아이의 번호
    ll child = finalChildren(t, ride);
    
    // 놀이긱구를 뒤에서부터 확인
    for (int i=m; i>=1; i--) {
        // 아이가 기구를 탈 수 있음
        if (t % ride[i] == 0) {
            // n번째 아이가 타는 순서라면
            if (child == n) {
                return i;
            }
            child--;
        }
    }
}

/*
 * [놀이 공원]
 *
 * n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!
 *
 * 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
 *    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
 *      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)
 *
 *    - left: 놀이기구 타는 시간의 최소 = 0
 *    - right: 놀이기구 타는 시간의 최대 = 1번 놀이기구 운행 시간 x n (타이트하게 잡으면 최소 운행 시간 x n 이지만 편의상 이렇게 설정)
 *
 *    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound
 *
 * 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서
 *    놀이기구를 m부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m;
    cin >> n >> m;
    
    vector<int> ride(m + 1, 0);
    for (int i=1; i<=m; i++)
        cin >> ride[i];
        
    // 아이의 수 <= 놀이기구의 수
    if (n <= m) {
        cout << n;
        return 0;
    }
    
    cout << lastRide(n, m, ride);
    
    return 0;
}
