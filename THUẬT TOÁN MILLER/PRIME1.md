SPOJ có 2 bài để sử dụng thuật toán này (cách này giúp hạn chế về time nếu số cần tính > 1e6)

ĐỀ BÀI 1 : https://www.spoj.com/problems/PRIME1/

ĐỀ BÀI 2 : https://vn.spoj.com/problems/PNUMBER/


Ý tưởng : 
- Nếu n < 2 return 0;
- Nếu n % 2 == 0 return n == 2
- Trường hợp còn lại làm theo các bước : 
+ Bước 1 : Phân tích n - 1 = 2^s . d
+ Bước 2 : Lập 1 hàm tính a^d % n với a = {2, 7, 61} khi n < 1e10
+ Bước 3 : 
* Nếu a^d % n == 1 (~ a^d đồng dư với 1 theo module n) thì return 1
* Nếu khác chuyển sang bước 4
+ Bước 4 : Kiểm tra ((a^d)^2r + 1) % n == 0 (~ (a^d)^2r đồng dư với -1 theo module n) thì return 1 với r thuộc [0, s-1]
+ Cách kiểm tra : 
* Giảm dần s về 1, nếu a^d % n == n - 1 thì return 1; (1)
* Nếu không thì giảm s, đặt p = a^d % n, p = p * p % n (reason?) rồi quay lại kiểm tra (1)

CODE : 
```sh
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

// Tim s, d trong n-1 = 2^s . d
// Cap {s, d} = {s, n}

pair<ll, ll> phantich(ll n){
    ll s = 0;
    while (!(n % 2)){
        s++;
        n /= 2;
    }
    return {s, n};
}

// Ham tinh a^d % n
// a.a % n = ((a % n).(a % n)) % n

ll mod(ll a, ll d, ll n){
    ll res = 1;
    a = a % n;
    while (d > 0){
        if (d % 2) res = res * a % n;
        d /= 2;
        a = a * a % n;
    }
    return res;
}

bool check(ll a, ll s, ll d, ll n){
    //2^s . d = n - 1
    if (n == a) return 1; // vi a la cac so nguyen tro
    
    ll p = mod(a, d, n);
    
    // Kiem tra a^d % n == 1 khong
    
    if (p == 1) return 1;
    
    // Kiem tra (2^d)^2r == n - 1 khong voi r trong [0, s-1]
    
    for(; s > 0; s--){
        if (p == n - 1) return 1;
        else p = p * p % n;
    }
    return 0;
}

bool miller(ll n){
    if (n < 2) return 0;
    if (n % 2 == 0) return n == 2;
    
    ll s, d;
    tie(s, d) = phantich(n-1);
    
    return check(2, s, d, n) && check(7, s, d, n) && check(61, s, d,n);
}

int main(){
    ll a, b; cin >> a >> b;
    for(ll i = a; i <= b; i++){
        if (miller(i)) cout << i << endl;
    }
}
```

Bonus các kiến thức nhỏ : 
- Kiểm tra số chẵn, lẻ (n) ta có thể dùng n & 1 
+ VD n = 8 chuyển hệ nhị thành 1000 và số  1 = 0001, kết quả thu được tất cả chuyển thành 0, bit cuối nếu chẵn (0) thì 1 & 0 = 0 là số chẵn
+ Ngược lại bit cuối lẻ (1) có 1 & 1 = 1 là số lẻ
- Left shift và right shift
+ Left shift >> tức là nhân thêm 2^x đơn vị VD : 8 >>= 2 -> 8.2^2  (TQ : n >>= x -> n.2^x)
+ Right shift << tức là giảm đi 2^x đơn vị VD : 8 <<= 2 -> 8/2^2   (TQ : n <<= x -> n/2^x)
