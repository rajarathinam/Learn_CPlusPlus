#include <fstream>

#include <iostream>

#include <deque>

#include<stack>

#include <iomanip>

#include <sstream>

#include <string>

#include<climits>
#include<queue>
#include<map>
#include "stub.h"

using namespace std;



struct tree 

{

  int data;

  tree *left, *right;

  tree(int val) : left(NULL), right(NULL), data(val) { }

};
multimap<int,tree*> levelnode;



// Find the maximum height of the binary tree

int height(tree *p) 

{

  if (!p) return 0;

  int leftHeight = height(p->left);

  int rightHeight = height(p->right);

 
  if(leftHeight > rightHeight) 
	  return (leftHeight + 1);
  else 
	  return (rightHeight + 1);

}



// Convert an integer value to string

string intToString2(int val)

{

  ostringstream ss;

  ss << val;

  return ss.str();

}



// Print the arm branches (eg, /    \ ) on a line

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<tree*>& nodesQueue, ostream& out) 

{

  deque<tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel / 2; i++) {  

    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");

    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");

  }

  out << endl;

}



// Print the branches and node (eg, ___10___ )

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<tree*>& nodesQueue, ostream& out) 

{

  deque<tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel; i++, iter++) {

    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));

    out << setw(branchLen+2) << ((*iter) ? intToString2((*iter)->data) : "");

    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');

  }

  out << endl;

}



// Print the leaves only (just for the bottom row)

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<tree*>& nodesQueue, ostream& out) 

{

  deque<tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel; i++, iter++) {

    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString2((*iter)->data) : "");

  }

  out << endl;

}

void printPretty(tree *root, int level, int indentSpace, ostream& out) 

{

  int h = height(root);

  int nodesInThisLevel = 1;



  int branchLen = 2*((1<<h) -1) - (3-level)*(1<<h-1);  // eq of the length of branch for each node of each level

  int nodeSpaceLen = 2 + (level+1)*(1<<h);  // distance between left neighbor node's right arm and right neighbor node's left arm

  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

    

  deque<tree*> nodesQueue;

  nodesQueue.push_back(root);

  for (int r = 1; r < h; r++) {

    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    branchLen = branchLen/2 - 1;

    nodeSpaceLen = nodeSpaceLen/2 + 1;

    startLen = branchLen + (3-level) + indentSpace;

    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);



    for (int i = 0; i < nodesInThisLevel; i++) {

      tree *currNode = nodesQueue.front();

      nodesQueue.pop_front();

      if (currNode) {

	      nodesQueue.push_back(currNode->left);

	      nodesQueue.push_back(currNode->right);

      } else {

        nodesQueue.push_back(NULL);

        nodesQueue.push_back(NULL);

      }

    }

    nodesInThisLevel *= 2;

  }

  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);

}

//----My functions------------------

void mirror(tree *root)

{

	if(!root)

		return;

	mirror(root->left);

	mirror(root->right);

	swap(root->left,root->right);

}

#define max(a,b) (a>b?a:b)

