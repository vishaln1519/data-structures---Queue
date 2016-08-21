#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int rear,front;

	unsigned capacity;

	int *array;


}QUEUE;


QUEUE *CreateQueue(unsigned capacity);
int isFull(QUEUE *queue);
int isEmpty(QUEUE *queue);
void enqueue(QUEUE *queue,int ele);
int dequeue(QUEUE *queue);
void traverse(QUEUE *queue);


int main()
{
	unsigned int size;int option;int x;int ele;
	printf("enter the size if the circular size \n");

	scanf("%d",&size);

	QUEUE *queue= CreateQueue(size);

	do{
		printf("entert the option\n");
		printf(" 1: for insertion(PUSH)\n");
		printf(" 2: for deleion  (POP) \n");
		printf(" 3: for traversing\n");
		printf(" 0: for quiting\n");	
		scanf("%d",&option);


		switch (option)
		{
			case 1: printf("enter the data to be pushed\n");
					scanf("%d",&ele);
					enqueue(queue,ele);
					break;
			case 2:  x= dequeue(queue);
					printf("dequeue element is %d\n",x);	
					break;
			case 3: traverse(queue);
					break;
			default:printf("enter a valid option\n");		
		}


	}while(option!=0);
	return 0;



}

int isFull(QUEUE *queue)
{
	if((queue->front == 0 && (queue->rear==queue->capacity -1)) || (queue->front>0 && (queue->rear == queue->front -1)))
		return 1;
	else
		return 0;


}

int isEmpty(QUEUE *queue)
{
	return (queue->rear == -1 && queue->front ==0);
}



void enqueue(QUEUE *queue,int ele)
{

	if(isFull(queue))
	{
		printf("the queue is full\n");
	}

	else  if(queue->front > 0 && (queue->rear == queue->capacity - 1))
	{
		queue->rear = 0;

		queue->array[queue->rear]= ele;
	}
	else if((queue->front==0 && queue->rear == -1) ||(queue->rear!= queue->front - 1) )
	{
		queue->array[++queue->rear]= ele;
	}



}

int dequeue(QUEUE *queue)
{
	int ele;

	if(isEmpty(queue))
	{
		printf("no elements to dequeue\n");
	}
	else if(queue->rear == queue->front )
	{
		ele= queue->array[queue->front];
		queue->front = 0;
		queue->rear = -1;
	}	
	else if (queue->front == queue->capacity - 1)
	{
		ele= queue->array[queue->front];
		queue->front = 0;
	}

	else
	{
		ele = queue->array[queue->front++];
	}
	
	return ele;

}

QUEUE *CreateQueue(unsigned capacity)
{
	QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));

	queue->front=0;
	queue->rear= -1;
	queue->capacity = capacity;

	queue->array = (int *)malloc(capacity*sizeof(int));

	return queue;
}

void traverse(QUEUE *queue)
{

	if(isEmpty(queue))
	{
		printf("no elements to print\n");
		return ;
	}
	else if (queue->front > queue->rear)
	{
		for (int i = 0; i <=queue->rear; ++i)		
			printf("\t%d\n",queue->array[i] );
		for (int i = queue->front; i <=queue->capacity-1; ++i)		
			printf("\t%d\n",queue->array[i] );
		
		printf("\n");
	}
	else
	{
		for (int i = queue->front; i <=queue->rear; ++i)
		{
			printf("\t%d\n",queue->array[i] );
		}
		printf("\n");
	}




}



