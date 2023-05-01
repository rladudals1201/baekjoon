#include <iostream>
#include <vector>
using namespace std;

int main() {

    long long n,k;
    cin >> n >> k;
    long long div = 1;
    long long digit = 0;
    while(n / div != 0) {
        div*=10;
        digit++;
    }

    
    long long start =1;

    long long length = 0;

    long long digits = 9;

    while(start <= digit) {
        if(start == digit) {
            length += (start*(n - (digits/9) + 1));
        }else {
        length += (start * digits);

        }
        digits*=10;
        start++;
    }
    if(k > length) {
        cout << -1 << endl;
    }else {
        long long sum = 0;
        long long plus = 9;
        long long startNum = 1;
        long long startIndex = 0;
        long long digit = 1;
        while(sum < k) {
            sum += (digit * plus);
            plus *=10;
            startNum *= 10;
            digit++;
        }

        if(k <= 9) {
            cout << k << endl;
        }else {
        startIndex = sum - ((digit - 1) * plus/10) + 1;
        startNum/=10;
        digit--;
  
        long long resultNum = startNum + (k - startIndex)/digit;
        long long remain = (k - startIndex)%digit;
        digit--;
        while(resultNum) {
            if(digit == remain) {
                cout << resultNum%10 << endl;
                break;
            }
            digit--;
            resultNum/=10;
        }
        


        }

    }

}