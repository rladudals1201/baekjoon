#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {

int n;
cin >> n;
map<int,priority_queue<int,vector<int>,less<int>>> m;
for(int i = 0; i<n; i++) {
    int d,w;
    cin >> w>> d;
    if(m.find(d) == m.end()) {
        priority_queue<int,vector<int>,less<int>> pq;
        pq.push(w);
        m.insert(make_pair(d,pq));
    }else {
        m.find(d)->second.push(w);

    }

}
    priority_queue<int,vector<int>,greater<int>> q;
    int day = 0;
    for(auto iter =m.begin(); iter!= m.end(); iter++) {

        priority_queue<int,vector<int>,less<int>> temp = iter->second;
        while(!temp.empty() && day < iter->first) {
            q.push(temp.top());
            temp.pop();
            day++;
        }
        
        while(!temp.empty() && temp.top() > q.top()) {
            q.pop();
            q.push(temp.top());            
            temp.pop();
        }
        
    }

    int sum = 0;
    while(!q.empty()) {
        sum += q.top();
        q.pop();
    }
    cout << sum << endl;
}