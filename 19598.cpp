#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count;
	multimap<int, priority_queue<int, vector<int>, greater<int>>> times;

	cin >> count;

	priority_queue<int, vector<int>, greater<int>> queue;
	int answer = 0;
	for (int i = 0; i < count; i++) {
		int start, end;

		cin >> start >> end;
		if (times.find(start) == times.end()) {
			priority_queue<int, vector<int>, greater<int>> insertQueue;
			insertQueue.push(end);
			times.insert(make_pair(start, insertQueue));
		}
		else {
			times.find(start)->second.push(end);
		}


	}

	for (auto iter = times.begin(); iter != times.end(); iter++) {


		while (!(iter->second.empty())) {

			if (queue.empty()) {
				queue.push(iter->second.top());
			}
			else {
				if (iter->first >= queue.top()) {
					queue.pop();
					queue.push(iter->second.top());
				}
				else {
					queue.push(iter->second.top());
				}
			}
			iter->second.pop();
		}
	}
	/*while (!queue.empty()) {
		int val = queue.top();
		cout << val << endl;
		queue.pop();
	}*/
	cout << queue.size() << endl;
}