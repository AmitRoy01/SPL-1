#include<bits/stdc++.h>

#define SPACE 0
#define OPERATOR 1
#define NUMBER 2
#define CHARACTER 3
#define FRACTIONAL_POINT 4
#define POWER 5

#define SIZE 20

using namespace std;

char numerical_value[]={'0','1','2','3','4','5','6','7','8','9'};
bool isDecimalpoint,isNegative1,isNegative2,isEqual;

char variable[SIZE][20],stored_data[20];
double matrix[SIZE][SIZE]={0},temp[SIZE][SIZE];

//find determinant of matrix
double determinant_matrix(double array[][SIZE], unsigned int number)
{
    for(size_t i=0;i<number;i++)
    {
        for (size_t j=number-1;j>i;j--)
            {
            if(array[j][i]==0)
            {
                continue;
            }
            else{
                if(array[j-1][i]==0)
                    {
                    //exchanging rows
                    for(size_t p=0;p<number;p++){
                        double temp = array[j][p];
                        array[j][p] = array[j-1][p];
                        array[j-1][p]=temp;
                    }
                    continue;
                }
            }
        }
    }

    //calculate determine of matrix required portion

    double sum=-1;
    for(size_t i=0;i<number;i++)
        {
        sum*=array[i][i];
    }
    //return determine as sum
    return sum;
}

//this function make a temporary array and calculate this

double  compute_determinant(double array[][SIZE],unsigned int number)
{
    double memory[SIZE][SIZE];

    for(size_t i=0;i<number;i++)
    {
        for(size_t j=0;j<number;j++){
            memory[i][j] = array[i][j];
        }
    }
    //return determinant of matrix
    return determinant_matrix;
}

// find variable coefficient we need to replace column_value with variable

void replaceColmn_by_variable(unsigned int x,unsigned int number)
{
    for(size_t i=0;i<number;i++){
        for(size_t j=0;j<number;j++){
            if(j==x){
                temp[i][j] = matrix[i][number];
            }
            else {
                temp[i][j]=matrix[i][j];
            }
        }
    }
}

//checking if there infinity solution

bool has_infinity_solution(double result[],int number_of_variable)
{
    for(int i=1;i<=number_of_variable;i++)
    {
        if(result[i]!=0) //there are infinity solution if all determine are zero
        {
            retrun false;
        }
    }
    return true;
}

void make_solution(int number_of_variable)
{

    double result[SIZE];
    unsigned int number = (unsigned)number_of_variable;

    result[0] = compute_determinant(matrix,number);

    for(size_t i=0;i<number;i++)
    {
         replaceColmn_by_variable(i,number);
         //find determinant for every variable
         result[i+1]=compute_determinant(temp,number);

    }


    //print Solution of the equations
    if(result[0]!=0)
    {
        cout<<"\n\n Solurtion is: "<<endl;
        for(size_t i=1;i<=number;i++)
        {
            cout<<variable[i-1]<<" = "<<result[i]/result[0]<<endl;

        }
    }
    else{
        if(has_infinity_solution(result,number_of_variable))
        {
            cout<<"\n The equations have infinity solutions."<<endl;
        }
        else
        {
            cout<<"\n\n OOPS, sorry. The equations have no Solution. Try another one."<<endl;
        }
    }
}


//check data type( Tokenizer part)

int data_type_checker(char input)
{
    int i=-1;
    while( ++i < 10)
    {
        if(input == numerical_value[i])
        {
            return NUMBER;
            //it is an number ( may be cofficient or constant values
        }
    }
    if(input == 32)
    {
        return SPACE;
        // it is space '='
    }
    else if(input == '+' || input == '=' || input == '\0')
    {
        return OPERATOR;
        //variables are separated by operator
    }
    else if(input == '-')
    {
        isNegative2 = true;
        return OPERATOR;
    }
    else if(input == '.')
    {
        return FRACTIONAL_POINT;
    }
    else if(input == '^')
    {
        return POWER;
    }
    else
    {
        return CHARACTER;
    }
}

