#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int>& path);

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos)
{
    int V = graph.size();
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle(vector<vector<int>>& graph)
{
    int V = graph.size();
    vector<int> path(V, -1);

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(vector<int>& path)
{
    cout << "Solution Exists: Following is one Hamiltonian Cycle\n";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

int main()
{
    vector<vector<int>> graph1 = {{0, 1, 0, 1, 0},
                                  {1, 0, 1, 1, 1},
                                  {0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 1},
                                  {0, 1, 1, 1, 0}};

    hamCycle(graph1);

    vector<vector<int>> graph2 = {{0, 1, 0, 1, 0},
                                  {1, 0, 1, 1, 1},
                                  {0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 0},
                                  {0, 1, 1, 0, 0}};

    hamCycle(graph2);

    return 0;
}
