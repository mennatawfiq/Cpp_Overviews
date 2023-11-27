#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;
    int left(int node)
    {
        int pos = 2 * node + 2;
        return (pos < size()) ? pos : -1;
    }
    int right(int node)
    {
        int pos = 2 * node + 1;
        return (pos < size()) ? pos : -1;
    }
    int parent(int node)
    {
        return (node == 0) ? -1 : (node - 1) / 2;
    }
    void reheapUp(int pos)
    {
        int par = parent(pos); // getting the index of the parent
        if (par > -1)
        { // checking that it is not the root
            if (heap[pos] < heap[par])
            {
                swap(heap[pos], heap[par]);
                reheapUp(par);
            }
        }
    }
    void reheapDown(int pos)
    {
        int sub_node = left(pos);
        if (sub_node == -1)
        { // no left or right
            return;
        }
        int right_node = right(pos);
        if (right_node == -1)
        { // no right node
            if (heap[pos] > heap[sub_node])
            {
                swap(heap[pos], heap[sub_node]);
                reheapDown(sub_node);
            }
        }
        else
        {
            if (heap[right_node] < heap[sub_node])
                sub_node = right_node;
            if (heap[pos] > heap[sub_node])
            {
                swap(heap[pos], heap[sub_node]);
                reheapDown(sub_node);
            }
        }
    }

public:
    int top()
    {
        if (!size())
        {
            assert(false);
        }
        return heap.front();
    }
    void push(int key)
    {
        heap.push_back(key);
        reheapUp(size() - 1);
    }
    void print()
    {
        for (int i : heap)
        {
            cout << i << "   ";
        }
        cout << endl;
    }
    void pop()
    {
        if (size())
        {
            heap[0] = heap.back();
            heap.pop_back();
            reheapDown(0);
        }
    }
    int size()
    {
        return heap.size();
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.print();
    pq.push(0);
    pq.print();
    cout << pq.top() << endl;
    pq.pop();
    pq.print();
}
