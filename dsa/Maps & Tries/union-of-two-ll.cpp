
string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int, int> M1;
    
    for(int i=0; i<n; i++)
    {
        int elem = a1[i];
        M1[elem] += 1;
    }
    
    for(int i=0; i<m; i++)
    {
        int elem = a2[i];
        if(M1[elem] >= 1)
        {
            M1[elem] --;
            continue;
        }
            
        if(M1[elem] == 0)
            return "No";
    }
    return "Yes";
    
}