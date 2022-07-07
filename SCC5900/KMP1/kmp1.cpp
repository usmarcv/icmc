#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

// -- Graph structure --
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector<int> vi;
// ---------------------

using namespace std;

#define TAM 1000001

int border[TAM];
vector<int> match;

void kmpPreProcess(string pattern, int len_pattern){
	
	int i = 0; 
	int j = -1;
	border[0] = -1;
	
	while(i < len_pattern){
			while(j >= 0 && pattern[i] != pattern[j]){
						j = border[j];
			}
			i++;
			j++;
			border[i] = j;
	}
}

void kmp(string text, string pattern, int len_text, int len_pattern){

	int i = 0, j = 0;
	while(i < len_text){
			
			while(j >= 0 && text[i] != pattern[j]){
							j = border[j];
			}
		
			i++;
			j++;
		
			if(j == len_pattern){
					match.push_back(i-j+1);
					j = border[j];
			}

	}

}
	
int main(){_

	int T;

	string text, pattern;

	cin >> T;
	while(T--){
		
	  cin >> text >> pattern;
		
		int len_text = text.length();
		int len_pattern = pattern.length();
	
		kmpPreProcess(pattern, len_pattern);
		kmp(text, pattern, len_text, len_pattern);

		int len_matching = match.size();
		if(len_matching > 0){
				cout << len_matching << endl;
				cout << match[0];
				for(int i = 1; i < (int)match.size(); i++){
						cout << " " << match[i];
				}
				cout << endl;
		}else
				cout << "Not Found\n";

		cout << endl;

		match.clear();

	}
	
	return 0;

}


