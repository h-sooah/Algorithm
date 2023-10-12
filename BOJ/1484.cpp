#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;

vector<int> curWeight(int left, int right, int g) {
    vector<int> ans;
    while (left < right) {
        
        int diff = right * right - left * left;
        
        if (diff == g) {
            ans.push_back(right);
            left++;
            right++;
            continue;
        }
        
        if (diff < g) {
            right++;
        } else {
            left++;
        }
        
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int G;
    cin >> G;
    
    vector<int> ans = curWeight(1, 2, G);
    
    if (ans.size() == 0) {
        cout << -1;
        return 0;
    }
    
    for (int a : ans)
        cout << a << '\n';
    
    return 0;
}