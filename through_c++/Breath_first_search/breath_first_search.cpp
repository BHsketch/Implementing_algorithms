#include<iostream>
#include<queue>
#include<string>// why an entire library for strings?
#include<vector>

std::vector<std::string> graph(std::string name)
{
        
    std::vector<std::string> You={"Alice", "Bob", "Claire"};
    std::vector<std::string> Bob={"Anuj", "Peggy"};
    std::vector<std::string> Alice={"Peggy"};
    std::vector<std::string> Claire={"Thom", "Jonny"};
    std::vector<std::string> Anuj={};
    std::vector<std::string> Peggy={};
    std::vector<std::string> Thom={};
    std::vector<std::string> Jonny={};
    std::vector<std::string> listoffriends;
        if(name=="You")
        {
            listoffriends=You;
        }else if(name=="Bob")
        {
            listoffriends=Bob;
        }else if(name=="Alice")
        {
            listoffriends=Alice;
        }else if(name=="Claire")
        {
            listoffriends=Claire;
        }else if(name=="Anuj")
        {
            listoffriends=Anuj;
        }else if(name=="Peggy")
        {
            listoffriends=Peggy;
        }else if(name=="Thom")
        {
            listoffriends=Thom;
        }else if(name=="Jonny")
        {
            listoffriends=Jonny;
        }
    return listoffriends;
}

std::string mangoseller(std::queue<std::string> friends)
{ 
    std::string mseller="random";
    if((friends.front()).back()=='m')
    {
        mseller=friends.front();
    }else if((friends.front()).back() !='m')
    {
        for(int i=0; i<(graph(friends.front())).size(); i++)
        {
            friends.push((graph(friends.front()))[i]);
        }
        friends.pop();
        mseller=mangoseller(friends);
    }
    else {
        mseller="none";
    }
    return mseller;
}

int main()
{
    std::string name="bhavya";
    std::queue<std::string> friends;
    friends.push("Alice");
    friends.push("Bob");
    friends.push("Claire");
    std::cout<<mangoseller(friends)<<" is a mango seller";

   
   
}
