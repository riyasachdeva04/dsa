#include <iostream>
#include<vector>
#include<string>

using namespace std;

class TrieNode
{
  public:
  char data;
  bool isTerminal;
  TrieNode* children[26];

  TrieNode(char d)
  {
    this->data = d;
    this->isTerminal = false;
    for(int i=0; i<26; i++)
      {
        this->children[i] = NULL;
      }
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

vector<string> storeAns(TrieNode* root, string solve, string temp, vector<string> output, int indx=0)
{ 
  
  int len = solve.length();
  
  if(root->isTerminal == true && indx >= len-1)
  {
    output.push_back(temp);
    temp = "";
  }
  
  if(root == NULL)
  {
    return output;
  }


  for(int i=0; i<26; i++)
    {
      TrieNode* child = root->children[i];
      if(child != NULL && indx >= solve.length())
      {
        temp += child->data;
      }
      else if(child != NULL && child->data==solve[indx])
      {
        temp += child->data; 
      }
      
      output = storeAns(child, solve, temp, output, ++indx);
    }

  return output;
}

vector<vector<string> > getSuggestions(TrieNode* root, string input,
vector<vector<string>> &ans, string solve = "")
{ 
  
  static int i=0;

  if(i == input.length())
    return ans;
  
  solve += input[i];
  // solve for first letter
  {
    // store bhi karna hai ans me 
    vector<string> answerIndiv;
    answerIndiv = storeAns(root, solve, "", answerIndiv);
    ans.push_back(answerIndiv);
  }
  i++;
  return getSuggestions(root, solve, ans);
}

int main() {
  TrieNode* root = new TrieNode('-');
  vector<string> v;
  v.push_back("LOVE");
  v.push_back("LOVER");
  v.push_back("LOST");
  v.push_back("LORD");
  v.push_back("LOVING");
  v.push_back("LANE");
  v.push_back("LAST");

  string input = "LOVI";

  
  for(int i=0; i<v.size(); i++)
    {
      insertWord(root, v[i]);
    }



  vector<vector<string>> output;

  output = getSuggestions(root, input, output);

}