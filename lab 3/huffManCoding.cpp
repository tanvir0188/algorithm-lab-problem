#include <iostream>
using namespace std;

struct huffManNode
{
    string s;
    int freq;
    bool bit;
    huffManNode *left = NULL;
    huffManNode *right = NULL;
};

struct CompareNodes
{
    bool operator()(huffManNode *const &p1, huffManNode *const &p2)
    {
        return p1->freq > p2->freq;
    }
};

int main()
{
}