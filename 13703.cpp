#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    unsigned long long n,k;
    cin >> n >> k;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    unsigned long long** num = new unsigned long long*[n + 1];
    for(int i = 1; i <= n; i++) {
        unsigned long long * line = new unsigned long long[n + 1];
        num[i] = line;
        
    for(int j = 0; j <= i; j++) {
        if(j == 0 || j == i) {
            num[i][j] = 1;
        }else {
            num[i][j] = num[i-1][j] + num[i-1][j-1];
        }
    }
    }

    unsigned long long a = 1;
    vector<unsigned long long> vec;
    unsigned long long mul = 1;
    
    for(int j = 0; j < n; j++) {
        vec.push_back(num[n][j]);
    }
   
    
    long long start = n + 1;
    if(n % 2 == 0) {

    while(start <= k){
    vector<unsigned long long> tempVec;
        tempVec.push_back(1);

    for(int i = 0; i < vec.size()-1; i++) {
     tempVec.push_back(vec[i] + vec[i + 1]);   
    }

    if(start % 2 == 1) {
        tempVec.push_back(vec[vec.size()-1]);
    }else {

    }
    vec = tempVec;
    start++;
    }
    unsigned long long ans = 0;
    for(int i = 0; i < vec.size(); i++) {
     ans += vec[i];
    }
    cout << ans << endl;
    }else {

     while(start <= k){
    vector<unsigned long long> tempVec;
        tempVec.push_back(1);

    for(int i = 0; i < vec.size()-1; i++) {
     tempVec.push_back(vec[i] + vec[i + 1]);   
    }

    if(start % 2 == 0) {
        tempVec.push_back(vec[vec.size()-1]);
    }
    vec = tempVec;
    start++;
    }
    unsigned long long ans = 0;
    for(int i = 0; i < vec.size(); i++) {
     ans += vec[i];
    }
    cout << ans << endl;
    }

 
    
}