#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int N, K, M;
	cin >> N >> K >> M;

	// 큐 채우기
	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	// 반전 요세푸스 순열
	int direction = 1, m = 0;
	for (int i = 0; i < N; i++) {

		// 정방향
		if (direction % 2 != 0) {
			
			// K번째 찾을 때까지 반복: 앞 제거 뒤 삽입
			for (int j = 1; j < K; j++) {
				int front = dq.front();
				dq.pop_front();
				dq.push_back(front);
			}

			// K번째 사람 제거
			cout << dq.front() << "\n";
			dq.pop_front();
			m++;

			// M명 제거 -> 방향 바꾸기
			if (m == M) {
				m = 0;
				direction++;
			}
		}

		// 역방향
		else {

			// K번째 찾을 때까지 반복: 뒤 제거 앞 삽입
			for (int j = 1; j < K; j++) {
				int back = dq.back();
				dq.pop_back();
				dq.push_front(back);
			}

			// K번째 사람 제거
			cout << dq.back() << "\n";
			dq.pop_back();
			m++;

			// M명 제거 -> 방향 바꾸기
			if (m == M) {
				m = 0;
				direction++;
			}
		}
	}

	return 0;
}