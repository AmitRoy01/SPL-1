#include<bits/stdc++.h>
#include "HEADER.h"

#define SPACE 0
#define OPERATOR 1
#define NUMBER 2
#define CHARACTER 3
#define FRACTIONAL_POINT 4
#define POWER 5

using namespace std;

bool isDecimalPoint,isNegative1, isNegative2,isEqual;
char numerical_number[]= {'0','1','2','3','4','5','6','7','8','9'};

double matrix[SIZE][SIZE]= {0},temp[SIZE][SIZE];
char  store[20], variable[SIZE][20];

double determinant_of_matrix(double arr[][SIZE], unsigned int number)
{

    for(size_t i=0; i<number; i++)
    {
        for(size_t j=number-1; j>i; j--)
        {
            if(arr[j][i] == 0)
            {
                continue;
            }
            else
            {
                if(arr[j-1][i] == 0)
                {
                    //exchange row
                    for(size_t x =0; x<number; x++)
                    {
                        double temp = arr[j][x];
                        arr[j][x] = arr[j-1][x];
                        arr[j-1][x] = temp;
                    }
                    continue;
                }

                double required_ratio = arr[j][i] / arr[j-1][i];

                for(size_t k =0; k<number; k++)
                {
                    arr[j][k] = arr[j][k] - required_ratio * arr[j-1][k];
                }
            }
        }
    }
    //calculate determine

    double sum =1;
    for(size_t i=0; i<number; i++)
    {
        sum *= arr[i][i];
    }
    //cout<<"result is: "<<sum<<endl;

    return sum;
}

double find_determinant_of_each_variable(double arr[][SIZE], unsigned int number)
{
    //this function make a temporary array and calculate this

    double store[SIZE][SIZE];

    for(size_t i=0; i<number; i++)
    {
        for(size_t j=0; j<number; j++)
        {
            store[i][j] = arr[i][j];
        }
    }

    return determinant_of_matrix(store, number);
}


void replace_column_with_constant_column(unsigned int x, unsigned int number)
{
    /*To find variable coefficient we need to replace column*/

    for(size_t i=0; i<number; i++)
    {
        for(size_t j=0; j<number; j++)
        {
            if(j == x)
            {
                temp[i][j] = matrix[i][number];
            }
            else
            {
                temp[i][j] = matrix[i][j];
            }
        }
    }

     for (int i = 0; i <number; i++) {
        for (int j = 0; j <number; j++) {
            cout << temp[i][j] << "  ";
        }
        cout << endl;
 }
 cout<<endl;

}



bool if_has_infinity_solution(double result[], int number_of_variable)
{
    for(int i=1; i<=number_of_variable; i++)
    {
        if(result[i] != 0) 			//There are infinite solution if all determine are zero
        {
            return false;
        }
    }

    return true;
}


