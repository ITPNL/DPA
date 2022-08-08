ĐỀ BÀI : https://vn.spoj.com/problems/COUNTCBG/

IV. Sinh phân hoạch nguyên của số tự nhiên n ( Cách phân tích n dưới dạng tổng các số tự nhiên không vượt quá n)

VD : n = 6;
- Cấu hình đầu tiên : 6
- Cấu hình cuối cùng : 1, 1, 1, 1, 1, 1

Phương pháp sinh:
- Tạo 1 biến đếm là số các số hạng tạo nên n
- Khi bắt gặp các số hạng = 1 sẽ bỏ qua, cho đến khi gặp số hàng lớn hơn 1 sẽ giảm sh đó xuống 1 đơn vị.
- Khi đó biến đếm cnt = i số hạng còn lại (các số hạng đứng trước luôn >= số hạng đứng sau)
- Dùng 1 biến phụ đếm số lượng số 1 đã bỏ qua và cộng thêm 1 do đã giảm sh trước đi 1 đơn vị
- Phân tách biến đếm phụ thành số lượng hạng từ bé đến lớn hớn qua biến chia dư và nguyên
- Kết thúc khi gặp cấu hình cuối full số 1

Code : 
```sh
#include <bits/stdc++.h>
using namespace std;
int n, a[100000], cnt, final;
void ktao(){
	cnt = 1;
	a[cnt] = n;
} 
void sinh(){
	int i = cnt;
	while (i >= 1 && a[i] == 1) i--;
	if (i == 0) final = 0;
	else {
		a[i]--;
		int d = cnt - i + 1; // dem sl so 1 da bo qua
		cnt = i;
		int q = d / a[i], r = d % a[i];
		if (q){
			for(int j = 1; j <= q; j++) {
				cnt++;
				a[cnt] = a[i];
			}
	}
		if (r){
			cnt++; a[cnt] = r;
		}
	}
}
int main(){
	cin >> n;
	ktao();
	final = 1;
	while (final){
		for(int i = 1; i <= cnt; i++) cout << a[i] << " ";
		cout << endl;
		sinh();
	}
}
```
