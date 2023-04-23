class Solution {
public:
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    int walls=0;
    
    bool isValid(int i,int j,int m,int n,vector<vector<int>> &vis)
    {
        return (i>=0 && i<m && j>=0 && j<n && !vis[i][j]); 
    }
    
    int find(int i,int j,int m,int n,vector<vector<int>>& a)
    {
        int c=0;
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        a[i][j]=2;
        q.push({i,j});
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                if(isValid(i+dx[k],j+dy[k],m,n,vis))
                {
                    if(a[i+dx[k]][j+dy[k]]==0)
                        c++;
                    else if(a[i+dx[k]][j+dy[k]]==1)
                    {
                        a[i+dx[k]][j+dy[k]]=2;
                        q.push({i+dx[k],j+dy[k]});
                    }
                                            
                    vis[i+dx[k]][j+dy[k]]=1;
                    
                }
            }
        }
        
        return c;
    }
    
    void putwalls(pair<int,int> &change,int m,int n,vector<vector<int>>& a)
    {
        int i,j;
        i=change.first;
        j=change.second;
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        q.push({i,j});
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            a[i][j]=-1;
            q.pop();
            
            
            for(int k=0;k<4;k++)
            {
                if(isValid(i+dx[k],j+dy[k],m,n,vis))
                {
                    if(a[i+dx[k]][j+dy[k]]==2)
                    {
                        q.push({i+dx[k],j+dy[k]});
                        a[i+dx[k]][j+dy[k]]=-1;
                        vis[i+dx[k]][j+dy[k]]=1;    
                    } 
                    else if(a[i+dx[k]][j+dy[k]]==0)
                        walls++;
                }
            }
        }
    }
    
    void spread(int m,int n,vector<vector<int>>& a)
    {
        int i,j;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==2)
                {
                    a[i][j]=1;
                    q.push({i,j});

                }
            }
        }
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                if(isValid(i+dx[k],j+dy[k],m,n,vis) && a[i+dx[k]][j+dy[k]]==0)
                {
                    a[i+dx[k]][j+dy[k]]=1;
                    vis[i+dx[k]][j+dy[k]]=1;     
                }
            }
        }
    }
    
    int containVirus(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int i,j;
        
        int infected=INT_MIN;
        pair<int,int> change;
        
        while(infected!=0)
        {
            infected=0;
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(a[i][j]==1)
                    {
                        int x=find(i,j,m,n,a);
                        if(x>infected)
                        {
                            change={i,j};
                            infected=x;
                        }
                    }
                }
            }
            
            if(infected!=0)
            {
                putwalls(change,m,n,a);
                spread(m,n,a);
            }
        }
        
        return walls;
    }
};