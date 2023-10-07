#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNumber(int left, int right, int target, vector<int> &v) {
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (v[mid] > target) {
            right = mid - 1;
        }
        else if (v[mid] < target) {
            left = mid + 1;
        }
        else if (v[mid] == target) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N, M, input;
    cin >> N;
    
    vector<int> v(N, 0);
    for (int i=0; i<N; i++)
        cin >> v[i];
    
    // !정렬!
    sort(v.begin(), v.end());
    
    cin >> M;
    while (M--) {
        cin >> input;
        cout << findNumber(0, N-1, input, v) << '\n';
    }
    
    return 0;
}