void solution_process(int number_of_variable)
{
    cout<<" \n\t\t\t*| SOLUTION PROCESS OF LINEAR EQUATION |* \t\t\\n"<<endl;
    //variable_number = number_of_variable;               //make it global variaable
    double result[SIZE];
    unsigned int number = (unsigned)number_of_variable;          //make signed int to unsigned int


   cout<<"\n*#* Make coefficient matrix (using coefficient of variables) : \n"<<endl;

         for (int i = 0; i <number; i++) {
        for (int j = 0; j <number; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
 }
 cout<<endl;

    result[0] = find_determinant_of_each_variable(matrix,number);            // make determine for constant
            // make determine for constant
    cout<<"## Determinant of the COEFFICIENT matrix  ( D ) : "<<result[0]<<endl;
     cout<<"\n-----------------------------------------------------------------------------------------------------------------"<<endl;
    for(size_t i=0; i<number; i++)
    {
        cout<<"\n-----------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"*#*  To solve "<<variable[i]<<" , the coefficients of the "<< variable[i]<<"-- column is replaced by the constant column\n"<<endl;
        replace_column_with_constant_column(i,number);
        result[i+1] = find_determinant_of_each_variable(temp,number);
      //find determine for each variable

      cout<<"##  Determinant ( above Matrix ) for "<<variable[i]<<" is D"<<variable[i]<<" = "<<  result[i+1] <<"\n"<<endl;
       cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    }

    cout<<"Find solution of variable using formula ( D / Dx,y,z,........ ) "<<endl;

    if(result[0] != 0)                                        //divide by zero is not possible
    {


        for(size_t i=1; i<=number; i++)
        {
            cout<<"\n\n Value of "<<variable[i-1] <<" is " <<"=  D"<<variable[i-1]<< " / D "<<" = "<<result[i]<<"/"<<result[0]<<" = " << result[i]/result[0]<<endl;          //print solution
        }
    }

    if(result[0] != 0)                                        //divide by zero is not possible
    {

        cout<<"\n\nSolution is: "<<endl;
        for(size_t i=1; i<=number; i++)
        {
            cout<<"\t"<<variable[i-1]<<" = "<<result[i]/result[0]<<endl;          //print solution
        }
    }
    else
    {
        if(if_has_infinity_solution(result, number_of_variable))
        {
            cout<<"\n\n These equation has infinitely many solution"<<endl;
        }
        else
        {
            cout<<"\n\n These equation has no solution"<<endl;
        }
    }
}


int data_type_checker(char item)
{
    int i=-1;
    while(++i < 10)
    {
        if(item == numerical_number[i])
        {
            return NUMBER;
        }
    }
    if(item == 32)
    {
        return SPACE;           //it is an space
    }
    else if(item == '+' || item == '=' || item == '\0')
    {
        return OPERATOR;                        //operator separate two variable
    }
    else if(item == '-')
    {
        isNegative2 = true;
        return OPERATOR;
    }
    else if(item == '.')
    {
        return FRACTIONAL_POINT;
    }
    else if(item == '^')
    {
        return POWER;
    }
    else
    {
        return CHARACTER;
    }
}

int variable_match(char variable[][20], char store[], int *number_of_variable)
{
    //use pointer for increase original variable
    for(int i=0; i<*number_of_variable; i++)
    {
        if(strcmp(variable[i],store)==0)
        {
            return i;
        }
    }
    strcpy(variable[(*number_of_variable)],store);
    return (*number_of_variable)++;
}


void organize_variable(int variable_number)
{
    /* When we solve equation with matrix method, we need organize variable and locate constant in last*/
    int index;

    if(strlen(variable[variable_number-1]) != 0)
    {

        for(int i=0; i<variable_number-1; i++)
        {
            if(strlen(variable[i]) == 0)
            {
                index = i;
            }
        }

        char variable_swap[20];
        strcpy(variable_swap, variable[index]);                           //swap two variable
        strcpy(variable[index], variable[variable_number-1]);
        strcpy(variable[variable_number-1], variable_swap);

        for(int i=0; i<variable_number-1; i++)                              //swap two matrix column
        {
            double x = matrix[i][index];
            matrix[i][index] = matrix[i][variable_number-1];
            matrix[i][variable_number-1] = x;
        }
    }

    for(int i=0; i<variable_number-1; i++)
    {
        matrix[i][variable_number-1] *= -1;
    }
}

int extract_variable_number(string str[], int n)
{

    double coefficient=0;
    int number_of_variable=0,initial=0,store_index=0,power_index=1;


    for(int i=0; i<n; i++)
    {
        isEqual = false;
        isNegative1 = false;
        isNegative2 = false;
        isDecimalPoint = false;

        while(initial<=(int)str[i].size())
        {

            if(data_type_checker(str[i][initial]) == SPACE)               //If found space it will skip and check next
            {
                //continue;
            }
            else if(data_type_checker(str[i][initial]) == NUMBER)
            {
                if(isDecimalPoint)                       //there are a floating point
                {
                    coefficient += ((str[i][initial] - '0')/pow(10,power_index++));
                }
                else                            //there are no floating point
                {
                    coefficient = (coefficient * 10) + (str[i][initial] - '0');
                }
            }
            else if(data_type_checker(str[i][initial]) == FRACTIONAL_POINT)
            {
                isDecimalPoint = true;
            }
            else if(data_type_checker(str[i][initial]) == CHARACTER)
            {
                store[store_index++] = str[i][initial];
            }
            else
            {

                store[store_index] = '\0';
                store_index = 0;
                if(coefficient == 0  && (strlen(store) != 0))                        //when there are no coefficient before variable, there are a default variable 1
                {
                    coefficient = 1;
                }
                if((isNegative1 && !isEqual) || (!isNegative1 && isEqual))             //there are negative value before variable
                {
                    coefficient *= -1;
                }

                isNegative1 = isNegative2;
                isNegative2 = false;


                matrix[i][variable_match(variable, store, &number_of_variable)] += coefficient;   //add coefficient number in matrix

                if(str[i][initial] == '=')
                {
                    isEqual = true;
                }

                coefficient = 0;
                power_index = 1;
                isDecimalPoint = false;


            }
            initial++;
        }
        initial = 0;        //index start with zero for next line
    }

    organize_variable(number_of_variable);

    return --number_of_variable;                //variable include constant part. So it reduce by one
}

int take_input(string str[])
{
    // take input in form ax + by = c or ax +  by + c = 0
    unsigned int number;

    cout<<"Input Number of Variables :  ";
    cin>>number;
    getchar();          //for consume ENTER

    cout<<"INPIUT "<<number <<"  Equations one by one : \n"<<endl;
    for(size_t i=0; i<number; i++)
    {
        getline(cin,str[i]);           //Input equations
    }

    return number;
}

void solve_linear_equation()
{
    string str[SIZE];

    int number = take_input(str);
    int num = extract_variable_number(str, number);      //create a matrix and return number of variable
    solution_process(num);                     //print solution
}


int make_matrix_and_return_variable_num(string str[], double matrix2[SIZE][SIZE], char variable_name[][20],int number)
{
    int number_of_variable = extract_variable_number(str, number);

    for(int i=0; i<number_of_variable; i++)
    {
        strcpy(variable_name[i], variable[i]);
    }

    for(int i=0; i<=number_of_variable; i++)
    {
        for(int j=0; j<=number_of_variable; j++)
        {
            matrix2[i][j] = matrix[i][j];
        }
    }

    return number_of_variable;
}
