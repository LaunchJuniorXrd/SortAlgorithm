#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

void PrintArray(int arr[], int n);
void InsertSort(int arr[], int n);
void ShellSort(int arr[], int n);
void BubbleSort(int arr[], int n);
void Quicksort(int* r, int low, int hight);
void Selectsort(int arr[], int n);
void HeapSort(int arr[], int n);
void Mergesort(int* a, int low, int hight);
void Radixsort(int arr[], int n);

int main()
{
    int n, i, t;

    while (1)
    {
        cout << "请输入要排序的个数：\n";
        cin >> n;
        int arr[n];
        cout << "请输入要排序的数：\n";
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cout << "排序前结果为：\n";
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "选择排序算法" << endl;
        cout << "1.直接插入排序" << endl;
        cout << "2.希尔排序" << endl;
        cout << "3.冒泡排序" << endl;
        cout << "4.快速排序" << endl;
        cout << "5.选择排序" << endl;
        cout << "6.堆排序" << endl;
        cout << "7.归并排序" << endl;
        cout << "8.基数排序" << endl;
        cout << "输入1-8选择" << endl;
        cin >> t;

        /* code */
        switch (t)
        {
            case 1:
                /* code */
                InsertSort(arr, n);
                PrintArray(arr, n);
                break;
            
            case 2:
                /* code */
                ShellSort(arr, n);
                PrintArray(arr, n);
                break;

            case 3:
                /* code */
                BubbleSort(arr, n);
                PrintArray(arr, n);
                break;

            case 4:
                /* code */
                Quicksort(arr, 0, n - 1);
                PrintArray(arr, n);
                break;

            case 5:
                /* code */
                Selectsort(arr, n);
                PrintArray(arr, n);
                break;

            case 6:
                /* code */
                HeapSort(arr, n);
                PrintArray(arr, n);
                break;

            case 7:
                /* code */
                Mergesort(arr, 0, n - 1);
                PrintArray(arr, n);
                break;

            case 8:
                /* code */
                Radixsort(arr, n);
                PrintArray(arr, n);
                break;
            
            default:
                break;
        }
    }
    
    // InsertSort(arr, n);
    // ShellSort(arr, n);
    // BubbleSort(arr, n);
    // Quicksort(arr, 0, n - 1);
    // Selectsort(arr, n);
    // HeapSort(arr, n);
    // Mergesort(arr, 0, n - 1);
    // Radixsort(arr, n);
    system("pause");
    return 0;
}

void PrintArray(int arr[], int n)
{
    int i;
    cout << "排序后的结果为：\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertSort(int arr[], int n)
{
    for( int i = 1 ; i < n ; i ++ ) {
        for( int j = i ; j > 0 ; j-- )
            if( arr[j] < arr[j-1] )
                swap( arr[j] , arr[j-1] );
            else
                break;
    }
}

void ShellSort(int arr[], int n)  
{
    int i,j,gap;   
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        
        for (i = 0 ;i < gap; i++)
        {
            for (j = i + gap; j < n; j += gap) 
            { 
                
                if (arr[j] < arr[j - gap])
                {
                    int tmp = arr[j];
                    int k = j - gap;
                    while (k >= 0 && arr[k] > tmp)
                    {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = tmp;
                }
            }
        }
    }
}

void BubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int part(int* r, int low, int hight) 
{
	int i = low, j = hight, pivot = r[low];
	while (i < j)
	{
		while (i<j && r[j]>pivot) 
		{
			j--;
		}
		if (i < j)
		{
			swap(r[i++], r[j]);  
		}
		while (i < j && r[i] <= pivot) 
		{
			i++;
		}
		if (i < j)
		{
			swap(r[i], r[j--]);  
		}
	}
	return i;  
}
void Quicksort(int* r, int low, int hight)
{
	int mid;
	if (low < hight)
	{
		mid = part(r, low, hight); 
		Quicksort(r, low, mid - 1); 
		Quicksort(r, mid+1, hight); 
	}
}

void Selectsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

void adjust(int arr[], int len, int index)
{
    int left = 2*index + 1;
    int right = 2*index + 2;
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx]) maxIdx = right;  
    if(maxIdx != index)                 
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);       
    }

}
void HeapSort(int arr[], int n)
{
    for(int i=n/2 - 1; i >= 0; i--)  
    {
        adjust(arr, n, i);
    }
    for(int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);          
        adjust(arr, i, 0);              
    }
}

void Merge(int* a, int low, int mid, int hight)  
{
	int* b = new int[hight - low + 1]; 
	int i = low, j = mid + 1, k = 0;   
	while (i <= mid && j <= hight)  
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];  
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= mid)   
	{
		b[k++] = a[i++];
	}
	while (j <= hight)
	{
		b[k++] = a[j++];
	}
	k = 0;  //从小标为 0 开始传送
	for (int i = low; i <= hight; i++) 
	{
		a[i] = b[k++];
	}
	delete[]b;    
}

void Mergesort(int* a, int low, int hight) 
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		Mergesort(a, low, mid);          
		Mergesort(a, mid + 1, hight);    
		Merge(a, low, mid, hight);       
	}
}

int Maxbit(int arr[], int n) 
{
    int d = 1; 
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(arr[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}

void Radixsort(int arr[], int n)
{
    int d = Maxbit(arr, n);
    int tmp[n];
    int count[10]; 
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) 
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; 
        for(j = 0; j < n; j++)
        {
            k = (arr[j] / radix) % 10; 
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; 
        for(j = n - 1; j >= 0; j--) 
        {
            k = (arr[j] / radix) % 10;
            tmp[count[k] - 1] = arr[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) 
            arr[j] = tmp[j];
        radix = radix * 10;
    }
}
