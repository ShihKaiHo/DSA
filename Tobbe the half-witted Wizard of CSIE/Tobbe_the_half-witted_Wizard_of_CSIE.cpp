#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool is_op(string);
int opWeight(string);
bool compare(string, string);
vector<string> postfix;
void to_postfix(vector<string>& infix)
{
    stack<string> S;
    for(int i = 0;i< infix.size();i++)
    {
        if(is_op(infix[i]))
        {
			while(!S.empty() && S.top() != "(" && compare(S.top(),infix[i]))
			{
				postfix.push_back(S.top());
				S.pop();
			}
			S.push(infix[i]);
        }
		else if(infix[i] == "("  )
			S.push("(");
		else if(infix[i][0] == ')')
		{
			while(!S.empty() && S.top() !=  "(")
            {
				postfix.push_back(S.top());
				S.pop();
			}
			S.pop();
		}
		else
        {
            postfix.push_back(infix[i]);
        }

    }
	while(!S.empty())
    {
		postfix.push_back(S.top());
		S.pop();
	}
}

bool is_op(string op)
{
	if(op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	return false;
}

int opWeight(string op)
{
	if(op=="+" || op=="-")
        return 1;
    else
        return 2;
}

bool compare(string op1, string op2)
{
	int op1Weight = opWeight(op1);
	int op2Weight = opWeight(op2);

	return op1Weight >= op2Weight ?  true: false;
}

int main()
{
    int n;
    scanf("%d ",&n);
    vector<string> infix;
    char temp[100];
    string buffer;
    for(int i=0;i<n;i++)
    {
        gets(temp);
        char * pch;
        pch = strtok (temp," ");
        while (pch != NULL)
        {
            infix.push_back(pch);
            pch = strtok (NULL, " ");
        }
        to_postfix(infix);
        for(auto it=postfix.begin();it!=postfix.end();it++)
        {
            if(it!=postfix.end()-1)
                printf("%s ",it->c_str());
            else
                printf("%s",it->c_str());
        }
        printf("\n");
        infix.clear();
        postfix.clear();
    }
    return 0;
}
