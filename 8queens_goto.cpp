#include <iostream>
#include <cmath>
using namespace std;

//CS211 ASSIGNMENT 5
//8 Queens 1-D Array with GOTO

int main() {
	
	int q[8];
	int c = 0;
	int counter=0;
	
	q[0] = 0;
	
	NC:
		c++;
		
		if (c==8) goto PRINT;
		
		q[c] = -1;
		
	NR: 
		q[c]++;
		
		if (q[c] == 8) goto BACKTRACK;
		
	TEST:
		
		for(int i=0; i<c; i++) {
			
			if ((q[i] == q[c]) || (c-i == abs(q[c] - q[i]))) {
				goto NR;
			}
			
		}
		
		goto NC;
	
	BACKTRACK:
		
		c--;
		if (c == -1) return 0;
		goto NR;
	
	PRINT:
		
        counter++;
		cout << "answer "<< counter <<endl<<endl;
		for( int i = 0 ; i < 8 ; i++ ) {
			
			for ( int j = 0 ; j < 8 ; j++ ) {
				
				if (q[i] == j) cout << "Q";
				
				else cout<< "x" ;
				
			}
			
			cout<<endl;
			
			}

		cout<<endl;
        
    goto BACKTRACK; 
	
	return 0;
}
