#ifndef SORTS_IMP_H_
#define SORTS_IMP_H_
#include <vector>
using namespace std;
void Merge(vector<int> &vec, int first, int mid, int last) {

    int size = last - first + 1;
    int *temp_arr = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = 0;

    while ((first1 <= last1) && (first2 <= last2)) {
        if (vec[first1] < vec[first2]) {
            temp_arr[index] = vec[first1];
            first1++;
        } else {
            temp_arr[index] = vec[first2];
            first2++;
        }
        index++;
    }
    while(first1 <=last1){
        temp_arr[index] = vec[first1];
        first++;
        index;
    }
    while(first2 <=last2){
        temp_arr[index] = vec[first2];
        first2++;
        index;
    }
    for(index = 0; index<size; index++){
        vec[first] = temp_arr[index];
    }
    delete[] temp_arr;
}

#endif