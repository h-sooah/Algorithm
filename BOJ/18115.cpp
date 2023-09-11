#include <iostream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

deque<int> dq;
stack<int> st;

void skillOne() {
    // 카드를 제일 위에 올려놓기
    int card = st.top();
    if (!st.empty())
        st.pop();
    dq.push_front(card);
}

void skillTwo() {
    // 카드를 위에서 두 번째 위치에 놓기
    int card = st.top();
    if (!st.empty())
        st.pop();
    int first = dq.front();
    if (!dq.empty())
        dq.pop_front();
    dq.push_front(card);
    dq.push_front(first);
}

void skillThree() {
    // 카드 제일 밑에 놓기
    int card = st.top();
    if (!st.empty())
        st.pop();
    dq.push_back(card);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N;
    cin >> N;
    
    for (int i=N; i>=1; i--)
        st.push(i);
    
    vector<int> skills(N);
    for (int i=N-1; i>=0; i--) {
        cin >> skills[i];
    }
    
    // 연산 & 출력
    for (int i : skills) {
        if (i == 1)
            skillOne();
        else if (i == 2)
            skillTwo();
        else
            skillThree();
    }
    
    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    
    return 0;
}
