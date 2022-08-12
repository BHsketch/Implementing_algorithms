#include<iostream>
#include<unordered_map>
#include<string>

int main()
{
    std::unordered_map<std::string, int> marks
    {
        {"physics", 40},
        {"maths", 45},
        {"EM", 40}
    };

    std::unordered_map<std::string, int>::iterator it=marks.begin();
    std::cout<<"subject 1: "<< it->first<<std::endl;
    std::cout<<"marks 1: "<<it->second<<std::endl;
    it++;
    std::cout<<"subject 2: "<<it->first<<std::endl;
    std::cout<<"marks 2: "<<it->second<<std::endl;
}