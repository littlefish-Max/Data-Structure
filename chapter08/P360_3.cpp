#include<iostream>
using namespace std;
void countsort(int a[],int b[],int n)
{
    //遍历每一趟
    int count=0;
    for(int i=0;i<n;i++)
    {
        //找比每个元素小的个数
        count=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]<a[i]) count++;
        }
        b[count]=a[i];
    }
}
int main()
{
    int a[6]={3,5,7,2,4,9},b[6];
    countsort(a,b,6);
    for(int i=0;i<6;i++) cout<<b[i]<<" ";
    return 0;
}