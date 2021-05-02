//BISMILAHIRAHMANIR RAHIM
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int               long long
#define endl			  "\n"
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
int block=0;
struct query{
	int l,r,k,i;
};
bool comp(query a,query b){
	if(a.l/block != b.l/block) return a.l/block < b.l/block;
	return a.r < b.r;
}
query q[200005];
int arr[200005];int ans[200005];
map<int,int>mp;
int freqOfreq[200005];int freq[200005];
int currenMax =0;
void add(int pos){
	int x = freq[arr[pos]];
	int y = x+1;
	freq[arr[pos]]++;
	freqOfreq[x]--;
	freqOfreq[y]++;
    
    if(y>currenMax) currenMax =y;

}
void remove(int pos){
	int x = freq[arr[pos]];
	int y = x-1;
	freq[arr[pos]]--;

	freqOfreq[x]--;
	freqOfreq[y]++;

	if(freqOfreq[currenMax]==0){
		currenMax = freq[arr[pos]];
	}
}
signed main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	block = 555;
	int tot=0;
	loop(i,0,n){
		cin>>arr[i];
		if(mp[arr[i]]==0){
			mp[arr[i]] =++tot;
		}
		arr[i]= mp[arr[i]];
	}

	loop(i,0,m){
		cin>>q[i].l>>q[i].r>>q[i].k;
		q[i].i=i;
		q[i].l--;
		q[i].r--;
	}

	sort(q,q+m,comp);
	int ML = 0, MR=-1;
	for(int i=0;i<m;i++){
		int l = q[i].l;
		int r = q[i].r;
		int k = q[i].k;

		//cout<<l<<' '<<r<<' '<<i<<endl;

		while(MR<r){
			MR++;
			add(MR);
		}
		while(MR>r){
			remove(MR);
			MR--;
		}

		while(ML<l){
			remove(ML);
			ML++;
		}
		while(ML>l){
			ML--;
			add(ML);
		}

		//cout<<currenMax<<endl;
		if(currenMax*k>=(r-l+1)){
			ans[q[i].i]=1;
		}
	}

	for(int i=0;i<m;i++){
		if(ans[i])cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}



	

	



}
///ALHAMDULILLAH//
