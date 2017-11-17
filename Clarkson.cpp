#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int myrandom (int i) {std::srand(time(0));return rand()%i;}

int main(int argc, char* argv[])
{
    int n,m;
    map< pair<int,int>,bool> covered;
    std::cin >> n >> m;
    std::vector<int> *adjacency = new std::vector<int>[n];
    vector< pair<int,int> > vp;
    int a,b;
    int *degree = new int[n];
    vector< pair<int,int> > edges;
    bool* elemFind = new bool[n];
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
        edges.push_back({min(a,b),max(a,b)});
        covered[make_pair(a,b)] = false;
        vp.push_back(make_pair(a,b));
    }
    int *weights = new int[n];
    int *residualWeights = new int[n];
    int *residualDegree = new int[n];
    for (int i = 0; i < n; ++i)
    {
        degree[i] = adjacency[i].size();
        cin >> weights[i];
        elemFind[i] = true;
        residualWeights[i] = weights[i];
        residualDegree[i] = degree[i];
    }
    set<int> ansVertices;
    while(edges.size()>0){
        //Let v be the node minimizing w′(v)/d′(v)
        int minVertex = -1;
        double minValue = 324234234.324;
        for (int i = 0; i < edges.size(); ++i)
        {
            pair<int,int> p = edges[i];
            if(minVertex == -1){
                minVertex = p.first;
                minValue = residualWeights[p.first]*1.0/residualDegree[p.first];
                if(minValue>(residualWeights[p.second]*1.0/residualDegree[p.second])){
                    minValue = (residualWeights[p.second]*1.0/residualDegree[p.second]);
                    minVertex = p.second;
                }
            } else{
                if(minValue>(residualWeights[p.first]*1.0/residualDegree[p.first]))
                {
                    minValue = residualWeights[p.first]*1.0/residualDegree[p.first];
                    minVertex = p.first;
                } if(minValue>(residualWeights[p.second]*1.0/residualDegree[p.second])){
                    minValue = (residualWeights[p.second]*1.0/residualDegree[p.second]);
                    minVertex = p.second;
                }
            }
        }

        ansVertices.insert(minVertex);

        for (int i = 0; i < adjacency[minVertex].size(); ++i)
        {
            if(!elemFind[adjacency[minVertex][i]]) continue;
            residualWeights[adjacency[minVertex][i]]-=(minValue);
            residualDegree[adjacency[minVertex][i]]-=1;
            int id = 0;
            for(int j = 0;j<edges.size();j++){
                if(min(adjacency[minVertex][i],minVertex) == edges[j].first && max(adjacency[minVertex][i],minVertex) == edges[j].second){
                    id = j;
                }
            }
            edges.erase(edges.begin()+id);
        }
        elemFind[minVertex] = false;
    }
    for(auto it = ansVertices.begin();it!=ansVertices.end();++it){
        std::cout << (*it) << " ";
    }
    return 0;
}