/* Function to get diameter of a binary tree */
int diameter(tree* tree)
{
   /* base case where tree is empty */
   if (tree == 0)
     return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 

int depth(tree *root,int d)

{

	if(!root)

		return d+1;

	return max(depth(root->left,d+1),depth(root->right,d+1));

}

bool isBST(tree *root,int low,int high)

{

	if(!root)

		return true;

	if( root->data > low && root->data<high && isBST(root->left,low,root->data) && isBST(root->right,root->data,high))

		return true;

	return false;



}

bool isSymmetric(tree *first,tree *second)

{

	if(!first && !second)

		return true;

	if(!first || !second)

		return false;

	return (first->data==second->data)&&isSymmetric(first->left,second->right)&&isSymmetric(first->right,second->left);

}

tree *LCA(tree *first,tree *second,tree *root)

{

	if(!root||root==first || root==second)

		return root;

	tree *left = LCA(first,second,root->left);

	tree *right = LCA(first,second,root->right);

	if(left && right) 

		return root;

	return right?right:left;

}

tree *merge(tree *root1,tree *root2)

{

	if(root1==NULL)return root2;

	if(root2==NULL)return root1;

	if(root1->data > root2->data)

	{

		if(root2->right != NULL)

		{

			//merge right subtree of tree2 with tree1

			root1 = merge(root1,root2->right);

			//remove right subtree from tree2

			root2->right=NULL;

		}

		//merge tree2 with left subtree of tree1

		root1->left=merge(root1->left,root2);

	}

	else

	{

		if(root2->left !=NULL )

		{

			//merge left subtree of tree2 with tree1

			root1 = merge(root1,root2->left);

			//remove left subtree from tree2

			root2->left=NULL;

		}

		//merge tree2 with right subtree of tree1

		root1->right=merge(root1->right,root2);

	}

	return root1;

}
void printGivenLevel(tree *root, int level)
{
  if( NULL == root)
  {
	  return;
  }
  if(1 == level)
  {
	  cout<<root->data<<"\n";
  }
  if(level > 1)
  {
	  printGivenLevel(root->right,level-1);
	  printGivenLevel(root->left,level-1);
  }
}
void printlevelorder(tree *root)
{
	int h = height(root);
	for(int i=h; i>=1;i--)
	{
		printGivenLevel(root,i);
	}
}
void reverselevelorder(tree *root)

{

	deque<tree *> Q;

	stack<tree *> S;

	Q.push_back(root);

	Q.push_back(NULL);

	while(!Q.empty())

	{

		tree *curr=Q.front();

		Q.pop_front();

		if(!curr)

		{

			S.push(NULL);
/*
			if(!Q.empty())

				Q.push_back(NULL);
				*/

		}

		else

		{

			S.push(curr);

			if(curr->right)

				Q.push_back(curr->right);

			if(curr->left)

				Q.push_back(curr->left);

		}

	}

	while(!S.empty())

	{

		if(S.top())

			cout<<(S.top())->data<<"\t";

		else

			cout<<endl;

		S.pop();

	}

	cout<<endl;

}


bool mirrorEquals(tree *lt, tree *rt)
{
	if( lt == NULL || rt == NULL )
	{
		return ( lt == NULL && rt == NULL);
	}
	return (lt->data == rt->data && mirrorEquals(lt->left,rt->right) &&
		mirrorEquals(lt->right,rt->left));
}
tree* bt2DoubleLinkedList(tree* root)
{
  if (root == NULL)
    return NULL;

  queue<tree*> nodeQueue;

  tree* head = root; //reference to head of the linked list
  tree* listIT = NULL; //current node being processed
  tree* prevNode = NULL; //previous node processed

  //initialize the stack
  nodeQueue.push(root);

  //convert to double linked list
  while (!nodeQueue.empty())
  {
    //process next node in stack
    prevNode = listIT; 
    listIT = nodeQueue.front();
    
    nodeQueue.pop();

    //add left child to stack
    if (listIT->left != NULL)
      nodeQueue.push(listIT->left);

    //add right child to stack
    if (listIT->right != NULL)
      nodeQueue.push(listIT->right);

    //add current node to linked list
    if (prevNode != NULL)
      prevNode->right = listIT;
    listIT->left = prevNode;
  }
  
  //connect end node of list to null
  listIT->right = NULL;

  return head;
}

void printList(tree *root)
{
	tree *temp = root;
	while(temp != NULL)
	{
		cout<<temp->data<<"=>";
		temp = temp->right;
	}
}
void inorder(tree *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<",";
		inorder(root->right);
	}
	else
	{
		return;
	}
}
void preorder(tree *root)
{
	if(root)
	{
		cout<<root->data<<",";
		preorder(root->left);
		preorder(root->right);
	}
	else
	{
		return ;
	}
}
int search(int arr[], int start, int end, int value)
{
  int i;
  for(int i = start; i <= end; i++)
  {
	  if(arr[i] ==  value)
		  return i;
  }
}

