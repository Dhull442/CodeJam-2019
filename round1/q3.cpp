#include<bits/stdc++.h>
using namespace std;

struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[26];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;

	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'A';	//extrct first character of word
		if(current->child[letter] == NULL)
			current->child[letter] = new node();

		current->child[letter]->prefix_count++;
		current = current->child[letter];
	}
	current->isEnd = true;
}

bool search(string word)
{
	node *current = head;
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'A';
		if(current->child[letter] == NULL)
			return false;		//not found
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix)
{
	node *current = head;
	for(int i = 0; i < prefix.length() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'A';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
}
int num_pairs(node* ptr){
  for(int i=0;i<26;i++){
    if(ptr->child[i]!=NULL){
      cout << "("<<ptr->child[i]->prefix_count<<","<<i<<") ";
    }
    else
      cout << "0 ";
  }
  cout << endl;
  if(ptr->prefix_count < 2){
    return 0;
  }
  int pairs=0;
  bool foundone=false,donesingles=false;
  for(int i=0;i<26;i++){
    if(ptr->child[i]!= NULL){
      if((ptr->child[i]->prefix_count)%2 !=0){
        if(!donesingles)
        {if(!foundone){
          cout << "found one "<<i<<endl;
          foundone=true;
        }
        else{
          cout<<"two singles found "<<i<<endl;
          donesingles = true;
          pairs +=2;
        }
        }
      }
      else{
        if(ptr->child[i]->isEnd)
      }
    }
  }
  for(int i=0;i<26;i++){
    if(ptr->child[i]!=NULL)
    pairs+=num_pairs(ptr->child[i]);
  }
  cout << pairs << endl;
  return pairs;
}
int main(){
  int t;
  cin >> t;
  for(int o=0;o<t;o++){
    cout << "Case #"<<o+1<<": ";
    int n;
    cin >> n;
    vector<string> x;
    init();
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      reverse(s.begin(),s.end());
      insert(s);
      x.push_back(s);
    }
    sort(x.begin(),x.end());
    int tpairs=0;
    // cout << head->prefix_count << endl;
    for(int i=0;i<26;i++){
      // cout << i+1 <<": ";
      if(head->child[i]!=NULL){
        // cout << head->child[i]->prefix_count<<endl;
        tpairs+=num_pairs(head->child[i]);
      }
      // else
        // cout << 0 << endl;
    }
    cout << tpairs<<endl;
    // for(int i=0;i<x.size();i++){
    //   string s = x[i];
    //   vector<node*> vec = roots;
    //   for(int j=0;j<s.size();j++){
    //
    //     node* head = NULL;
    //     for(int k=0;k<roots.size();k++){
    //       if(roots[i]->data == s[j]){
    //
    //       }
    //     }
    //     if(head == NULL){
    //       node* newhead = (node*)malloc(sizeof(node));
    //       newhead->data = s[0];
    //
    //     }
    //   }
    // }

  }
}
