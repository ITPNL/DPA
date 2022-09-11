#include <bits/stdc++.h>
#include <iostream>
using namespace std;
ifstream fi("NGUOC.INP");
ofstream fo("NGUOC.OUT");
int main(){
    while (!fi.eof()){
        int k, n; fi >> k >> n;
        int sl = k;
        while (n){
            if (k/10 == 0) fo << k << " ";
            else {
                int x = 0;
                while (k){
                    x = x*10 + k%10;
                    if (k % 10) fo << k%10;
                    k/=10;
                }
                k = x;
                fo << " ";
            }
            n--;
            k+=sl;
        }
        fo << endl;
    }
    fi.close();
    fo.close();
}
