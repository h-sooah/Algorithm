#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int divide(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return divide(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, tree;
    vector<int> trees;
    vector<int> dists;
    cin >> N;
    while (N--) {
        cin >> tree;
        trees.push_back(tree);
    }
    
    // 연산 및 출력
    // 1. 거리 정보 구하기
    for (int i=1; i<trees.size(); i++) {
        dists.push_back(trees[i] - trees[i-1]);
    }
    
    // 2. 거리들의 최대 공약수 구하기
    int GCD = dists[0];
    for (int i=1; i<dists.size(); i++) {
        GCD = divide(GCD, dists[i]);
    }
    
    // 3. 거리들을 최대공약수로 나눠서 추가해야 할 나무 개수 count
    int result = 0;
    for (int i=0; i<dists.size(); i++)
        result += (dists[i] / GCD) - 1;
    
    cout << result;
    
    return 0;
}

