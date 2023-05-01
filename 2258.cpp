#include <iostream>
#include <map>
#include <set>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,m;
    cin >> n >> m;
    map<long long, priority_queue<long long, vector<long long>, less<long long> >> mp;

    for(int i= 0; i < n; i++) {
        long long w,p;
        cin >> w >> p;
        if(mp.find(p) ==mp.end()) {
            priority_queue<long long, vector<long long>, less<long long>> s;
            s.push(w);
            mp.insert(make_pair(p,s));
        }else {
            mp.find(p)->second.push(w);
        }
    }

    long long s = 0;

    auto iter = mp.begin();
    bool result = false;
    long long comp = 10000000000;
    long long price2 = 10000000000;
    while(iter != mp.end()) {
        long long temp = s;
        
        long long tot = 0;
        long long price = 0;
        while(!(iter->second.empty())) {
        auto iter2= iter->second.top();
        price += iter->first;
        temp+=iter2;    
        if(temp >= m) {
            result = true;
            if(price < comp) {
                comp = price;
            }
        }  
            iter->second.pop();
        }
        
        s = temp;
        iter++;
    }


    if(!result) {
        cout << -1 << endl;
    }else {
       
   cout << comp << endl;

    }
}