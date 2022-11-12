#include "bits/stdc++.h"
using namespace std;

bool palindromeCheck(string x) {
    int len = 0;
    while(len<=x.length()/2) {
        if(x[len] != x[x.length()-1-len]) {
            return false;
        }
        len++;
    }
    return true;
}

int main() {
    string soal;
    cin >> soal;
    string t = soal, t1, t2;
    string u,m;
    bool d = false;
    for (int i = 1; i < soal.length(); i++)
    {
        t = soal;
        u = t.substr(0,i);
        m = t.erase(0,i);
        if(palindromeCheck(u) && palindromeCheck(m)) {
            d = 1;
            t1=u;
            t2=m;
        }
    }
    if(d) {
        cout << t1 << " " << t2;
    }else{
        cout << "NO\n";
    }
}