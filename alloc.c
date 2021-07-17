#include<stdio.h>
#include<stdlib.h>

/**************************
 Dynamic Memory Allocation
**************************/

void print(int, int*);


int main(){

    int i, n;
    printf("Enter the number of integers you want to store in the array: ");
    scanf("%d", &n);
    int *ptr = (int*)malloc(n*sizeof(int));

    if(ptr == NULL){

        printf("Allocation unsuccessful!");
        exit(1);
    }


    //allocate integers to array
    for(i = 0; i < n; ++i)
    {
        printf("Enter an integer: ");
        scanf("%d", ptr+i);
    }

    print(n, ptr);

    char c = 'y';
    

    //this loop asks if user wants to allocate more space to array
    while(scanf("%c", &c))
    {
        printf("Want to allocate more integers? [Y/N]: ");
        scanf("%c", &c);

        if(c == 'Y' || c == 'y')
        {
            int m;
            printf("Enter the number of new integers you want to store in the array: ");
            scanf("%d", &m);
            n += m;

            ptr = (int*)realloc(ptr, (n)*sizeof(int));

            for(i = n-m; i < n; ++i)
            {
                printf("Enter an integer: ");
                scanf("%d", ptr+i);
            }

            print(n, ptr);

        }
        else break;
    }

    //free the dynamic allocated memory 
    free(ptr);
    
    return 0;
}

//function that prints the given array
void print(int n, int* p){

    for(int i = 0; i < n; ++i)
    {
        if(i == n-1)
            printf("%d", *(p+i));

        else
            printf("%d,", *(p+i));
    }
    printf("\n");
}

/*
Memory allocated by calloc is initialized with 0. 
Memory allocated by malloc is initialized with some garbage value.
Both return NULL if there is not sufficient memory available on heap.
Realloc is changing the size of the memory block without losing the data.
Free is releasing the dynamic allocated memory.
*/
