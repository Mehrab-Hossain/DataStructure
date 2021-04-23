//BISMILAHIRAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define int               long long

struct query
{
	int l;
	int r;
	int i;
};
query Q[200001];
int freq[1000001] , arr[200001];
int ans[200001];
int block=500,sum=0;
bool comp(query a , query b){
	if(a.l/block != b.l/block){
		return a.l/block < b.l/block;
	}
	return a.r<b.r;
}
void add(int pos){
	int x = freq[arr[pos]];
	sum-= ((x*x)*arr[pos]);
	freq[arr[pos]]++;
	x+=1;
	sum+= ((x*x)*arr[pos]);
}
void remove(int pos){

	int x = freq[arr[pos]];
	sum-= ((x*x)*arr[pos]);
	freq[arr[pos]]--;
	x-=1;
	sum+= ((x*x)*arr[pos]);

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
	for(int i=0;i<n;i++)cin>>arr[i];

	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].l--;
		Q[i].r--;
		Q[i].i=i;
	}
	//block = sqrt(n);
	sort(Q,Q+q,comp);
	int ML=0,MR=-1;
	//for(int i=0;i<q;i++)cout<<Q[i].l<<" "<<Q[i].r<<endl;
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

	    ans[Q[i].i]=sum;

	}

	for(int i=0;i<q;i++)cout<<ans[i]<<endl;
	



}
///ALHAMDULILLAH//
