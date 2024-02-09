#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjacencyList;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; ++i)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{

    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printAdjacencyList(struct Graph *graph)
{
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; ++i)
    {
        printf("%d: ", i);
        struct Node *current = graph->adjacencyList[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int **createAdjacencyMatrix(struct Graph *graph)
{
    int **adjacencyMatrix = (int **)malloc(graph->vertices * sizeof(int *));
    for (int i = 0; i < graph->vertices; ++i)
    {
        adjacencyMatrix[i] = (int *)malloc(graph->vertices * sizeof(int));
    }

    for (int i = 0; i < graph->vertices; ++i)
    {
        for (int j = 0; j < graph->vertices; ++j)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < graph->vertices; ++i)
    {
        struct Node *current = graph->adjacencyList[i];
        while (current != NULL)
        {
            adjacencyMatrix[i][current->data] = 1;
            adjacencyMatrix[current->data][i] = 1;
            current = current->next;
        }
    }

    return adjacencyMatrix;
}

void printAdjacencyMatrix(struct Graph *graph)
{
    int **adjacencyMatrix = createAdjacencyMatrix(graph);
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; ++i)
    {
        for (int j = 0; j < graph->vertices; ++j)
        {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < graph->vertices; ++i)
    {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
}

void DFSUtil(struct Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node *current = graph->adjacencyList[vertex];
    while (current != NULL)
    {
        if (!visited[current->data])
        {
            DFSUtil(graph, current->data, visited);
        }
        current = current->next;
    }
}
void DFS(struct Graph *graph)
{
    bool *visited = (bool *)malloc(graph->vertices * sizeof(bool));

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->vertices; ++i)
    {
        visited[i] = false;
    }

    printf("Depth-First Search (DFS): ");
    for (int i = 0; i < graph->vertices; ++i)
    {
        if (!visited[i])
        {
            DFSUtil(graph, i, visited);
        }
    }

    free(visited);
    printf("\n");
}
void BFS(struct Graph *graph, int startVertex)
{
    bool *visited = (bool *)malloc(graph->vertices * sizeof(bool));

    for (int i = 0; i < graph->vertices; ++i)
    {
        visited[i] = false;
    }

    int *queue = (int *)malloc(graph->vertices * sizeof(int));
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = true;

    printf("Breadth-First Search (BFS): ");
    while (front != rear)
    {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node *current = graph->adjacencyList[currentVertex];
        while (current != NULL)
        {
            int adjacentVertex = current->data;
            if (!visited[adjacentVertex])
            {
                queue[++rear] = adjacentVertex;
                visited[adjacentVertex] = true;
            }
            current = current->next;
        }
    }

    free(visited);
    free(queue);
    printf("\n");
}

int main()
{
    int vertices, edges, choice, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);
    printf("\nGraph Operations Menu:\n");
    printf("1. Add Edge\n");
    printf("2. Compute Adjacency List\n");
    printf("3. Compute Adjacency Matrix\n");
    printf("4. Perform Depth-First Search (DFS)\n");
    printf("5. Perform Breadth-First Search (BFS)\n");
    printf("6. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter source and destination vertices (0 to %d): ", vertices - 1);
            scanf("%d %d", &src, &dest);
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices)
            {
                addEdge(graph, src, dest);
                printf("Edge added between %d and %d.\n", src, dest);
            }
            else
            {
                printf("Invalid vertex indices. Please try again.\n");
            }
            break;
        case 2:

            printAdjacencyList(graph);
            break;
        case 3:

            printAdjacencyMatrix(graph);
            break;
        case 4:

            DFS(graph);
            break;
        case 5:

            printf("Enter the starting vertex for BFS (0 to %d): ", vertices - 1);
            scanf("%d", &src);
            if (src >= 0 && src < vertices)
            {
                BFS(graph, src);
            }
            else
            {
                printf("Invalid vertex index. Please try again.\n");
            }
            break;
        case 6:
            printf("Exiting program. Bye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

