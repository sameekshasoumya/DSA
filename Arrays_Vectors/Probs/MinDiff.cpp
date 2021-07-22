//O(N^2)

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int min_diff = INT_MAX;
    pair<int,int> output;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            min_diff = min(min_diff, abs(a[i]-b[j]));
            if(abs(a[i]-b[j])==min_diff)
            {
                output.first = a[i];
                output.second = b[j];
            }
        }
    }
    
    return output;
}