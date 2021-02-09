#include <bits/stdc++.h>
using namespace std;

void queryAndSave(vector<int>& a, int i){
    if(a[i] == 0){
        cout << "? " << i << endl;
        cin >> a[i];
    }
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N + 2, 0);
    a[0] = INT_MAX;
    a[N + 1] = INT_MAX;

    int l = 1;
    int r = N;
    while(l != r){
        int mid = (l + r + 1) / 2;
        queryAndSave(a, mid - 1);
        queryAndSave(a, mid);
        if(a[mid - 1] < a[mid]){
            r = mid - 1;
        }else{
            l = mid;
        }
    }

    cout << "! " << r << endl;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    solve(cin, cout);

    return 0;
}