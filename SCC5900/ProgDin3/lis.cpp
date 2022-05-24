#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

class Solution {
public:
    int lis(vector<int>& nums) {
        
				int maxlen = 0;
        
				vector <int> dp(nums.size(), 1);
			
				int tam = nums.size();
				for(int i = 0; i < tam; i++){
        
					for(int j = 0; j < i; j++) 
              if(nums[j] < nums[i]){
								dp[i] = max(dp[i], dp[j] + 1);
     			}
					
					maxlen = max(maxlen, dp[i]);
        
				}

        return maxlen;
    }
};

int main(){_
	
	Solution s;

	int t;
	cin >> t;
	vector <int> nums;

	while(t--){
		int x;
		cin >> x;
		nums.push_back(x);
	}

	cout << s.lis(nums) << endl;
  
	return 0;
}


