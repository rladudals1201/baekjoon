#include <iostream>
using namespace std;

int main() {

    long long n;
    cin >> n;
    long long * num = new long long[n + 1];
    
    long long qtys[21];
    
    fill(qtys, qtys+21,0);
    
    for(int i =1; i <= n; i++) {
        cin >> num[i];
    }

    qtys[num[1]]++;

    for(int i =2; i <= n - 1; i++) {
    long long temp[21];
    fill(temp, temp+21,0);
    for(int j =0; j <= 20; j++) {
        if(qtys[j] > 0) {
            if(j + num[i] >= 0 && j + num[i] <= 20) {
            temp[j + num[i]] += qtys[j];

            }
            if(j - num[i] >= 0 && j - num[i] <= 20) {
            temp[j - num[i]] += qtys[j];

            }
        }
    }
    for(int j =0; j <= 20; j++) {
    qtys[j] = temp[j];

    }
    }
    long long ans = 0;
    for(int j =0; j <= 20; j++) {
        
    if(j == num[n]) {
        
        ans = qtys[j];
    }

    }
    cout << ans << endl;
}