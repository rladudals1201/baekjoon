#include <iostream>
#include <map>
using namespace std;

int main() {

    long long n,p,q,x,y;
    cin >> n >> p >> q >> x >> y;
    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }
    map<long long, long long>m;
    
    m.insert(make_pair(n,1));
    long long ans = 0;
    while(!m.empty()) {

        auto iter = m.end();
        iter--;
        long long index = iter->first;
        if(index / p - x<= 0) {
            ans += iter->second;
        }else {
            auto iter2 = m.find(index/p - x);
            if(iter2 != m.end()) {
                iter2->second += iter->second;
            }else {
                m.insert(make_pair(index/p - x,iter->second));
            }
        }

        if(index / q - y <= 0) {
            ans += iter->second;
            
        }else {
            auto iter2 = m.find(index/q - y);
            if(iter2 != m.end()) {
                iter2->second += iter->second;
            }else {
        m.insert(make_pair(index/q - y,iter->second));

            }
        }
        m.erase(index);
    }
    cout << ans << endl;
}