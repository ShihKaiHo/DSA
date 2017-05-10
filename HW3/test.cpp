#include <iostream>
using namespace std;
int n = 0;
int m = 0;
float S = 0;
//定義商品數、交易紀錄總數、推薦門檻
//定義交易紀錄清單
int a[9500] = {0};
//再重整之清單，紀錄可以推薦的商品總數
int x = 0;
int y = 0;
//x及y為運算中的輔助變數

void setTransactions(int** , int* , int );
//負責找出與該名顧客購買的商品具相同組合或是包含該組合的紀錄，傳送該紀錄給下一個函數重整
void rearrange(int , int** , int*);
//負責對包含該組合的購買紀錄中，一個一個找出除了該組合外尚購買了哪些商品，彙整為a[1000]的一維陣列
void print();
//以a[1000]為基底計算出哪項商品出現次數最多，並確認出現的機率高於推薦門檻
int main()
{
    cin >> n >> m >> S;
    //前三列輸入商品數、交易總紀錄數目、推薦門檻
    int** trans = new int*[m];

    int* itemCnt = new int[m];


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

    setTransactions(trans, itemCnt, m);
    print();
    return 0;
}
void setTransactions(int** trans, int* itemCnt, int m)
{
    for(int i = 0; i < m; i++)
        //從第一列開始比對
    {
        if(itemCnt[i] >= itemCnt[m])
            //交易紀錄中，購買商品數量比目前的購買組合數量多才會比對
        {
            int num = 0;
            //定義num為第i列中與目前的品項相同的數目
            for(int k = 0; k < itemCnt[m]; k++)
                //m行即是目前的購買組合，具有k個商品
            {
                for(int j = 0; j < itemCnt[i]; j++)
                {
                    if(trans[i][j] == trans[m][k])
                        //第i行與m行間的比對，若有相同商品則讓num＋1
                    {
                        num++;
                        break;
                    }
                }
            }
            if(num == itemCnt[m])
                //當相同的商品數目與目前購買的數量一樣時，可以確認這份購買紀錄是包含著目前的購買組合的，因此以函數rearrange重新整理記錄之
            {
                //y代表的數字為，在歷史清單內一共有多少購買記錄有包含到目前這份購買組合
                y++;
                rearrange(i, trans, itemCnt);
            }
        }
    }
}
void rearrange(int i, int** trans,int* itemCnt)
{
    //cout << i;可以確認正確的清單紀錄有被送到此進行重整
    for(int j = 0; j < itemCnt[i]; j++)
    {
        bool same = false;
        //宣告bool變數判斷商品的對應性
        for(int k = 0; k < itemCnt[m]; k++)
        {
            //用目前的購買組合去比對之前的歷史紀錄，當出現品項為目前購買組合所不包含的商品時以a[]陣列紀錄之
            if(trans[i][j] == trans[m][k])
            {
                same = true;
            }
        }
        if(same == false)
        {
            a[x] = trans[i][j];
            //cout << a[x]<< " ";可以確認紀錄的商品是否正確
            x++;
        }
    }
}
void print()
{
    //用來計算a[]陣列中，哪一項商品(max)出現次數(maxf)最多
    int max = 0;
    int maxf = 0;

    for(int i = 0; i < x; i++)
    {
        int num = 0;
        for(int j = 0; j < x; j++)
        {
            //a[]陣列中每個元素都會被拿去對所有(包含自己)元素比對，藉此計算出現數量
            if(a[i] == a[j])
                num++;
        }
        //兩個不同等級的判定，當num比目前的最大次數大就取代之，當num與最大次數相同則需要推薦“編號最小”的商品
        if(num > maxf)
        {
            maxf = num;
            max = a[i];
        }
        if(num == maxf)
        {
            maxf = num;
            if(a[i] < max)
                max = a[i];
            else
                max = max;
        }
    }

    if(static_cast<float>(maxf)/m >= S)

        //最後確認最大次數的出現頻率有高於推薦門檻，才會印出
        //分別印出推薦商品(出現次數最多的商品中編號最小)，與目前購買組合共同出現的次數，以及目前購買組合一共出現在多少歷史紀錄中
        cout << max << " "<< maxf <<" "<< y;
}
