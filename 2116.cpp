#include <iostream>
using namespace std;

int main() {

    int n;
     cin >> n;
    int ** dices = new int*[n + 1];
    int ** max = new int*[n + 1];
    for(int i = 1; i<= n; i++) {
        int * line = new int[7];
        int * line2 = new int[7];
        for(int j = 1;j <= 6; j++) {
            cin >> line[j];
            
        }
        for(int j = 1;j <= 6; j++) {
            if(j == 1) {
                int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 1 && k != 6) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }else if(j==2) {
            int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 2 && k != 4) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }else if(j == 3) {
            int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 3 && k != 5) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }else if(j == 4) {
            int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 2 && k != 4) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }else if(j == 5) {
            int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 3 && k != 5) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }else if(j == 6) {
            int up = 1;
                for(int k = 1; k <=6;k++) {
                    if(k != 1 && k != 6) {
                        if(line[k] > up) {
                            up = line[k];
                        }
                    }
                }
                line2[j] = up;
            }
        }
        dices[i] = line;
        max[i] = line2;
    }
    if(n == 1) {
        cout << 6 << endl;
    }else {
        int up = 0;
        int ans = 0;
        for(int i = 1; i <= 6; i++) {
            int sum = 0;
        int down = 0;
        if(i == 1) {
            down = dices[1][6];
            sum += max[1][1];
        }else if(i == 2) {
            down = dices[1][4];
            sum += max[1][2];
        }else if(i == 3) {
            down = dices[1][5];
            sum += max[1][3];
        }else if(i == 4) {
            down = dices[1][2];
            sum += max[1][4];
        }else if(i == 5) {
            down = dices[1][3];
            sum += max[1][5];
        }else if(i == 6) {
            down = dices[1][1];
            sum += max[1][6];
        }
        
        for(int j = 2; j <= n; j++) {
            for(int k = 1; k <= 6; k++) {
                if(dices[j][k] == down) {
                    sum += max[j][k];
                    if(k == 1) {down = dices[j][6];}else if(k == 2) {down = dices[j][4];}else if(k == 3) {down = dices[j][5];}
                    else if(k == 4) {down = dices[j][2];}else if(k == 5) {down = dices[j][3];}else{down = dices[j][1];}
                    break;
                }
            }
        }
        if(sum > ans) {
            ans = sum;
        }


        }
        cout << ans << endl;
    }

}