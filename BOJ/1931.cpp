#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool cmp (const ci &a, const ci &b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int countMeetings(int N, vector<ci> &meetings) {
    
    int cnt = 0;
    int prev_end = 0; // 전 회의의 끝나는 시각
    
    for (int i=0; i<N; i++) {
        auto[start, end] = meetings[i];
        
        if (prev_end <= start) {
            cnt++;
            prev_end = end;
        }
    }
    
    return cnt;
}

/*
 1. 끝나는 시간 순서대로 정렬
 2. 시작 시간 순서대로 정렬
 -> 끝나는 시간 <= 시작 시간인 회의 찾아서 count
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N;
    cin >> N;
    
    vector<ci> meetings(N);
    for (int i=0; i<N; i++)
        cin >> meetings[i].first >> meetings[i].second;
    
    sort(meetings.begin(), meetings.end(), cmp);
    
    cout << countMeetings(N, meetings);
    
    return 0;
}