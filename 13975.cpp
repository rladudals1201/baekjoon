#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    
    for(long long i = 0; i < t; i++) {

        long long a;
        cin >> a;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long j = 0; j < a; j++) {
            long long num;
            cin >> num;
            pq.push(num);
        }

        long long sum = 0;
        while(pq.size() !=1) {
            long long front = pq.top();
            pq.pop();
            long long front2 = pq.top();
            pq.pop();
            sum += (front + front2);
            pq.push(front + front2);
        }
        cout << sum << "\n";
    }

}