tree* buildTreeFromArray(int arr[],int start, int end)
{
	if( end < start)
	{
		return NULL;
	}
    int mid = (start + end) / 2;
	tree* temp = new tree(arr[mid]);
	temp->left = buildTreeFromArray(arr,start,mid-1);
	temp->right = buildTreeFromArray(arr,mid+1,end);
	return temp;


}
tree* buildTree(int in[], int pre[], int start, int end)
{
	static int preIndex = 0;
	if(start > end)
		return NULL;
	tree *node = new tree(pre[preIndex++]);

	if( start == end)
		return  node;

	int index = search(in,start,end, node->data);
	node->left = buildTree(in,pre,start,index-1);
	node->right= buildTree(in,pre,index+1,end);
	return node;
}


void printLeafNodes(tree *root)
{
	if( NULL == root)
		return;
	if( root->left == NULL && root->right == NULL)
		cout<<root->data<<" ";
	printLeafNodes(root->left);
	printLeafNodes(root->right);
}

void NthLargest(tree *root, int n)
{
	if(NULL == root)
		return;
	static int index =0;
	NthLargest(root->right,n);

	if(++index == n)
	{
		cout<<" "<<n<<"th Largest Element:"<<root->data<<endl;
		return;
	}
	NthLargest(root->left,n);


}

bool isIdentical(tree *t1,tree *t2)
{
	if( NULL == t1 && NULL == t2)
	{
		return true;
	}
	if( NULL != t1 && NULL != t2)
	{
		return ( (t1->data == t2->data) &&
				 isIdentical(t1->left,t2->left) &&
				 isIdentical(t1->right,t2->right)
				);
	}
	return false;
}

int getLevelUtil(tree *node, int data, int level)
{
	
	if (node == NULL)
        return 0;
 
    if (node->data == data)
        return level;
 
    int downlevel = getLevelUtil(node->left, data, level+1);

    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right, data, level+1);

    return downlevel;
}
int getLevel(tree *node, int data)
{
    return getLevelUtil(node,data,0);
}

void LevelOrderUsing2Queues(tree* root)
{
	queue<tree*> currentlevel,nextlevel;
	currentlevel.push(root);
		while(!currentlevel.empty())
		{
			tree* currentnode = currentlevel.front();
			currentlevel.pop();
			if(currentnode)
			{
				cout<<currentnode->data<<" ";
				nextlevel.push(currentnode->left);
				nextlevel.push(currentnode->right);

			}



		
		if(currentlevel.empty())
		{
			cout<<"\n";
			swap(currentlevel,nextlevel);
		}
}
}

