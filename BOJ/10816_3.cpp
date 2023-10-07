#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(int left, int right, int target, vector<int> &v) {
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (v[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int upperBound(int left, int right, int target, vector<int> &v) {
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (v[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
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
        cout << upperBound(0, N-1, input, v) - lowerBound(0, N-1, input, v) << ' ';
    }
    
    return 0;
}
