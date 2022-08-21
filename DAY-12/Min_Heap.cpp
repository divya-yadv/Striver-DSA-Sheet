void heapify(vector<int>&heap,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    if(left<heap.size() && heap[left] <heap[smallest])
    {
        smallest = left;
    }
    if(right <heap.size() && heap[right] <heap[smallest] ){
        smallest = right;
    }
    if(smallest != i)
    {
        swap(heap[smallest],heap[i]);
        heapify(heap,smallest);
    }
}
void heapify_up(vector<int>& heap,int child){
    int parent=(child-1)/2;
    if(child >=0 && heap[parent]>heap[child]){
        swap(heap[child],heap[parent]);
        heapify_up(heap,parent);
    }
}
void push(vector<int>&heap,int key)
{
    heap.push_back(key);
    heapify_up(heap,heap.size()-1);
}
void pop(vector<int>&heap)
{
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap,0);
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap,ans;
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0])
        {
            ans.push_back(heap[0]);
            pop(heap);
        }
        else
        {
            push(heap,q[i][1]);
        }
    }
    return ans;
}
