#include <map>
#include <typeinfo>
using namespace std;


struct dictionary
{
    vector<string> words;
    dictionary(int n)
    {
        words.resize(n);
    }
    unsigned int frequency;
};

struct Node
{
    map<char, Node*> children;
    dictionary* source;
    bool is_end;
    Node()
    {
        is_end=0;
    }
};

Node* newNode()
{
    Node* _newNode=new Node;
    return _newNode;
}


void insert_word(Node* parent,string words)
{
    int length = words.length();
    map<char, Node*>::iterator iter;
    for(int i=0;i<length;i++)
    {
        if(i==length-1)
        {
            parent->is_end=1;
        }
        if((iter=parent->children.find(words[i]))!=parent->children.end())
            parent=iter->second;
        else
        {
            Node* _newNode=newNode();
            parent->children[words[i]]=_newNode;
            parent=_newNode;
        }
    }
}

int main(int argc, char *argv[])
{
    vector<dictionary> ii_dictionary(8430018);
    ifstream ii_gm("2gm.small.txt",ios::in);
    dictionary buffer(2);
    for(int i=0;ii_gm.good();i++)
    {
        ii_gm>>ii_dictionary.at(i).words.at(0);
        ii_gm>>ii_dictionary.at(i).words.at(1);
        ii_gm>>ii_dictionary.at(i).frequency;
    }


    //Node root;
    //insert_word(&root,ii_dictionary.at(0).words.at(0));

    ii_gm.close();
  return 0;
}

