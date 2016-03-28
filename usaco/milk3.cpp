/*
ID: lizardo1
PROG: milk3
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int a, b, c;
bool cube[21][21][21];
set<int> cbucket;

typedef struct state{

	int a, b, c;
	
} state;

void process(queue<state> &s_queue, state s){

	if(cube[s.a][s.b][s.c])
		return;
		
	//cout << s.a << " " << s.b << " " << s.c << endl;
	
	cube[s.a][s.b][s.c] = true;
	
	if(s.a == 0)
		cbucket.insert(s.c);
		
	state ns;	
	
	
	int da = a - s.a;
	int db = b - s.b;
	int dc = c - s.c;
	
	//c - a	
	if(da >= s.c){
		ns.a = s.a + s.c;
		ns.c = 0;
	}
	else{
	    ns.c = s.c - da;
	    ns.a = a;
	}
	ns.b = s.b;
	s_queue.push(ns);

	//c - b	
	if(db >= s.c){
		ns.b = s.b + s.c;
		ns.c = 0;
	}
	else{
	    ns.c = s.c - db;
	    ns.b = b;
	}
	ns.a = s.a;
	s_queue.push(ns);

	//b - a
	if(da >= s.b){
		ns.a = s.a + s.b;
		ns.b = 0;
	}
	else{
	    ns.b = s.b - da;
	    ns.a = a;
	}
	ns.c = s.c;
	s_queue.push(ns);

	//b - c	
	if(dc >= s.b){
		ns.c = s.c + s.b;
		ns.b = 0;
	}
	else{
	    ns.b = s.b - dc;
	    ns.c = c;
	}
	ns.a = s.a;
	s_queue.push(ns);

	//a - b
	if(db >= s.a){
		ns.b = s.b + s.a;
		ns.a = 0;
	}
	else{
	    ns.a = s.a - db;
	    ns.b = b;
	}
	ns.c = s.c;
	s_queue.push(ns);

	//a - c
	if(dc >= s.a){
		ns.c = s.c + s.a;
		ns.a = 0;
	}
	else{
	    ns.a = s.a - dc;
	    ns.c = c;
	}
	ns.b = s.b;
	s_queue.push(ns);

}

void search(state init){
	queue<state> s_queue;
	
	s_queue.push(init);
	
	while(!s_queue.empty()){
		state s = s_queue.front();
		s_queue.pop();
		
		process(s_queue, s);
	}	
}


int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("milk3.in", "r");
    fout = fopen("milk3.out", "w");

	fscanf(fin, "%d %d %d", &a, &b, &c);

	state s_init;
	s_init.a = 0;
	s_init.b = 0;
	s_init.c = c;
	
	search(s_init);
	
	// print	
	for (set<int>::iterator it=cbucket.begin(); it!=cbucket.end(); ++it){
		
		if(it == cbucket.begin() )
			fprintf(fout, "%d", *it);
		else
		    fprintf(fout, " %d", *it);
			   	
    }
    fprintf(fout, "\n"); 
	
	fclose(fin);
	fclose(fout);

	return 0;
}




