#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll inv(ll a, ll m) 
{ 
    ll m0 = m, t, q; 
    ll x0 = 0, x1 = 1; 
 
    if (m == 1) 
    return 0; 
 
    while (a > 1) 
    { 
        q = a / m; 
 
        t = m; 
 
        m = a % m, a = t; 
 
        t = x0; 
 
        x0 = x1 - q * x0; 
 
        x1 = t; 
    } 
 
    if (x1 < 0) 
    x1 += m0; 
 
    return x1; 
} 

ll findMinX(vector<ll>num, vector<ll> rem, ll k) 
{ 
    ll prod = 1; 
    for (int i = 0; i < k; i++) 
        prod *= num[i]; 
 
    ll result = 0; 
 
    for (int i = 0; i < k; i++) 
    { 
        ll pp = prod / num[i]; 
        result += rem[i] * inv(pp, num[i]) * pp; 
    } 
 
    return result % prod; 
} 

int main() {
	vector<ll> a;
	vector<ll> n;
	ll val;
	int x = 0;
	while(cin >> val) {
		if(val != -1) {
			a.push_back(x%val==0 ? 0 : val - x%val);
			n.push_back(val);
		}
		x++;
	}
	
	cout << findMinX(n, a, a.size()) << endl;
}
