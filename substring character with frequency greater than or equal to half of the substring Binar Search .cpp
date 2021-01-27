//BISMILAHIRAHMANIR RAHIM
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define allr(x)			  (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define loop(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define br                break
#define con               continue 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

priority_queue<pii, vector<pii>, greater<pii> >q;
const int mxx = 2e5+5;
queue<int>pos[200010];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n;
		cin>>s;

		int ans = INT_MIN;

		for(int i=0;i<26;i++){
			int freq[n+5]={0};//storing frequency for every character a-z;
			int count=0;
			for (int j = 0; j < n; j++) { 
            if (s[j] - 'a' == i) 
                count++; 
            	freq[j] = count; 
            }

			//main objervation for a valid substring freq[r]-freq[l-1]>=(r-l)/2;
			//thats means 2*freq[r]-r>= 2*freq[l-1]-l;
			//So for every position j 0 to n need to array one l[j]= 2*freq[j-1]-j and r[j]=2*freq[j]-j

			vector<int>L,R,A;

			for (int j = 0; j < n; j++) { 
	            if(j==0){
	                L.push_back((2 * 0) - j);
	            }
	            else L.push_back((2 * freq[j-1]) - j);
	            R.push_back((2 * freq[j]) - j); 
       		} 
       		int max_len = INT_MIN; 
       		int min_val = INT_MAX; 

			// A vector every je we get decending values so find lower bound
			for (int j = 0; j < n; j++) { 
	            min_val = min(min_val, L[j]); 
	            A.push_back(min_val); 
	  
	            int l = 0, r = j; 
	  
	            // Finding the lower bound of i. 
	            while (l <= r) { 
	                int mid = (l + r) >> 1; 
	                if (A[mid] <= R[j]) { 
	                    max_len = max(max_len, j - mid + 1); 
	                    ans = max(ans, max_len);
	                    r = mid - 1; 
	                } 
	                else { 
	                    l = mid + 1; 
	                } 
	            } 
            } 
            ans = max(ans, max_len); 

		}
		cout<<ans<<endl;
	}

	


}
///ALHAMDULILLAH//v