#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
//using adjmatrix = vector<vector<float>>; //use this?
//notes from zach: return graph(vector<float>(0, n)) to generate an empty graph

vector<vector<float>> firstGraphGenerator(int n)
{
    //generates the first type of graph
    srand((unsigned)time(NULL));
    vector<vector<float>> graph = vector<vector<float>>(n, vector<float>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            graph[i][j] = (double) rand()/RAND_MAX;
        }
    }
    return graph;
}


vector<vector<float>> secondGraphGenerator(int n)
{
    //generates the second type of graph
}


vector<vector<float>> thirdGraphGenerator(int n)
{
    //generates the third type of graph
}


void prim(const vector<vector<float>>& graph)
{
    //prims algorithm
}


int main()
{
    //generate graph
    int n;
    cout << "Give a value of n: " << endl;
    cin >> n;

    auto graph = firstGraphGenerator(n);
    //graph = secondGraphGenerator();
    //graph = thirdGraphGenerator();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << graph[i][j] << " ";
        }
    }


    //perform mst algorithm
    //prim(graph);
    return 0;
}


