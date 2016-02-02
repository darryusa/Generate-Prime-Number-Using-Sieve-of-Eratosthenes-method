// Jessica Ball
// Neal Nguyen

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void testMaxPrime();
void primeGenerator();
void sumPrimeNum();
void printSumPrimes();

int main()
{

    int maxPrimeFind = 0, maxCheck = 0;
    int *prime,*numTest, *sumPrimes, max=0,test=0, i;

    // will scan for the number of times the program will find the sum of n primes
    scanf("%d",&test);

    // dynamically allocates memory for arrays that will hold the n number of primes to sum specified by the user
    // and the sum of those n number of primes
    numTest = malloc(sizeof(int) * test);
    sumPrimes = malloc(sizeof(int) * test);

    for(i = 0; i <test;i++)
        {
            scanf("%d",numTest+i);
        }
    // function to find the maximum number of primes needed to find as specified by the user
    testMaxPrime(numTest,test,&max);

    // dynamically allocates the array of primes based off of the maximum number of primes to sum specified by the user
    prime = malloc(sizeof(int) * max);
    // finds a smaller domain for the numbers needed to find the maximum number of primes
    // instead of computing 10,000 primes every time unnecessarily
    maxPrimeFind = max * 11;
    // after finding maxPrimeFind the smaller domain is put in the array num(bers)
    int num[2][maxPrimeFind];

    // finds the minimum amount of numbers needed for the Sieve of Erathosthenes method of finding the primes by crossing off multiples
    // of 2 through "maxCheck" as not primes
    maxCheck = sqrt(maxPrimeFind);

    // populates the numbers array based on the smaller domain of numbers needed to find the maximum number of primes
    // second row is set to zero and will keep a tally every time a multiple of the number in the same column is found.
        for(i = 0; i < maxPrimeFind;i++)
    {
        num[0][i] = (i+1);
        num[1][i] = 0;
    }

    // function to find the primes needed to sum
    primeGenerator(prime,maxPrimeFind,num,maxCheck,max);

    // function to sum n number of primes specified by the user
    sumPrimeNum(numTest,prime,sumPrimes,test);
    // function to print all the sums of primes specified by the user
    printSumPrimes(sumPrimes,test);


    // instructions to free all dynamically allocated memory
    free(prime);
    free(sumPrimes);
    free(numTest);

    return 0;
}
void testMaxPrime(int *numTest,int test,int* max)
{
    int i;
    // test = number of times to find the sum of n primes
    for(i = 0;i <(test);i++)
        {
            if((*max) < (*(numTest+i)) )
            {
                *max = (*(numTest+i));
            }
        }
}

void primeGenerator(int* prime,int maxPrimeFind,int num[][maxPrimeFind],int maxCheck,int max)
{
    int i,j,k,result = 0,start = 0;
    for(i = 2 ;i < (maxCheck+1);((i)*(i)))
    {
        for(j= 2 ;j < (maxPrimeFind/i)+1;j++)
        {
            // result is the number that will find multiples/ composite numbers
            result = j*i;
            (num[1][result-1])++;

        }
        i++;
    }
    j = 1;
    for( i = 0;i <max;i++)
    {
        while(j < maxPrimeFind)
        {
            // if the tally in second row is equal to 1 then the number in the same column
            // but first row is prime and put that number in the prime array (in order)
            if(num[1][j] == 0)
            {
                *(prime+i) = num[0][j];
                break;
            }
            j++;
        }
        j++;
    }
}

void sumPrimeNum(int *numTest, int *prime, int *sumPrimes, int test)
{
    int i,j;
    for(i=0;i<test;i++)
    {
        // initialize the array at each index = to zero before computing the sum
        *(sumPrimes+i) =0;
        // sums the primes from index 0 to the number in the numTest array
        // which is the input of the number of primes to sum specified by the user
        for(j=0;j< *(numTest+i);j++)
        {
            // puts the sum of each number of primes into an array to hold all sums
            *(sumPrimes+i) += *(prime+j);
        }
    }
}

void printSumPrimes(int *sumPrimes, int test)
{
    int i;
    for(i=0;i<test;i++)
    {
        // prints from the array sumPrimes that hold all sums
        printf("%d\n", *(sumPrimes+i));
    }
}



