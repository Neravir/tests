#include <iostream>
#include <vector>
using namespace std;


class MinHeap
{
   vector<int> vec;
public:
   //constructor for int
   MinHeap(vector<int> arr,int size): vec(size)
   {
       for(int i = 0;i < size; ++i)
       {
           vec[i] = arr[i];
       }
       Heapify();
   }

   //constuctor for double
   MinHeap(vector<double> arr,int size): vec(size)
   {
       for(int i = 0;i < size; ++i)
       {
           vec[i] = arr[i];
       }
       Heapify();
   }

   //organize heap
   void Heapify()
   {
       int lenght = vec.size();
       for(int i = lenght - 1; i >= 0; --i)
       {
           HeapifyDown(i);
       }
   }

   //move min elements to the root
   void HeapifyDown(int index)
   {
       int lenght = vec.size();
       int left = 2 * index + 1;
       int right = 2 * index + 2;

       if(left >= lenght)
           return;
       int min = index;

       if(vec[index] > vec[left])
       {
           min = left;
       }

       if((right < lenght) && (vec[min] > vec[right]))
       {
           min = right;
       }

       if (min != index)
       {
           int temp = vec[index];
           vec[index] = vec[min];
           vec[min] = temp;
           HeapifyDown(min);
       }
   }

   void HeapifyUp(int index)
   {
       if(index == 0)
           return;

       int parent = (index - 1) / 2;
       if(vec[parent] > vec[index])
       {
           int temp = vec[parent];
           vec[parent] = vec[index];
           vec[index] = temp;
           HeapifyUp(parent);
       }

   };

   //remove min element
   void pop()
   {
       vec[0] = vec.back();
       vec.pop_back();
       HeapifyDown(0);
   }

   //insert new element
   void push(int k)
   {
       //insert element
       vec.push_back(k);
       //get element index and heapyfy up
       int index = getSize() - 1;
       HeapifyUp(index);
   }

   int getSize()
   {
       return vec.size();
   }

   int getMin()
   {
       return vec[0];
   }
};

int main()
{
    vector<int> vect = {10,5,100,4,3};
    MinHeap heap(vect,vect.size());
    cout << "min: " << heap.getMin() << " size: " << heap.getSize() << endl <<endl;
    heap.push(2);

    cout << "min: " << heap.getMin() << " size: " << heap.getSize() << endl;
    for(int i = heap.getSize() - 1; i > 0 ; i--)
    {
        heap.pop();
        cout << "min: " << heap.getMin() << " size: " << heap.getSize() << endl;
    }
    return 0;
}
