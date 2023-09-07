#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(const pair<int, int> &A, const pair<int, int> &B) {
    if (A.first != B.first)
        return A.first > B.first;
    else
        return A.second > B.second;
}

int average(vector<int> &v) {
    double avg = 0;
    for (int i : v) {
        avg += i;
    }
        
    avg /= v.size();
    
    if (round(avg) == 0 | round(avg) == -0)
        return 0;
        
    return round(avg);
}

int middle(vector<int> &v) {
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}

int count(vector<int> &v) {
    
    int max_cnt = 1, cnt = 1;
    
    int before = v[0];
    vector<int> result;
    result.push_back(v[0]);
    for (int i=1; i<v.size(); i++) {
        if (before == v[i]) {
            cnt++;
        }
        else {
            before = v[i];
            cnt = 1;
        }
        
        if (cnt > max_cnt) {
                max_cnt = cnt;
                result.clear();
                result.push_back(v[i]);
            }
        else if (cnt == max_cnt) {
            result.push_back(v[i]);
        }
    }
    
    sort(result.begin(), result.end());
        
    if (result.size() >= 2)
        return result[1];
    else
        return result[0];
}

int range(vector<int> &v) {
    return v[v.size() - 1] - v[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    vector<int> v(N, 0);
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }

    // 연산 및 출력
    if (N == 1) {
        cout << v[0] << "\n";
        cout << v[0] << "\n";
        cout << v[0] << "\n";
        cout << 0 << "\n";
        return 0;
    }
    
    cout << average(v) << "\n";
    cout << middle(v) << "\n";
    cout << count(v) << "\n";
    cout << range(v) << "\n";
    
    return 0;
}
