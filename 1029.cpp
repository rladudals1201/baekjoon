#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    char** arr = new char*[n + 1];
    for(int i = 1; i <= n; i++) {
        char * line = new char[n + 1];
        for(int j = 1; j <= n; j++) {
            cin >> line[j];
        }
        arr[i] = line;
    }

    

}