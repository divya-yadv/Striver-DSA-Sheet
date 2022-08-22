Class MyStack{
       private:
                 int arr[100];
                 int top;
      public:
            MyStack(){
              top = -1;
              int top();
              void push(int);
            }
}
void MyStack :: push(int x)
{
    top++;
    arr[top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return arr[top--];
    }
}
