#include <iostream>
using namespace  std;

int main()
{

	int n;
	cin >> n;

	int* index = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		int number;
		cin >> number;
		index[number] = i;
	}
	/*for (int i = 1; i <= n; i++) {
		cout << index[i] << " ";
	}
	cout << endl;*/
	int curr = index[1];
	int seq = 1;
	int max = 1;
	for (int i = 2; i <= n; i++) {
		if (index[i] > curr) {
			seq++;

		}
		else {
			seq = 1;
		}
		if (max < seq) {
			max = seq;
		}
		curr = index[i];
	}
	cout << n - max << endl;
}