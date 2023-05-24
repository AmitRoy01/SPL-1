using namespace std;


#define SIZE 20


void solve_polynomial_equation();

void solve_linear_equation();
void solve_linear_equation_with_process();
void create_matrix();

int make_matrix(string str[] , double matrix_2[SIZE][SIZE], char vari_name[][20],int number);

void input_linear_programming();

int data_type_checker(char item);

bool if_has_infinite_solution(double result[], int number_of_variable);

void create_solution();

int large_size_matrix();

void starting_method(double coefficient[], int total);
void Linear_Graph();
void Polynomial_Graph();
