#include <bits/stdc++.h>
using namespace std;
const int V = 5;

bool isSelected(int selected[V], int l, int edge)
{
    for (int i = 0; i < l; i++)
    {
        if (selected[i] == edge)
        {
            return true;
        }
    }
    return false;
}
int *prims(int edgeMatrix[V][V], int n)
{
    int *selected = new int[n];
    for (int i = 0; i < n; i++)
        selected[i] = false;
    int edgesSelected = 0;
    edgesSelected = 1;
    selected[0] = 0;
    while (edgesSelected <= n)
    {
        int min[2] = {-1, INT_MAX};
        for (int i = 0; i < edgesSelected; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (
                    !isSelected(selected, edgesSelected, j)
                    && edgeMatrix[i][j]
                    && min[1]>edgeMatrix[i][j])
                {
                    min[0] = j;
                    min[1] = edgeMatrix[i][j];
                    
                }
            }
        }
        selected[edgesSelected] = min[0];
        edgesSelected++;
    }
    return selected;
}

int main()
{
    int G[V][V] = {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}};
    int *mst = prims(G, V);
    for (int i = 0; i < V; i++)
    {
        cout << mst[i] << " ";
    }
    cout << endl;
}