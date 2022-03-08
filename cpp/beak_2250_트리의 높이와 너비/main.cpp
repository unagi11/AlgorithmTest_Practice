#include <cstdio>
#include <vector>

using namespace std;

class Node
{
private:
public:
    int centerNum, leftNum, rightNum;

    Node *leftNode;
    Node *rightNode;

    Node();

    Node(int center, int left, int right)
    {
        centerNum = center;
        leftNum = left;
        rightNum = right;
    }

    Node(Node *left, Node *right)
    {
        leftNode = left;
        rightNode = right;
    }

    void print()
    {
        printf("%d : %d %d\n", centerNum, leftNum, rightNum);
    }

    ~Node();
};

int main(int argc, char const *argv[])
{
    int countOfNodes;

    scanf("%d", &countOfNodes);

    // vector<int> centers;
    // vector<int> lefts;
    // vector<int> rights;

    vector<Node> nodes;

    for (int i = 0; i < countOfNodes; i++)
    {
        int center, left, right;
        scanf("%d %d %d", &center, &left, &right);

        nodes.push_back(Node(center, left, right));
    }

    for (Node node : nodes)
    {
        node.print();
    }

    return 0;
}
