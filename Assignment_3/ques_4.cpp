#include <iostream>
using namespace std;
#define nmax 20
float w[nmax][nmax];
float e[nmax][nmax];
int map[nmax][nmax];
template <typename T>
class Node
{
    public:
    T data;
    Node *left;
    Node *right;
    Node(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
     ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};
class key
{
public:
    float p;
    float q;
    char name;
};
void OBST(key k[], int n)
{
    // for (int i = 1; i <= n; i++)
    // {

    //     for (int j = 0; j <= n; j++)
    //     {

    //         if (i == j + 1)
    //         {
    //             w[i][j] = k[j].q;
    //         }
    //         else if (i <= j)
    //         {
    //             w[i][j] = w[i][j-1] + k[j].p + k[j].q;
    //         }
    //     }
    // }
    for (int i = 1; i <= n + 1; i++)
    {
        e[i][i - 1] = k[i - 1].q;
        w[i][i - 1] = k[i - 1].q;
    }
    int j;
    for (int m = 1; m <= n; m++)
    {
        for (int i = 1; i <= n - m + 1; i++)
        {
            j = i + m - 1;
            e[i][j] = 1e9;
            w[i][j] = w[i][j - 1] + k[j].p + k[j].q;
            for (int r = i; r <= j; r++)
            {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                {
                    e[i][j] = t;
                    map[i][j]=r;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<map[i][j]<<"\t";
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << e[i][j] << "\t";
        }
        cout << endl;
    }
}
Node<int>*Tree(int i,int j)
{
    if(i==j)
    {
        return NULL;
    }
    int t=map[i][j];
    Node<int> *root=new Node<int>(t);
    root->left=Tree(i,map[i][j]-1);
    root->right=Tree(map[i][j]-1,j);
    return root;

}
int main()
{
    int n;
    cin >> n;
    key k[n];
    for (int i = 0; i < n; i++)
    {
        // cin>>k[i].name;
        if (i == 0)
        {
            cin >> k[i].q;
        }
        else
        {
            cin >> k[i].p;
            cin >> k[i].q;
        }
    }
    OBST(k, n);
    return 0;
}

// 4
// 0.15
// 0.5 0.1
// 0.1
// 0.05
// 0.05 0.05