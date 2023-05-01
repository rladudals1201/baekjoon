#include <iostream>
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    
    int * moneys = new int[n + 1];
    for(int i = 1; i <=n;i++) {
        cin >> moneys[i];
    }
    int ** qtys = new int*[n + 1];
    
    for(int i = 0; i <=n;i++) {
        int* line = new int[k+1];
        fill(line,line + k + 1, 100000);
        line[0] = 0;
        qtys[i] = line;
    }
    for(int i = 1; i <=n;i++) {
    for(int j = 0; j <=k;j++) {
        if(j < moneys[i]) {
            qtys[i][j] = qtys[i-1][j];
        }else {
            if(qtys[i][j - moneys[i]] + 1 < qtys[i-1][j]) {
                qtys[i][j] = qtys[i][j - moneys[i]] + 1;
            }else {

                qtys[i][j] = qtys[i-1][j];
            }
        }
    }
    }
    if(qtys[n][k] == 100000) {
        cout << -1 << endl;
    }else {
    cout << qtys[n][k] << endl;

    }
}