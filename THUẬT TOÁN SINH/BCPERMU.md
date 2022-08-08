ĐỀ BÀI : https://www.spoj.com/PTIT/problems/BCPERMU/

II. Liệt kê các hoán vị từ 1 -> n
VD : n = 5
- Cấu hình đầu tiên : 1; 2; 3; 4; 5
- Cấu hình cuối cùng : 5; 4; 3; 2; 1
+ Với cấu hình vd như 123897654 -> 123945678
+ Nhận xét : Khi chạy vòng từ n – 1 về 1 ta thấy nếu bắt gặp a[i] < a[i+1] thì ta sẽ hoán đổi vị trí 2 số và lật ngược từ i+1 -> n

Phương pháp sinh :
+ Bước 1 : Duyệt tìm vị trí của a[i] < a[i + 1]
+ Bước 2 : Hoán đổi a[i] cho số nhỏ nhất lớn hơn a[i]
+ Bước 3 : Lật ngược mảng từ n đến i+1
+ Bước 4 : In

Code :
```sh
#include <bits/stdc++.h>
using namespace std;
int n, a[100000],final;
void ktao(){
	for(int i = 1; i <= n; i++) a[i] = i;
}
void sinh(){
	int i = n - 1;
	while (i >= 1 && a[i] > a[i + 1]) i--; // do phai di tim a[i] < a[i - 1]
	if (i == 0) final = 0;
	else {
		int j = n;
		while (a[j] < a[i]) j--;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1); // lat nguoc mang
	}
}
int main(){
	cin >> n;
	ktao();
	final = 1;
	while (final){
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
		sinh();
	}
}
```
Hoặc :
```sh
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("DP_A1.INP", "r", stdin);
	freopen("DP_A1.OUT", "w", stdout);	
	int n; cin >> n;
	int a[100000];
	for(int i = 0; i < n ; i++) a[i] = i + 1;
	do{
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	} while (next_permutation(a, a + n) == 1);
}
```
Bonus : 
+ next_permuatation : tạo hoán vị từ cấu hình đầu 
+ prev_permutation : tạo hoán vị từ cấu hình cuối

// Khi dùng cho xâu, chỉ số như dùng cho vector
