#Link da questão : https: // leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution
{
public:
    int smallestDistancePair(std::vector<int> &nums, int k)
    {
        // Função para contar o número de pares com distância menor ou igual a 'distance'
        auto countPairs = [&](int distance)
        {
            int count = 0;
            int j = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                // Encontra o próximo número que forma um par válido
                while (j < nums.size() && nums[j] - nums[i] <= distance)
                {
                    j++;
                }
                count += j - i - 1;
            }
            return count;
        };

        // Ordena o vetor de entrada
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        // Aplica a busca binária para encontrar a menor distância possível
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (countPairs(mid) < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};
