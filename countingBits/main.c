//
//  main.c
//  countingBits
//
//  Created by LiLingyu on 16/4/3.
//  Copyright © 2016年 LiLingyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    
    *returnSize = num+1;
    int* bits=NULL;
    
    bits=(int*)malloc((num+1)*sizeof(*bits));
    
    if (num==0) {
        bits[0]=0;
    }
    else if (num==1)
    {
        bits[0]=0;
        bits[1]=1;

    }
    else
    {
        
        bits[0]=0;
        bits[1]=1;
        
        for (int i=2; i<=num; i*=2) {
            //1. copy the first half from previous array
            for (int j=i; (j<i+i/2)&&(j<=num); j++) {
                bits[j]=bits[j-i/2];
                
            }
            
            //2. plus 1 from the previous array
            for (int j=i+i/2; (j<2*i)&&(j<=num); j++) {
                bits[j]=bits[j-i/2]+1;

            }
        }
    }
    
    
    
    
    return bits;
}

int main(int argc, const char * argv[]) {
    
    int num = 5;
    int returnsize=0;
    
    int* bits = countBits(num, &returnsize);
    
    printf("num=%d\n", num);
    
    printf("\nbits=\n");
    for (int i=0; i<=num; i++) {
        printf("%d\t", bits[i]);
    }
    
    free(bits);
    
    return 0;
}
