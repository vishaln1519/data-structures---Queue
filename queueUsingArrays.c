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
		int size;int option;int ele;	
	printf("enter the size of the queue\n");
	scanf("%d",&size);int x;

	QUEUE *queue = CreateQueue(size);
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
			case 2:  x =dequeue(queue);
					printf("dequeue element is %d\n",x );	
					break;
			case 3: traverse(queue);
					break;
			default:printf("enter a valid option\n");		
		}


	}while(option!=0);
	return 0;



}

QUEUE *CreateQueue(unsigned capacity)
{


	QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));

	queue->rear=-1;
	queue->front = 0;
	queue->capacity = capacity;
	queue->array= (int *)malloc(capacity*sizeof(int));


	return queue;


}

int isFull(QUEUE *queue)
{
	return (queue->rear == (queue->capacity -1))	;

}

int isEmpty(QUEUE *queue)
{

	return (queue->rear == -1 && queue->front == 0)  || ( queue->front > queue->rear);

}

void enqueue(QUEUE *queue,int ele)
{

	if(isFull(queue))
	{
		printf("the queue is full\n");
		return ;
	}

	queue->array[++queue->rear]=ele;



}

int dequeue(QUEUE *queue)
{
	if(isEmpty(queue))
	{
		printf("no elements to dequeue\n");
		return 0;
	}

	return queue->array[queue->front++];
}

void traverse(QUEUE *queue)
{
	for(int i=queue->front;i<=queue->rear;i++)
        {
            printf("\t%d",queue->array[i]);
        }

        printf("\n");

}