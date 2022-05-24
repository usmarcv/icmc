#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long

using namespace std;

set <ll> pos;
vector <ll> a;
vector <ll> pre_sum;

void search(ll s, ll e){

	pos.insert(pre_sum[e+1] - pre_sum[s]);

	if(a[s] == a[e]){
		return;
	}
	
	ll l = s;
	ll h = e + 1;
	ll val = (a[s] + a[e]) / 2;

	while(l < h){
		ll mid = (l + h) / 2;
		if(a[mid] <= val){
				l = mid + 1;
		}else{
				h = mid;
		}
	}
	
	ll pivot = h - 1;
	search(s, pivot);
	search(pivot + 1, e);

}



int main(){_
	
	ll t;

	cin >> t;
	
	while(t--){
	
		ll n, q;
		cin >> n >> q;

		pos.clear();
		a.resize(n, 0);
		pre_sum.resize(n + 1, 0);

		
		for(ll i = 0; i < n; i++){
				cin >> a[i];
		}
		
		sort(a.begin(), a.end());

		for(ll i = 1; i <= n; i++){
				pre_sum[i] = pre_sum[i - 1] + a[i - 1];
		}
		
		search(0, n - 1);
			
		while(q--){
				ll num;
				cin >> num;
				if(pos.find(num) != pos.end()){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
		}
	}

  return 0;
}


