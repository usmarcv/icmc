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

vi color;
vector<vii>adjList(201);


bool bipartite(int u){
	
	queue<int> q;
	bool isBipartite = true;

	color[u] = 0;
	q.push(u);

	while(!q.empty()){
		
		int k = q.front(); q.pop();
		
		for(int i = 0; i < (int)adjList[k].size(); i++){

				ii v = adjList[k][i];			
			
				if(color[v.first] == NOTCOLOR){
				
						color[v.first] = 1 - color[k];		
						q.push(v.first);
				
				}else if(color[v.first] == color[k]){
									isBipartite = false;
									break;
				}
		}
	
	}

	return isBipartite;

}


int main(){_


	while(cin >> N && N){
		
		int l, u, v;
	
		color.assign(N, NOTCOLOR);
		//iadjList.assign(N, COLOR);
	
		cin >> l;
		while(l--){
			
			cin >> u >> v;
			adjList[u-1].push_back(make_pair(v-1,0));
			adjList[v-1].push_back(make_pair(u-1,0));

		}		
		
		//printAdjList();

		if(bipartite){
				cout << "BICOLORABLE." << endl;
		}else{
				cout << "NOT BICOLORABLE." << endl;
		}

	}

	return 0;

}

