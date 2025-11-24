#include <stdio.h>

#define MAX 20   

int adj[MAX][MAX];
int n = 0;       

void initGraph() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
}

void createGraph() {
    int edges, u, v;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }

    initGraph();

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in the form: u v (vertices are 1 to %d)\n", n);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Invalid edge: (%d, %d). Skipping.\n", u, v);
            continue;
        }

        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }

    printf("Graph created successfully.\n");
}

void insertEdge() {
    int u, v;

    if (n == 0) {
        printf("Graph not created yet. Use option 1 first.\n");
        return;
    }

    printf("Enter edge to insert (u v): ");
    scanf("%d %d", &u, &v);

    if (u < 1 || u > n || v < 1 || v > n) {
        printf("Invalid vertices.\n");
        return;
    }

    adj[u - 1][v - 1] = 1;
    adj[v - 1][u - 1] = 1;

    printf("Edge (%d, %d) inserted successfully.\n", u, v);
}

void printAdjacencyMatrix() {
    if (n == 0) {
        printf("Graph not created yet.\n");
        return;
    }

    printf("Adjacency Matrix:\n   ");
    for (int i = 0; i < n; i++)
        printf("%3d", i + 1);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%3d", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%3d", adj[i][j]);
        }
        printf("\n");
    }
}

void listAdjacent() {
    int v;

    if (n == 0) {
        printf("Graph not created yet.\n");
        return;
    }

    printf("Enter vertex number (1 to %d): ", n);
    scanf("%d", &v);

    if (v < 1 || v > n) {
        printf("Invalid vertex.\n");
        return;
    }

    printf("Vertices adjacent to %d: ", v);
    int found = 0;
    for (int j = 0; j < n; j++) {
        if (adj[v - 1][j] == 1) {
            printf("%d ", j + 1);
            found = 1;
        }
    }

    if (!found)
        printf("None");
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- UNDIRECTED GRAPH MENU -----\n");
        printf("1. Create Graph\n");
        printf("2. Insert an Edge\n");
        printf("3. Print Adjacency Matrix\n");
        printf("4. List all vertices adjacent to a specified vertex\n");
        printf("6. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createGraph();
            break;
        case 2:
            insertEdge();
            break;
        case 3:
            printAdjacencyMatrix();
            break;
        case 4:
            listAdjacent();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
