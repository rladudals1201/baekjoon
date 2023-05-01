#include <iostream>
using namespace std;

int main() {

    int papers[7];
    papers[0] = 0;
    cin >> papers[1] >>papers[2] >>papers[3] >>papers[4] >>papers[5] >>papers[6];
    
    int sum = papers[6];
  

    if(papers[5] > 0) {
        sum += papers[5];
        if(papers[1] >= 11 * papers[5]) {
            papers[1]-= 11 * papers[5];
        }else {
            papers[1] = 0;
        }
    } 
   
    if(papers[4] > 0) {
        sum += papers[4];
        int leftOver = 20 * papers[4];
        int i = 0;
        
        if(4*papers[2] >= leftOver) {
            papers[2]-= (leftOver/4);
            leftOver = 0;
        }else {
            leftOver -= 4 * papers[2];
            papers[2] = 0;
        }
        if(leftOver > 0) {
            if(papers[1] >= leftOver) {
            papers[1]-= leftOver;
        }else {
            papers[1] = 0;
        }
        
        }
    }
   
    if(papers[3] > 0) {
        if(papers[3] % 4 == 0) {
            sum += (papers[3]/4);
        } else {
            sum += (papers[3]/4 + 1);
            int left = 9*(4 - (papers[3]%4));
            if(papers[2] > 0) {
                    
                if(left % 4 == 1) {
                    papers[2]--;
                    left -=4;
                }else if(left % 4 == 2) {
                    papers[2]-=3;
                    left -=12;

                }else if(left % 4 == 3) {
                    left -=20;
                    papers[2]-=5;
                    
                }
            }
            
                if(left > 0) {
                 
                    if(papers[1] > 0) {
                        if(papers[1] > left) {
                            papers[1]-=left;
                        }else{
                            papers[1] = 0;
                        }
                    }
                }
        }
    }
   
    if(papers[2] > 0) {
        if(papers[2]%9 == 0) {
            sum +=(papers[2]/9);
        }else {
            sum +=(papers[2]/9 + 1);
            int left = 4 * (9-(papers[2]%9));
            if(papers[1] > 0) {
                if(papers[1] > left) {
                    papers[1]-=left;
                }else {
                    papers[1] = 0;
                }
            }
        }
    }
    
    if(papers[1] > 0) {
        if(papers[1]%36 == 0) {
            sum += (papers[1]/36);
        }else {
            sum += (papers[1]/36 + 1);

        }
    }
    cout <<  sum << endl;  
 
    
}