#include <iostream>
#include<unordered_map>
using namespace std;

class TrieNode
{
  public:
  char data;
  TrieNode* children[26];
  bool isTerminal;

  TrieNode(char d)
  {
    this->data = d;
    for(int i=0; i<26; i++)
    {
      children[i] = NULL;
    }
    this->isTerminal = false;
  }
};

void insertWord(TrieNode* root, string word)
{
  // base case
  if(word.length() == 0)
  {
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch-'A';

  TrieNode* child;
  
  // present
  if(root->children[index] != NULL)
  {
    child = root->children[index];
  }
  else
  {
    child = new TrieNode(ch); 
    root->children[index] = child;
  }

  // rec
  insertWord(child, word.substr(1));
}



int main() {

  TrieNode* root = new TrieNode('-');

  insertWord(root, "Coding");

}