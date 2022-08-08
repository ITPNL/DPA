ĐỀ BÀI : https://www.spoj.com/PTIT/problems/P171SUME/

Thuật toán Kanade : 
- Đối với dãy con không liên tiếp :
+ Nếu tất cả phần tử âm thì lấy phần tử lớn nhất
+ Nếu có phần tử dương thì chi lấy phần tử dương
- Đối với dãy con liên tiếp :
+ Tổng lớn nhất của dãy con liên tiếp từ 0 đến i là a[i] hoặc sum + a[i]
+ Là a[i] khi dãy con liên tiếp trước nó có tổng (cả nó) nhỏ hơn a[i]
+ Là sum + a[i] khi thêm được a[i] vào dãy con
+ Duy trì 1 biến sumM để lưu được dãy con có tổng lớn nhất

CODE : 
```sh
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main(){
    int n; cin >> n;
    bool check = 1;
    ll a[100001];
    
    ll sum = 0, sumM; 
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > 0) check = 0;
        sum = max(a[i], sum + a[i]);
        if (!i) sumM = sum;
        else sumM = max(sum , sumM);
    }
    
    cout << sumM << " ";
    
    ll M = a[0], cnt = 0;
    for(int i = 0; i < n; i++){
        M = max(M, a[i]);
        if (a[i] > 0) cnt += a[i];
    }
    if (check) cout << M;
    else cout << max(M, cnt);
} 
```
