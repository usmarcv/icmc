#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;


int arrangingCoins(int n){
		
		int x = ceil(sqrt(2) * sqrt(n));
	
		while((x + 1) * (x/2.0) > n){
					x--;
		}
		
	return x;

}

int main(){_

	int n;

	cin >> n;

	cout << arrangingCoins(n) << endl;	

  return 0;

}


