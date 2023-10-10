#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntRest(int len, vector<int> &rest) {
    int sum = 0;
    for (int i=1; i<rest.size(); i++) {
        int road = rest[i] - rest[i-1];
        sum += road / len;
        if (road % len == 0 )
            sum -= 1;
    }
    return sum;
}


int lowerPeriod(int left, int right, int target, vector<int> &rest) {
    while (left <= right) {
        int mid = (left + right) / 2;
        // 휴게소 없는 구간의 최대 길이가 mid일 때, 추가 설치 가능한 휴게소 개수
        int cnt = cntRest(mid, rest);
        
        // 휴게소 개수가 M개보다 적다면 -> 더 설치할 수 있게 구간 줄이기
        if (cnt <= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

/*
  현재 휴게소 N개 있는데, M개 더 세우려는 상황.
  이미 있는 곳에 세울 수 X & 고속도로 끝에도 세울 수 X & 정수 위치에만 건설
  -> 휴게소 M개 더 지어서, 휴게소 없는 구간의 길이의 최댓값을 최소로
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, l;
    cin >> n >> m >> l;
    
    // n == 0 일 땐 입력 없음
    int input;
    vector<int> rest;
    for (int i=0; i<n; i++) {
        cin >> input;
        rest.push_back(input);
    }
    rest.push_back(0);
    rest.push_back(l);
        
    sort(rest.begin(), rest.end());
    
    cout << lowerPeriod(1, l - 1, m, rest);
    
    return 0;
}
