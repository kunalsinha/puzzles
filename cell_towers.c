#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);

int main()
{
    int i, size;
    int cost[] = {0,314,159,265,358,979,323,846,264,338};
    int **sol;
    
    size = sizeof(cost)/sizeof(int);
    sol = (int **) malloc(sizeof(int *) * size);
    for(i=0; i<size; i++)
        sol[i] = (int *) malloc(sizeof(int) * 2);
    
    sol[0][0] = 0;
    sol[0][1] = 0;
    sol[1][0] = cost[1];
    sol[1][1] = cost[1];
    
    for(i=2; i<size; i++)
    {
        sol[i][1] = min(min(sol[i-2][1], sol[i-2][0]) + cost[i], sol[i-1][1] + cost[i]);
        sol[i][0] = sol[i-1][1];
    }
    
    //for(i=0;i<size;i++)
    //    printf("%d\t%d\n", sol[i][0],sol[i][1]);
    printf("Minimum cost of cell towers to cover all the towns = $%d\n", min(sol[size-1][0], sol[size-1][1]));
    
    return 1;
}

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

