#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<limits>
#include"priorityqueue.cpp"

#define costmax std::numeric_limits<int>::max()

std::unordered_map<std::string, std::unordered_map<std::string, int>> graph 
    { 
        {"book", {{"LP",5}, {"poster",0}}},
        {"LP", {{"guitar", 15}, {"drum", 20}}},
        {"poster", {{"guitar", 30}, {"drum", 35}}},
        {"guitar", {{"piano", 20}}},
        {"drum", {{"piano", 10}}},
        {"piano", {}}
    };

std::unordered_map<std::string, int> cost
{
    {"book", 0},
    {"LP", costmax},
    {"poster", costmax},
    {"guitar", costmax},
    {"drum", costmax},
    {"piano", costmax}
};

std::unordered_map<std::string, std::string> parent
{
    {"book", ""},
    {"LP", ""},
    {"poster", ""},
    {"guitar", ""},
    {"drum", ""},
    {"piano", ""}
};

int getweight(std::string node1, std::string node2)
{
    int weight;
    weight = (graph[node1])[node2];
    return weight;
}

void neighbouriterate(std::string name)
{
    int nodecost=cost[name];
    int totalcost;
    std::string currentneigh;
    std::unordered_map<std::string, int>::iterator it=(graph[name]).begin(); //set iterator to be at the first node(whatever the compiler considers as first)
    for(int i=0; i<(graph[name]).size(); i++) //for each neighbor 
    {
        currentneigh = (it->first); //we first set currentneigh to the neighbour name
        totalcost = nodecost + getweight(name, currentneigh);
        if(parent[currentneigh]=="")
        {
            parent[currentneigh]=name;
        }//give it a parent if not already there
        if(totalcost < cost[currentneigh] )
        {
            cost[currentneigh]=totalcost;
            parent[currentneigh]=name;

        }//for each neighbour, if the total cost through the current element is lesser than its cost in the table, update cost and parent
        it++;
    }
}

bool inchecked(std::vector<std::string> checked, std::string node)
{
    bool isthere=0;
    for(int i=0; i<checked.size(); i++)
    {
        if(checked[i]==node)
        {
            isthere =1;
        }
    }
    return isthere;
}

void printpath(std::string lastnode)
{
    if(parent[lastnode]=="book")
    {
        std::cout<<"The path that gives the least cost: ";
        std::cout<<"book ";
        std::cout<<"-> "<<lastnode<<" ";
    }else{
        printpath(parent[lastnode]);
        std::cout<<" -> "<<lastnode;
    }
}



class edge{

    public:

    std::string parent;
    std::string current;
    int totalcost;

    edge(std::string parent1, std::string current1, int totalcost1)
    {
        (this->parent) = parent1;
        (this->current) = current1;
        (this->totalcost) = -1*totalcost1;
    }

    edge()
    {
        (this->parent) = "";
        (this->current) = "";
        (this->totalcost) = 0;
    }

    bool operator<(edge edge1)
    {
        bool returnval;
        if((this->totalcost)<(edge1.totalcost))
        {
            returnval = 1;
        }else{
            returnval = 0;
        }

        return returnval;
    }

    bool operator>(edge edge1)
    {
        bool returnval;
        if((this->totalcost)>(edge1.totalcost))
        {
            returnval = 1;
        }else{
            returnval = 0;
        }

        return returnval;
    }

    void operator=(edge edge1)
    {
        (this->parent) = edge1.parent;
        (this->current) = edge1.current;
        (this->totalcost) = (edge1.totalcost);
    }

    void operator=(int num)
    {
        if(num==0)
        {
            (this->parent) = "";
            (this->current) = "";
            (this->totalcost) = 0;
        }
    }

    bool operator!=(int num)
    {
        bool returnval;
        if(num==0)
        {
            if(((this->parent) == "")&&((this->current) == "")&&((this->totalcost) == 0))
            {
                returnval = 0;
            }else{
                returnval = 1;
            }
        }

        return returnval;
    }


};

int main()
{
    //Implementing the graph with an unordered_map first:

    //Declaring a queue of edges
    //I have not implemented a min heap yet, so will use a max heap with negative totalcosts
    //Have overloaded the equality operator so that the pulled edge always has the positive totalcost
    maxheap<edge> pqueue;

    //edge we are working on
    edge pullededge("-", "book", 0);
    edge* tempedge;

    int count=0;

    for(count=0; count<7; count++)
    {
        //adding this edge to the totalcost table and updating its parent
        cost[pullededge.current] = pullededge.totalcost;
        parent[pullededge.current] = pullededge.parent;

        if(count == 6)
        {
            break;
        }

        std::unordered_map<std::string, int>::iterator it;
        it = (graph[pullededge.current]).begin();

        //for all neighbours of pullededge.current
        //std::cout<<"checking neighbours of "<<pullededge.current<<std::endl;

        for(int i=0; i<(graph[pullededge.current]).size(); i++)
        {
            //std::cout<<"    pushing "<<pullededge.current<<"->"<<(it->first)<<"  "<<(pullededge.totalcost + it->second)<<std::endl;
            //creating an edge to represent this neighbour's connection
            //setting the total cost for this neighbour to pullededge.totalcost + weight of this edge
            tempedge = new edge(pullededge.current, it->first, (pullededge.totalcost + it->second));
            pqueue.insert(*tempedge);
            it++;
        }

        //pqueue.printH();
        //std::cout<<std::endl;

        //at the end of the loop, we pull another edge from the priority queue
        pullededge = pqueue.pull();
        pullededge.totalcost = (-1)*(pullededge.totalcost);
        //std::cout<<"pulled: "<<pullededge.parent<<" "<<pullededge.current<<" "<<pullededge.totalcost<<std::endl;
        //pqueue.printH();
        //std::cout<<std::endl;
    }

    std::cout<<"the cheapest path to the piano is: "<<cost["piano"]<<std::endl;
    std::cout<<"path taken: ";
    printpath("piano");

}