#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 3e9 + 1;

vector<int> mixLiquid(int N, vector<int> &liquid) {
    
    ll ans = INF, sum;
    vector<int> result;
    // 하나의 용액 미리 포함시킴
    for (int i=0; i<N; i++) {
        
        sum = liquid[i];
        int left = 0;
        if (i == 0)
            left += 1;
        int right = N-1;
        if (i == N-1)
            right -= 1;
        
        sum += liquid[left];
        sum += liquid[right];
        while (left < right) {
            
            if (sum == 0) {
                result.clear();
                result.push_back(liquid[i]);
                result.push_back(liquid[left]);
                result.push_back(liquid[right]);
                return result;
            }
            
            if (abs(sum) < ans) {
                ans = abs(sum);
                result.clear();
                result.push_back(liquid[i]);
                result.push_back(liquid[left]);
                result.push_back(liquid[right]);
            }
            
            if (sum > 0) {
                sum -= liquid[right--];
                if (right == i)
                    right--;
                sum += liquid[right];
            }
            else if (sum < 0) {
                sum -= liquid[left++];
                if (left == i)
                    left++;
                sum += liquid[left];
            }
        }
        
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    vector<int> liquid(N, 0);
    for (int i=0; i<N; i++)
        cin >> liquid[i];
    
    sort(liquid.begin(), liquid.end());
    
    vector<int> ans = mixLiquid(N, liquid);
    sort(ans.begin(), ans.end());
    
    for (int a : ans)
        cout << a << ' ';
    
    return 0;
}