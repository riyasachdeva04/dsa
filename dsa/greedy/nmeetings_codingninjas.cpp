bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int, int>> v;
    for(int i=0; i<start.size(); i++){
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);

    }
    sort(v.begin(), v.end(), cmp);
    int count = 1;
    int endMeeting = v[0].second;

    for(int i=1; i<start.size(); i++){
            if(v[i].first>endMeeting){
                count++;
                endMeeting = v[i].second;
            }
    }
    return count;
}