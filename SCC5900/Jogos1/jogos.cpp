#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define INF 0x3f3f3f3f
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;


// -- Graph structure --
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// ----------------------


int main(){_

	int T, n;
	ll ans;

	cin >> T;
	while(T--){
		
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++){
				int w;
				cin >> w;
				ans ^= w;
		}	

		if(ans) cout << "0" << endl;
		else cout << "1" << endl;
	
	}

	return 0;

}

