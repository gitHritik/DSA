class Solution
{

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() != 1)
        {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            if (M[A][B] == 1)
            {
                s.push(B);
            }
            else
            {
                s.push(A);
            }
        }
        int ans = s.top();

        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                zeroCount++;
            }
        }
        if (zeroCount != n)
        {
            return -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
            {
                oneCount++;
            }
        }

        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};