#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int a,n;
    cin >> a >> n;
    int * turn = new int[n + 1];
    int * on = new int[n + 1];
    int * index = new int[n + 1];
    fill(index,index+n+1,10000);
    int plugged = 0;
    for(int i = 1; i <= n; i++) {
        cin >> turn[i];
        on[i] = 0;
    }
    int count = 0;
    
    vector<set<int>> vec;
    
    set<int> s;
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        
        if(count < a) {
            if(on[turn[i]] == 0) {
            on[turn[i]] = 1;
            count++;

            }
        }else {
            if(on[turn[i]] == 0) {
                
        for(int j = i+1; j <= n; j++) {
            if(on[turn[j]] == 1 && index[turn[j]] == 10000) {
                index[turn[j]] = j;
            }
        }
        int max = 0;
        int change = 0;
        for(int j = 1; j <= n; j++) {
            if(on[j] == 1 && max < index[j]) {
                max = index[j];
                change = j;
            }
        }
    
        on[change] = 0;
       
        on[turn[i]] = 1;
        ans++;
        fill(index,index+n+1,10000);
            }
        }

    }
    cout << ans << endl;
}