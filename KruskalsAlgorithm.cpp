#include <iostream>
#include<algorithm>
using namespace std;
class Edges{
    public:
    int source;
    int dest ;
    int weight;
};
bool compare(Edges e1 , Edges e2){
    return e1.weight < e2.weight ;
}

int findparent(int v , int *parent){
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v] , parent);
}

void kruskals(Edges *input , int N , int E ){
    sort(input , input+E , compare);
    Edges *output = new Edges[N-1];

    int *parent = new int[N];
    for(int i=0;i<N;i++){
        parent[i] = i;
    }

    int count = 0;
    int i=0;
    while(count!=N-1){
        Edges currentEdge = input[i];

        int sourceparent = findparent(currentEdge.source , parent);
        int destparent = findparent(currentEdge.dest ,parent);

        if(sourceparent != destparent){
            output[count] = currentEdge;
            count++;
            parent[sourceparent] = destparent;
        }
        i++;
        

    }

    for(int i=0;i<N-1;i++){
        if(output->source < output->dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }


}
int main(){
    int N , E;
    cin>>N>>E;
    Edges *input = new Edges[E];
    for(int i=0;i<E;i++){
        int s , d , w ;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;

    }
    kruskals(input , N , E);
}

/*
6 11
0 1 1
2 3 10
4 5 2
0 2 5
2 4 8
1 3 3
3 5 6
0 3 4
1 2 4
2 5 9
4 7 3

*/