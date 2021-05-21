
#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */

# define MAX_VERTEX 10
#define stack_size 10
typedef struct node
{
	int vertex;
	struct node* next;
}Node;


typedef struct
{
	Node* graph[MAX_VERTEX];
	int visited;
	int n;
}Graph;



void initilizeGraph(Graph* g);
void printGraph(Graph* g);
void insertvertex(Graph* g);
void insertEdge(Graph* g, int v1, int v2);

void DFS(Graph* g, int v);
void freeGraph(Graph* g);

/*DFS에 필요한 함수*/
void push(int n) ;
int pop();
int stack[stack_size] = { 0, };
int top = -1;


int main()
{
	char command;
	int n1, n2;
	Graph* G = (Graph*)malloc(sizeof(Graph));

	printf("\nJeongjaemin      2018038067\n\n");
	do {
		printf("----------------------------------------------------------------\n");
		printf("                        Graph  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph    = z                               ");
		printf(" \nInsert  Vertex      = i         Insert Edge          = e \n");
		printf(" Depth First Search  = d         Breath First Search = b\n");
		printf(" Print Graph         = p         Quit                = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initilizeGraph(G);
			break;
		case 'i': case 'I':
			insertvertex(G);
			break;
		case 'e': case 'E':
			printf("put connect vertex: (v1, v2)");
			scanf(" %d", &n1);
			scanf(" %d", &n2);
			insertEdge(G, n1, n2);
			insertEdge(G, n2, n1);
			break;

			/*case 'n': case 'N':
				printf("Your Key = ");
				scanf_s("%d", &key);
				insertLast(headnode, key);
				break;
			case 'e': case 'E':
				deleteLast(headnode);
				break;
			case 'f': case 'F':
				printf("Your Key = ");
				scanf_s("%d", &key);
				insertFirst(headnode, key);
				break;
			case 't': case 'T':
				deleteFirst(headnode);

				break;
			case 'r': case 'R':
				invertList(headnode);
				break;
			case 'q': case 'Q':
				freeList(headnode);
				break;*/
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


void initilizeGraph(Graph*g)
{
	g->n = 0;
	for (int n = 0; n < MAX_VERTEX; n++)
	{
		g->graph[n] = NULL;
	}

}

void insertvertex(Graph*g)
{
	if (g->n  >= MAX_VERTEX)
	{
		printf("\nover number of vertex .\n");
		return;
	}
	g->n++;
	printf("number of vertex: %d\n",g->n);
}

void insertEdge(Graph* g, int v1, int v2)
{
	Node* vertexnode;
	if (v1 >= g->n || v2 >= g->n)
	{
		printf("\nThere are no vertices to fit in..\n");
		return;
	}
	vertexnode = (Node*)malloc(sizeof(Node));
	vertexnode->vertex = v2;
	vertexnode->next = g->graph[v1];
	g->graph[v1] = vertexnode;
}



void DFS(Graph* g, int v) {
   for (int i = 0; i < MAX_VERTEX; i++)
    {
      g->visited[i] = 0;       
   	}
   graph_node* w;           
   push(v);   
   g->visited[v] = 1;      
   printf("%d", v);

   while (is_empty() != 1) {
      v = pop();
      w = g->adj_list[v];      

      while (w) {
         if (g->visited[w->vertex] == 0) {         
            push(v);
            push(w->vertex);
            g->visited[w->vertex] = 1;
            printf("%3d", w->vertex);
            v = w->vertex;
            w = g->adj_list[v];
         }
         else w = w->link;        
      }
   }
}

void push(int n) {
   if (is_full() == 1) {
      fprintf(stderr, "스택이 가득 찼습니다");
      return;
   }
   stack[++top] = n;
}

int pop() {
   if (is_empty() == 1) {
      fprintf(stderr, "스택이 비었습니다");
      return 0;
   }
   return stack[top--];
}