/*
 ------------
|            |
1 --- 2 ---- 3
      |
      |
      4 --- 7
      |     |
      5 --- 6
      
      
      
      1 --- 2-----
      |     |     |   
      |     |     |
       ---  3 --- 4
寻找 scc strongly connected component. 主要是dfs，在dfs时候每个node设定一个自己的当前次数和这次探索（stack上的）次数。根据这两个值可以找到题设要得
关键路径。

只要是在一堆里的，总能把一堆里面最小的 lowlink给分享给大家

细节注意代码里的comment。
*/

class Solution {
public:
		map< int ,vector< int > > graph ;
		int time_stamp = 1 ; // global counter 
    
		struct Vetex {
			int index ;  // time_stamp 
			int lowlink ; // 这次探索（本轮，stack上的）次数
		};
    
		vector< Vetex > check ;
		vector< vector<int> > ans ;
    
		void dfs( int cur , int parent ) {
			check[cur].index = time_stamp ; 
			check[cur].lowlink = time_stamp ;
			time_stamp ++ ;

			for( auto &next : graph[cur] ){
				if ( next == parent ) continue ; //这是防止上图中，2->4, 4又回到2的情况。
				if ( check[next].index == 0 ){ // not visited
					dfs( next , cur ) ; 
					// 关键就是地下这三句
          // 因为next都探索完了， 看他有没有能找到更小的lowindex, 考虑从6退回到5
					check[cur].lowlink = min( check[cur].lowlink , check[next].lowlink ) ; 
          //兜了一圈回来也没有找到比自己原来更小的，说明不在自己的这个圈子里
					if ( check[next].lowlink > check[cur].index ) // this must be a bridge 
						ans.push_back( {cur,next } ) ; 
				}  else {
          // 见过了就跟见过的那个index比一下，所有scc里的点肯定会被第一个点的index都更新掉，考虑第二张图
					check[cur].lowlink = min( check[cur].lowlink , check[next].index ) ; 
				}
			}

		}
    
		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
			check.resize( n+1 ) ; 
			// construct graph 
			for( auto &edge : connections ) {
				graph[edge[0]].push_back( edge[1] ) ; 
				graph[edge[1]].push_back( edge[0] ) ; 
			}
			for( int i=0 ; i< n ; i++ ) 
				if ( check[i].index == 0 ) // not visited 
					dfs( i , -1 ) ; 
			return ans ; 
		}    
};
