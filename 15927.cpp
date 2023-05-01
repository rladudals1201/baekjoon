#include <iostream>
using namespace std;

int main() {

    string input;
    cin >> input;
    int length = input.length();
    int alpha[26];
    fill(alpha,alpha + 26,0);
    for(int i = 0; i < length;i++) {
        alpha[input[i]-65]++;
    }
    int i = 0;
    while(i < length) {
        if(input[i] != input[length-1-i]) {
            break;
        }
        i++;
    }
    if(i != length) {
        cout << length << endl;
            
    }else {
        int cou = 0;
        for(int i = 0; i < 26; i++) {
            if(alpha[i] > 0) {
                cou++;
            }
        }
        if(cou == 1) {
            cout << -1 << endl;
        }else {
            cout << length-1 << endl;
        }
    }
}