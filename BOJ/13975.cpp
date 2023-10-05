#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll calMinCost(priority_queue<ll, vector<ll>, greater<>> &pq) {
    
    vector<ll> result;
    while (pq.size() > 1) {
        ll f1 = pq.top();
        pq.pop();
        ll f2 = pq.top();
        pq.pop();
        ll f = f1 + f2;
        pq.push(f);
        result.push_back(f);
    }
    
    ll ans = 0;
    for (ll i : result) {
        ans += i;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int T;
    cin >> T;
    
    int k, file;
    while (T--) {
        cin >> k;
        
        priority_queue<ll, vector<ll>, greater<>> pq;
        while (k--) {
            cin >> file;
            pq.push(file);
        }
        
        cout << calMinCost(pq) << '\n';
    }
    
    return 0;
}