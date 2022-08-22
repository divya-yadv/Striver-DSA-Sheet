
// O(N^2),O(N)
void sortInsert(stack<int>&stack,int num)
{
    if((stack.empty()) || ((!stack.empty())&& (stack.top()<num)))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
  // again find the position for num
    sortInsert(stack,num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    
    sortStack(stack);
    sortInsert(stack,num);
}
