#include <iostream>
#include <vector>
#include <bits/stdc++.h>

//#include"HEADER.h"

#include "(header) Linker.h"

using namespace std;

int main(void)
{
    while(1)
    {
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
        cout<<"\n\n\n\t\t\t\t     WELCOME TO \n\t\t\t      *EQUATON SOLVER & PLOTTER*\n\n\n";
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
        int choice;
        cout<<"\t\t\t\tWHAT DO YOU WANT ?\n"<<endl;
        cout<<"\t\t*_*1.LINEAR EQUATION SOLUTION PROCESS \n\n\\n\t\t*_* 2.POLYNOMIAL EQUATION SOLVE \n\n\t\t*_* 3. POLYNOMIAL EQUATION SOLUTION PROCESS (upto power 2)\n\n\t\t*_* 4.GRAPH \n\n\t\t*_* 5. EXIT\n\n ------->      ";
        cin>>choice;
        if(choice == 1)
        {
            cout<<"\n\n\n\n\t\t1. INPUT LINEAR  EQUATION\n\t\t...................................."<<endl;
            solve_linear_equation();
        }
        else if(choice == 2)
        {
            solve_polynomial_equation();
        }
        else if(choice == 3)
        {
            Poly_EQ_runner runner;
            runner.run();
        }
        else if(choice == 4)
        {
            int optn;
            cout<<"\nWhich Graph do you want?\n 1.  LINEAR FUNCTION GRAPH \n 2. POLYNOMIAL FUNCTION GRAPH \n "<<endl;
            cin>>optn;
            if(optn==1)
            {
                Linear_Graph();
            }
            else if(optn == 2)
            {
              polynomial_Graph();
            }
        }
        else if(choice == 5)
        {
            return 0;
        }
        else
        {
            cout<<"\nPLEASE GIVE RIGHT INPUT. "<<endl;
        }
    }
    return 0;
}


/*

2x + 6y = 12
3x -y = 42

x  + y=5
2x +2y =8

x^2 - 5x + 6 =0

x+3y+4z=4
−x+3y+2z=2
3x+9y+6z=−6

x^4 -5 x^3 + 7x^2 -5x+6=0

3x^2-5x-12=0

x^2 - 8x + 15 =0

x^2-14x+45=0

x^2 -12x + 37 =0

2x^3 + 3x^2 -11x  - 6 = 0

3x - 2y =12
x + 4y = 17




*/

