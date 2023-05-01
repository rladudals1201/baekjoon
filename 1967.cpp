#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    map<int, map<int, int>> numMap;
    int* rad = new int[n + 1];
    fill(rad, rad + n + 1, 0);
    for (int i = 0; i < n-1; i++) {

        int start, end, dist;
        cin >> start >> end >> dist;

        if (numMap.find(start) == numMap.end()) {

            map<int, int> child;
            child.insert(make_pair(end, dist));
            numMap.insert(make_pair(start, child));
        }
        else {

            numMap.find(start)->second.insert(make_pair(end, dist));
        }
    }

    int max = 0;
   

    auto iter = numMap.end();
    iter--;

    while (true) {
        int val = 0;
        vector<int> inserts;
       /* cout << "node : " << iter->first << endl;*/
       int index = 0;
        for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
            inserts.push_back(iter2->second + rad[iter2->first]);
            if (iter2->second + rad[iter2->first]> val) {
                val = iter2->second + rad[iter2->first];
                index = iter2->first;
            }
        }

        sort(inserts.begin(), inserts.end());

        if (inserts.size() == 1) {
            if (inserts[0] > max) {
                max = inserts[0];
            }
        }
        else {
            int size = inserts.size();
            if (inserts[size-1] + inserts[size-2] > max) {
                max = inserts[size - 1] + inserts[size - 2];
            }

        }

        rad[iter->first] = val;
        rad[index] = val;

        if (iter == numMap.begin()) {
            break;
        }
        iter--;
    }

    cout << max << endl;
}