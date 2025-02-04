#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


#include "num.h"

int sumOfDigits(int num){
    //take the absolute value of the number 
    if(num<0){
        num = -num;
    }
    int sum=0;
    for(int i = num; i>0 ; i=i/10){
        sum += i%10;
    }
    return sum;
}


int reverseNumber(int num){
    bool positive = true;
    if(num < 0){
        num = -num;
        positive = false;
    }
    int reversed=0;
    while(num>0){
        reversed= reversed * 10 + num%10;
        num /= 10;
    }
    return positive ? reversed : -reversed;
}


bool isPalindrome(int num){
    /*We consider Negative number as they are 
    capable of being pallidrome (absolute value)*/
    return num == reverseNumber(num);
}


bool isPrime(int num){
    // edge cases
    if(num<= 1) return false;
    if(num <= 3) return true; 
    if(num % 2 ==0 ||num %3 == 0) return false;
    for(int i=5 ; i * i <= num; i += 6){
        if(num% i ==0|| num%(i+2)==0){
            return false;
        }
    }
    return true;
    /*Every prime number greater than 3 is either 1 
    less or 1 more than a multiple of 6. This means 
    prime numbers are spaced in a pattern around
    multiples of 6.*/
}


int gcd(int a, int b){
    a = a < 0 ?-a : a;
    b = b < 0 ? -b :b; 
    if(b> a){  
        int temp=a;
        a=b;
        b=temp;
    }

    while(b != 0){  
        int temp=a;
        a=b ;
        b =temp % b;
    }
    return a; 
}


int lcm(int a, int b){
    a= a<0 ?-a: a;
    b= b<0 ? -b : b; 
    return (a*b) / gcd(a,b);
}


long factorial(int num){
    if(num < 0) return 0;

    unsigned long long int fact =1;
    for(int i = 2 ; i <= num ; i++){
        fact *= i;
        if(fact > LLONG_MAX / i){ //check if multiplying would cause overflow
            return -1;
        }
    }
    return fact;
}


bool isEven(int num){
    return (num & 1) == 0; //check if the LSB is 0 then it is even (even for negative numbers)
}


void primeFactors(int num){
    if(num <= 1){
        printf("%d has no prime factors !!", num);
    } 
    
    printf("Prime factors of %d are : ", num);

    int first = 1;
    for(int i = 2; i <= num; i++){
        while(num % i == 0){
            if(!first) printf(" , ");
            printf("%d", i);
            while(num % i == 0){
                num /= i;
            }
            first = 0;
        }
    }

    printf("\n");
}


bool isArmstrong(int num){
    if(num < 0){
        return false;
    }
    int digits = 0;
    for(int i =num ; i>0 ; i=i/10){//digits count
        digits++;
    }


    int sum =0;
    int digit;

    for(int i = num ; i > 0; i /= 10){
        //calculate digit^digits manually
        digit = i%10;
        int digit_power = 1;
        for(int j = 0; j < digits ; j++){
            digit_power *= digit;
        }
        sum += digit_power;        
    }

    return num == sum ;
}


void fibonacciSeries(int n){
    if(n< 0){
        printf("invalid input!!\n");
    }else if(n == 0){
        printf("0\n");
    }else{
        printf("0");
        int n1= 0;
        int n2= 1;

        while(n2 <= n){
            printf(", %d", n2);
            int temp = n1+ n2;
            n1 =n2 ;
            n2 = temp;
        }
        printf("\n"); 
    }
}

int sumDivisors(int num){
    if(num < 0){
        return -1;//Error
    }
    int sum = num;// include num as self divisor

    for(int i = 1 ; i <= num/2 ; i++){
        if(num % i ==0){
            sum+=i;
        }
    }
    return sum;
}

bool isPerfect(int num){
    if(num <= 0){
        return false;
    }

    //calculate sum of divisors ( except the number itself )
    int sum = 0;
    for(int i = 1 ; i <= num/2 ; i++){
        if(num % i ==0){
            sum+=i;
        }
    }

    return num == sum;
}

bool isMagic(int num){
    return num<0 ? false : num% 9 == 1; // we consider zero as a non-magic number
    /*num % 9 represents digital root which is mathematically
    the result of iterative process of summing digits*/
}

bool isAutomorphic(int num){
    if(num < 0){
        return false;
    }
    // calculating 10^(NumberOfDigits -1)
    int factor = 1;
    for(int i = num ; i>0 ; i/=10){
        factor*=10;
    }
    return (num*num)%factor == num;
}


void toBinary(int num){
    int binary=0;
    int i = 0;
    while(num > 0){
        binary += (num % 2)*pow(10,i);
        num /= 2;
        i++;
    }

    printf("%d\n" , binary);
}

bool isNarcissistic(int num){
    return isArmstrong(num);
}

