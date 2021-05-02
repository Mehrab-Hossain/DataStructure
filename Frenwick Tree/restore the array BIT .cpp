//BISMILAHIRAHMANIR RAHIM
//problem-linnk : https://codeforces.com/contest/1023/problem/D
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

int bit[3000000],visit[3000000];
int n,m;
void add(int x){
	int i=x;
	while(i<=m){
		bit[i]+=1;
		int j= (i & -i);
	    i+=j;
	}
}
int sum(int x){
	int i = x;
	int res=0;
	while(i>0){
		res += bit[i];
		i-= (i & -i);
	}
	return res;
}
signed main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    

  
    cin>>n>>m;

    int a[n+1];
    int isq=false,coun0=0;

    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==0)coun0++;
    	else if(a[i]==m)isq=true;
    }

    if(isq==false && coun0==0){
    	cout<<"NO"<<endl;
    	return 0;
    }
    bool flag = false;

    for(int i=1;i<=n;i++){
        if(a[i]==0)continue;
    	if(visit[a[i]]){
    		int value = sum(a[i]);

    		if(value!=visit[a[i]]){
    			flag=true;
    			break;
    		}
    	}
		add(a[i]);
	    visit[a[i]]=sum(a[i]);
    	
    }

    if(flag){
    	cout<<"NO"<<endl;
    	return 0;
    }
    a[0]=1;
    for(int i=1;i<=n;i++){
    	if(a[i]==0 && isq==false){
    		a[i]=m;
    		isq=true;
    	}
    	else if(a[i]==0){
    		a[i]=a[i-1];
    	}
    }
    cout<<"YES"<<endl;

    for(int i=1;i<=n;i++)cout<<a[i]<<" ";

    cout<<endl;









	

	



}
///ALHAMDULILLAH//
