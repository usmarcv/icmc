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


void find_all(ll n){
	
	vector<int> x;
	int s = sqrt(n);

	for(int i = 1; i <= s; i++){
			if(n % i){
				if(n/i == i){
					x.push_back(i);
				}else{
					x.push_back(i);
					x.push_back(n/i);
				}
			}
	}
	
	//	x.push_back(n);

	for(int i = 0; i < x.size(); i++){
				printf("%d ",x[i]);
	}
	
	printf("\n");

}

int main(){_

	ll n;

	cin >> n;

	find_all(n);

	return 0;

}

