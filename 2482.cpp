#include <iostream>
#define DIV 1000000003
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << n << endl;
    }else {
        
     

            long long ** counts = new long long*[n + 1];
            for(long long i = 1; i <= n; i++) {

                long long * line = new long long[k + 1];
                fill(line, line + k + 1, 0);
                counts[i] = line;

            }

            for(long long j = 1; j <=k ;j++) {
                if(j == 1) {
            for(long long i = 1; i <= n; i++) {
                
                counts[i][j] = i;
            
            }
            }else {
             for(long long i = j * 2; i <= n; i++) {
                
                counts[i][j] = (counts[i-1][j]%DIV + counts[i-2][j-1]%DIV) % DIV;
            
            }   
            }
            }
            cout << counts[n][k] << endl;
    }

}