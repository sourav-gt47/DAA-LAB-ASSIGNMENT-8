#include<bits/stdc++.h>
using namespace std;

struct knap{

int cost;
int weight;

};


bool compare(struct knap a , struct knap b){

double l1 =double(a.cost/a.weight); 
double l2 =double(b.cost/b.weight); 
return l1 > l2;

}



double knapsack(int w , struct knap arr[], int n)
{
  sort(arr,arr+n,compare); //compare on the basis of cost/weight.
 int curweight=0;
 double finalcost=0.0; //knapsack cost


 for(int i=0;i<n;i++)
{
  if(curweight + arr[i].weight<=w)
  {
    curweight +=arr[i].weight;
    finalcost+=arr[i].cost;


  }  
else{

  //for fractional part 
  int remain=(w-curweight);
  finalcost+=arr[i].cost * ((double) remain / (double) arr[i].weight);
  break;


}

}


return finalcost;

}


int main(){

int n,w;
cout<<"Enter n::";
cin>>n;
knap arr[n];  //array of structure
cout<<"Enter w::";
cin>>w;
cout<<"Enter profit of " << n<<" items::";
for(int i=0;i<n;i++)
{ cin>>arr[i].cost;
  
}
cout<<"Enter weight of " << n<<" items::";                          
for(int i=0;i<n;i++)
{ cin>>arr[i].weight;
  
}

cout<<"Total Cost:: Rs."<<knapsack(w, arr ,n)<<endl;
    return 0;
}


