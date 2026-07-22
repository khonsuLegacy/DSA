#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr, int low , int mid, int high){
    {
        // take temporary array
        vector<int>temp;
        int left = low; // Left pointer ----> [low.....mid]
        int right = mid+1; // Right pointer ----> [mid+1......high]

        //Iterate through the both array 
        while ( left<=mid && right <= high){

            if (arr[left]<arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        //After the above step if  any element left then take it to 
        //LEFT PART
        while (left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        // RIGHT PART
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        // Copy twmp array to the original array 
        for (int i =low; i<=high;i++){
            arr[i]=temp[i-low];
        }

    }
}
void mergeSortt(vector<int>&arr,int low, int high){
    if (low>=high) return ;

    // Divide them first 
    int mid = (low+high)/2;
    mergeSortt(arr,low,mid);
    mergeSortt(arr,mid+1,high);

    // Merge them 

    merge(arr,low,mid,high);

}    

/* for leetcode or other 
void msSort(vector<int>&arr,int n){
    mergeSortt(arr,0,n-1);
}

*/


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSortt(arr,0,n-1);
    // Print sorted array to verify
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}