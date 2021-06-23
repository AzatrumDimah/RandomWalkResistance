#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;
#define RI (rand() % 2)
void step(int &x , int n);
/*The problem modelled here is
We find the effective resistance between two random points in  a grid of d dimensions and one which extends from -n
to  n in all dimensions , The starting here by default is origin, note if the point is taken somewhere else be 
sure to edit the final answer if the the point is a boundary point 
 NOTE :- To change the dimension ;line 17 39 40 44*/
int main()
{
	int n;
	int d=2;
	// d gives dimensions
    cout << "Give range(of grid)  ";
	cin >> n;
	int N;
	cout << "Give number of simulations  ";
	cin >> N;
	int P[2]={-1,1};
	srand(time(NULL))	;
	 int num=0;
	 int ret =0;
	
    int pf[d];
	cout << "Give the final position   "<<endl;
		for (int i=0; i!=d; i++)
        {
		    cin >> pf[i];
		}
	for (int i=0;i!=N;i++)
	
		{
	     //change here when d changes
		   int p[d]={0,0};
		    while (p[0] != pf[0] ||p[1] != pf[1]  )
		    {
			      int m = rand() % d;
			      step (p[m] , n);
			      if (p[0] == 0 && p[1] == 0)
			        {
				     ret=ret+1;
				     break;
			        }
			        
		    }
		}  
		  

	cout <<"escape probability   "<< (double(N-ret)/N)<< endl;
	cout << "effective resistance -- "<< (1/(2*d*(double(N-ret)/N)))<< endl;
	//cout << "Expected errror -- " <<setprecision(9) << (1/double(2*d*pow(N,0.5)) )	;
	
	
	return 0;
	
	
}

void step(int &x , int n )
{
  static int P[2]={-1,1};
			if (x==n)
			{
				x=x-1;
			}
			else if (x== -n)
			{
				x=x+1;
			}
			else
			{
			x=  x+ P[RI];
		}
		
		
	}
