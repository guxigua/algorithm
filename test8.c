#include <stdio.h>
#include <stdlib.h>

struct list
{
	struct list *previous; 
	struct list *next;
	int key;
};
struct list* enter_Bucket(struct list *list,int key)
{
	struct list * temp;
	if(list == NULL)
	{
		 list		=(struct list*)malloc(sizeof(struct list));
		 list->previous	=	NULL;
		 list->next	=	NULL;
		 list->key	=	key;
		 temp		=	list;
	
	}
	else
	{
	      	 temp	=	list;
		 while(list->next != NULL)	list=list->next;
		 list->next	=(struct list*)malloc(sizeof(struct list));
		 list->next->previous	=	list;
		 list->next->next	=	NULL;
		 list->next->key	=	key;
	}
	return temp;
}

void get_num(struct list **list, int *arr,  int size)
{
	int i=0;
	int j=0;
	struct list *temp;
	for(i=0; i < size; i++)
	{
		while(*(list+i) != NULL)
		{
			temp		=	(*(list+i))->next;
			*(arr+j)	=	(*(list+i))->key;
			j++;
			free(*(list+i));
			(*(list+i))	=	temp;
		}
	}
}
void add(int *arr, int size, int higest)
{
	int i,j,k;
	int temp;
	int divisor;
	int high=1;
	struct list *bucket[10]={NULL};
	for(i=1; i < higest; i++)
	high*=10;
	for(k=1; k <= higest; k++)
	{
		for(i=0; i < size; i++)
		{
			divisor=high;
			temp = *(arr+i);
			for(j=higest; j > k; j--)
			{
				temp %= divisor;
				divisor/= 10; 
			}
			temp/=divisor;
		*(bucket+temp)=enter_Bucket(*(bucket+temp), *(arr+i));
		}
		get_num(bucket, arr, 10);
	}
}
int main()
{
	int arr[10]={101,202,302,40,585,686,78,80,908,19};
	add(arr, 10, 3);
}
