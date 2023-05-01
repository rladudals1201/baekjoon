#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int * num = new int[n];
    int * cou = new int[1000001];
    int * ans = new int[n];
    fill(cou, cou + 1000001, 0);
    fill(ans, ans + n, -1);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        cou[num[i]]++;
    }
    stack<int> st;
    for(int i =0;i < n;i++) {
    while(!st.empty()) {
        int comp = st.top();
       
        if(cou[num[comp]] >= cou[num[i]]) {
            
            break;
        }
        ans[comp] = num[i];
        st.pop();
    }
    st.push(i);

    }
    for(int i =0;i < n;i++) {
        cout << ans[i] << " ";
    }
    
}