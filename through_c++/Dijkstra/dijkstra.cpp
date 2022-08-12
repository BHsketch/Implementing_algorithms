#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<limits>

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

int main()
{
          std::string cheapestnode;
          std::unordered_map<std::string, int>::iterator costit = cost.begin();
          //cheapestnode=costit->first;
          std::vector<std::string> checked;
          int count=0;

          for(int i=0; i<cost.size(); i++) // for each node
          {
            costit= cost.begin();//iterate all over again to find the next cheapest node
            //std::cout<<"outer "<< i<<"("<<costit->first<<")"<<std::endl;
            count=0;
            for(int j=0; j<cost.size(); j++) //finding the cheapest node everytime
            {
                //std::cout<<"    inner "<<j<<"("<<inchecked(checked, costit->first)<<")"<<std::endl;
                if(!(inchecked(checked, costit->first)))
                {
                    if(count==0)
                    {
                        cheapestnode=costit->first;
                        count=1;
                    }
                }
                if((costit->second)<cost[cheapestnode] && !(inchecked(checked, costit -> first))) 
                {
                    cheapestnode=(costit->first);
                }
                costit++;
            }
            //std::cout<<" cheapest node for this iteration: "<<cheapestnode<<std::endl;
            neighbouriterate(cheapestnode);
            checked.push_back(cheapestnode); //once cheapest unchecked node is found, we iterate through its neighbours and add it to the checked list
            // for(int k=0; k<checked.size(); k++)
            // {
            //     std::cout<<" checked elements: "<<checked[i]<<", ";
            // }
            //std::cout<<inchecked(checked, cheapestnode);
            //std::cout<<std::endl;
            if(i==(cost.size() -1))
            {
                std::cout<<"The cheapest path to Piano is: "<<cost["piano"]<< " dollars"<<std::endl;
                break;
            }
         }
         printpath("piano");

}