class Solution {
	/*
		该函数一次只打印矩阵的最外围一圈。
		当前矩阵的边界由左上角(r0,c0), 右下角(r1, c1)定义
		并且要考虑特殊情况，只有一行和一列的时候
	*/
    void doPrint(const vector<vector<int>> &matrix, vector<int> &out, int r0, int c0, int r1, int c1)
    {
        if (r0 > r1 || c0 > c1)
            return;
        for (int i = c0; i <= c1; ++i)
            out.push_back(matrix[r0][i]);
        for (int i = r0+1; i <= r1; ++i)
            out.push_back(matrix[i][c1]);
        for (int i = c1 - 1; r1 != r0 && i >= c0; --i) 	// 考虑只有一行的情况
            out.push_back(matrix[r1][i]);
        for (int i = r1 - 1; c1 != c0 && i > r0; --i)	// 考虑只有一列的情况
            out.push_back(matrix[i][c0]);
        doPrint(matrix, out, r0+1, c0+1, r1-1, c1-1);
    }
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        if (matrix.size() > 0)
			doPrint(matrix, ans, 0, 0, matrix.size()-1, matrix[0].size()-1);
        return ans;
    }
};
