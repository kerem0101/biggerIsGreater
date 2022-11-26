#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rowInput[100] = {0};

void swap(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 /*
// A function to implement bubble sort
void sort(char input[], int numSequence, int n)
{
    int i=0;
    for (; i < n - 1; i++)
 
        // Last i elements are already in place
        for (int j = numSequence; j < n - i - 1; j++)
            if (input[j] < input[j + 1])
                swap(&input[j], &input[j + 1]);
}

*/

void changeBiggerWithSmallest(char input[], int biggerNum, int length){
    int n = biggerNum;
    char smallest = input[n+1];
    int k = biggerNum+1;
    for(;n<length; n++){
        if(input[n] < smallest){
            if(input[biggerNum]<input[n]){
                smallest = input[n];
                k=n;
            }
            
        }
    }
    swap(&input[biggerNum],&input[k]);
    /*
    char temp = input[biggerNum];
    input[biggerNum] = input[k];
    input[k] = temp;
    */
}

int checkBigger(char input[], int length){
    
    int n = length-1;
    while(n > 0){
        
        if(input[n] > input[n-1]){
            break;
        }
        
        n--;
    }
    
    return n-1;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

int main()
{
    int rowNumber=0;
    
    int biggerNumSeq=0;
    int length = 0;
    int sortParam = 0;
    
    scanf("%d",&rowNumber);
    
    while(rowNumber > 0){
        scanf("%s",rowInput);
        length = strlen(rowInput);
        biggerNumSeq=checkBigger(rowInput,length);
        if(biggerNumSeq < 0){
            printf("no answer\n");
            
        }
        else{
            changeBiggerWithSmallest(rowInput,biggerNumSeq,length);
            sortParam = length - (biggerNumSeq + 1);
            qsort(rowInput+biggerNumSeq+1, sortParam, sizeof(char), cmpfunc);
            //sort(rowInput,biggerNumSeq,length);
            for(int i=0;i<length;i++){
                printf("%c",rowInput[i]);
            }
            printf("\n");
        }
        
        rowNumber--;
    }
    
    return 0;
}