void printLevelOrderZigZag(tree *root) 
{
  stack<tree*> currentLevel, nextLevel;
  bool leftToRight = true;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    tree *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      if (leftToRight) {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      } else {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if (currentLevel.empty()) {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}

stack<int> stack1;
bool printPaths(tree* root,int key)
{
	

	if( NULL == root)
		return false;
	if(root->data == key)
	{
		return true;
	}
	if(printPaths(root->left,key) ||printPaths(root->right,key))
	{
		//cout << root->data <<" ";
		stack1.push(root->data);
		return true;
	}
	return false;

}



int findPivot(int arr[],int low, int high)
{
	int i;
	 for (i = low; i < high; ++i)
	 {
		 if(arr[i]  > arr[i+1])
			 break;	

	 }
	  return i;
		
}
// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{
   // Sort arrival and departure arrays
   //sort(arr, arr+n);
   //sort(dep, dep+n);
 
   // plat_needed indicates number of platforms needed at a time
   int plat_needed = 1, result = 1;
   int i = 1, j = 0;
 
   // Similar to merge in merge sort to process all events in sorted order
   while (i < n && j < n)
   {
      // If next event in sorted order is arrival, increment count of
      // platforms needed
      if (arr[i] < dep[j])
      {
          plat_needed++;
          i++;
          if (plat_needed > result)  // Update result if needed
              result = plat_needed;
      }
      else // Else decrement count of platforms needed
      {
          plat_needed--;
          j++;
      }
   }
 
   return result;
}

int BinaryToDecimal(int bin[])
{
    int i = 0, decimal = 0;
    for(; i < (sizeof bin/sizeof *bin); i++)
    {
        decimal = (decimal<<i)| bin[i];
    }
   
    return decimal;
}


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int aqwwqq() 

{

	string  str= "I use this to split string by a delim";
	vector<string> myvector;
	split(str,' ',myvector);


	

	int arr[4][3] = {{1,0,1},{1,0,0},{1,1,0},{1,1,1}};
	int decimal = 0;

	map<int,int> mymap;
    mymap[1] = 10;
	mymap[2] = 20;
	mymap[3] = 30;
	cout << mymap[2];
//	cout <<mymap.at(4);

	int row = 0, col = 0;
	for(row = 0; row < 4; row++)
	{
		decimal = 0;
	    
        for(int i = 0; i < 3; i++)
		{
		decimal = (decimal<<1)| arr[row][i]; 
		}
		cout <<row << " "<<decimal<< endl;
		mymap.insert(pair<int,int>(decimal,row));
		
	
	}

	map<int,int>::reverse_iterator it=mymap.rbegin();
	cout << " Row:" << it->second  << " " <<"Value:"<<it->first;

/*
 int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
		 */

  tree *root1 = new tree(2);
  root1->left = new tree(1);
  root1->right = new tree(3);
  printPretty(root1, 3, 0, cout);
  mirror(root1);
  printPretty(root1, 3, 0, cout);


//  int arr[] = { 4,5,6,1,3};
//  int array_size = sizeof arr/sizeof *arr;
 // cout << findPivot(arr,0,array_size-1);

 // int arr1[] = { 1,2,3,4,5,6,7};
//tree* test = buildTreeFromArray(arr1,0,6);
//printPaths(test,7);
  cout<<"===============Binary Tree Representation ========================="<<endl;
//  printPretty(test, 3, 0, cout);
  cout<<"===================================================================="<<endl;
  //LevelOrderUsing2Queues(root1);
  //printLevelOrderZigZag(root1);
  cout<<"\n";
 //printlevelorder(root1);
 // reverselevelorder(root1);


/*
  

  cout<<"Given Node Level is :"<<getLevel(root1,10)<<endl;

  tree *root2 = new tree(8);
  root2->left = new tree(4);
  root2->right = new tree(9);
*/



 //NthLargest(root,6);  
  cout<<endl;

  
  //cout<<"\n/*===============Inoder Traversal====================*/"<<endl<<endl;
  //inorder(root);
  //cout<<endl;
  //cout<<"\n/*===============Preorder Traversal==================*/"<<endl<<endl;
  //preorder(root);
  //cout<<endl<<endl;
  //cout<<"\n/*===============Height of the Tree==================*/"<<endl<<endl;
  //cout<<height(root)-1;
  //cout<<"\n/*=================Leaf Nodes in the Tree=============*/"<<endl<<endl;
  //printLeafNodes(root);
  //cout<<endl<<endl;
  //cout<<"\n/*=================Diameter of  the Tree=============*/"<<endl<<endl;
  //cout<<diameter(root);
  //cout<<endl<<endl;
  if(isBST(root1,1,4))
  cout<<endl<<"Yes BST";
  else
  cout<<endl<<"Not BST";

/*
  int inorder[] = { 22,11,33};
int preorder[] = {11,22,33};
  printPretty(buildTree(inorder,preorder,0,2),1,0,cout);

  //bt2DoubleLinkedList(root);
  //printList(root);


  root->left->left = new tree(40);
  root->left->right = new tree(30);
   root->right->left = new tree(30);
  root->right->right = new tree(40);
  
  



  
  cout<<"\n=========Original Tree:===================\n";
  printPretty(root, 1, 0, cout);
  mirror(root);
  cout<<"\n==========Mirrored Tree:=================\n";
  printPretty(root, 1, 0, cout);
  if(mirrorEquals(root->left,root->right))
  {
	  cout<<"\n Mirror Equals";
  }
  else
  {
	  cout<<"\n Mirror Not Equal";
  }

  cout<<endl;
  */
  return 0;

}
