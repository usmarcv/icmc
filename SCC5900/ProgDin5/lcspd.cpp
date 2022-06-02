#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;


string lcs(string a, string b, int m, int n){

		int memo[n+1][m+1];
		
		memset(memo, 0, sizeof(memo));
	
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
					//quando o ultimo caracterer e igual
					if(a[i-1] == b[j-1])
							memo[i][j] = 1 + memo[i-1][j-1];
					else
							memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
			}
		}
	
		int i = n, j = m;
		string found = "";
		while(i > 0 && j > 0){
					if(a[i-1] == b[j-1]){
							found += a[i-1];
							i--, j--;
					}else{
							if(memo[i][j-1] > memo[i-1][j]){
									j--;
							}else{
									i--;
							}
					}
		}
		
		reverse(found.begin(), found.end());
		
		return found;
	
}


int main(){

	string s, t;

	cin >> s >> t;
	
	int n = s.length();
	int m = t.length();

	cout << lcs(s, t, m, n) << endl;

	return 0;

}

