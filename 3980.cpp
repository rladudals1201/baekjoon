#include <iostream>
using namespace std;
void calc(int i, int sum, int& max,int players[12][12],int play[12]) {
    if(i == 12) {
        if(max < sum) {
            max = sum;
        }
        
    }else {
    for(int j = 1; j <= 11; j++) {
        if(players[j][i] != 0 && play[j] == 0) {
         
            play[j] = 1;
            calc(i+1,sum + players[j][i],max,players,play);
            play[j] = 0;
        }
    }

    }
}
int main() {
       
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {

    int players[12][12];
    int play[12];

    for(int i =1; i <= 11; i++) {
    for(int j =1; j <= 11; j++) {
        cin >> players[i][j];
    }
        play[i] = 0;
    }

    int sum = 0;
    int max = 0;
    calc(1,sum,max,players,play);
    cout << max << "\n";
    }
}