#include <iostream>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int N, call, sum = 0, hour, min;
	string time;
	cin >> N;


	while (N--) {

		cin >> time >> call;
		
		hour = (time[0] - '0') * 10 + (time[1] - '0');
		min = (time[3] - '0') * 10 + (time[4] - '0');

		// 기준 바뀜

		if ((hour == 18 && min + call > 60) || (hour == 6 && min + call > 60)) {
			int min_a, min_b;

			min_a = 60 - min;
			min_b = call - min_a;

			// 18:mm -> 19:mm
			if (hour == 18) {
				sum += (min_a * 10 + min_b * 5);
			}
			// 06:mm -> 07:mm
			else {
				sum += (min_a * 5 + min_b * 10);
			}
		}


		// 기준 안 바뀜
		else {
			
			// 07:00 ~ 19:00
			if (hour >= 7 && hour < 19) {
				sum += (call * 10);
			}
			// 19:00 ~ 07:00
			else {
				sum += (call * 5);
			}
		}
	}

	cout << sum << "\n";
	return 0;

	/*
	18:00 60

	19:00

	59 * 10 + 5 = 595
	*/
}