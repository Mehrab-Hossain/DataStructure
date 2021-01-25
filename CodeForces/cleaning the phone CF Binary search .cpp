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
		int n,m;
		cin>>n>>m;
		vector<int>ones,twos;
		vector<int>v(n);
		loop(i,0,n)cin>>v[i];
		int sum=0;
		for(int i=0;i<n;i++){
			int x ;
			cin>>x;
			if(x==1)ones.pb(v[i]);
			else twos.pb(v[i]);
			sum+=v[i];
		}
		if(sum<m){
			cout<<-1<<endl;
			continue;
		}
		sort(allr(ones));
		sort(allr(twos));

		for(int i=1;i<ones.size();i++)ones[i]+=ones[i-1];
		for(int i=1;i<twos.size();i++)twos[i]+=twos[i-1];

		int mn = INF;
		for(int i=0;i<ones.size();i++){
			int rem = m - ones[i];
			if(rem<=0){
				mn = min(i+1,mn);

			}
			else if(twos.size()>0){
				auto it= lower_bound(all(twos),rem);
				if(it!=twos.end()){
					int x = it-twos.begin();
					int y = (x+1)*2;
					mn =min(mn,y+i+1);

				}
			}
		}
		for(int i=0;i<twos.size();i++){
			int rem = m - twos[i];
			if(rem<=0){
				mn = min((i+1)*2,mn);
				//cout<<mn<<" "<<i<<endl;
			}
			else if(ones.size()>0){
				auto it= lower_bound(all(ones),rem);
				if(it!=ones.end()){
					int x = it-ones.begin();
					int y = (x+1);
					mn =min(mn,y+((i+1)*2));
					//cout<<mn<<" "<<i<<endl;
				}
			}
		}
		auto it= lower_bound(all(ones),m);
		if(it!=ones.end()){
			int x = it-ones.begin();
			int y = (x+1);
			mn =min(mn,y);
		}
		it= lower_bound(all(twos),m);
		if(it!=twos.end()){
			int x = it-twos.begin();
			int y = (x+1)*2;
			mn =min(mn,y);
		}

		cout<<mn<<endl;

	}
	


}
///ALHAMDULILLAH//