#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define visited 1
#define unvisited 0
void addq(int data){
	
	if(rear>=MAX-1){
		printf("\n Queue is full\n");
		return;
	}
	rear++;
	q[rear]=data;
	if(front==-1){
		front=0;front++;
		
	}
}

void delq(){
	if(front==-1){
		printf("\nQueue is empty\n");
		return;
	}
	q[front]=0;
	if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
}
struct graphNode
{
    int data;
    struct graphNode *next;
};
struct graphNode *arr[MAX];
int vertex_list[MAX] = {1,2,3,4,5};
struct graphNode *createList(int vertex)
{
    struct graphNode *r;
    int data;
    printf("vertex %d connected to:",vertex);
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    r = (struct graphNode *)malloc(sizeof(struct graphNode));
    r-> data =data;
    r-> next = createList(vertex);
    return r;
}
int find_index(int cwv){
	int i;
	for(i=0;i<MAX;i++){
		if(cwv==vertex_list[i]){
			return i;
		}
	}
}
void bfs(int cwv)//current working vertex
{
	//rule#1
		int vli=0;//visited list index
		visited_list[vli]=cwv;//visit and marked
		printf("%d",cwv);//display vertex
		addq(cwv);//insert in q
	//	find_index(cwv);
		*adjacent=arr[find_index(cwv)];//set pointer to vertex
	//rule #2
	
	int i;
	int flag;
	
while(front!=-1){

	while(adjacent!=NULL){
	flag=unvisited;
	for(i=0;i<MAX;i++){
		if(adjacent->data==visited_list[i]){
			flag=visited;
			break;
		}
	}	
	if(flag==unvisited){
		vli++;
		visited_list[vli]=adjacent->data;//visit and marked as visited
		printf("%d",adjacent->data);//display the vertex
		addq(adjacent->data);//insert in q
		
		adjacent=adjacent->next;//move to next element
	}
	else{//if(flag==visited)
		adjacent=adjacent->next;
	}
}

delq();
cwv=q[front];
adjacent=arr[find_index(cwv)];
}
}
int main()
{
	int i;
	for(i=0; i<MAX; i++)
	{
		arr[i] = createList(vertex_list[i]);
	}
	for(i=0; i<MAX; i++)
	{
		printf("\nAdjacent of %d: \n" , vertex_list[i]);
		struct graphNode *temp = arr[i];
		
		while(temp != NULL)
		{
		printf("\t%d", temp->data);
		temp = temp->next;
		}
	}
 
	return 0;
}

	



