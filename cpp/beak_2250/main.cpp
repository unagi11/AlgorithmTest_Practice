#include <cstdio>
#include <vector>

using namespace std;

class Node
{
private:
public:
    Node *leftNode;
    Node *rightNode;

    Node();
    Node(Node *left, Node *right)
    {
        leftNode = left;
        rightNode = right;
    }

    ~Node();
};

int main(int argc, char const *argv[])
{
    int countOfNodes;

    scanf("%d", &countOfNodes);

    vector<int> centers;
    vector<int> lefts;
    vector<int> rights;

    for (int i = 0; i < countOfNodes; i++)
    {
        int center, left, right;
        scanf("%d %d %d", &center, &left, &right);

        centers.push_back(center);
        lefts.push_back(left);
        rights.push_back(right);
    }

    for (int i = 0; i < countOfNodes; i++)
    {
        printf("%d %d %d \n", centers[i], lefts[i], rights[i]);
    }

    return 0;
}
