#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    
    priority_queue<int,vector<int>,less<int>> pq;
    
    int qty1 = n;
    int qty2 = 0;

    while(true) {
        if(1000 * qty1 + qty2 * 5000 >= x) {
            break;
        }
        qty1--;
        qty2++;
    }
    if(1000 * qty1 + qty2 * 5000 > x) {
        qty2--;
        qty1++;
    }

    int amount = 0;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a>> b;
        amount += b;
        pq.push(a-b);
    }
    int ocheon = 0;
    while(ocheon < qty2 && !pq.empty()) {
        if(pq.top() <= 0) {
            break;
        }
       
        amount += pq.top();
        ocheon++;
        pq.pop();
    }
    cout << amount << endl;

}