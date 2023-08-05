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

bool searchWord(TrieNode* root, string word, string wordCopy, string check = "")
{


  int len = word.length();

  // cout << check << ", " << len << word << ": " << wordCopy << endl;

  if(check == wordCopy && len == 0 && root->isTerminal == true)
    return true;

  char ch = word[0];
  int index = ch-'A';

  if(root->children[index] == NULL)
    return false;
  else
    return searchWord(root->children[index], word.substr(1), wordCopy, (check+ch));
  
}



int main() {

  TrieNode* root = new TrieNode('-');

  insertWord(root, "CAB");
  insertWord(root, "CAR");
  insertWord(root, "CARE");
  insertWord(root, "CODE");
  insertWord(root, "CODING");
  insertWord(root, "EAT");
  insertWord(root, "EAGLE");


  cout << searchWord(root, "CODING", "CODING") << endl;
  cout << searchWord(root, "CODE", "CODE") << endl;
  cout << searchWord(root, "RIYA", "RIYA") << endl;
  cout << searchWord(root, "EAT", "EAT") << endl;
  cout << searchWord(root, "EAGLE", "EAGLE") <<endl;


}