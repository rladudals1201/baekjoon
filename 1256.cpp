#include <iostream>
using namespace std;
long long factorial(long long n2,long long m2) {
    if (m2 == 0 || n2 == m2) {
        return 1;
    }
    long long mul = 1;
    if(n2 - m2 > m2) {
        for(long long i = n2; i >= n2-m2; i--) {
            mul *=i;
        }
        for(long long i = m2; i >= 1; i--) {
            mul /=i;
        }
    }else {
        for(long long i = n2; i >= m2; i--) {
            mul *=i;
        }
        for(long long i = n2-m2; i >= 1; i--) {
            mul /=i;
        }
    }
    return mul;
}
int main() {

    long long n, m, k;
    cin >> n >> m >> k;

    long long sum = 0;
    long long qty = 1;
    long long aCount = n;
    long long zCount = m;
    while(k) {
        
        long long n2 = 0;
        long long m2 = m - qty;
        
        long long value = 0;
        while(true) {
         value += factorial(n2 + m2,m2);
        
         if(value >= k) {
            break;
         }
         n2++;         
        }
        
        value -= factorial(n2 + m2,m2);
        n2--;
         
        
        /*cout << "value : " << value << endl;
        cout << "aCount : " << aCount << endl;
        cout << "n2 : " << n2 << endl;*/
        for(int i = 1; i <= aCount-n2; i++) {
            cout << "a";
        }
        aCount=aCount - (aCount-n2);
        cout << "z"<<endl;
        k-=value;
        /*cout << "k: " << k << endl;*/
        zCount--;
        qty++;
    }

    for(int i = 0; i < zCount; i++) {
        cout << "i : " << i << endl;
        cout << "z";

    }

    if(sum > k) {
        cout << -1 << endl;
    }

}