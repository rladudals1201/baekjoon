#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int * A = new int[N + 1];
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

bool changed = false;
for (int i=1; i<=N+1; i++) {
    changed = false;
    for (int j=1; j<=N-i; j++) {
        if (A[j] > A[j+1]) {
            changed = true;
            swap(A[j], A[j+1]);
        }
    }
    if (changed == false) {
        cout << i << '\n';
        break;
    }
}
for (int i=1; i<=N; i++) {
cout << A[i] << " ";
}

}