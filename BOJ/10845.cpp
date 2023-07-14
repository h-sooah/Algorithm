#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10e4 + 1;
vector<int> queue(SIZE);
int pointer_front = 0, pointer_rear = 0;

int empty() {
	return pointer_front == pointer_rear;
}

void push(int x) {
	pointer_rear++;
	queue[pointer_rear] = x;
}

int pop() {
	if (empty())
		return -1;
	return queue[++pointer_front];
}

int size() {
	int num = pointer_rear - pointer_front;
	return num;
}

int front() {
	if (empty())
		return -1;
	return queue[pointer_front + 1];
}

int back() {
	if (empty())
		return -1;
	return queue[pointer_rear];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int N;
	cin >> N;

	string cmd;
	int x;
	while (N--) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> x;
			push(x);
			continue;
		}

		if (cmd == "pop") {
			cout << pop() << "\n";
			continue;
		}

		if (cmd == "size") {
			cout << size() << "\n";
			continue;
		}

		if (cmd == "empty") {
			cout << empty() << "\n";
			continue;
		}

		if (cmd == "front") {
			cout << front() << "\n";
			continue;
		}

		if (cmd == "back") {
			cout << back() << "\n";
			continue;
		}
	}
	return 0;
}