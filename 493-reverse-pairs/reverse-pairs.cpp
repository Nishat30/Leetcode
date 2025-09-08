class Solution {
public:
    int count_pairs(vector<int>& arr, int l, int m, int r){
        int cnt = 0;
        int right = m+1;
        for(int left=l; left<=m; left++){
            while(right <= r and  arr[left] > 2ll*arr[right]){
                right++;
            }

            cnt += right - (m + 1);
        }

        return cnt;
    }

    void merge(vector<int>& arr, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r - m;

        vector<int> left(n1);
        for(int i=0; i<n1; i++){
            left[i] = arr[l+i];
        }

        vector<int> right(n2);
        for(int i=0; i<n2; i++){
            right[i] = arr[m+1+i];
        }

        int i=0, j=0, k=l;
        while(i < n1 and j < n2){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
                k++;
            }
            else{
                arr[k] = right[j];
                j++;
                k++;
            }
        }

        while(i < n1){
            arr[k] = left[i];
            i++;
            k++;
        }

        while(j < n2){
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    int mergeSort(vector<int>& arr, int l, int r){
        int ans = 0;
        if(l < r){
            int m = l + (r-l)/2;

            ans += mergeSort(arr, l, m);
            ans += mergeSort(arr, m+1, r);

            ans += count_pairs(arr, l, m, r);

            merge(arr, l, m, r);
        }

        return ans;
    }

    int reversePairs(vector<int>& nums) { 
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};
