#include <iostream>
#include <cstring>
using namespace std;
int sq[31][31];
bool is_dele[31][31];
void playgame(int n, int m)
{
    int tmp = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;)
        {
            tmp = sq[i][j];
            int cnt = 0;
            while(j<m && sq[i][j]==tmp)
            {
                cnt++;
                j++;
            }
            if(cnt>=3)
            {
                for(int k=j-cnt;k<j;k++)
                {
                    is_dele[i][k] = true;
                }
            }
            tmp = sq[i][j];
        }
    }
    for(int j=0;j<m;j++)
    {
        
        for(int i=0;i<n;)
        {
            tmp = sq[i][j];
            int cnt = 0;
            while(i<n && sq[i][j]==tmp)
            {
                cnt++;
                i++;
            }
            if(cnt>=3)
            {
                for(int k=i-cnt;k<i;k++)
                {
                    is_dele[k][j] = true;
                }

            }
            tmp = sq[i][j];
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    memset(sq, 0, sizeof(sq));
    memset(is_dele, false, sizeof(is_dele));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> sq[i][j];
    playgame(n, m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(is_dele[i][j])
                sq[i][j] = 0;
            cout  << sq[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
