#include<bits/stdc++.h>

#define SIZE 1000000
#define PHI 1e-15

using namespace std;

double *a,*b,*c, r, s,dr,ds,value_p, value_q,recent_r, recent_s;
int n;
bool last_equation = false;
//for last rest equation

void declare_array()
{
    a = new double[SIZE];
    b = new double[SIZE];
    c = new double[SIZE];
}

double return_absolute_value(double x)          //return absolute value
{
    if(x<0)
    {
        x *= -1;
    }
    return x;
}

double error_value_remove(double value)
{
    int integer = value;
    if(return_absolute_value(integer - value) <= PHI)
    {

        value = (double)integer;
    }
    return value;
}

void show_solution(double x,double p, double q)
{
    if(!last_equation)
    {
        //for r and s , we need to change sign of r and s
        p = (-1)*error_value_remove(p);
        q =(-1)*error_value_remove(q);
    }
    else
    {
        // we find solution from rest of equation
        p = error_value_remove(p);
        q = error_value_remove(q);
    }

    double determinant = (p*p) - (4*x*q);


    if(determinant<0)
    {
        determinant *= -1;

        determinant = sqrt(determinant);

        if(p == 0)
        {
            //pure imaginary number
            if((determinant/(2*x)) == 1)
            {
                //coefficient 1 , not necessary to print
                cout<<"\t Root : "<<"i"<<endl;
                cout<<"\t Root: "<<"-i"<<endl;
            }
            else
            {
                //there are coefficient
                cout<<"\t Root: "<<(determinant/(2*x))<<"i"<<endl;
                cout<<"\t Root: "<<" - "<<(determinant/(2*x))<<"i"<<endl;
            }
        }
        else
        {
            //when not a pure imaginary number
            if((determinant/(2*x)) == 1)
            {
                //a +i or a - i
                cout<<"\t Root: "<<((-p)/(2*x))<<" + "<<"i"<<endl;
                cout<<"\t Root: "<<((-p)/(2*x))<<" - "<<"i"<<endl;
            }
            else
            {
                //they are in form a + ib or a - ib
                cout<<"\t Root: "<<((-p)/(2*x))<<" + "<<(determinant/(2*x))<<"i"<<endl;
                cout<<"\t Root: "<<((-p)/(2*x))<<" - "<<(determinant/(2*x))<<"i"<<endl;
            }
        }
    }
    else
    {
        determinant = sqrt(determinant);
      //  cout<<determinant<<endl;
        double first = error_value_remove(((-p) - determinant)/(2*x));
        double second =  error_value_remove(((-p) + determinant)/(2*x));

        cout<<"\t Root: "<<first<<endl;
        cout<<"\t Root: "<<second<<endl;

    }
}

void single_root_output(double x, double y)
{
    // If existance equation has only one solution
    double root = -(y/x);

    cout<<"\t Root: "<<root<<endl;
}

void calculate_R_and_S()
{
    //need to find r and s for iteration.  From r and s we find two solution of equation

    dr = (b[0]*c[3] - b[1]*c[2]) / (c[2]*c[2] - c[1]*c[3]);
    ds = (b[1]*c[1] - b[0]*c[2]) / (c[2]*c[2] - c[1]*c[3]);

    recent_r = r ;
    recent_s = s;

    r += dr;
    s += ds;
}
void calculate_column(double p[], double q[])
{
    //iteration column to find solution
    q[n] = p[n];
    q[n-1] = p[n-1] + q[n]*r;

    for(int i=n-2; i>=0; i--)
    {
        q[i] = p[i] + (q[i+1]*r) + (q[i+2]*s);
    }
}
void reduce_equation_after_iteration()
{
    //After iteration we find two solution and the equations's power reduce by two.
    //Replace a[] coefficient by b[] coefficient
    for(int i=0; i<n-1; i++)
    {
        a[i] = b[i+2];
    }

    n -= 2;
}

void calculate_root()
{
    //iteration until equation goes to power 1 or 2
    double ratio_s, ratio_r;

    if(n == 0)
    {
        cout<<"There is no variable.\n Wrong input\n\n";
        exit(0);
    }
    else if(n == 1)
    {
        single_root_output(a[n], a[n-1]);
    }
    else if(n == 2)
    {
        last_equation = true;
        show_solution(a[n], a[n-1], a[n-2]);
    }
    else
    {

        while(1)
        {
            calculate_column(a,b);
            calculate_column(b,c);

            calculate_R_and_S();

            ratio_s = ds/recent_s;
            ratio_r = dr/recent_r;


            if(((return_absolute_value(b[0]) <= PHI) && (return_absolute_value(b[1]) <= PHI)) || ((return_absolute_value(ratio_r) <= PHI) || (return_absolute_value(ratio_s) <= PHI)))
            {

                show_solution(1,r,s);

                if(n == 4)
                {
                    last_equation = true;            //for last part there no sign change
                    show_solution(b[n],b[n-1],b[n-2]);
                    break;              //equation go to zero
                }

                if(n == 3)
                {
                    single_root_output(b[n], b[n-1]);
                    break;
                }

                reduce_equation_after_iteration();
            }
        }
    }
}

void starting_method(double coefficient[], int total)
{

    declare_array();         //initialize array as dynamic for controll million of data
    //copy array to global array
    for(int i= total; i>=0; i--)
    {
        a[i] = coefficient[i];
    }
    n = total;


    r = a[n-1]/a[n];
    s = a[n-2]/a[n];

// declare default value for r & s is 0.1
    if(r == 0)
    {
        r = 0.1;
    }

    if(s ==0)
    {
        s = 0.1;
    }

    calculate_root();
  //  delete_array();//for memory deallocation

    return;
}
