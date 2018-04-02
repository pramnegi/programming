#include<iostream>
using namespace std;
bool func(int arr[],int n, int sum)
{
	if(sum==0)
	return true;
	if(sum<0 || n<0)
	return false;
	
	
	if(func(arr,n-1,sum-arr[n-1]))
	{
		
		cout<<arr[n-1]<<" ";
		return true;
	}
	else if(func(arr,n-1,sum))
	return true; 
	else 
	return false;
}
int main()
{
	int arr[100],n,sum;
	cin>>n;
	cin>>sum;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	func(arr,n,sum);
return 0;
}
