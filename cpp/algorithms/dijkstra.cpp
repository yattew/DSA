#include <bits/stdc++.h>
using namespace std;

const int V = 9;

int minDistance(int dist[V], bool visitedVertex[V])
{
    int minDist = INT_MAX, index;
    for (int i = 0; i < V; i++)
    {
        if (!visitedVertex[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            index = i;
        }
    }
    return index;
}

int *dijkstra(int graph[V][V], int vertex)
{
    int *vertexDist = new int[V];
    bool visitedVertex[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i])
            vertexDist[i] = graph[vertex][i];
        else
            vertexDist[i] = INT_MAX;
    }
    vertexDist[vertex] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int choosenVertex = minDistance(vertexDist, visitedVertex);
        visitedVertex[choosenVertex] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visitedVertex[v] &&
                graph[choosenVertex][v] &&
                vertexDist[choosenVertex] + graph[choosenVertex][v] < vertexDist[v])
                vertexDist[v] =
                    vertexDist[choosenVertex] + graph[choosenVertex][v];
        }
    }
    return vertexDist;
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int *dist = dijkstra(graph, 0);
    for (int i = 0; i < V; i++)
    {
        cout << "vertex: " << i << " | distance: " << dist[i] << endl;
    }

    return 0;
}