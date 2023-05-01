#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    map<long long, long long> m;
    vector<pair<long long,long long>> vec;
    for(long long i = 0; i < n; i++) {
        long long j,k;
        cin >> j >> k;
        if(m.find(j) == m.end()) {
            m.insert(make_pair(j,k));
        }else {
            m.find(j)->second+=k;
        }
    }
    
    double tot = 0;
    double person = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        vec.push_back(make_pair(iter->first,iter->second));
        person += iter->second;
        tot += (iter->first * iter->second);
    }
    
    person = -person;
   
    double min = tot + (person*(vec[0].first));
   
    long long ans = vec[0].first;
    for(int i = 0; i < vec.size() - 1; i++) {
        person += (2*vec[i].second);
        tot-=(2*vec[i].second * vec[i].first);
        
        double dap = 0;
        if(person < 0) {
            dap = person * vec[i + 1].first + tot;
       
            
            if(min > dap) {
            min = dap;
            ans = vec[i+1].first;       
        }
        }else {
            dap = person * vec[i].first + tot;
       
        if(min > dap) {
            min = dap;
            ans = vec[i].first;   
        }
        }
    }
   
    cout << ans << endl;
   
}
/*99995999950000*/