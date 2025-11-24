#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  char ch;
  int freq;
  Node *left, *right;

  Node(char c, int f)
  {
    ch = c;
    freq = f;
    left = right = NULL;
  }
};

// Comparator for priority queue
class Compare
{
public:
  bool operator()(Node *a, Node *b)
  {
    return a->freq > b->freq;
  }
};

class Huffman
{
private:
  Node *root;

  // recursive function to print codes
  void printCodes(Node *node, string code)
  {
    if (!node)
      return;

    if (!node->left && !node->right)
    {
      cout << node->ch << " : " << code << endl;
    }

    printCodes(node->left, code + "0");
    printCodes(node->right, code + "1");
  }

public:
  Huffman()
  {
    root = NULL;
  }

  // Build Huffman Tree
  void build(const string &text)
  {
    unordered_map<char, int> freq;

    // Count frequency
    for (char c : text)
      freq[c]++;

    // Min-heap priority queue
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto it : freq)
    {
      pq.push(new Node(it.first, it.second));
    }

    // Build tree
    while (pq.size() > 1)
    {
      Node *left = pq.top();
      pq.pop();
      Node *right = pq.top();
      pq.pop();

      Node *parent = new Node('\0', left->freq + right->freq);
      parent->left = left;
      parent->right = right;

      pq.push(parent);
    }

    root = pq.top();
  }

  // Print codes (public)
  void print()
  {
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");
  }
};

int main()
{
  string text;
  cout << "Enter text: ";
  getline(cin, text);

  Huffman h;
  h.build(text);
  h.print();

  return 0;
}
