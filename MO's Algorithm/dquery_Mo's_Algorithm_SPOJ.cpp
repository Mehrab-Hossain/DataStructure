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
int block =0;
struct query
{
	int l;
	int r;
	int i;
};
int freq[1000010];
int ans[1000010];
int arr[1000010];
query Q[300005];
int coun=0;
bool comp(query a, query b){
	if(a.l/block != b.l/block){
		return a.l/block < b.l/block;
	}
	else return a.r<b.r;
}
void add(int pos){
	freq[arr[pos]]++;

	if(freq[arr[pos]]==1)coun++;
}
void remove(int pos){
	freq[arr[pos]]--;

	if(freq[arr[pos]]==0)coun--;
}
signed main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	block = sqrt(n);

	for(int i=0;i<n;i++)cin>>arr[i];

	int q;
	cin>>q;

	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;

	    Q[i].i=i;

	    Q[i].l--;
	    Q[i].r--;
	}

	sort(Q,Q+q,comp);

	//for(int i=0;i<q;i++)cout<<Q[i].l<<" "<<Q[i].r<<endl;

	int ML =0,MR =-1;
	for(int i=0;i<q;i++){
		int L = Q[i].l;
		int R = Q[i].r;

		while(MR<R){
			MR++;
			add(MR);
		}
		while(ML>L){
			ML--;
			add(ML);
		}

		while(MR>R){
			remove(MR);
			MR--;
		}
		while(ML<L){
			remove(ML);
			ML++;
		}

		ans[Q[i].i]=coun;

		//cout<<coun<<endl;
	}

	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	



}
///ALHAMDULILLAH//