double sqrtApprox(int num){
    double x0 = (double)num /2; // initial guess
    double x1;
    double accuracy = 0.00001;
    while(true){
        x1 = 0.5*(x0 + (num / x0));
        if(fabs(x1 -x0) /x0 <= accuracy){ // Check the accuracy by relative difference  
            break;
        }
        x0=x1;


    }

    return x1;
}

double power(int base, int exp){
    
    if(base == 0 && exp == 0){
        return 1;
    } 
    if(base == 0 && exp < 0){
        return 0;  // division by zero
    }
    if(exp == 0){
        return 1;
    }

    double result = 1.0;
    int abs_exp = (exp<0) ? -exp: exp;

    for(int i = 0; i <abs_exp; i++){
        result *= base;
    }

    // if the exponent is negative, take the inverse
    if(exp < 0){
        result =1 / result;
    }
    return result;
}


bool isHappy(int num){
    if(num <= 0) return false;
    bool seen[1000] = {false};//a set to track the sums we've seen before (we'll use an array as a simple set)
    while(num !=1){
        int sum=0 ;
        while(num > 0){
            sum+= (num % 10)*(num % 10); 
            num /=10;
        }
        num=sum;
        if(seen[num]) return false;//if the number is already seen , we are in a cycle
        seen[num] = true; // mark the num ber as seen
    }

    return true; // if it reaches 0 , the number is happy!

}


bool isAbundant(int num){
    if(num <= 0) return false;

    return sumDivisors(num)-num > num;
}

bool isDeficient(int num){
    if(num <= 0) return false;
    return sumDivisors(num) - num < num;
}


int sumEvenFibonacci(int n){
    if(n < 2) return 0;

    int n1= 0;
    int n2= 1;
    int sum =0;
    // sum all odd fibonacci numbers (n-2 iterations since we already use 0 and 1)
    for(int i =0 ; i < n-2 ; i++){
        int temp = n1+ n2;
        n1=n2;
        n2=temp;
        if(n2%2 ==0) sum+=n2; // add only even numbers
    }
    return sum;

}


bool isHarshad(int num){
    if(num <= 0) return false; // Only positive integers are considered
    return num % sumOfDigits(num) == 0;
}

unsigned long catalanNumber(int n){
    // we mean by nth catalan number the 'rank' of the number 
    if(n <= 0) return 0; 
    if(n == 1) return 1; //base case : C0 = 1

    unsigned long catalan = 1; // start with C_0 = 1
    for(int i = 0; i < n-1; i++){
        catalan = catalan * 2 * (2 * i + 1) / (i + 2);//formula of catalan number
    }
    return catalan;
}


void pascalTriangle(int n){
    for(int i = 0; i < n; i++){
        int value = 1;  //first element in every row is 1

        // print initail spaces for
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }

        //calculate and print each element in the row
        for(int j = 0 ; j <=i; j++){
            if(j >0){
                value = value * (i- j + 1) / j;  // calculate the next value in the row
            }
            printf("%d ", value);  //print the value
        }
        printf("\n");
    }
}


unsigned long arrangement(int num , int k){
        return factorial(num) / (factorial(k) * factorial(num-k));
}
unsigned long bellNumber(int n){
    if(n == 0) return 1; //base case: B0 = 1

    unsigned long bell = 0;
    for(int k = 0; k <= n-1; k++){ //nth bell number means the 'rank'
        bell += arrangement(n - 1, k) * bellNumber(k);// we use recursive function call
    }
    return bell;
}

bool isKaprekar(int num){
    if(num <= 0) return false;

    //calculate number of the number and its sqaure digits
    long long int n2 = num*num;
    int digitsNum=0,digitsNum2=0;

    for(long long int i = n2 ; i>0; i /= 10) digitsNum2++;
    for(int i = 1 ; i < digitsNum2;i++){
        long long int divisor = (int)power(10,i);
        long long int left = n2 / divisor;
        long long int right = n2% divisor ;
        if(left + right ==num) return true;
    }
    
    return false;
}

bool isSmith(int num){
    if(num <= 1 ||isPrime(num)) return false;

    //calculate digits of num
    int numDigits =sumOfDigits(num);

    //factorizing the number and summing digits of each
    int sumPrimesDigits =0; 
    for(int i = 2; i <= num; i++){
        while(num % i == 0){
            sumPrimesDigits += sumOfDigits(i);
            num /= i;
        }
    } 

    return numDigits == sumPrimesDigits;
}
int sumOfPrimes(int n){
    if(n<=1) return 0; // no prime less than 2
    if(n ==2) return 2; //we check for 2 to skip even numbers in the loop

    // calculate sum intialized with 2 since n is greater than 2
    int sum = 2;
    for(int i = 3; i <= n ; i+= 2){
        if(isPrime(i)) sum+=i;
       
    }

    return sum;
}