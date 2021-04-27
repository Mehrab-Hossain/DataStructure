#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 1000002
ll n;
vector<ll> BIT(1000001,0);
void update(ll i,ll val){
	for(;i<=n;i+= i&-i)
		BIT[i]+=val;
}
ll query(ll i){
	ll sum=0;
	for(;i>0;i-= i&-i)
		sum+=BIT[i];
	return sum;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll m,c;
	cin>>n>>m>>c;
	char ch;
	ll l,r,p,k;
	while(m--){
		cin>>ch;
		if(ch=='Q'){
			cin>>p;
			cout<<(query(p)+c)<<"\n";
		}
		else{
			cin>>l>>r>>k;
			update(l,k);
    		update(r+1,-k);
		}
	}
	return 0;
}