#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

bool comp (const point &a, const point &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, x, y;
    cin >> N;
    
    // 연산 및 출력
    vector<point> v;
    point p;
    while (N--) {
        cin >> x >> y;
        p.x = x;
        p.y = y;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (point p : v) 
        cout << p.x << " " << p.y << "\n";
    
    return 0;
}