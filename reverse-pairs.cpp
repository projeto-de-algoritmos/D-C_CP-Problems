#include <vector>

using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &numbers)
    {
        return mergeSort(numbers, 0, numbers.size() - 1);
    }

private:
    int mergeSort(vector<int> &numbers, int leftIndex, int rightIndex)
    {
        if (leftIndex >= rightIndex)
        {
            return 0;
        }

        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        int count = mergeSort(numbers, leftIndex, midIndex) + mergeSort(numbers, midIndex + 1, rightIndex) + merge(numbers, leftIndex, midIndex, rightIndex);
        return count;
    }

    int merge(vector<int> &numbers, int leftIndex, int midIndex, int rightIndex)
    {
        int count = 0;
        vector<int> temp(rightIndex - leftIndex + 1);
        int i = leftIndex;
        int j = midIndex + 1;
        int k = 0;

        while (i <= midIndex && j <= rightIndex)
        {
            if (static_cast<long long>(numbers[i]) > 2LL * numbers[j])
            {
                count += midIndex - i + 1;
                j++;
            }
            else
            {
                i++;
            }
        }

        i = leftIndex;
        j = midIndex + 1;

        while (i <= midIndex && j <= rightIndex)
        {
            if (numbers[i] <= numbers[j])
            {
                temp[k++] = numbers[i++];
            }
            else
            {
                temp[k++] = numbers[j++];
            }
        }

        while (i <= midIndex)
        {
            temp[k++] = numbers[i++];
        }

        while (j <= rightIndex)
        {
            temp[k++] = numbers[j++];
        }

        for (int p = 0; p < temp.size(); p++)
        {
            numbers[leftIndex + p] = temp[p];
        }

        return count;
    }
};
