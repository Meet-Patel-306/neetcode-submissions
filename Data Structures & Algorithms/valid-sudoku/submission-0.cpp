class Solution {
public:
    bool validRow(vector<vector<char>>& board,int i){
        vector<int> valid(10,0);
        for(int j = 0;j<9;j++){
            if(board[i][j] == '.') continue;
            if(valid[board[i][j]-'0']){
                return false;
            }
            valid[board[i][j]-'0'] = 1;
        }
        return true;
    }
    bool validCol(vector<vector<char>>& board,int i){
        vector<int> valid(10,0);
        for(int j = 0;j<9;j++){
            if(board[j][i] == '.') continue;
            if(valid[board[j][i]-'0']){
                return false;
            }
            valid[board[j][i]-'0'] = 1;
        }
        return true;
    }
    bool validAll(vector<vector<char>>& board,int i,int j){
        vector<int> valid(10,0);
        for(int r = i;r<i+3;r++){
            for(int c = j;c<j+3;c++){
                if(board[r][c] == '.') continue;
                if(valid[board[r][c]-'0']){
                    return false;
                }
                valid[board[r][c]-'0'] = 1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            if(!(validCol(board,i) && validRow(board,i))) return false;
        }
        for(int i = 0;i<9;i+=3){
            for(int j = 0;j<9;j+=3){
                if(!validAll(board,i,j)) return false;
            }
        }
        return true;
    }
};
