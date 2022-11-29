#include<iostream>
#include<vector>
#include<math.h>


//function to check whether the left child or right child should be swapped with the parent
//Implementing a priority queue using a max heap
//implementing heap sort

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

    // i) the array H, push and pull operations together create the priority queue abstraction
    // ii) the heapsort function sorts an input array into descending order by converting it into 
    // a max heap first

    private:
    T H[100];
    int last = -1;
    int current;
    int parent;
    int lchild, rchild;
    T temp;
    int i;
    int lr;
    T highestpriority;

    public:

    maxheap()
    {

    }
    //inserts an element into the heap and bubbles it up until the heap property is satisfied
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

    //returns the highest priority element from the heap, and heapifies the root to maintain 
    //the max heap invariant
    T pull()
    {
        //setting the return value to the root, swapping the root with the last node, and then
        //deleting that last node
        highestpriority = H[0];
        H[0] = H[last];
        H[last] = 0;
        last --;

        //the following is heapify(root) done in an iterative manner
        current = 0;
        lchild = current*2 + 1;
        rchild = current*2 + 2;
        for(i=0; (H[lchild] != 0)&&((H[current] < H[lchild])||((H[rchild]!=0)&&(H[current] < H[rchild]))); i++)
        {
            lr = max(H[lchild], H[rchild]);
            temp = H[lchild + lr];
            H[lchild + lr] = H[current];
            H[current] = temp;

            current = lchild + lr;

            lchild = current*2 + 1;
            rchild = current*2 + 2;
        }

        return highestpriority;
    }

    //prints the heap that is used to implement our priority queue
    void printH()
    {
        std::cout<<std::endl;
        for(i = 0; H[i]!= 0 ; i++)
        {
            std::cout<<(H[i]).totalcost<<" ";
        }
    }

    void heapify(T* arr, int index, int size)
    {
        int lchild, rchild;
        int current = index;
        int i;
        T temp;
        lchild = 2*current + 1;
        rchild = 2*current + 2;

        if(((lchild>=size)&&(rchild>=size))||((arr[current] > arr[lchild])&&(arr[current]>arr[rchild])))
        {
            return;
        }else if((lchild>=size)^(rchild>=size))
        {
            if(lchild >= size)
            {
                if(arr[current]<arr[rchild])
                {
                    temp = arr[rchild];
                    arr[rchild] = arr[current];
                    arr[current] = temp;
                }
            }else{
                if(arr[current]<arr[lchild])
                {
                    temp = arr[lchild];
                    arr[lchild] = arr[current];
                    arr[current] = temp;
                }
            }
            return;
        }else{

            //swap current element with the bigger of the two children;
            lr = max(arr[lchild], arr[rchild]);
            temp = arr[lchild + lr];
            arr[lchild + lr] = arr[current];
            arr[current] = temp;

            current = lchild + lr;

            //we replaced one child with a smaller element, so the subtree where that child was 
            //the root could have been affected; so to handle the repurcussions
            //we gotta heapify that affected sub-tree
            heapify(arr, current, size);
        }
    }

    void heapsort(T* arr, int size)
    {
        int logarithm;
        int start;
        logarithm = (int)log2(size);
        start = (int)pow(2, logarithm) - 2;
        int i, j;
        int last = size - 1;
        T temp;

        std::cout<<"input array: ";
        for(i = 0; i<size ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;

        //to create a maxheap, heapify every node (except the ones in the last level)
        for(i=start; i>=0; i--)
        {
            heapify(arr, i, size);
        }
        //at this point our array had been converted to a heap

        //now, we will start pulling elements from the front, and start placing them starting
        //from the end of the array.
        for(i=last; i>=0; i--)
        {
            //swapping the first element with the last one
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            //heapify the rest of the array
            heapify(arr, 0, i);
        }

        std::cout<<"sorted array: ";
        for(i = 0; i<size ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
    }

    //Note, the pull function is the same as the heapify function, but done in an iterative
    //manner. Also, it performs the one extra step of swapping the root with the last element
    //before performing heapify on the root.
};

    

// int main()
// {
//     maxheap<int> priorityqueue;
//     priorityqueue.insert(5);
//     priorityqueue.insert(23);
//     priorityqueue.insert(1);
//     priorityqueue.insert(15);
//     priorityqueue.insert(16);
//     priorityqueue.insert(3);
    
//     priorityqueue.printH();

//     std::cout<<std::endl;

//     std::cout<<"pull 1: "<<priorityqueue.pull()<<std::endl;
//     std::cout<<"pull 2: "<<priorityqueue.pull()<<std::endl;
//     std::cout<<"pull 3: "<<priorityqueue.pull()<<std::endl;
//     std::cout<<"pull 4: "<<priorityqueue.pull()<<std::endl;
//     std::cout<<"pull 5: "<<priorityqueue.pull()<<std::endl;
//     std::cout<<"pull 6: "<<priorityqueue.pull()<<std::endl;

//     int nums[7] = {10, 6, 7, 5, 15, 17, 12};

//     maxheap<int> heap;
//     heap.heapsort(nums, 7);

// }