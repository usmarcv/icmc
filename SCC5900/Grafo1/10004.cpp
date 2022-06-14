#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

// ----------------------------------

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define NOTCOLOR -1
#define COLOR 0

int N;
vector<vii> adjList(200);
vi color;


bool bipartite(int u){
	
	queue<int> q;

	color[u] = 0;
	q.push(u);

	while(!q.empty()){
		
		int k = q.front();
		q.pop();

		for(int i = 0; i < adjList[k].size(); ++i){

				ii v = adjList[k][i];			
			
				if(color[v.first] == NOTCOLOR){
				
						color[v.first] = 1 - color[k];		
						q.push(v.first);
				
				}else if(color[v.first] == color[k]){
						return false;
				}

		}
	
	}

	return true;

}


int main(){_


	while(cin >> N and N){
		
		int l, u, v;
		color.assign(N, NOTCOLOR);		

		cin >> l;
		while(l--){
			
			cin >> u >> v;
			adjList[u].push_back(make_pair(v,0));
			adjList[v].push_back(make_pair(u,0));

		}		
		
		if(bipartite){
				cout << "BICOLORABLE." << endl;
		}else{
				cout << "NOT BICOLORABLE." << endl;
		}

	}

	return 0;

}

