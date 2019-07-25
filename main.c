#include <stdio.h>
#include <string.h>

int program_counter = 0;

//Recursive Programming

int Factorial(int num){
    program_counter++ ;
    if( num == 0 ) return 1;
    return Factorial( num-1 ) * num;
}

int Fabonacci(int num){
    program_counter++;
    if( num == 0 ) return 0;
    if( num == 1 ) return 1;
    return Fabonacci( num-1 ) + Fabonacci( num-2 );
}

int Combination(int n, int m){
    program_counter++;
    if ( m == 0 || n == m ) return 1;
    return Combination( n-1, m ) + Combination( n-1, m-1 );
}

int GCD(int n, int m){ //Greatest Common Divisor
    program_counter++;
    if( n % m == 0 ) return m;
    return GCD( m, n%m );
}

int Ackerman(int m, int n){
    program_counter++;
    if ( m == 0 ) return n+1;
    else if ( n == 0 ) return Ackerman( m-1, 1 );
    return Ackerman( m-1, Ackerman( m, n-1 ));
}

int sum(int n){
    program_counter++;
    if ( n==0 ) return 0;
    return n + sum(n-1);
}

int Hanoi(int disk_num){
    program_counter++;
    if ( disk_num == 1 ) return 1;
    return 2 * Hanoi( disk_num-1 ) + Hanoi(1);
}

//swap the value with the pointer
void swap( char *a, char *b ){
    printf("a value: %p\n", a);
    printf("b value: %p\n", b);
    char temp = *a;
    printf("temp value: %p\n", temp);
    *a = *b;
    *b = temp;
}

int comb_num = 0;

void Permutation(char *arr, int start_flag, int end_flag){
    program_counter++;
    if ( start_flag == end_flag ){
        for ( int j=0; j<=end_flag; j++ ) {
            printf("%c", arr[j]);
        }
        printf("\n");
        comb_num++;
    } else {
        for( int j=start_flag ; j<=end_flag; j++){
            swap(&arr[start_flag], &arr[j]);
            Permutation(arr, start_flag+1, end_flag);
            swap(&arr[start_flag], &arr[j]);
        }
    }
   
}

//void StackPermutation(char *input_arr, char *output_arr, int start_flag, int end_flag){
//    
//}
//
//void push( char input, char output){
//    if (strlen(input)-1 > )
//}

//Pointer

void sum_diff(int n1, int n2, int *sum, int *diff){
    *sum = n1+n2;
    *diff = (n1-n2) ? (n1-n2) : (n2-n1);
}

void sum_diff_main(){
    int na, nb;
    int sum=0,diff=0;
    puts("Please input two value:");
    printf("IntegerA: "); scanf("%d", &na);
    printf("IntegerB: "); scanf("%d", &nb);
    sum_diff(na, nb, &sum, &diff);
    printf("Sum of two values: %d \nDiff of two values: %d\n",sum, diff);
}


int main(int argc, const char * argv[]) {
//    printf("%d\n", Hanoi(3));
    char arr[] = "AB";
    Permutation(arr, 0, strlen(arr)-1);
    printf("With the Combination number of: %d\n", comb_num);
    printf("It execute: %d times\n", program_counter);

}
