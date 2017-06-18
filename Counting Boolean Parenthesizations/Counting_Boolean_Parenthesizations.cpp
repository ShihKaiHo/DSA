#include <iostream>

using namespace std;

string TF;
string op;
string temp;

int count_TF(string& TF,string& op)
{
    int n=TF.length();
    int** T=new int*[n];
    for(int i=0;i<n;i++)
        T[i]=new int[n];

    int** F=new int*[n];
    for(int i=0;i<n;i++)
        F[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        T[i][i]=(TF[i] == 't')? 1: 0;
        F[i][i]=(TF[i] == 'f')? 1: 0;
    }
    for(int step=1;step<n;step++)
    {
        for(int i=0,j=step;j<n;i++,j++)
        {
            T[i][j] = F[i][j] = 0;
            for (int s=0;s<step;s++)
            {
                int k = i + s;

                int sum_ik = T[i][k] + F[i][k];
                int sum_kj = T[k+1][j] + F[k+1][j];


                if (op[k] == 'a')
                {
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (sum_ik*sum_kj - T[i][k]*T[k+1][j]);
                }
                else if (op[k] == 'o')
                {
                    F[i][j] += F[i][k]*F[k+1][j];
                    T[i][j] += (sum_ik*sum_kj - F[i][k]*F[k+1][j]);
                }
                else if (op[k] == 'x')
                {
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
            }
        }
    }
    int buff=T[0][n-1];
    for(int i=0;i<n;i++)
        delete [] T[i];
    delete [] T;
    for(int i=0;i<n;i++)
        delete [] F[i];
    delete [] F;
    return buff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        cin>>temp;
        TF.push_back(temp.front());
        for(int j=0;j<m/2;j++)
        {
            cin>>temp;
            op.push_back(temp.front());
            cin>>temp;
            TF.push_back(temp.front());
        }
        cout<<count_TF(TF,op)<<'\n';
        TF.clear();
        op.clear();
    }
    return 0;
}
