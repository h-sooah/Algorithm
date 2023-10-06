#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int countClass(int N, vector<ci> &lec) {
    
    // 종료 시간을 저장하는 우선순위 큐, 최소 힙
    priority_queue<int, vector<int>, greater<>> pq;
    
    pq.push(-1); // 인덱스 에러를 방지하기 위해 더미 데이터 삽입 
    
    for (int i=0; i<N; i++) {
        // 시작 시간이 가장 빨리 끝나는 시간보다 크거나 같다면
        // 같은 강의실 사용 가능
        if (lec[i].first >= pq.top())
            pq.pop();
            
        pq.push(lec[i].second); // 신규 종료 시간 삽입
    }
    
    return pq.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N;
    cin >> N;
    
    vector<ci> lecture(N, {0, 0}); // first: 수업 시작, second: 수업 끝
    for (int i=0; i<N; i++)
        cin >> lecture[i].first >> lecture[i].second;
    
    sort(lecture.begin(), lecture.end()); // 시작 시간 순으로 오름차순 정렬 
    
    cout << countClass(N, lecture);
    
    return 0;
}
