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



struct Node{
	
	int nxt[26];
	int ctr, e;

	Node(){
		memset(nxt, -1, sizeof nxt);
		e = 0;
		ctr = 0;
	}

};

vector<Node> trie;

void add(string s){

	int cur = 0;
	for(int i = 0; i < (int)s.size(); i++){
			if(trie[cur].nxt[s[i]-'a'] == -1){
					trie.push_back(Node());
					trie[cur].nxt[s[i]-'a'] = trie.size() - 1;
			}
			cur = trie[cur].nxt[s[i]-'a'];
			trie[cur].ctr++;
	}
	trie[cur].e++;	
}


int get(string s){
	
	int cur = 0;
	for(int i = 0; i < (int)s.size(); i++){	
			if(trie[cur].nxt[s[i]-'a'] == -1){
					return 0;
			}
			cur = trie[cur].nxt[s[i]-'a'];
	}
		return trie[cur].ctr;
}


string s;
int n, q;

int main(){_

	trie.push_back(Node());

	cin >> n >> q;
	for(int i = 0; i < n; i++){
			cin >> s;
			add(s);
	}

	for(int i = 0; i < q; i++){
			cin >> s;
			cout << get(s) << endl;
	}


	return 0;

}

