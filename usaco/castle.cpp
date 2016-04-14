/*
ID: lizardo1
PROG: castle
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool mycomp (pair<int, int> i, pair<int, int> j) { return (i.second >j.second); }

string mapInput(int t){
	switch(t){	
		case 0:			
			return "1111";	
		case 1:			
			return "1110";
		case 2:
			return "0111";
		case 3:
			return "0110";
		case 4:
			return "1011";
		case 5:
			return "1010";
		case 6:
			return "0011";
		case 7:
			return "0010";
		case 8:				
			return "1101";
		case 9:
			return "1100";
		case 10:
			return "0101";
		case 11:
			return "0100";
		case 12:
			return "1001";
		case 13:
			return "1000";
		case 14:
			return "0001";
		case 15:
			return "0000";
	}
	
	return "1111";
}


pair<int, int> num2coord(int num, int c){
	
	int x, y;
	
	x = num/c;
	x += num%c ? 1 : 0;
	
	y = c - (x*c - num) -1;
	
	return make_pair(x, y);
}


int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("castle.in", "r");
    fout = fopen("castle.out", "w");

	int m, n, t;
	fscanf(fin, "%d %d", &n, &m);
	
	vector< vector<int> > graph(m*n);
	
	int u=0, map[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			map[i][j] = u++;
		}
	}		
		
	// INPUT *************************************************	
		
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			fscanf(fin, "%d", &t);
			
			string str = mapInput(t);
			if(str[0] == '1')
				graph[ map[i][j] ].push_back( map[i-1][j] );
				
			if(str[1] == '1')
				graph[ map[i][j] ].push_back( map[i][j+1] );
				
			if(str[2] == '1')
				graph[ map[i][j] ].push_back( map[i+1][j] );
			
			if(str[3] == '1')
				graph[ map[i][j] ].push_back( map[i][j-1] );
		}
	}
	
	/*for(int i=0; i<graph.size(); i++){
		printf("%d -", i);
		for(int j=0; j<graph[i].size(); j++){
			printf(" %d", graph[i][j]);
		}
		printf("\n");
	}*/
	
	
	// DFS ********************************************
	
	int component = -1;
	vector<int> rooms(m*n, -1);
	stack<int> mystack;
	
	vector< int > comps_size;
	vector< vector<int> > components;
	
	for(int j=0; j<graph.size(); j++){
	
		if(rooms[j] == -1){
			mystack.push(j);	
			component++;
			comps_size.push_back( 0 );
			vector<int> tmp;
			
			while(!mystack.empty()){
		
				int top = mystack.top();
				mystack.pop();
				
				if(rooms[top] == -1){
		
					rooms[top] = component;
					comps_size[component]++;
					tmp.push_back(top);
		
					for(int i=0; i<graph[top].size(); i++){				
						mystack.push(graph[top][i]);
					}	
				}
			}
			
			components.push_back(tmp);			
		}		
	}
	
	/*printf("\n");		
	for(int i=0;i<comps_size.size(); i++)
		printf("%d %d\n", i, comps_size[i]);
	printf("\n");

	for(int i=0;i<rooms.size(); i++)
		printf("%d -- %d\n", i, rooms[i]);
	
	printf("\n");
	for(int i=0;i<components.size(); i++){
		for(int j=0;j<components[i].size(); j++)
			printf("%d ", components[i][j]);
		printf("\n");
	}*/
	
	//--------------------------------------------------------------------
	
	int biggest_component = comps_size[0];
	for(int i=1;i<comps_size.size(); i++)
		if(comps_size[i] > biggest_component)
			biggest_component = comps_size[i];
	
	fprintf(fout, "%ld\n%d\n", comps_size.size(), biggest_component);
		
			
	int max=0, m1=0, m2=1;
	int mi=0, mj=0;
	char mWall='E';
	
	
	//for(int i=m-1; i>=0; i--){	
		//for(int j=0; j<n; j++){
	for(int j=0; j<n; j++){
		for(int i=m-1; i>=0; i--){		
		
			int tile = map[i][j];
			int c1 = rooms[ tile ];
			
			//if(i==3 && j==0)
				//printf("\nAqui %d %d %d - %d %d\n\n", tile, c1, rooms[map[i-1][j]], comps_size[c1], comps_size[rooms[map[i-1][j]]]);
			
			
			//up
			if( i > 0 ){
				int tileUp = map[i-1][j];
				int cup = rooms[ tileUp ];
				
				if(c1!=cup && (comps_size[c1] + comps_size[cup] > max)){
					max = comps_size[c1] + comps_size[cup];
					m1 = tile;
					m2 = tileUp;
					mi = i;
					mj = j;
					mWall = 'N';
					//printf("\nInside: i: %d, j: %d\n", i, j);
				}
			}
			
			//right
			if( j < n-1 ){
				int tileRight = map[i][j+1];
				int cright = rooms[ tileRight ];
				
				if(c1!=cright && comps_size[c1] + comps_size[cright] > max){
					max = comps_size[c1] + comps_size[cright];
					m1 = tile;
					m2 = tileRight;
					mi = i;
					mj = j;
					mWall = 'E';
				}
			}
		}	
	}
	
//	printf("\n\nm1 %d   m2 %d   wall %c", m1, m2, mWall);
	fprintf(fout, "%d\n%d %d %c\n", comps_size[ rooms[ m1 ] ] + comps_size[ rooms[ m2 ] ], mi+1, mj+1, mWall); 
		
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




