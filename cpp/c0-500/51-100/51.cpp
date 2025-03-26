class Solution {
public:
    int n;
    unordered_map<int,bool>Row;
    unordered_map<int,bool>upperDiagonal;
    unordered_map<int,bool>lowerDiagonal;
    bool isSafe2(int r,int c,vector<vector<string>>&matrix){
        if(Row[r])return false;
        if(upperDiagonal[r-c])return false;
        if(lowerDiagonal[r+c])return false;
        return true;
    }
    bool isSafe1(int r,int c,vector<vector<string>>&matrix){
        int x=r,y=c;
        for(int i=0;i<=c;i++){
            if(matrix[r][i]=="Q") return false;
        }
        while(x>=0&&y>=0){
             if(matrix[x][y]=="Q") return false;
             x--,y--;
        }
        x=r,y=c;
        while(x<n&&y>=0){
            if(matrix[x][y]=="Q") return false;
            x++,y--;
        }
        return true;
    }
    void solve(int col,vector<string>&temp,vector<vector<string>>&result,vector<vector<string>>&matrix){
        if(col>=n){
            result.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            // if(isSafe1(row,col,matrix)){
            if(isSafe2(row,col,matrix)){
                matrix[row][col]="Q";
                temp[row][col]='Q';
                Row[row]=true;
                lowerDiagonal[row+col]=true;
                upperDiagonal[row-col]=true;
                solve(col+1,temp,result,matrix);
                matrix[row][col]=".";
                temp[row][col]='.';
                Row[row]=false;
                lowerDiagonal[row+col]=false;
                upperDiagonal[row-col]=false;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        vector<vector<string>>result;
        vector<string>temp(n,string(n,'.'));
        vector<vector<string>>matrix(n,vector<string>(n,"."));
        solve(0,temp,result,matrix);
        return result;
    }
};class Solution {
public:
    int n;
    unordered_map<int,bool>Row;
    unordered_map<int,bool>upperDiagonal;
    unordered_map<int,bool>lowerDiagonal;
    bool isSafe2(int r,int c,vector<vector<string>>&matrix){
        if(Row[r])return false;
        if(upperDiagonal[r-c])return false;
        if(lowerDiagonal[r+c])return false;
        return true;
    }
    bool isSafe1(int r,int c,vector<vector<string>>&matrix){
        int x=r,y=c;
        for(int i=0;i<=c;i++){
            if(matrix[r][i]=="Q") return false;
        }
        while(x>=0&&y>=0){
             if(matrix[x][y]=="Q") return false;
             x--,y--;
        }
        x=r,y=c;
        while(x<n&&y>=0){
            if(matrix[x][y]=="Q") return false;
            x++,y--;
        }
        return true;
    }
    void solve(int col,vector<string>&temp,vector<vector<string>>&result,vector<vector<string>>&matrix){
        if(col>=n){
            result.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            // if(isSafe1(row,col,matrix)){
            if(isSafe2(row,col,matrix)){
                matrix[row][col]="Q";
                temp[row][col]='Q';
                Row[row]=true;
                lowerDiagonal[row+col]=true;
                upperDiagonal[row-col]=true;
                solve(col+1,temp,result,matrix);
                matrix[row][col]=".";
                temp[row][col]='.';
                Row[row]=false;
                lowerDiagonal[row+col]=false;
                upperDiagonal[row-col]=false;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        vector<vector<string>>result;
        vector<string>temp(n,string(n,'.'));
        vector<vector<string>>matrix(n,vector<string>(n,"."));
        solve(0,temp,result,matrix);
        return result;
    }
};