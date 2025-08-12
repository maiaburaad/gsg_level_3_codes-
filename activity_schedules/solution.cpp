#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<deque>
#define pb(a) push_back(a)
#include <unordered_map>
#include <queue>
#define fst first
#define sec second
#define Hi ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define enter(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define out(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define ll long long
#define dd double
#define tt "\n"
using namespace std;

int n; 
int counter = 0; 

void recur(vector<string> cur) {
    
    if (cur.size() == n) {
        counter++; 
        for (int i = 0; i < cur.size(); i++) {
            cout << cur[i] << " ";
        }
        cout << tt; 
        return; 
    }

    if (cur.empty()) {           //اول يوم
     
        recur({ "Running" });
        recur({ "Swimming" });
        recur({ "Football" });
    }

    else if (cur.back() == "Football") {
        vector<string> A = cur;
        A.push_back("Running");
        vector<string> B = cur;
        B.push_back("Swimming");
        recur(A);
        recur(B);
    }

    else if (cur.back() == "Running") {
        vector<string> C = cur;
        C.push_back("Football");
        vector<string> B = cur;
        B.push_back("Swimming");

        recur(B);
        recur(C);
    }
    else if (cur.back() == "Swimming") {
        vector<string> C = cur;
        C.push_back("Football");
        vector<string> A = cur; 
        A.push_back("Running");

        recur(A);
        recur(C);
    }
   
}



int main() {
    cin >> n;
    recur({});

    cout << "COUNT: " << counter << tt;

  

    return 0;
}









