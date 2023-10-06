#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ci;

ll calMinCost(int N, vector<ci> oil) {
    ll ans = 0;
    
    ll cost = oil[0].second;
    for (int i=0; i<N; i++) {
        if (oil[i].second < cost) // 오일 가격 더 낮으면 교체
            cost = oil[i].second;
        
        ans += cost * oil[i].first;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N;
    cin >> N;
    
    vector<ci> oil(N, {0, 0}); // first: 다음 도시로의 거리, second: oil 가격
    
    for (int i=0; i<N-1; i++)
        cin >> oil[i].first;
    for (int i=0; i<N; i++)
        cin >> oil[i].second;
    
    cout << calMinCost(N, oil);
    return 0;
}