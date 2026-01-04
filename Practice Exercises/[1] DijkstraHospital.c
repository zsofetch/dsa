//ACTIVITY

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of locations (intersections/buildings) in our city

// Function to find the unvisited node with the smallest distance
int getMinDistanceNode(int dist[], bool visited[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    printf("Location \t Fastest Time from Hospital\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        char locName[20];
        if(i==0) sprintf(locName, "Hospital (0)");
        else if(i==4) sprintf(locName, "PATIENT (4)");
        else sprintf(locName, "Location %d", i);
        
        printf("%-15s \t %d mins\n", locName, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     // The output array. dist[i] will hold the shortest distance from src to i
    bool visited[V]; // visited[i] will be true if vertex i is included in shortest path tree

    // 1. Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // 2. Distance of source vertex from itself is always 0
    dist[src] = 0;

    // 3. Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = getMinDistanceNode(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // 4. Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // - It is not in visited
            // - There is an edge from u to v
            // - And total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print the constructed distance array
    printSolution(dist);
}

int main() {
    // Representation of the City Roads (Adjacency Matrix)
    // 0 means no direct road. Numbers represent minutes of travel.
    int cityGraph[V][V] = {
        // 0   1   2   3   4
        { 0,  10,  0,  5,  0 }, // Node 0 (Hospital) connects to 1 (10m) and 3 (5m)
        { 10,  0,  1,  2,  0 }, // Node 1 connects to 0, 2, 3
        { 0,   1,  0,  9,  4 }, // Node 2 connects to 1, 3, 4
        { 5,   2,  9,  0,  2 }, // Node 3 connects to 0, 1, 2, 4
        { 0,   0,  4,  2,  0 }, // Node 4 (Patient) connects to 2, 3
    };

    printf("Calculating fastest ambulance routes...\n\n");
    dijkstra(cityGraph, 0); // Start from Node 0 (Hospital)

    return 0;
}