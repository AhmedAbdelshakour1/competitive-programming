// https://leetcode.com/problems/construct-quad-tree/description/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

Node* ConstructQuadTree(vector<vector<int>>& grid, int n, int sRow, int eRow, int sCol, int eCol){
    if(sRow > eRow || sCol > eCol) return NULL;
    
    int val = grid[sRow][sCol], isLeaf = 1;
    for (int i = sRow; i <= eRow; ++i) {
        for (int j = sCol; j <= eCol; ++j) {
            if(grid[i][j] != val) {
                isLeaf = 0;
                break;
            }
        }
        if(!isLeaf) break;
    }
    if(isLeaf) return new Node(val, isLeaf);
    int r = (sRow + eRow) / 2;
    int c = (sCol + eCol) / 2;
    Node* topLeft = ConstructQuadTree(grid, n, sRow, r, sCol, c);
    Node* topRight = ConstructQuadTree(grid, n, sRow, r, c + 1, eCol);
    Node* bottomLeft = ConstructQuadTree(grid, n, r + 1, eRow, sCol, c);
    Node* bottomRight = ConstructQuadTree(grid, n, r + 1, eRow, c + 1, eCol);
    return new Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight);
}
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return ConstructQuadTree(grid, n, 0, n - 1, 0, n - 1);
    }
};
