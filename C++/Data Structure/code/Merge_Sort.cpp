#include<iostream>
using namespace std;
/*                                                                              Merge_Sort_implementation
                                                                                by => Eng/ Ahmed Mitwally Essa
*/

void merge(int arr[], int l, int m, int r)//m = l + (r - l) / 2;
{
    int i, j, k;
    int n1 = m - l + 1;// First subarray is arr[l..m]
    int n2 = r - m;// Second subarray is arr[m+1..r]
    int *L=new int[n1], *R=new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[] = { 60,10,20,5,60,70 };
    int n = sizeof(arr) / sizeof(arr[0]);//24/4=6
    mergeSort(arr, 0, n-1);

    cout<<"Array  After Merge Sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}
