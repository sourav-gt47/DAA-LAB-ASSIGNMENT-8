#include<bits/stdc++.h>
using namespace std;

struct job
{
 int id;
 int deadline;
 int profit;
 
};


bool compare(struct job a , struct job b){

return (a.profit > b.profit);

}

void job_sequencing(struct job arr[],int n)
{
 sort(arr, arr+n,compare); //compare on the basis of profit.
 bool slot[n];
 int result[n];

 for(int i=0; i<n ;i++) 
   slot[i]=false;

 for(int i=0;i<n;i++)
{
  for(int j=min(arr[i].deadline , n)-1 ; j>=0; j--) //seaching back for empty slot.
   {
        if(slot[j]==false){

             result[j]=i;
             slot[j]=true;
             break;

        }       
   }
}
//printing and total profit
int sum=0;
cout<<"Order--> ";
for(int i=0;i<n;i++)
{
  if(slot[i])

  sum+=arr[result[i]].profit , cout<<char(arr[result[i]].id + 64)<<" ";
    

}

 cout<<"\nTotal profit::"<<sum<<endl;   
}





int main(){


int n,w;
cout<<"Enter n::";
cin>>n;
job arr[n];  //array of structure
for(int i=0;i<n;i++)
{  arr[i].id= (i+1);
  
}

cout<<"Enter profit of " << n<<" items::";
for(int i=0;i<n;i++)
{ cin>>arr[i].profit;
  
}
cout<<"Enter dealine of " << n<<" items::";                          
for(int i=0;i<n;i++)
{ cin>>arr[i].deadline;
  
}

job_sequencing(arr,n);

    return 0;
}