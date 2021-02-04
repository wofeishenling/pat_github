//数组中的第K个最大元素
//快速选择 快速堆 分区减治
#include<vector>
#include<algorithm>

using namespace std;

void my_nth_element(vector<int>::iterator first,vector<int>::iterator nth,vector<int>::iterator last){
    vector<int>::iterator p = __unguarded_partition(first,last,*first);
    
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //nth_element用quick_select实现，时间复杂度为O(n)
        nth_element(nums.begin(),nums.begin()+(k-1),nums.end(),[](const int &a, const int &b){return a>b;});
        return nums[k-1];
    }
};

// nth_element() and its auxiliary functions.  

template <class _RandomAccessIter, class _Tp>
void __nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*) {
  while (__last - __first > 3) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
  }
  __insertion_sort(__first, __last);
}

template <class _RandomAccessIter>
inline void nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                        _RandomAccessIter __last) {
  __STL_REQUIRES(_RandomAccessIter, _Mutable_RandomAccessIterator);
  __STL_REQUIRES(typename iterator_traits<_RandomAccessIter>::value_type,
                 _LessThanComparable);
  __nth_element(__first, __nth, __last, __VALUE_TYPE(__first));
}
template <class _RandomAccessIter, class _Tp>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first, 
                                        _RandomAccessIter __last, 
                                        _Tp __pivot) 
{
  while (true) {
    while (*__first < __pivot)
      ++__first;
    --__last;
    while (__pivot < *__last)
      --__last;
    if (!(__first < __last))
      return __first;
    iter_swap(__first, __last);
    ++__first;
  }
} 
