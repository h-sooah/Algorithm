#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int calMaxSubjects(int n, int m, vector<int> &v) {
    
    // 오름차순 정렬
    sort(v.begin(), v.end());
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        if (v[i] > m)
            break;
        
        m -= v[i];
        ans++;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, m, p, l, mile;
    cin >> n >> m;
    
    vector<int> miles;
    for (int i=0; i<n; i++) {
        priority_queue<int> pq;
        
        cin >> p >> l;
        
        for (int j=0; j<p; j++) {
            cin >> mile;
            pq.push(mile);
        }
        
        if (p < l) {
            //cout << "top: 1\n";
            miles.push_back(1);
            continue;
        }
        
        //각 과목별 수강 위한 마일리지 구하기
        for (int j=0; j<l-1; j++) {
            if (pq.empty())
                break;
            pq.pop();
        }
        //cout << "top: " << pq.top() << '\n';
        miles.push_back(pq.top()); // 수강하는 데 필요한 마일리지
        
    }

    // 최대 수강 가능 과목 개수 구하기
    cout << calMaxSubjects(n, m, miles);
    
    return 0;
}