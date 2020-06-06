--------------------------------IMPORTANT FUNCTIONS------------------------------------------------

1. BIT
// Convert decimal number in binary string
string s = bitset<16>(n).to_string();
// Convert binary string to decimal number
unsigned long decimal = bitset<16>(s).to_ulong();

-------------------------------------------------------------------------------------------------- -
2. Rotate string by k units

//imagine with your hands
// 1. left hand reverse karo, 2. right hand reverse karo 3. fir pure string ko reverse kr do

void leftrotate(string &s, int d) {
	cout << s << endl;
	reverse(s.begin(), s.begin() + d);
	cout << s << endl;
	reverse(s.begin() + d, s.end());
	cout << s << endl;
	reverse(s.begin(), s.end());
	cout << s << endl;
}

void rightrotate(string &s, int d) {
	leftrotate(s, s.length() - d);
}

------------------------------------------------------------------------------------------------------

// Modulo Power Exponentiation
int power(int val, int pwr)
{
	if (pwr == 1)
		return val;

	if (pwr == 0)
		return 1;

	else
	{
		int ans = power(val, pwr / 2);
		if (pwr % 2 == 0)
			return ((ans % mod) * (ans % mod)) % mod;
		else
			return ((((ans % mod) * (ans % mod)) % mod) * val % mod) % mod;
	}
}

------------------------------------------------------------------------------------------------------ -

// nCr

#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1000000007;
int fact[1000005] = {1};
int invfact[1000005] = {1};

int power(int val, int pwr) {
	if (pwr == 0)
		return 1;
	if (pwr == 1)
		return val;
	int res = 1;

	while (pwr) {
		if (pwr & 1)
			res = (res * val) % mod;
		pwr /= 2;
		val = (val * val) % mod;
	}

	return res;
}

void factorial() {
	for (int i = 1; i <= 1000004 ; i++)
		fact[i] = (fact[i - 1] * i) % mod;
}

void inversefact() {
	invfact[1000004] = power(fact[1000004], mod - 2);
	for (int i = 1000003; i >= 0; i--)
		invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}

int nCr(int n, int r) {
	if (r > n)
		return 0;
	int res = fact[n];
	res = (res * invfact[r]) % mod;
	res = (res * invfact[n - r]) % mod;

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	factorial();
	inversefact();

	int t, m, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int N =  n - ((m - 1) * k);
		cout << nCr(N , m) << '\n';
	}
	return 0;
}

---------------------------------------------------------------------------------------------- -
