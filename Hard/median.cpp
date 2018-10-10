/*
 * Program: median.cpp
 * Description: There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 * Date: 10/9/2018
 * Difficulty: hard
 */

#include <iostream>
#include <vector>
using namespace std;

/* description: function that takes two sorted arrays and merge sorts them, also works if the lengths of the two arrays are uneven
 * return: a single sorted array from the two input arrays */
vector<int> mergeSortUneven(vector<int>& small, vector<int>& big)
{
        vector<int>finalArray;
        int smallSize = small.size();
        int largeSize = big.size();

        int n=0, //iterator for small array
            m=0; //iterator for big array

        int total = big.size()+small.size();

        for (int i=0; i< total; i++)
        {
                if ( n < smallSize ) //not all of members in small size are added yet
  {
                                if ( small[n] < big[m] ) //current value in small is smaller than one in big
                                        {
                                                finalArray.push_back(small[n]); //push small in results array
                                                n++; //increment the iterator for small
                                        }
                                else if (small[n] > big[m] ) //current value in small is larger than one in big
                                        {
                                                if (m < largeSize) //not all of contents in large array have been added yet
                                                        {
                                                                finalArray.push_back(big[m]); //push big in results array
                                                                m++; //increment the iterator for big
                                                        }
                                                else //all of contents in large array have been loaded
                                                        {
                                                                finalArray.push_back(small[n]); //push small in results array
                                                                n++; //increment the iterator for small
                                                        }

                                        }
                                else if (small[n] == big[m] ) //both are equal, we can push either one
                                        {
                                                finalArray.push_back(big[m]); //push small in results array
                                                m++; //increment the iterator for big
                                        }
                        }
                else //all of members in small size have been added in
                        {
                                finalArray.push_back(big[m]);
                                m++;
                        }
        }

        return finalArray;
}

/* description: return the median of an array */
double median(vector<int> data)
{
        double median;
        if (data.size()%2 == 0 ) //is even
        {
                int first = data[data.size()/2];
                //cout << "first: " << first << endl;
                int second = data[data.size()/2-1];
                //cout << "second: " << second << endl;
                median = (double)((first+second)/2.0);
        }
        else //is odd
        {
                median = (double)(data[data.size()/2]);
        }
        return median;
}

/* description: function that takes in two sorted arrays and finds the median of them both when merged */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
        vector<int>result;
        //find out who is the smaller array
        if (nums1.size() > nums2.size() )
                result = mergeSortUneven(nums2, nums1);
        else
                result = mergeSortUneven(nums1, nums2);
        return median(result);
}

int main()
{
        /* sample input: expected 2.5 */
        vector<int>nums2 = {1,2};
        vector<int>nums1= {3,4};

        cout << findMedianSortedArrays(nums1, nums2) << endl;

        return 0;
}
