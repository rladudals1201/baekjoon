#include <iostream>
#include <map>
using namespace std;

int main() {

    long long n,p,q;
    cin >> n >> p >> q;
    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }
    map<long long, long long>m;
    map<long long, long long>m2;
    m.insert(make_pair(n,1));
    long long ans = 0;
    while(!m.empty()) {

        auto iter = m.end();
        iter--;
        long long index = iter->first;
        if(index / p == 0) {
            ans += m.find(index)->second;
        }else {
            if(m.find(index/p) != m.end()) {
                m.find(index/p)->second += m.find(index)->second;
            }else {
        m.insert(make_pair(index/p,m.find(index)->second));

            }
        }

        if(index / q == 0) {
            ans += m.find(index)->second;
            
        }else {
            if(m.find(index/q) != m.end()) {
                m.find(index/q)->second += m.find(index)->second;
            }else {
        m.insert(make_pair(index/q,m.find(index)->second));

            }
        }
        m.erase(index);
    }
    cout << ans << endl;
}