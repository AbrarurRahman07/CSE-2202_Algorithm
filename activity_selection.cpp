#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int ID;
    int start;
    int finish;
};

vector<int> actselect(vector<Activity> activities){

    sort(activities.begin(), activities.end(), [](Activity a1,Activity a2){
           return a1.finish < a2.finish;  
    });
  vector<int> selected;

  int lastfinish = activities[0].finish;
  selected.push_back(activities[0].ID);
   
  for(int i = 1; i<activities.size(); i++){
       if(activities[i].start >= lastfinish){
        selected.push_back(activities[i].ID);
        lastfinish = activities[i].finish;
       }
  }

  return selected;
    
}

int main(){
    int n;
    cin>>n;

    vector<Activity> activities(n);

    for(int i = 0;i<n;i++){
        cin>>activities[i].ID>>activities[i].start>>activities[i].finish;
    }

    vector<int> selected = actselect(activities);
    

    for(auto i:selected) cout<<i<<" ";

}