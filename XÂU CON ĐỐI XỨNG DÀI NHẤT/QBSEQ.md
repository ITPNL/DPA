// CODE CHƯA FULL DO MẢNG 2 CHIỀU QUÁ LỚN

Đề bài : https://vn.spoj.com/problems/QBSEQ/

Code 
```sh
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    n = s.size();
    bool f[50002][50002];
    memset(f, 0, sizeof(f));
    
// Xâu đối xứng độ dài 1
    for(int i = 1; i <= n; i++) f[i][i] = 1;
    int lenm = 1, l, r;
    
// Xét các xâu có độ dài từ 2 đến n
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
// Xâu sẽ set là các xâu bắt đầu từ tmp, kết thúc ở j và có độ dài i
            int tmp = i + j - 1;
// Xau co do dai la 2 <check>
            if (i == 2 && s[j] ==s[tmp]) f[j][tmp] = 1;
            else {
// Xau co do dai lon hon 2
                f[j][tmp] = f[j + 1][tmp - 1] && (s[j] == s[tmp]); 
            }
            if (f[j][tmp] && lenm < i) {
                lenm = i;
                l = j; r = tmp;
            }
        }
    }
    cout << lenm;
}
```
