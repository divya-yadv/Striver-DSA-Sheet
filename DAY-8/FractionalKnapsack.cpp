static bool comp(Item n1, Item n2)
    {
        double val1 = double(n1.value)/n1.weight;
        double val2 = double(n2.value)/n2.weight;
        return (val1 > val2);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
      // sort according to value/weight ratio
        sort(arr,arr+n,comp);
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            if(W >= arr[i].weight)
            {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                ans += (arr[i].value)*(W/double(arr[i].weight));
                break;
            }
        }
        return ans;
    }
