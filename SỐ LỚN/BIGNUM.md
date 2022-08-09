* Hàm cân bằng chiều dài 
```sh
void ellen(string &a, string &b){
	while (a.size() < b.size()) a = '0' + a;
	while (a.size() > b.size()) b = '0' + b;
}
```

1. Cộng hai số lớn
```sh
string add(string a, string b){
	ellen(a, b);
	string c = ""; int cr = 0;
	for(int i = a.size() - 1; i >= 0; i--){
		int tg = a[i] + b[i] - 2*48 + cr;
		if (tg / 10) cr = 1;
		else cr = 0;
		c.insert(0, 1, tg % 10 + 48);
	}
	if (cr) c = '1' + c;
	return c;
}
```
2. Trừ hai số lớn (số lớn trừ số bé)
```sh
string sub(string a, string b){
	ellen(a, b);
	string c = ""; int cr = 0;
	for(int i = a.size() - 1; i >= 0; i--){
		int tg = a[i] - b[i] - cr;
		if (tg < 0) {
			cr = 1;
			tg += 10;
		}
		else cr = 0;
		c.insert(0, 1, tg % 10 + 48);
	}
	while (c[0] == '0') c.erase(0, 1);
	return c;
}
```
3. Nhân số lớn với số bé
```sh
string multi(string a, int n){
	if (n == 1) return a;
	string c = "", tmp; int cr = 0;
	for(int i = a.size() - 1; i >= 0; i--){
		ll s = (a[i] - 48) * n + cr;
		cr = s / 10;
		c.insert(0, 1, s % 10 + 48);
	}
	while (cr){
		c.insert(0, 1, cr % 10 + 48);
		cr /= 10;
	}
	return c;
}
```
4. Nhân hai số lớn
```sh
string multi(string a, string b){
	string sum = "", int m = -1;
	for(int i = a.size() - 1; i >= 0; i--){
	     m++;
	     string tmp = "";
	     for(int j = 1; j <= a[i] - 48; j++) tmp = add(tmp, b);
	     for(int j = 1; j <= m; j++) tmp += '0';
	     sum = add(sum, tmp);
	}
	return sum;
}
```
5. Chia lấy dư số lớn cho số bé
```sh
bool mod(string a, int d){
// hold la so du
// hold = a[i] - 48 + hold*10
	
	int hold = 0;
	for(int i = 0; i < a.size(); i++){
		hold = (a[i] - 48 + hold * 10) % d; // (1)
	}
	if (hold) return 0;
	return 1;
}
```
