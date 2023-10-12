#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

ci maxVisitor(int n, int x, vector<int> &blog) {
    int visitor = 0;
    for (int i=0; i<x; i++)
        visitor += blog[i];
    
    int max_visitor = visitor;
    int cnt = 1;
    for (int i=x; i<n; i++) {
        visitor -= blog[i-x];
        visitor += blog[i];
        if (visitor > max_visitor) {
            max_visitor = visitor;
            cnt = 1;
        } else if (visitor == max_visitor) {
            cnt++;
        }
    }
    
    return {max_visitor, cnt};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, x;
    cin >> n >> x;
    
    vector<int> blog(n, 0);
    for (int i=0; i<n; i++)
        cin >> blog[i];

    // 출력
    ci ans = maxVisitor(n, x, blog);
    
    if (ans.first == 0) {
        cout << "SAD";
    } else {
        cout << ans.first << '\n' << ans.second;
    }
    
    return 0;
}