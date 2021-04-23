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

struct query
{
	int l;
	int r;
	int i;
};
query Q[100001];
int freq[100001],freqOfreq[100001],arr[100001];
int block;
int currMax=0;
int ans[100001];

bool comp(query a,query b){
	if(a.l/block != b.l/block) return a.l/block < b.l/block;
	return a.r < b.r;
}

void add(int pos){
	int x = freq[arr[pos]];
	int y = x+1;

	freq[arr[pos]]++;

	freqOfreq[x]--;
	freqOfreq[y]++;

	if(y>currMax) currMax=y;
}

void remove(int pos){
	int x = freq[arr[pos]];
	int y = x-1;
	freq[arr[pos]]--;

	freqOfreq[x]--;
	freqOfreq[y]++;

	
	if(!freqOfreq[currMax]) currMax = freq[arr[pos]];
}
signed main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,q;
	cin>>n>>q;
	block = 555;
	for(int i=0;i<n;i++)cin>>arr[i];

	int ML =0, MR=-1;

    for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;

	    Q[i].i=i;

	}

    sort(Q,Q+q,comp);

    for(int i=0;i<q;i++){
    	int L = Q[i].l;
    	int R = Q[i].r;

    	while(MR<R)
    		MR++,add(MR);
    	while(MR>R)
    		remove(MR),MR--;
    	

    	while(ML<L)
    		remove(ML),ML++;
    	
    	while(ML>L)
    		ML--,add(ML);
    	

    	ans[Q[i].i]= currMax;
    }

    for(int i=0;i<q;i++)
    	cout<<ans[i]<<endl;






	

	



}
///ALHAMDULILLAH//
