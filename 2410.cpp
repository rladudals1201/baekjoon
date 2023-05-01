#include <iostream>
using namespace std;

int main() {

    long long n;
    cin >> n;

    long long * count = new long long[n + 1];
    fill(count,count+n+1,0);
    count[0] = 1;
    
    long long k = 1;
    while(k <= n) {

        for(long long i = 0 ; i <= n; i++) {
            if(i >= k) {
                count[i] = (count[i]%1000000000 + count[i-k]%1000000000)%1000000000;
            }
        }

        k*=2;
    }
    cout << count[n] << endl;
}