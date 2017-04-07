#include <iostream>
using namespace std;


    int main()
    {
        int n = 0;
        int m = 0;
        double S = 0;

        cin >> n >> m >> S;
        //前三列輸入商品數、交易總紀錄數目、推薦門檻
        int** trans = new int*[m+1];
        int* itemCnt = new int[m+1];
        for(int i = 0; i <= m; i++)
        {
            int len = 0;
            cin >> len;


            itemCnt[i] = len;
            trans[i] = new int[len];

            for(int j = 0; j < len; j++)
            {
                cin >> trans[i][j];
            }
        }
        cout << "eofij";
      for(int i = 0; i <= m; i++)
      {
            for(int j = 0; j < itemCnt[i]; j++)
            {
                cout << trans[i][j]<< " ";
            }
            cout << "\n";
      }

        cout << "eofij";
         //some delete statements






        delete []trans;
        delete []itemCnt;

            return 0;


    }
