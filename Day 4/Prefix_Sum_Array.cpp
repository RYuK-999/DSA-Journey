#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrefixSum(vector<int> &arr){
    vector<int> prefixSum;

    int n = arr.size();
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += arr[i];
        prefixSum.push_back(sum);
    }

    return prefixSum;
}

int main(){
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = findPrefixSum(arr);
    for(auto i:prefixSum) {
        cout<<i<<" ";
    }

    return 0;
}

/*Another way of writing the function :)

vector<int> findPrefixSum(vector<int> &arr){
    vector<int> prefixSum;

    int n = arr.size();
    prefixSum[0]=arr[0];

    for (int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    return prefixSum;
}
    */