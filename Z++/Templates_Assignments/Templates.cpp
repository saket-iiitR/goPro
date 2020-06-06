#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}

== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =
#include <bits/stdc++.h>
    using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--)
	{

	}
	return 0;
}

//======================================================================================

#include <iostream>
#include <list>
#include <queue>

using namespace std;
int main()
{

	return 0;
}


// Prime Sieve-------------------------------------------------------------------------

int n = 1000001;
bool sieve[n];

for (int i = 2; i < n; i++)
	if (i % 2 == 0)
		sieve[i] = false;
	else sieve[i] = true;

sieve[0] = sieve[1] = false;
sieve[2] = true;

for (int p = 3; p < sqrt(n); p += 2)
	for ( int i = p*p; i < n; i += 2 * p)
		if (sieve[i])
			sieve[i] = false;


//Remove multiple of 2 when checking
//------------------------------------------------------------------------------------

// Prime Factors ---------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 10000;
	vector<int> v;

	for (auto i = 0; i < n + 1; i++)
		if (i % 2 == 0)
			v.push_back(0);
		else v.push_back(1);

	v[2] = 1;
	v[0] = v[1] = 0;

	for (auto p = 3; p < n + 1; p++)
		if (v[p])
			for (auto i = p * p; i < n + 1; i += 2 * p)
				v[i] = 0;

	vector<int> prime;
	for (int i = 0; i < v.size(); i++)
		if (v[i])
			prime.push_back(i);


	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> m;
		cout << "Prime Factors are :";

		int i = 0;
		int prime_no = prime[i];
		vector<int> vec;
		while (prime_no <= m)
		{
			if (m % prime_no == 0)
			{
				vec.push_back(prime_no);

				while (m % prime_no == 0)
					m = m / prime_no;
			}

			i = i + 1;
			prime_no = prime[i];

		}

		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;

	}
	return 0;

}

---------------------------------------------------------------------------------------------------------------- -
== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

// Policy based DS


#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	new_data_set st;

	cout << 0 - st.order_of_key(0) << endl;
	st.insert(0);
	cout << 1 - st.order_of_key(4) << endl;
	st.insert(3);
	cout << 2 - st.order_of_key(-1) << endl;
	st.insert(-2);
	cout << 3 - st.order_of_key(6) << endl;
	st.insert(5);
	cout << 4 - st.order_of_key(0) << endl;
	st.insert(-1);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (i - st.order_of_key(arr[i] + 1));
		st.insert(arr[i]);
	}

	cout << ans << "\n";

	return 0;
}
