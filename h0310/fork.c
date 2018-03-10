#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void Sort(int *arr,int len)
{
	int i,j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - i- 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void Show(int *arr,int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void SecondMax(int *arr,int len)
{
	if(len<2)
	{
		return;
	}

	Sort(arr,len);
	printf("second max number is:%d\n",arr[len-2]);

}

int main()
{
	int arr[]={9,5,6,1,3,4,8,6,9,7,18,16};
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		Show(arr,sizeof(arr)/sizeof(arr[0]));
		Sort(arr,sizeof(arr)/sizeof(arr[0]));
		Show(arr,sizeof(arr)/sizeof(arr[0]));
	}
	else if(pid == 0)
	{
		SecondMax(arr,sizeof(arr)/sizeof(arr[0]));
	}
	else
	{
		printf("error");
	}
	exit(0);
}
