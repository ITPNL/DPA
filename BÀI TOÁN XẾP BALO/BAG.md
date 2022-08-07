ĐỀ BÀI : https://www.spoj.com/KSTN/problems/BAG/

CODE : Giải bằng ý tưởng qui hoạch động

```sh
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int n, s; cin >> n >> s; 
    int v[1001], w[1001]; 
// v : value là mảng giá trị sản phẩm
// w : weigh là mảng chi phí (trọng lượng) sản phẩm

    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i]; 
    int f[1001][1001]; 
    
// xét từng khoảng trọng lượng từ 1 -> s và xem xét đồ vật thứ i có thỏa mãn để đưa vào túi hay không
// f[i][j] là với j là trọng lượng túi đang xét và i là giá trị có thể nhận được khi quyết ddingj cho vật vào túi hay không
// f[i][j] sẽ có 2 khả năng : 
    memset(dp, 0, sizeof(dp)); 
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= s; j++){ 
        // Khả năng 1 : Không cho vật vào túi vì túi khối lượng j chứa không đủ w[i]
            f[i][j] = f[i-1][j]; 
        // Khả năng 2 : Nếu túi có thể chứa vật i thì so sánh value túi hiện tại có và sau khi thêm vật i 
        // (f[i-1][j-w[i] + v[i] là giá trị sau khi thêm vật i + value túi khi vật còn đủ trọng lượng để chứa vật còn lại
            if (j >= w[i]) { 
                f[i][j] = max(f[i][j], f[i-1][j-w[i]] + v[i]); 
            } 
        } 
    } 
    cout << f[n][s];
}
```

- Vấn đề đặt ra là làm cách nào để in ra số lượng và thứ tự các vật đã chọn ?
