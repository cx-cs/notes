void dfs(int i,int depth){
	visit[i]=1;
  	for(int j=0;j<n;j++)             //for(int j=0;j<v[i].size();j++)
  		if(!visit[j]&&v[i][j]!=INF)  	//if(!visit[v[i][j]])
    		dfs(j,depth+1);          		//dfs(v[i][j],depth+1);
}

void bfs(int i){
	queue<int> q;
  	q.push(i);
 	visit[i]=1;
 	while(!q.empty()){
    	i=q.front();
   		q.pop();
   		for(int j=0;j<n;j++)			//for(int j=0;j<v[i].size();j++)
			if(!visit[j]&&v[i][j]!=INF){	//if(!visit[v[i][j]]){
       			q.push(j);						//q.push(v[i][j]);
        		visit[j]=1;						//visit[v[i][j]]=1;
      		}							//}
	}
}
void search(){
	for(int i=0;i<n;i++)
    if(!visit[i])
      	search(i);
}
