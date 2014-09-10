#include <iostream>
#include <vector>
using namespace::std;
void resetFlag(vector<bool> &flag)
{
        for(int i=0;i<flag.size();i++)
            flag[i]=false;
}
bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> flag1(9+1,false);//9行,标志某字符出现过没有
        vector<bool> flag2(9+1,false);//9列
        vector<bool> flag3(9+1,false);//9小块
        for(int i=0;i<9;i++)
        {
            resetFlag(flag1);
            resetFlag(flag2);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(flag1[board[i][j]-'0'])
                    {
                        cout<<"return false"<<"i:"<<i<<" j:"<<j<<endl;
                        return false;
                    }
                    else
                        flag1[board[i][j]-'0']=true;
                }
                if(board[j][i]!='.')
                {
                    if(flag2[board[j][i]-'0'])
                    {
                        cout<<"return false"<<"j:"<<j<<" i:"<<i<<endl;
                        return false;
                    }
                    else
                        flag2[board[j][i]-'0']=true;
                }
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                resetFlag(flag3);
                for(int m=0;m<3;m++)
                {
                    for(int n=0;n<3;n++)
                    {
                        if(board[i+m][j+n]!='.')
                        {
                            if(flag3[board[i+m][j+n]-'0'])
                            {
                                cout<<"return false"<<"m:"<<m<<" n:"<<n<<endl;
                                return false;
                            }
                            else
                                flag3[board[i+m][j+n]-'0']=true;
                        }
                    }
                }
            }
        }
        return true;
    }
int main()
{
    vector<vector<char> >board;
    vector<char> temp(9,'0');
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cin>>temp[j];
        board.push_back(temp);
    }
//          for(int j=0;j<9;j++)
 //           cout<<temp[j];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
            if(j==8)
                cout<<endl;
        }

    }

    bool result=isValidSudoku(board);
    if(result)
        cout<<"Sudoku Valid"<<endl;
    else
        cout<<"Sudoku Invalid"<<endl;
    return 0;
}
