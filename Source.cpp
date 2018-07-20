#include <iostream>

#include <vector>
#include <algorithm> 

using namespace std; 
void printarrINT(int arr[], int n){

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}
void countsort(int arr[], int n){
	int max, min; 
	int i, j, id; 
	//find max, min element. 
	max = min = arr[0];
	for ( i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i]; 
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max - min + 1; 
	int *output = new int[range]; 

	for (i = 0; i < range; i++)
	{
		output[i] = 0; 
	}
	for (i = 0; i < n; i++)
	{
		output[arr[i] - min] ++; 
	}
	id = 0; 
	for (i = min; i <= max; i++)
	{
		for (j = 0; j < output[i-min]; j++)
		{
			arr[id++] = i; 
		}
	}
	delete[] output; 
}
void printarrFLO(float arr[], int n){
	for (int  i = 0;  i < n;  i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n"; 
}
void radixsort(float arr[], int n){
	float bucket[10]; 
	
	int i, j, id, freq = 1; float max;
	//find max element. 
	max = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max) 
		{
			max = arr[i]; 
		}
	}
	//call output array. 
	float *out = new float[n];
	while (max / freq > 0)
	{
		//set memory. 
		memset(bucket, 0, sizeof(float) * 10); 
		memset(out, 0, sizeof(float) *n); 

		for (i = 0; i < n; i++)
		{
			id =(int (arr[i] / freq)) % 10; 
			bucket[id] ++;
		}
		for (i = 1; i < 10 ; i++)
		{
			bucket[i] += bucket[i - 1]; 
		}
		for (i = n-1; i >= 0; i--)
		{
			id = (int(arr[i] / freq)) % 10; 
			id = --bucket[id]; 
			out[id] = arr[i]; 
		}
		for (i = 0; i < n; i++)
		{
			arr[i] = out[i]; 
		}
		freq *= 10;
	}
}

const int bsize = 10; 
void bucketsort(float arr[], int n){
	vector<float> bucket[bsize]; 

	int i, j; 
	float max, devider; 
	//get max element. 
	max = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//cal devider. 
	devider = ceil(float(max + 1) / bsize); 
	for (i = 0; i < n; i++)
	{
		j = floor(arr[i] / devider); 
		bucket[j].push_back(arr[i]);
	}
	//rearrange sort in bucket array. 
	for (i = 0; i < bsize; i++)
	{
		sort(bucket[i].begin(), bucket[i].end());
	}
	//rearrange to array. 
	int id = 0; 
	for (i = 0; i < bsize; i++)
	{
		for (j = 0; j < bucket[i].size(); j++)
		{
			arr[id++] = bucket[i][j];
		}
	}
}

void shellsort(float arr[], int n){
	int i, j, gap; 
	float temp; 
	for (gap = n/2; gap >  0; gap /=2)
	{
		for (i = gap; i < n; i++)
		{
			temp = arr[i];
			for (j = i; j >= gap && arr[j-gap] > temp; j -=gap)
			{
				arr[j] = arr[j - gap]; 
			}
			arr[j] = temp; 
		}
	}
}
int main(){
	/*int arr[100], i, n; 
	cout << "nhap sz cua mang: "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	countsort(arr, n); 
	printarrINT(arr, n);*/
	////////////////////////////////////
	float arr[100]; int i, n; 
	cout << "nhap size arr[]: "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	//float neg[10], pos[10]; 
	//int j = 0, k = 0, l = 0; 
	//for (i = 0; i < n; i++)
	//{
	//	if (arr[i] < 0)
	//	{
	//		neg[j] = arr[i];
	//		neg[j] =abs(neg[j]);
	//		j++; 
	//	}
	//	else
	//	{
	//		pos[k] = arr[i]; 
	//		k++;
	//	}
	//}
	//////call function radix sort. 
	////radixsort(neg, j); 
	////cout << "mang am: "; 
	////for (i = 0; i < j; i++)
	////{
	////	cout << neg[i] << " "; 
	////}
	////cout << "\n"; 
	////radixsort(pos, k); 
	////cout << "Mang duong: "; 
	////for (i = 0; i < k; i++)
	////{
	////	cout << pos[i] << " "; 
	////}
	////cout << "\n";

	////BUCKET SORT FUNCTION. 
	//bucketsort(neg, j);
	//cout << "mang am: "; printarrFLO(neg, j); 
	//cout << "\n"; 
	//bucketsort(pos, k); 
	//cout << "mang duong: "; printarrFLO(pos, k); 
	//cout << "\n"; 
	////ghep mang. 
	//l = j - 1; 
	//for (i = 0; i < j; i++)
	//{
	//	arr[i] = neg[l]; 
	//	arr[i] -= neg[l] * 2; 
	//	l--;
	//}
	//l = 0; 
	//for (i = j; i < n; i++)
	//{
	//	arr[i] = pos[l++];
	//}

	shellsort(arr, n); 
	cout << "array duoc sx la: "; printarrFLO(arr, n); 
	return 0;
}