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
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
        covered[make_pair(a,b)] = false;
        vp.push_back(make_pair(a,b));
    }
    int *id_val = new int[n];
    int *ac_val = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> ac_val[i];
        id_val[i] = 0;
    }
    srand (time(NULL));
    set<int> ansVertices;
    random_shuffle(vp.begin(),vp.end(),myrandom);
    for(int i = 0;i<m;i++){
        if(covered[vp[i]]){
            std::cout <<"covered "<<vp[i].first<<" "<<vp[i].second << "\n";
            continue;
        }
        else{
            std::cout <<"not-covered "<<vp[i].first<<" "<<vp[i].second << "\n";
            covered[vp[i]] = true;
            int x,y;
            x = ac_val[vp[i].first] - id_val[vp[i].first];
            y = ac_val[vp[i].second] - id_val[vp[i].second];
            int t = min(x,y);
            x-=t;
            y-=t;
            id_val[vp[i].first]+=t;
            id_val[vp[i].second]+=t;
            if(x == 0){
                ansVertices.insert(vp[i].first);
                for(int j = 0;j<adjacency[vp[i].first].size();j++){
                    covered[make_pair(adjacency[vp[i].first][j],vp[i].first)] = true;
                    covered[make_pair(vp[i].first,adjacency[vp[i].first][j])] = true;
                }
            } else{
                ansVertices.insert(vp[i].second);
                for(int j = 0;j<adjacency[vp[i].second].size();j++){
                    covered[make_pair(adjacency[vp[i].second][j],vp[i].second)] = true;
                    covered[make_pair(vp[i].second,adjacency[vp[i].second][j])] = true;
                }
            }
        }
    }
    for(auto it = ansVertices.begin();it!=ansVertices.end();++it){
        std::cout << (*it) << " ";
    }
    return 0;
}
