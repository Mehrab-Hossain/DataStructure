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

const int mxx = 2e6+5;
int bit[mxx];
int n,m;
int sum (int x){
	int sum=0;
	while(x>0){
		sum+= bit[x];
		x-= (x&-x);
	}
	return sum;
}
void update(int idx,int value){
	while(idx<=n){
		bit[idx]+=value;
		idx+= (idx & -idx);
	}
}
int find(int x){
	int left=1,right=n;
	int ans=0;
	while(left<=right){
		int mid = (left+right)/2;
		if(sum(mid)>=x){
			ans =mid;
			right=mid-1;
		}
		else left = mid+1;

	}
	return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	int mx=0;
	loop(i,0,n){
		int x;
		cin>>x;
		update(x,1);
	}

	loop(i,0,m){
		int x;
		cin>>x;
		if(x>0){
			update(x,1);
		}
		else{
			update(find(-x),-1);
		}
	}

	cout<<find(1)<<endl;




	


}
///ALHAMDULILLAH//