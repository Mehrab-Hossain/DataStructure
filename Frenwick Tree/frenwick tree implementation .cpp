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
const int mxx = 2e4+5;
int tr[100]={0},a[100];

int sum(int i){
	int sum1=0;
	while(i>0){
		sum1+=tr[i];
		i-=(i&-i);
	}
	return sum1;
}
void treeupdate(int i,int value,int  n){
	while(i<=n){
		tr[i]+=value;
		i+=(i&-i);
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,x;
	cin>>n;
	loop(i,1,n+1){ 
		cin>>x;
		a[i]=x;
		tr[i]+=x; //update the current one;
		int j = i+(i&-i);; //i+lsb(i)
		if(j<=n)tr[j]+=tr[i]; //update lsb responsible value
	}
	for(int i=1;i<=n;i++){
		cout<<tr[i]<<" ";
	}
	cout<<endl;
	treeupdate(1,3,12);
	for(int i=1;i<=n;i++){
		cout<<tr[i]<<" ";
	}
	cout<<endl;
	cout<<sum(2)-sum(0)<<endl;

	return 0;


}
///ALHAMDULILLAH//