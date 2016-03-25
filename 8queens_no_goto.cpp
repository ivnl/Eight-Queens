//CS 211 Assignment #6
//Queens Algorithm without Goto
//Difficulty: 7

#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col) { //function to test validity of queen position (true/false)
	
	for(int i=0; i<col; i++) 
	if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
	
	return true;
	
}

void backtrack (int &col) { //call by Reference function to track column position
	
	col--;
	if(col== -1) exit(1);
} //exit program if all solutions found, (col goes under 0 signifies all possibilities checked)
	


void print(int q[]) {
	
	static int count=0; //clever use of static count = 0 to have it track one instance only
	cout<<"Solution #"<< ++ count<<endl<<endl;
	
	for(int i=0; i<8; i++) 
		cout<<q[i]<<" ";
		cout<<endl<<endl;
	
}

int main(){
int q[8]; q[0]=0;
int c=1;
 
bool from_backtrack=false; //tracker to see if we need to reset row to top or not


 // The outer loop keeps looking for solutions
 // The program terminates from function backtrack
 // when we are forced to backtack into column -1

while(true){
	
	// if we just returned from backtrack,use current value of q[c]
    // if not, get ready to start at the top of this column
	
	while(c<8){ 
		
 		if(!from_backtrack) q[c] = -1; //start at the 'top' of column
 		from_backtrack=false; //reset marker
 
 		while(q[c]<8){ // place queen in this column or backtrack as required
 		
 			q[c]++;
 			
 			// if the row = 8, there is no valid square in this column
 			// so backtrack and continue the loop in the previous column
 
 			if(q[c]==8) {
 				
 				backtrack(c);
 				continue;
 			}
 			
 			//if this position is ok, place the queen
 			// and move on to the next column,
 			// otherwise keep looking in this column
 			
 			if ((ok(q,c))) break;
 		}

		 c++; // placed ok, move to the next column
 	}
 	
	print(q); //print board solution
	backtrack(c); //backtrack for other solutions until c=-1
	from_backtrack=true;
}
 
}
