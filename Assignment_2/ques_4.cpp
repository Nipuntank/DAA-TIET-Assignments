#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    char data;
    int freq;
    Node *left,*right;
    Node(char data,int freq)
    {
        this->data = data;
        this->freq=freq;
        left=NULL;
        right=NULL;
    }
};
class Compare
{
    public:
    bool operator()(Node *l,Node *r)
    {
        return (l->freq>r->freq);
    } 
};
// void printCodes(Node *root,string str)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     if(root->data!='$')
//     {
//         cout<<root->data<<":"<<str<<endl;
//     }
//     printCodes(root->left,str+"0");
//     printCodes(root->right,str+"1");
// }
void printCodes(Node* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCode(char data[],int freq[],int n)
{
    Node *leftNode,*rightNode,*topNode;
    priority_queue<Node *,vector<Node*>,Compare>pq;
    for(int i=0;i<n;i++)
    {
        Node *newNode = new Node(data[i],freq[i]);
        pq.push(newNode);
    }
    while(pq.size()!=1)
    {
        leftNode = pq.top();
        pq.pop();
        rightNode = pq.top();
        pq.pop();
        
        Node *topEle = new Node('$',leftNode->freq+rightNode->freq);
        topNode = topEle;
        topNode->left = leftNode;
        topNode->right = rightNode;
        pq.push(topEle);
    }
    printCodes(pq.top(),"");
}
int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    HuffmanCode(arr,freq,n);
    return 0;
}