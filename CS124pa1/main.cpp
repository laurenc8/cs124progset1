#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;
//using adjmatrix = vector<vector<float> >; //use this?
//notes from zach: return graph(vector<float>(0, n)) to generate an empty graph

vector<vector<float> > firstGraphGenerator(int n)
{
    //generates the first type of graph
    srand((unsigned)time(NULL));
    vector<vector<float> > graph = vector<vector<float> >(n, vector<float>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i < j)
            {
                graph[i][j] = (double) rand()/RAND_MAX;
            }
            else if (i == j)
            {
                graph[i][j] = 2;
            }
            else
            {
                graph[j][i] = graph[i][j];
            }
        }
    }
    return graph;
}


vector<vector<float> > secondGraphGenerator(int n)
{
    //generates the second type of graph
}


vector<vector<float> > thirdGraphGenerator(int n)
{
    //generates the third type of graph
}


void prim(const vector<vector<float> >& graph, int n)
{
    vector<float> dist = vector<float> (n, 0);
    vector<float> prev = vector<float> (n, NULL);
    vector<float> s = vector<float> (n, NULL);
    vector<float> h = vector<float> (n, NULL);
    h[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
    }
    dist[0] = 0;
    while(!h.empty())
    {
        int min = 2;
        int v = 0;
        for(int i = 0; i < n; ++i)
        {
            if(h[i] < min)
            {
                min = h[i];
                v = i;
            }
        }
        h[min] = NULL;
        for(int j = 0; j < n; ++j)
        {
            if(s[j] != NULL)
            {
                s[j] = v;
            }
        }
        for(int w = 0; w < n; ++w)
        {
            if(count(s.begin(), s.end(), (float)w) == 0)
            {
                if(dist[w] > graph[v][w])
                {
                    dist[w] = graph[v][w];
                    prev[w] = v;
                    h[w] = dist[w];
                }
            }
        }
    }
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
    prim(graph, n);
    return 0;
}