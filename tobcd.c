#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int frombcd_MSBFirst( char* bcd, int *val, int size)
{
	int i=0;
	unsigned int mul = 1;
	for(i=size-1;i>=0;i--){
		*val += bcd[i] * mul;
		mul*=10;
	}
}



int tobcd_MSBFirst(int val, char* bcd, int size)
{
	int i=size-1;
	unsigned int div = 10;
	while(val){
		if(div/10!=1)
			bcd[i] = (val % div) / (div/10);
		else
			bcd[i] = (val % div);
		val-=val % div;
		i--;
		if((i < 0)&&(val))
			printf("Error on Size\n");
		if(div*10 > div)
			div*=10;

		//printf("val = %i\n",val);
	}
}


int tobcd_LSBFirst(int val, char* bcd)
{
	int i=0;
	unsigned int div = 10;
	while(val){
		if(div/10!=1)
			bcd[i] = (val % div) / (div/10);
		else
			bcd[i] = (val % div);
		val-=val % div;
		i++;
		if(div*10 > div)
			div*=10;
			
		printf("val = %i\n",val);
	}
}



int getsize(int d)
{
	int i = 0;
	int size = 0;
	
	while(d){
		size++;
		d/=10;
	}
	printf("Size = %i \n",size);
	return size;
}



int main(int argc, char** argv)
{
	int decimal =0, i=0;
	char *bcd;
	int size;
	
	printf("Enter the number to convert to bcd\n");
	scanf("%d",&decimal);
	/* Count the number of digit */
	size = getsize(decimal);
	/* Allocate correct array size */
	bcd = malloc(size);
	memset(bcd,0,size);
	/* Convert to BCD */
	tobcd_MSBFirst(decimal, bcd, size);
	/* Print BCD Array */
	printf("bcd : \t");
	for(i=0;i<size;i++)
		printf("%i ",bcd[i]);
	printf("\n");
	
	printf("TO Decimal\n");
	decimal = 0;
	frombcd_MSBFirst(bcd, &decimal, size);
	printf("decimal = %i\n",decimal);
	
}
