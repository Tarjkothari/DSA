#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Graph {
    int numVertices;
    struct Node** adjList;
    int* visited;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}


void DFS(struct Graph* graph, int startVertex) {

    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    struct Node* temp = graph->adjList[startVertex];
    while (temp) {
        int adjVertex = temp->data;
        if (graph->visited[adjVertex] == 0) {

            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
	
	int n;
	
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    printf("Enter the Node you want to start : ");
    scanf("%d",&n);
    
    printf("Depth First Search starting from vertex %d: ",n);
    
	DFS(graph, 0);
    printf("\n");

    free(graph->adjList);
    free(graph->visited);
    free(graph);

    return 0;
}
