 #include<iostream>
 using namespace std;
int quicksort(int a[],int low,int high)
 {
    //i一开始指向high位置
   int i=high;
    //从倒数二个开始遍历到头
   int p=a[high];
   for(int j=high-1;j>=0;j--)
    {
        //如果大于基准值
        if(a[j]>p) swap(a[--i],a[j]);
            //交换到后面去
    } 
    //将基准元素插入到最终的位置
  swap(a[high],a[i]);
    //返回基准元素的位置
    return i;
 }
 int main()
 {
     int a[5]={3,5,7,2,4};
     cout<<quicksort(a,0,4);
     return 0;
 }