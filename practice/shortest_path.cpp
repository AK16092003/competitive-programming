#define print(k) for(auto j: k) cout<<j <<" ";cout<<endl;
#define inf 1000000

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        
        int n = grid.size();
        int m = grid[0].size();

        int k = 0;
        int start_x = -1 , start_y = -1;

        int pos_x_lock[7] ; int pos_y_lock[7];
        int pos_x_key [7] ; int pos_y_key [7];

        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j  < m ; j++)
            {
                // store all lock and key position...

                if((grid[i][j] - 'A') <= 7 && (grid[i][j] - 'A') >= 0)
                {
                    k = max(k , (grid[i][j] - 'A'));
                    pos_x_lock[grid[i][j] - 'A'] = i;
                    pos_y_lock[grid[i][j] - 'A'] = j;                
                }
                if((grid[i][j] - 'a') <= 7 && (grid[i][j] - 'a') >= 0)
                {
                    pos_x_key[grid[i][j] - 'a'] = i;
                    pos_y_key[grid[i][j] - 'a'] = j;
                }

                if(grid[i][j] == '@')
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        vector<int> perm;
        k++;

        int fans = inf;

        for(int j = 0 ; j < k ; j ++)
        {
            perm.push_back(j);
        }


        do
        {
            // permutation of keys ... 

            int cur_x = start_x;
            int cur_y = start_y;

            vector<string> copy_grid = grid;

            // all lock cells are unreachable at initial ..
            
            for(int i = 0 ; i < n ; i ++)
            {
                for(int j =  0 ; j  < m ; j ++)
                {
                    if((copy_grid[i][j] - 'A') <= 7 && (copy_grid[i][j] - 'A') >= 0)
                    {
                        copy_grid[i][j] = '#';
                    }  
                } 
            }


            int operation = 0;

            for(int cur = 0 ; cur < k ; cur++)
            {
                // do bfs from (x , y) to (cur_key_x , cur_key_y)

                int visited[n][m];
                for(int i = 0 ; i  < n ; i ++)
                {
                    for(int j = 0 ; j  < m ; j ++)
                    {
                        visited[i][j] = 0;
                    }
                }

                queue<tuple<int,int,int>> qq;
                qq.push({cur_x , cur_y , 0});

                visited[cur_x][cur_y] = 1;

                vector<pair<int , int>> direc = {{-1,0} , {1,0} , {0,1} , {0,-1} };

                while(qq.size())
                {
                    int fake_x , fake_y , lev;
                    tie(fake_x , fake_y , lev) = qq.front();
                    qq.pop();

                    if(fake_x == pos_x_key[perm[cur]] && fake_y == pos_y_key[perm[cur]])
                    {
                        operation += lev;
                        break;
                    }

                    for(auto dd : direc)
                    {
                        int next_x = fake_x + dd.first;
                        int next_y = fake_y + dd.second;

                        if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
                        {
                            if(!visited[next_x][next_y])
                            {
                                if(copy_grid[next_x][next_y] != '#')
                                {
                                    qq.push({next_x , next_y , lev+1});
                                    visited[next_x][next_y] = 1;
                                }
                            }
                        }

                    }
                }
                
                if(visited[pos_x_key[perm[cur]]][pos_y_key[perm[cur]]] == 0)
                {
                    // cur_key not reachable
                    operation += inf;
                    break;
                }

                // cur key reachable
                // make lock open

                copy_grid[pos_x_lock[perm[cur]]][pos_y_lock[perm[cur]]] = '.';

                cur_x = pos_x_key[perm[cur]];
                cur_y = pos_y_key[perm[cur]];   
            }
            fans = min(fans , operation);

        }
        while(next_permutation(perm.begin() , perm.end()));

        if(fans >= inf) return -1;

        return fans;
    }
};
