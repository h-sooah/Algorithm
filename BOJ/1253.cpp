#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGood(int target, int target_index, int N, vector<int> &arr) {
    int left = 0, right = N-1;
    while (left < right) {
        
        if (left == target_index) {
            left++;
            continue;
        }
        
        if (right == target_index) {
            right--;
            continue;
        }
        
        int sum = arr[left] + arr[right];
        
        if (sum == target)
            return true;
        
        if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return false;
}

int cntGood(int N, vector<int> &arr) {
    
    int ans = 0;
    for (int i=0; i<N; i++) {
        if (isGood(arr[i], i, N, arr))
            ans++;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    vector<int> arr(N, 0);
    for (int i=0; i<N; i++)
        cin >> arr[i];
        
    sort(arr.begin(), arr.end());
        
    cout << cntGood(N, arr);
    
    return 0;
}