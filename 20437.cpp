#include <iostream>
#include <stack>
#include<queue>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    deque<int> dq;
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string input;
        cin >> input;
        int a;
        cin >> a;
        int alpha[26];
        
        vector<int> alphaIndex[26];
        fill(alpha,alpha + 26,0);
        int max  = 0;
        int min  = 100000;
        for(int j = 0; j < input.length(); j++) {
            alphaIndex[input[j]-97].push_back(j);
            
            if(alphaIndex[input[j]-97].size() >= a) {
                if(j - alphaIndex[input[j]-97][alpha[input[j]-97]] + 1 > max) {
                    max = j - alphaIndex[input[j]-97][alpha[input[j]-97]] + 1;
                }
                if(j - alphaIndex[input[j]-97][alpha[input[j]-97]] + 1 < min) {
                    min = j - alphaIndex[input[j]-97][alpha[input[j]-97]] + 1;
                }
                alpha[input[j]-97]++;
            }
        }
        if(min == 100000 && max == 0) {
            cout <<  -1 << "\n";
        }else {
        cout << min << " " << max << "\n";

        }

    }

}