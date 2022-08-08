ĐỀ BÀI : https://www.spoj.com/PTIT/problems/BCTOHOP/

Sinh tập con k phân tử từ n phần tử cho trước (tổ hợp chập k của n phần tử)

VD : n = 5, k = 3

- Cấu hình đầu tiên : 1; 2; 3; 4 (1, 2, 3, ... k)
- Cấu hình cuối cùng : 7; 8; 9; 10 (n-k+1, n-k+2, n-k+3, ... , n–k
+k)
- Nhận xét : có thể thấy với mỗi vị trí thứ i, value max đạt được chỉ có thể là n – k + i (vì các tập được sắp xếp từ bé đến lớn). Khi tất cả phần tử đều đạt max -> ta nhận được cấu hình cuối cùng 
- Phương pháp sinh: 
+ Khi a[i] chưa đạt đến n – k + 1 tăng a[i] lên 1 đơn vị
+ Khi a[i] đạt tới, duyệt sang bên trái (i--), nếu a[i] chưa đạt, duyệt từ i+1 -> k có a[j] = a[j – 1] + 1;

Code : 
```sh
#include <bits/stdc++.h>
using namespace std;
int n, a[100000], k, final;
void ktao(){
	for(int i = 1; i <= k; i++) a[i] = i;
}
void sinh(){
	int i = k;
	while (i >= 1 && a[i] == n - k + i) --i;
	if (i == 0) final = 0;
	else {
		a[i]++;
		for(int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
 	}
}
int main(){
	cin >> n >> k;
	ktao();
	final = 1;
	while (final){
		for(int i = 1; i <= k; i++) cout << a[i] << " ";
		cout << endl;
		sinh();
	}
}
```
