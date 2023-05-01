#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    char* bulbs = new char[n+1];
    char* change = new char[n+1];
    
    for(int i = 1; i <= n; i++) {
        cin >> bulbs[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> change[i];
    }
    int qty = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            if(bulbs[1] == change[1] && bulbs[2] == change[2]) {
                
            }

        }else if(i == n) {

        }else {
        if(bulbs[i] != change[i]) {
            
        }

        }

    }

}