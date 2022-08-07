ĐỀ BÀI : https://www.spoj.com/PTIT/problems/NTSEQS2/

CODE : 
```sh
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s; cin >> n >> s;
    int a[200];
    for(int i = 0; i < n; i++) cin >> a[i];
    // f[i] khả năng có hay không có tập ton có tổng bằng i
    bool f[40001];
    memset(f, 0, sizeof(f));
    
    // luôn tồn tại tập con là tập rỗng có tổng bằng 0;
    f[0] = 1;
    
    for(int i = 0; i < n; i++){
        // Nếu f[j-a[i]] = 1 tức là đã tồn tại tập con có tổng là j - a[i] thì sẽ luôn tồn tại tập con có tổng là f[j]
        // Chỉ xét từ dưới lên (s - a[i]) do nếu xét từ 0 -> a[i] sẽ bị thừa tập con (sai)
        // Nếu f[j] = 1 thì giữ nguyên
        for(int j = s; j >= a[i]; j--){
            if (f[j - a[i]]) f[j] = 1;
        }
    }
    
    if (f[s]) cout << "YES";
    else cout << "NO";
}
```
