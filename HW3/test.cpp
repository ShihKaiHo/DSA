#include <iostream>
using namespace std;
int n = 0;
int m = 0;
float S = 0;
//�w�q�ӫ~�ơB��������`�ơB���˪��e
//�w�q��������M��
int a[9500] = {0};
//�A���㤧�M��A�����i�H���˪��ӫ~�`��
int x = 0;
int y = 0;
//x��y���B�⤤�����U�ܼ�

void setTransactions(int** , int* , int );
//�t�d��X�P�ӦW�U���ʶR���ӫ~��ۦP�զX�άO�]�t�ӲզX�������A�ǰe�Ӭ������U�@�Ө�ƭ���
void rearrange(int , int** , int*);
//�t�d��]�t�ӲզX���ʶR�������A�@�Ӥ@�ӧ�X���F�ӲզX�~�|�ʶR�F���ǰӫ~�A�J�㬰a[1000]���@���}�C
void print();
//�Ha[1000]���򩳭p��X�����ӫ~�X�{���Ƴ̦h�A�ýT�{�X�{�����v������˪��e
int main()
{
    cin >> n >> m >> S;
    //�e�T�C��J�ӫ~�ơB����`�����ƥءB���˪��e
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
        //�q�Ĥ@�C�}�l���
    {
        if(itemCnt[i] >= itemCnt[m])
            //����������A�ʶR�ӫ~�ƶq��ثe���ʶR�զX�ƶq�h�~�|���
        {
            int num = 0;
            //�w�qnum����i�C���P�ثe���~���ۦP���ƥ�
            for(int k = 0; k < itemCnt[m]; k++)
                //m��Y�O�ثe���ʶR�զX�A�㦳k�Ӱӫ~
            {
                for(int j = 0; j < itemCnt[i]; j++)
                {
                    if(trans[i][j] == trans[m][k])
                        //��i��Pm�涡�����A�Y���ۦP�ӫ~�h��num��1
                    {
                        num++;
                        break;
                    }
                }
            }
            if(num == itemCnt[m])
                //��ۦP���ӫ~�ƥػP�ثe�ʶR���ƶq�@�ˮɡA�i�H�T�{�o���ʶR�����O�]�t�ۥثe���ʶR�զX���A�]���H���rearrange���s��z�O����
            {
                //y�N���Ʀr���A�b���v�M�椺�@�@���h���ʶR�O�����]�t��ثe�o���ʶR�զX
                y++;
                rearrange(i, trans, itemCnt);
            }
        }
    }
}
void rearrange(int i, int** trans,int* itemCnt)
{
    //cout << i;�i�H�T�{���T���M��������Q�e�즹�i�歫��
    for(int j = 0; j < itemCnt[i]; j++)
    {
        bool same = false;
        //�ŧibool�ܼƧP�_�ӫ~��������
        for(int k = 0; k < itemCnt[m]; k++)
        {
            //�Υثe���ʶR�զX�h��蠟�e�����v�����A��X�{�~�����ثe�ʶR�զX�Ҥ��]�t���ӫ~�ɥHa[]�}�C������
            if(trans[i][j] == trans[m][k])
            {
                same = true;
            }
        }
        if(same == false)
        {
            a[x] = trans[i][j];
            //cout << a[x]<< " ";�i�H�T�{�������ӫ~�O�_���T
            x++;
        }
    }
}
void print()
{
    //�Ψӭp��a[]�}�C���A���@���ӫ~(max)�X�{����(maxf)�̦h
    int max = 0;
    int maxf = 0;

    for(int i = 0; i < x; i++)
    {
        int num = 0;
        for(int j = 0; j < x; j++)
        {
            //a[]�}�C���C�Ӥ������|�Q���h��Ҧ�(�]�t�ۤv)�������A�Ǧ��p��X�{�ƶq
            if(a[i] == a[j])
                num++;
        }
        //��Ӥ��P���Ū��P�w�A��num��ثe���̤j���Ƥj�N���N���A��num�P�̤j���ƬۦP�h�ݭn���ˡ��s���̤p�����ӫ~
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

        //�̫�T�{�̤j���ƪ��X�{�W�v��������˪��e�A�~�|�L�X
        //���O�L�X���˰ӫ~(�X�{���Ƴ̦h���ӫ~���s���̤p)�A�P�ثe�ʶR�զX�@�P�X�{�����ơA�H�Υثe�ʶR�զX�@�@�X�{�b�h�־��v������
        cout << max << " "<< maxf <<" "<< y;
}
