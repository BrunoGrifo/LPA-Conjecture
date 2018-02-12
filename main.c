#include<stdio.h>
#include<stdlib.h>
int recursive(int num,int* passos);
static int passos[100000];
static int max[100000];
int main()
{
    int a,i;
    while( scanf("%d", &a) > 0 ) {
    	if(max[a-1]!=0){
    		printf("%d %d\n",a,max[a-1]);
    	}else{
    		i=1;
    		while(i<=a){
    			if(passos[i-1]!=0)
    				i++;
    			else{
    				int num=0;
    				num=recursive(i,passos);
    				if(num > max[i-2] && i!=1){
    					max[i-1]=num;
    				}else{
    					max[i-1]=max[i-2];
    				}
    				passos[i-1]=num;
    				i++;
    			}
    		}
    		printf("%d %d\n",a,max[a-1]);
		}
		
    }
    return 0;
}

int recursive(int num,int passos[]){
	if(num-1<100000){
		if(passos[num-1]!=0){
			return passos[num-1];
		}	
	}
	if(num==1){
		return 0;	
	}
	if(num%2==0){
		return 1+recursive(num/2,passos);
	}
	if(num%2!=0){
		return 1+recursive(num*3 +1,passos);
	}
	return 0;
}
