#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

void solve(ll k){

	vector <int> divisors;

	for(int i = 1; i <= k; i++){
			if(k % i == 0){
					divisors.push_back(k/i);
			}
	}

	for(int j = divisors.size() - 1; j >= 0; j--){
				printf("%d ", divisors[j]);
	}

	printf("\n");
	
}


int main(){_

	ll n;

	cin >> n;

	solve(n);
	
	return 0;

}

