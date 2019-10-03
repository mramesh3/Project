/* 
Author: Mahendri Ramesh

Topic: Sorting algorithms: 
------------------------------
Typically there are 4 broad categories of algorithms: 
	Divide and conquer 
	Prune and search 
	Dynamic programming
	Greedy algorithm
	
It is a pretty vast area with both searching algorithms and sorting algorithms, but here, we deal with only sorting algorithms. 
Our approach will be divide and conquer! Starting with the basic sorting algorithm
One thing to be kept in mind for sorting is the order of sorting. Ascending or descending. Though there won't be any drastic 
changes o the code, except the traversal and the comparison logic. That would be inverted. Here we have assumed it is ascending 
order.
------------------------------------------------------------------------------------------------------------------------------------------------------------

Bubble sort: 
-------------
It is a comparison based algorithm where adjacent elements are compared and swapped if they are not already 
sorted. This procedure repeats until all elements are sorted. 
This algorithm has a time complexity of O(n^2) and hence it is not suitable for very large data sets. 

Pseudo-code: 

void Bubblesort(int arr[],length)
{
	for(int i=0;i<length-1;i++)					//this for loop is to traverse the list n (=length )number of times the sorting needs to be done
	{
		for(j=0;j<length-1-i;j++)				// this for loop is to traverse the list
		{
			if(arr[j]>arr[j+1])					//condition to check if the element at j is greater than the next element at j+1
				swap(arr[j],arr[j+1])			//use a temp variable to swap the values
		}
	}
}
------------------------------------------------------------------------------------------------------------------------------------------------------------

Selection sort: 
-----------------
This is a linear sorting algorithm. This is again not suitable for large data sets as it has O(n^2) complexity. 
In this, the list is divided as sorted and unsorted arrays. The sorted array is to the left and the unsorted is the rest of the
array. There are two way to approach this. To start at the highest value or start at the lowest value.
In the beginning, the first element is compared with the rest of the elements to determine the highest element. Once the highest
element is found, it is swapped with the last element. This continues till all the elements are sorted. 
(We can use the lowest element first as well.)
Pseudo-code: 

void selectionsort(int arr[], int size)
{
	for(int j=size-1;j>0;j++)			//this is for the last element (sorted array)
	{
		int pos=0;						
		for(int i=1;i<=j;i++)			//this is the inner unsorted array
		{
			if(arr[i]>arr[pos])			//check for the greater element of the two
			{
				pos=i;
			}
		}
		swap(arr[pos],arr[j]);			//if it is lower then swap positions
	}
}
------------------------------------------------------------------------------------------------------------------------------------------------------------

Insertion sort:
----------------
This is again one of the simpler algorithms. Worst case complexity is O(n^2). 
------------------------------------------------------------------------------------------------------------------------------------------------------------

Quick sort: 
------------
This algorithm is based on divide and conquer method. It divides the entire list into two at the pivot element and then sort.
Pivot element is an element chosen from the list which is used as a bar to compare with other elements and divide the list 
accordingly. The sorting is called recursively in order to divide(along the pivot) and conquer(sort) Basis for choosing pivot 
element is: Highest index, lowest index or mid value (can be any random value or median value).The efficiency of this algorithm
depends on the choice of the pivot element. 

Pseudo-code:

void quicksort(int x[], int low, int high)
{
	int pivot=(x[low]+x[high])/2;		//taking the mid value as the pivot
	if(high-low<=0)
		return; 			//to check if index of high is greater or less than index of low
	int i=low,j=high;		//initializing high and low
	
	while(i<j)
	{
		while(x[i]<pivot)
			i++;
		while(x[j]>pivot)
			j--;
		if(i<=j)
			swap(x[i],x[j])
	}
	quicksort(x,low,i-1);
	quicksort(x,i,high);
}
------------------------------------------------------------------------------------------------------------------------------------------------------------

Merge sort: 
------------
This is also based on divide and conquer method. Here the list is divided until atomised size elements are reached.

Pseudo-code: 
if(size<2) 
	return;
mid=size/2;
leftArr=size
------------------------------------------------------------------------------------------------------------------------------------------------------------
*/