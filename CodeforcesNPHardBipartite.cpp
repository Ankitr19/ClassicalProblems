/*
 * Ankit Raj, NIT Agartala
 */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 100007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
int colorVetex[MAX_RANGE];
vector<vector<int>>Graph(MAX_RANGE);
bool visited[MAX_RANGE];
int n,m;
bool BipartiteCheck(int src)
{
	queue<int>Q;
	//int src = 1;
	Q.push(src);
	colorVetex[src] = 1;
	visited[src] = true;
	while(!Q.empty())
	{
		int parent = Q.front();
		Q.pop();
		for(int v=0;v<Graph[parent].size();v++)
		{
			if(Graph[parent][v] && colorVetex[Graph[parent][v]]==-1 && visited[Graph[parent][v]]==false)
			{
				colorVetex[Graph[parent][v]] = 1 - colorVetex[parent];
				Q.push(Graph[parent][v]);
				visited[Graph[parent][v]] = true;
			}
			else if(Graph[parent][v] && colorVetex[parent]==colorVetex[Graph[parent][v]])
			{
				return false;
			}
		}
	}
	return true;
			
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
	//int n,m;
	cin>>n>>m;
	memset(colorVetex,-1,sizeof(colorVetex));
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	bool checker = true;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==false)
		{
			bool temp = BipartiteCheck(i);
			if(temp==false)
			{
				checker = false;
			}
		}
	}
	if(checker==false)
	{
		cout<<"-1"<<"\n";
	}
	else
	{
		map<int,vector<int>>M;
		for(int i=1;i<=n;i++)
		{
			//cout<<i<<" "<<colorVetex[i]<<"\n";
			if(colorVetex[i]==-1)
			{
				M[1].push_back(i);
			}
			else
			{
				M[colorVetex[i]].push_back(i);
			}
			
		}
		map<int,vector<int>>::iterator it;
		for(it=M.begin();it!=M.end();it++)
		{
			cout<<it->second.size()<<"\n";
			for(int i=0;i<it->second.size();i++)
			{
				cout<<it->second[i]<<" ";
			}
			cout<<"\n";
		}
			
		
	}
	
	

	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}