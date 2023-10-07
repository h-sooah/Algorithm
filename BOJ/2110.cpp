#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최소 인접 거리가 dist 일 때, 설치할 수 있는 최대 공유기 개수
int countRouter(int dist, vector<int> &house) {
    int cnt = 1; // 일단 첫 번째 집에 설치하고 시작 -> 1개부터 count
    int last = house[0]; // 마지막으로 공유기 설치한 집
    
    for (int i=1; i<house.size(); i++) {
        if (house[i] - last >= dist) {
            cnt++;
            last = house[i];
        }
    }
    
    return cnt;
}

int upperSearch(int left, int right, int target, vector<int> &house) {
    while (left <= right) {
        // left, right, mid -> 집 사이 최소 인접 거리를 나타냄
        int mid = (left + right) / 2;
        int installed = countRouter(mid, house); // 최소 인접 거리가 k일 때 설치된 최대 공유기 개수
        
        // 설치된 공유기 개수가 목표 개수보다 적으면 
        // 거리를 좁혀서 개수를 더 늘려야 함
        if (installed < target) {
            right = mid - 1;
        }
        // 설치된 공유기 개수가 목표 개수보다 많으면
        // 거리를 늘려서 개수를 줄여야 함
        // 설치된 공유기 개수가 같은 경우에도 오른쪽으로 이동 
        // -> 그렇게 해야 upper bound를 구할 수 있음
        // (현재 우리가 구하고 싶은 건 최대 인접 거리이기 때문)
        else {
            left = mid + 1;
        }
    }
    
    return left - 1;
}

/*
  [Parametric Search]
  - 최적화 문제 -> 결정 문제
  - 이분 탐색 활용 
  - 비오름차순 or 비내림차순 정렬 필수
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, c;
    cin >> n >> c;
    
    vector<int> house(n, 0);
    for (int i=0; i<n; i++)
        cin >> house[i];
    
    // 정렬
    sort(house.begin(), house.end());
    
    // left: 제일 왼쪽 집의 위치 (X)
    // left: 인접 거리의 최소값 = 1
    // right: 제일 오른쪽 집의 위치 (X)
    // right: 인접 거리의 최대값 = 마지막 집의 위치 - 첫 번째 집의 위치
    cout << upperSearch(1, house[n-1] - house[0], c, house);
    
    return 0;
}
