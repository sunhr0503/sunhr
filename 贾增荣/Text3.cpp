#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n; 
typedef struct node{
    int ch,ma,en;
    int sum,id;
}node;
node stu[305]={0};
bool cmp(node a,node b){
    if(a.sum>b.sum) return true;
    else if(a.sum==b.sum&&a.ch>b.ch) return true;
    else if(a.sum==b.sum&&a.ch==b.ch&&a.id<b.id) return true;
    else return false;
}
int main(int argc, char** argv) {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stu[i].ch>>stu[i].ma>>stu[i].en;
        stu[i].sum=stu[i].ch+stu[i].ma+stu[i].en;
        stu[i].id=i;
    }
    sort(stu+1,stu+n+1,cmp);
    for(int j=1;j<=5;j++){
        cout<<stu[j].id<<" "<<stu[j].sum<<endl;
    }
    
    return 0;
}