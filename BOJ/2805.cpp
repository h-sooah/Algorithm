#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = 1;
const int MAX = 1000000000;

long long calLength(int l, vector<int> &trees) {
    long long sum = 0;
    for (int i=0; i<trees.size(); i++) {
        if (trees[i] - l <= 0)
            return sum;
        sum += (trees[i] - l);
    }
    return sum;
}

int upperHeight(int left, int right, int target, vector<int> &trees) {
    while (left <= right) {
        int mid = (left + right) / 2;
        // 절단기의 높이를 mid로 설정했을 때, 가져갈 수 있는 나무의 길이
        long long length = calLength(mid, trees);
        
        // 나무의 길이가 너무 짧아 -> 절단기의 높이 낮추기
        if (length < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left - 1;
}

/*
  적어도(최소) M미터의 나무를 가져갈 수 있는 H의 최댓값 구하기
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m;
    cin >> n >> m;
    
    vector<int> trees(n, 0);
    for (int i=0; i<n; i++)
        cin >> trees[i];
      
    // 정렬 -> 최댓값 줄어들고(not 10e9), calLength 바로 return 가능하므로 더 효율적 
    sort(trees.begin(), trees.end(), greater<>());
    
    cout << upperHeight(1, trees[0], m, trees);
    
    return 0;
}
