ĐỀ BÀI : https://vn.spoj.com/problems/QBSTR/

Ý tưởng : 
- Nếu a[i] = b[j] thì f[i][j] = f[i - 1][j - 1] + 1;
- Nếu a[i] != b[j] thì f[i][j] = max(f[i - 1][j], f[i][j - 1])
- f[i][0] = 0
- f[0][j] = 0

CODE 1: 
```sh
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    int n = a.size(), m = b.size();
    a = '-' + a;
    b = '-' + b;
// f[i][j] là độ dài xâu con chung của i kí tự đầu tiên xâu A và j kí tự đầu tiên xâu b
    int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));
    
// xâu con f[0][j] và f[i][0] luôn bằng 0 dao không có xâu chung nào tạo bởi 0 kí tự bất kì của xâu A hay B
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][m];
}
```
CODE 2: Chung ý tưởng nhưng cách code khác nhau
```sh
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    int n = a.size(), m = b.size();
    int f[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if (!i || !j) f[i][j] = 0;
            else {
                if (a[i - 1] == b[j - 1]) 
                    f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    cout << f[n][m];
}
```
