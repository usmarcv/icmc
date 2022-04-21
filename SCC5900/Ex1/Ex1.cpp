#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

#define SINGLE 0

int main(){

	int t, n;

	cin >> t;
	while(t--){

		cin >> n;
		int mList[n+1][n+1];
		int wList[n+1][n+1];
		int manCurrentMatch[n+1];
		int womanCurrentMatch[n+1];
		int manNext[n+1];

		//Pegando as entradas e setando cada mulher como solteira
		for(int i = 1; i <= n; i++){
				womanCurrentMatch[i] = SINGLE;
				for(int j = 0; j <= n; j++){
							cin >> wList[i][j];
			}
		}

		for(int i = 1; i <= n; i++){
				manCurrentMatch[i] = SINGLE;
				manNext[i] = 1;
				for(int j = 0; j <= n; j++){
							cin >> mList[i][j];
			}
		}
		
		//Começando com um homem livre
		bool freeMan = true; 
		
		//Pegando o primeiro homem livre na iteração
		int m = 1; 

		while(freeMan){
			
			freeMan = false;
			int w = mList[m][manNext[m]++];

			if(womanCurrentMatch[w] == SINGLE){
					womanCurrentMatch[w] = m;
					manCurrentMatch[m] = w;
			}else{	
				//w esta comprometida
				bool better = false;
				//checando lista de preferencias
				for(int k = 1; k <= n; k++){
						if(wList[w][k] == womanCurrentMatch[w]){
							better = false;
							break;
						}
						if(wList[w][k] == m){
							better = true;
							break;
						}
				}
					if(better){
						manCurrentMatch[womanCurrentMatch[w]] = SINGLE;
						womanCurrentMatch[w] = m;
						manCurrentMatch[m] = w;
					}
				}
			
				//encontrando um novo homen livre
				for(int k = 1; k <= n; k++){
						if(manCurrentMatch[k] == SINGLE){
							m = k;
							freeMan = true;
							break;
						}
				}	
			}

			for(int i = 1; i <= n; i++){
					cout << i <<" " <<  manCurrentMatch[i] << endl;
			}

	}


  return 0;
}
