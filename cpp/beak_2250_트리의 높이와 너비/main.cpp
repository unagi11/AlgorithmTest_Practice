#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
private:
public:
    int centerNumber, centerIndex;

    int x_position;

    Node *leftNode = NULL;
    Node *rightNode = NULL;
    Node *parentNode = NULL;

    Node(int number, int index)
    {
        centerNumber = number;
        centerIndex = index;
    };

    void print()
    {
        int leftNumber = leftNode != NULL ? leftNode->centerNumber : -1;
        int rightNumber = rightNode != NULL ? rightNode->centerNumber : -1;
        int parentNumber = parentNode != NULL ? parentNode->centerNumber : -1;

        printf("%d : l[%d] r[%d] p[%d]\n", centerNumber, leftNumber, rightNumber, parentNumber);
    }
};

int x_count = 0;

void dfs_inorder_traverse(Node *n)
{
    if (n->leftNode != NULL)
        dfs_inorder_traverse(n->leftNode);

    n->x_position = x_count;
    x_count++;

    if (n->rightNode != NULL)
        dfs_inorder_traverse(n->rightNode);
}

int main(int argc, char const *argv[])
{
    int countOfNodes;

    scanf("%d", &countOfNodes);

    vector<int> centers;
    vector<int> lefts;
    vector<int> rights;

    vector<Node> nodes;

    // 입력받는다.
    for (int i = 0; i < countOfNodes; i++)
    {
        int center, left, right;
        scanf("%d %d %d", &center, &left, &right);

        centers.push_back(center);
        lefts.push_back(left);
        rights.push_back(right);

        nodes.push_back(Node(center, i));
    }

    // 노드를 연결한다.
    for (int i = 0; i < nodes.size(); i++)
    {
        int centerIndex = nodes[i].centerIndex;

        if (lefts[centerIndex] != -1)
        {
            auto leftIt = find(centers.begin(), centers.end(), lefts[centerIndex]);
            int leftIndex = leftIt - centers.begin();

            nodes[i].leftNode = &nodes[leftIndex];
            nodes[leftIndex].parentNode = &nodes[i];
        }

        if (rights[centerIndex] != -1)
        {
            auto rightIt = find(centers.begin(), centers.end(), rights[centerIndex]);
            int rightIndex = rightIt - centers.begin();

            nodes[i].rightNode = &nodes[rightIndex];
            nodes[rightIndex].parentNode = &nodes[i];
        }
    }

    // 루트를 구한다.
    Node *root = &nodes[0];
    while (root->parentNode != NULL)
        root = root->parentNode;

    // 중위순회해서 x_position을 구한다.
    dfs_inorder_traverse(root);

    // bfs 순회로 너비를 구한다.
    vector<Node *> Breadth;
    Breadth.push_back(root);

    int max_level = 0;
    int max_width = 0;

    for (int level = 0; Breadth.size() != 0; level++)
    {
        vector<Node *> Next;

        int left = Breadth[0]->x_position, right = Breadth[Breadth.size() - 1]->x_position;

        if (max_width < right - left)
        {
            max_width = right - left;
            max_level = level;
        }

        for (int j = 0; j < Breadth.size(); j++)
        {
            if (Breadth[j]->leftNode != NULL)
                Next.push_back(Breadth[j]->leftNode);
            if (Breadth[j]->rightNode != NULL)
                Next.push_back(Breadth[j]->rightNode);
        }
        Breadth = Next;
    }

    printf("%d %d", max_level + 1, max_width + 1);

    return 0;
}
