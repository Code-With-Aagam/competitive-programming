/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, ele;
    set<long long> st;
    cin >>n;
    while(n--){
        cin >>ele;
        st.insert(ele);
    }
    if(st.size() < 2){
        cout <<"NO";
    }
    else{
        auto it = st.begin();
        it++;
        cout <<*it;
    }
    return 0; 
}
