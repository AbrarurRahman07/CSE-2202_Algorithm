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

// Comparator for min-heap
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
  unordered_map<char, string> huffCode;

  // Generate codes (recursive)
  void generateCodes(Node *node, string code)
  {
    if (!node)
      return;

    if (!node->left && !node->right)
    {
      huffCode[node->ch] = code;
    }

    generateCodes(node->left, code + "0");
    generateCodes(node->right, code + "1");
  }

public:
  Huffman() { root = NULL; }

  // Build Huffman tree
  void build(const string &text)
  {
    unordered_map<char, int> freq;

    for (char c : text)
      freq[c]++;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto it : freq)
      pq.push(new Node(it.first, it.second));

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

    generateCodes(root, "");
  }

  // Encode text to binary string
  string encode(const string &text)
  {
    string encoded = "";
    for (char c : text)
      encoded += huffCode[c];
    return encoded;
  }

  // Decode binary string back to original text
  string decode(const string &binary)
  {
    string decoded = "";
    Node *node = root;

    for (char bit : binary)
    {
      if (bit == '0')
        node = node->left;
      else
        node = node->right;

      if (!node->left && !node->right)
      { // leaf
        decoded += node->ch;
        node = root; // go back to root
      }
    }
    return decoded;
  }

  // Print codes
  void printCodes()
  {
    cout << "\nHuffman Codes:\n";
    for (auto &it : huffCode)
    {
      cout << it.first << " : " << it.second << endl;
    }
  }
};

int main()
{
  string text;
  cout << "Enter text: ";
  getline(cin, text);

  Huffman h;
  h.build(text);

  h.printCodes();

  string encoded = h.encode(text);
  cout << "\nEncoded: " << encoded << endl;

  string decoded = h.decode(encoded);
  cout << "Decoded: " << decoded << endl;

  return 0;
}
