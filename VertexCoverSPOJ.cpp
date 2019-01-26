/*
 * Ankit Raj, NIT Agartala
 */
 //Basic idea from searching the solution, either the root is in the set or not
 //If the root is in the set, then all its children shouldn't be covered, 
 //And if the root is not in the set, then all its children should be covered
 //Also Bipartite checking will not work here!!
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 100007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define F first
#define S second
vector<vector<int>>Graph(MAX_RANGE);
int color[MAX_RANGE];
int n;
int dp[MAX_RANGE][2];
void dfs(int u, int parent)
{
	dp[u][1] = 1;
	for(auto it:Graph[u])
	{
		if(it==parent)
		{
			continue;
		}
		dfs(it,u);
		dp[u][1] += min(dp[it][0],dp[it][1]);
		dp[u][0] += dp[it][1];
	}
}
int main()
{
	BOOST;
	NITRO;
	clock_t t1,t2;
	t1 = clock();
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/ 
	//Main Code
	//int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(1,0);
	int ans = min(dp[1][0],dp[1][1]);
	ans = max(ans,1);
	cout<<ans<<"\n";
	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}