//the function match the variables
int isVariable(char variable[][20], char stored_data[], int *number_of_variable)
{
    //check if it is variable
    for(int i=0;i<*number_of_variable;i++)
    {
        if(strcmp(variable[i],stored_data)==0)
        {
            return i;
        }
    }
    strcpy(variable[(*number_of_variable)],stored_data);
    return (*number_of_variable)++;
}

//Locate the variables in matrix
//This is done to ensure that the constant in each equation is located in the last column of the matrix
void relocate_variable(int numberOfVariable)
{
    int relocate_index;

    if(strlen(variable [numberOfVariable -1)!=0) //if the last variable in the variable array is not an empty string.
    {
        for(int i=0;i<numberOfVariable - 1;i++)
        {
            if(strlen(variable[i])== 0)
            {
                relocate_index = i;
            }
        }

        char exchange_variable[20];
        strcpy(exchange_variable,variable[relocate_index]);
        // exchange two variable

        strcpy(variable[exchange_index],variable[numberOfVariable-1]);
        strcpy(variable[numberOfVariable -1],exchange_variable);

        //swap two matrix column
        for(int i=0;i<numberOfVariable-1;i++)
        {
            double temp = matrix[i][relocate_index];
             matrix[i][relocate_index] = matrix[i][numberOfVariable-1];
            matrix[i][numberOfVariable-1] = x;
        }

    }

    for(int i=0;i<numberOfVariable-1;i++)
    {
        matrix[i][numberOfVariable-1] *= -1;
    }
}

//This function extract the variables,constants from expressions
int extract_from_expression(string str[], int n)
{

    double coefficient=0;
    int number_of_variable=0;
    int initial=0;
    int store_index=0;
    int power_index=1;


    for(int i=0;i<n;i++){
        isEqual = false;
        isNegative1 = false;
        isNegative2 = false;
        isDecimalpoint = false;

        while(initial<=(int)str[i].size()){

            if( data_type_checker(str[i][initial]) == SPACE){
                        //If found space it will skip and check next

            }
            else if( data_type_checker(str[i][initial]) == NUMBER){
                if(isDecimalpoint){
                    //check if there is floating point
                    coefficient += ((str[i][initial] - '0')/pow(10,power_index++));
                }
                else{
                     //if there is no floating point
                    coefficient = (coefficient * 10) + (str[i][initial] - '0');
                }
            }
            else if( data_type_checker(str[i][initial]) == FRACTIONAL_POINT){
                isDecimalpoint = true;
            }
            else if( data_type_checker(str[i][initial]) == CHARACTER){
                store[store_index++] = str[i][initial];
            }
            else{

                store[store_index] = '\0';                  //variable string terminated by NULL
                store_index = 0;
                if(coefficient == 0  && (strlen(store) != 0)){
                        //when there are no coefficient before variable, there are a default variable 1
                    coefficient = 1;
                }
                if((isNegative1 && !isEqual) || (!isNegative1 && isEqual)){
                       //there are negative value before variable
                    coefficient *= -1;
                }

                isNegative1 = isNegative2;
                isNegative2 = false;

                //add coefficient number in matrix
                matrix[i][variable_match(variable, store, &number_of_variable)] += coefficient;


                if(str[i][initial] == '='){
                    isEqual = true;
                }

                coefficient = 0;
                power_index = 1;
                decimal_point = false;


            }
            initial++;
        }
        initial = 0;
    }


    relocate_variable(number_of_variable);

    return --number_of_variable;                //variable include constant part. So it reduce by one
}

//This function take equation as input
int input_controller(string str[])
{

unsigned int number_of_variable

cout<<" Number of variables :  "<<number_of_variable<<endl;
cin>>number_of_variable;
getchar();    //for consume ENTER

cout<<" INPUT "<<number_of_variable<<" EQUATIONS \n "<<endl;

for(size_t i=0;i<number;i++)
{
    getline(cin,str[i]);
}
return number_of_variable;
}

//this function call required functions for solving linear equation

