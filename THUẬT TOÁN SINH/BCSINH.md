I. Xâu nhị phân có độ dài n
- Cấu hình đầu : n bit 0
- Cấu hình cuối : n bit 1
- Bắt đầu từ bit cuối, nếu gặp bit cuối là bit 1 -> 0 và dich sang trái, cứ gặp 1 -> 0. Gặp số 0 -> 1 và những cái còn lại copy xuống (không đổi)
1	0	1	1	1

1	1	0	0	0

1	1	0	0	1

- Bắt đầu từ bit cuối, khi tìm thấy bit 0 sẽ dừng, khi gặp bit 1 -> 0 (khi chưa gặp bit 0)
Code : 
```sh
#include <bits/stdc++.h>
using namespace std;
int n, a[100], final;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if (i == 0) final = 0; // day la cau hinh cuoi
	else a[i] = 1; 
}
int main(){
	cin >> n;
	final = 1;
	ktao();
	while(final){ // khi chua noi gi thi final = 1;
		for(int i = 1; i <= n; i++) cout << a[i];
		cout << endl;
		sinh();
	}
}
```
