#include <iostream>
#include <vector>

long long int mergeAndCount(std::vector<long long int> &a, int start, int mid, int end)
{
    long long int count = 0;

    std::vector<long long int> temp(end - start + 1);
    int leftPtr = start;
    int rightPtr = mid + 1;
    int tempPtr = 0;

    while (leftPtr <= mid && rightPtr <= end)
    {
        if (a[leftPtr] >= a[rightPtr])
        {
            count += mid - leftPtr + 1;
            temp[tempPtr++] = a[rightPtr++];
        }
        else
        {
            temp[tempPtr++] = a[leftPtr++];
        }
    }

    while (leftPtr <= mid)
    {
        temp[tempPtr++] = a[leftPtr++];
    }

    while (rightPtr <= end)
    {
        temp[tempPtr++] = a[rightPtr++];
    }

    std::copy(temp.begin(), temp.end(), a.begin() + start);

    return count;
}

long long int countCrossings(std::vector<long long int> &a, int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    long long int leftCrossings = countCrossings(a, start, mid);
    long long int rightCrossings = countCrossings(a, mid + 1, end);
    long long int mergeCrossings = mergeAndCount(a, start, mid, end);

    return leftCrossings + rightCrossings + mergeCrossings;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<long long int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        long long int crossings = countCrossings(a, 0, n - 1);
        std::cout << crossings << std::endl;
    }

    return 0;
}