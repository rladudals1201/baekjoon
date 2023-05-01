#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;

    for(long long i = 1; i <= t; i++) {
        long long num;
        cin >> num;
        
        if(num % 9 != 0) {
            cout << -1 << " ";
        }else {
            long long temp = num;
            long long div = 0;
            while(temp != 0) {
                div = div*10 + 9;
                temp/=10;
            }
            long long sum = 0;
            bool result = true;
            temp = num;
            while(div != 0) {
                if(temp / div >= 10) {
                    cout << -1 << " ";
                    result = false;
                    break;
                }
                sum = sum*10 + (temp/div);
                temp = temp% div;
                div/=10;
                
            }
            if(result == true) {
            cout << sum*10 << " ";

            }
            
        }

    }

}