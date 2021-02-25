#include <iostream>
#include <time.h>

using namespace std;
//using adjmatrix = vector<vector<float> >; //use this?
//notes from zach: return graph(vector<float>(0, n)) to generate an empty graph

// float** firstGraphGenerator(int n)
// {
//     //generates the first type of graph
//     srand((unsigned)time(NULL));
    
//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < n; ++j)
//         {
//             if(i < j)
//             {
//                 graph[i][j] = (float) rand()/RAND_MAX;
//             }
//             else if (i == j)
//             {
//                 graph[i][j] = 2;
//             }
//             else
//             {
//                 graph[i][j] = graph[j][i];
//             }
//         }
//     }
//     return graph;
// }


// vector<vector<float> > secondGraphGenerator(int n)
// {
    //generates the second type of graph
// }


// vector<vector<float> > thirdGraphGenerator(int n)
// {
    //generates the third type of graph
// }

int extractmin(float dist[], int size, bool s[])
{
    int index = -1;
    float mindist = 2;
    for(int i = 0; i < size; i++)
    {
        if(dist[i] < mindist && s[i] == false)
        {
            index = i;
            mindist = dist[i];
        }
    }
    return index;
}

float prim(int n)
{
    srand((unsigned)time(NULL));
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float)rand()/RAND_MAX;
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}

float prim2d(int n)
{    
    srand((unsigned)time(NULL));
    float graph[n][2];
    for(int k = 0; k < n; ++k)
    {
        graph[k][0] = (float)rand()/RAND_MAX;
        graph[k][1] = (float)rand()/RAND_MAX;
    }
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float) sqrt((float)pow(graph[w][0] - graph[v][0], 2) + (float)pow(graph[w][1] - graph[v][1], 2));
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}

// float prim(float **graph, int n)
// {
//     float dist[n];
//     bool s[n];
//     for(int i = 0; i < n; ++i)
//     {
//         dist[i] = 2;
//         s[i] = false;
//     }
//     dist[0] = 0;
//     for(int j = 0; j < n; ++j)
//     {
//         int v = extractmin(dist, n);
//         s[v] = true;
//         for(int w = 0; w < n; ++w)
//         {
//             if(s[w] == false && dist[w] > graph[v][w])
//             {
//                 dist[w] = graph[v][w];
//                 s[w] = true;
//             }
//         }
//     }
//     float size = 0;
//     for(int k = 0; k < n; ++k)
//     {
//         size += dist[k];
//     }
//     return size;
// }

int main()
{
    //generate graph
    int n;
    cout << "Give a value of n: " << endl;
    cin >> n;

    //graph = secondGraphGenerator();
    //graph = thirdGraphGenerator();

    //perform mst algorithm
    cout << prim(n) << endl;
    cout << prim2d(n) << endl;
    return 0;
}