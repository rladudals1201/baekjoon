#include <iostream>
#include <vector>
using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> nums;
    vector<long long> big;
    vector<long long> small;
    long long zero = 0;
    while(n) {
       if(n%2 == 0) {
            zero++;

       }
        nums.push_back(n%2);

        n/=2;
    }
    nums.push_back(n);
    
        long long size = nums.size();
    
    for(int i = size-1; i >= 0; i--) {
        
        big.push_back(nums[i]);
        small.push_back(nums[i]);
    }
    
    long long mul2 = 1;
        long long mul = 1;
        long long digit = 1;
        while(digit < size) {
            mul*=2;
            mul2 *= 2;
            digit++;
        }
    if(zero == 0) {
        cout << 0 << " ";
        long long temp = big[0];
        big[0] = big[1];
        big[1] = temp;
        long long ans = 0;
        for(long long i = 0; i < big.size(); i++) {
            ans += (mul * big[i]);
            mul/=2;
        }
        cout << ans << endl;
    }else {
        long long size = big.size();
        long long index = size-1;       
        long long zero = 0;
        long long one = 0;

        while (true) {
            if (small[index] == 0 && small[index - 1] == 1) {
                break;
            }
            if (small[index] == 0) {
                zero++;
            }
            else {
                one++;
            }
            index--;
        }
        
        long long index2 = size-1;
        long long zero2 = 0;
        long long one2 = 0;
        
        while (true) {
            if (big[index2] == 1 && big[index2 - 1] == 0) {
                break;
            }
            if (big[index2] == 0) {
                zero2++;
            }
            else {
                one2++;
            }
            index2--;
        }


        long long temp = small[index];
        small[index] = small[index - 1];
        small[index - 1] = temp;

        long long temp2 = big[index2];
        big[index2] = big[index2 - 1];
        big[index2 - 1] = temp2;
        index++;
        index2++;
        long long cnt = 0;
        while (index <= size - 1 && cnt < one) {
            small[index] = 1;
            cnt++;
            index++;
        }
        long long cnt2 = 0;
        while (index <= size - 1 && cnt2 < zero) {
            small[index] = 0;
            cnt2++;
            index++;
        }

        cnt = 0;
        while (index2 <= size - 1 && cnt < zero2) {
            big[index2] = 0;
            cnt++;
            index2++;
        }
        cnt2 = 0;
        while (index2 <= size - 1 && cnt2 < one2) {
            big[index2] = 1;
            cnt2++;
            index2++;
        }
        long long ans = 0;
        for (long long i = 0; i < small.size(); i++) {
            ans += (mul * small[i]);
            mul /= 2;
        }
        long long ans2 = 0;
        for (long long i = 0; i < big.size(); i++) {
            ans2 += (mul2 * big[i]);
            mul2 /= 2;
        }
        cout << ans << " " << ans2<< endl;
    }
   
}