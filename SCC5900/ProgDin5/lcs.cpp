#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

int lcs(string a, string b, int m, int n){

		if( m == 0 || n == 0) return 0;

		if(a[m-1] == b[n-1]){
			return 1 + lcs(a,b, m-1, n-1);
		}else{
			return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
		}

	
}


int main(){_

	string s, t;

	cin >> s >> t;
	
	int m = s.length();
	int n = t.length();


	cout << lcs(s, t, m, n) << endl; 

	return 0;

}

