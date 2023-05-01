#include <iostream>
using namespace std;
/*
11
DDACDDAADDA
ADDACDDAADD (틀린 답)
*/
int main() {

    int a;
    
    cin >> a;
    char * str = new char[a];
    for(int i = 0; i < a;i++) {
        cin >> str[i];
    }
    string ans;
    
    int left = 0;
    int right = a-1;
    int letter = 0;
    while(left < right) {
        
        if(str[left] < str[right]){
           
            ans += str[left];
            left++;
            letter++;
        }else if(str[left] == str[right]){

            int temp1 = left + 1;
            int temp2 = right - 1;
            int same = str[left];
            while(temp1 < temp2 && str[temp1] == str[temp2] && str[temp1] <= same) {
                same = str[temp1];
                temp1++;
                temp2--;
            }

            if(str[temp1] > str[temp2]) {
                while(right > temp2) {
                   
                
            ans += str[right];
                right--;
            letter++;
                }
            }else {
            while(left < temp1) {
           
               
            ans += str[left];
                left++;
                letter++;
                }
            }

        }else {
              
            ans += str[right];
            
            right--;
 letter++;
        }


    }
    
            ans += str[left];
   
    letter++;
    
    for(int i = 0; i < ans.length(); i++) {
        cout << ans[i];
        if( i != 0 && i % 80 == 79) {
            cout << "\n";
        }
    }
    
}
