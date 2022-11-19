#include<iostream>
#include<vector>


//function to check whether the left child or right child should be swapped with the parent
template<typename T>
int max(T left, T right)
{
    int lr;
    if(left>right)
    {
        lr = 0;
    }else{
        lr = 1;
    }

    return lr;
}

template<typename T>
class maxheap{
    private:
    T H[100] = {0};
    int last = -1;
    int current;
    int parent;
    int lchild, rchild;
    T temp;
    int i;
    int lr;
    T highestpriority;

    public: 
    void insert(T v)
    {
        H[last+1] = v;
        last++;
        current = last;

        for(i=0; current != 0 ; i++)
        {
            if(current%2 != 0)
            {
                parent = (current - 1)/2;
            }else if(current%2 == 0)
            {
                parent = (current - 2)/2;
            }

            if(H[parent]<H[current])
            {
                temp = H[parent];
                H[parent] = H[current];
                H[current] = temp;

                current = parent;
            }else{
                break;
            }
        }

    }

    T pull()
    {
        highestpriority = H[0];
        H[0] = H[last];
        H[last] = 0;
        last --;

        current = 0;
        lchild = current*2 + 1;
        rchild = current*2 + 2;
        for(i=0; (H[lchild] != 0)&&((H[current] < H[lchild])||(H[current] < H[rchild])); i++)
        {
            lchild = current*2 + 1;
            rchild = current*2 + 2;
            lr = max(H[lchild], H[rchild]);
            temp = H[lchild + lr];
            H[lchild + lr] = H[current];
            H[current] = temp;

            current = lchild + lr;
        }

        return highestpriority;
    }

    void printH()
    {
        for(i = 0; H[i]!= 0 ; i++)
        {
            std::cout<<H[i]<<" ";
        }
    }
};

int main()
{
    maxheap<int> priorityqueue;
    priorityqueue.insert(5);
    priorityqueue.insert(23);
    priorityqueue.insert(1);
    priorityqueue.insert(15);
    priorityqueue.insert(16);
    priorityqueue.insert(3);
    
    priorityqueue.printH();

    std::cout<<std::endl;

    std::cout<<"pull 1: "<<priorityqueue.pull()<<std::endl;
    std::cout<<"pull 2: "<<priorityqueue.pull()<<std::endl;
    std::cout<<"pull 3: "<<priorityqueue.pull()<<std::endl;
    std::cout<<"pull 4: "<<priorityqueue.pull()<<std::endl;
    std::cout<<"pull 5: "<<priorityqueue.pull()<<std::endl;
    std::cout<<"pull 6: "<<priorityqueue.pull()<<std::endl;

}