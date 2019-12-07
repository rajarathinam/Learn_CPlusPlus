#include "stub.h"
#include <sstream>
struct Tree
{
  int data;
  Tree *left;
  Tree *right;
  Tree *nextRight;
  Tree(int val) : left(NULL), right(NULL),nextRight(NULL), data(val)
  { 
  }
};


unsigned short int  height(Tree* root)
{
    
	if(!root)
	  return 0;
   queue<Tree*> Q;
   int level = 0;
   Q.push(root);
   Q.push(NULL);
   while(!Q.empty())
   {
	   root = Q.front();
	   Q.pop();
	   
	   if(root == NULL)
	   {
		   level++;
		   if(!Q.empty())
			   Q.push(NULL);
	   }
	   else
	   {
	   if(root->right)
		   Q.push(root->right);
	   if(root->left)
		   Q.push(root->left);
	   }

   }
   return level;
	/*
  if(!root)
	  return 0;
  unsigned short int leftheight = height(root->left);
  unsigned short int rightheight = height(root->right);
  if(leftheight>rightheight)
  {
	  return (leftheight+1);
  }
  else
  {
	return (rightheight+1);
  }
  */

}

// Convert an integer value to string

static string intToString(int val) 

{

  ostringstream ss;

  ss << val;

  return ss.str();

}



// Print the arm branches (eg, /    \ ) on a line

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Tree*>& nodesQueue, ostream& out) 

{

  deque<Tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel / 2; i++) {  

    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");

    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");

  }

  out << endl;

}



// Print the branches and node (eg, ___10___ )

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Tree*>& nodesQueue, ostream& out) 

{

  deque<Tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel; i++, iter++) {

    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));

    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");

    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');

  }

  out << endl;

}



// Print the leaves only (just for the bottom row)

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Tree*>& nodesQueue, ostream& out) 

{

  deque<Tree*>::const_iterator iter = nodesQueue.begin();

  for (int i = 0; i < nodesInThisLevel; i++, iter++) {

    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");

  }

  out << endl;

}

void printPretty(Tree *root, int level, int indentSpace, ostream& out) 

{

  int h = height(root);

  int nodesInThisLevel = 1;



  int branchLen = 2*((1<<h) -1) - (3-level)*(1<<h-1);  // eq of the length of branch for each node of each level

  int nodeSpaceLen = 2 + (level+1)*(1<<h);  // distance between left neighbor node's right arm and right neighbor node's left arm

  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

    

  deque<Tree*> nodesQueue;

  nodesQueue.push_back(root);

  for (int r = 1; r < h; r++) {

    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    branchLen = branchLen/2 - 1;

    nodeSpaceLen = nodeSpaceLen/2 + 1;

    startLen = branchLen + (3-level) + indentSpace;

    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);



    for (int i = 0; i < nodesInThisLevel; i++) {

      Tree *currNode = nodesQueue.front();

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
/*----------------------------------------------------------
    Binary Tree - My Functions
 ------------------------------------------------------------*/

bool lookup(Tree* root, int key)
{
   if(root == NULL)
   {
	return false;
   }
   else
   {
	   if( root->data == key)
	   {
		   return true;
	   }
	   else
	   {
		   lookup(root->left,key);
		   lookup(root->right,key);
	   }
   }
   
}
unsigned short int size(Tree* root)
{
	if(!root)
	{
		return 0;
	}
	queue<Tree*> Q;
	Tree* temp;
	int count = 0;
	Q.push(root);
	while(!Q.empty())
	{
       temp = Q.front();
	   Q.pop();
	   count++;
	   if(temp->left)
		   Q.push(temp->left);
	   if(temp->right)
		   Q.push(temp->right);
	}
	return count;
	/*
	if(!root)
	{
		return 0;
	}
	return( size(root->left) + 1 + size(root->right));
	*/

}
void preordertraversal_recursive(Tree* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preordertraversal_recursive(root->left);
		preordertraversal_recursive(root->right);
	}


}
void preordertraversal_nonrecursive(Tree* root)
{
	if(!root)
		return;
	stack<Tree*> S; 
	while(1)
	{
		while(root)
		{
			cout<<root->data<<" ";
			S.push(root);
			root = root->left;
		}
		if(S.empty())
			break;
		root = S.top();
		S.pop();
		root = root->right;
	}
	/*stack<Tree*>  S;
	if(root)
	{
		 
		 S.push(root);
	}
	while( !S.empty())
	{
		
		root = S.top();
		cout<<root->data<<" ";
		S.pop();
		
		if(root->right)
		{
			S.push(root->right);
		}

		if(root->left)
		{
			S.push(root->left);
		}
	
		
	}
	*/


}
void inordertraversal_recursive(Tree* root)
{
	if(root)
	{
		inordertraversal_recursive(root->left);
		cout<<root->data<<" ";
		inordertraversal_recursive(root->right);
	}


}
void inordertraversal_nonrecursive(Tree* root)
{
	
	if(!root)
		return;
	stack<Tree*> S; 
	while(1)
	{
		while(root)
		{
			cout<<root->data<<" ";
			S.push(root);
			root = root->left;
		}
		if(S.empty())
			break;
		root = S.top();
		S.pop();
		root = root->right;
	}
	/*stack<Tree*>  S;

	while(1)
	{
		
		while(root)
		{
		
			S.push(root);
			root = root->left;		
		}
		if(S.empty())
		{
			break;
		}
		else
		{
			root  = S.top();
			S.pop();
			cout<<root->data<<" ";
			root = root->right;
			
		}
		
	}
	*/


}
void postordertraversal_nonrecursive(Tree* root)
{
	
	// Check for empty tree
    if (root == NULL)
        return;
     
    stack<Tree*> S;
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
				S.push(root->right);
            S.push(root);
 
            // Set root as root's left child 
            root = root->left;
        }
 
        // Pop an item from stack and set it as root   
        root = S.top();
		S.pop();
 
        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && S.top() == root->right)
        {
            S.pop();// remove right child from stack
            S.push(root);  // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            cout<<root->data<<" ";
            root = NULL;
        }
    } while (!S.empty());
	
		


}
void ReverseLevelOrderTraversal(Tree* root)
{
	if(!root)
		return;
	queue<Tree*> Q;
	stack<Tree*> S;
	Q.push(root);
	while(!Q.empty())
	{
		Tree* temp = Q.front();
		Q.pop();
		S.push(temp);
		
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
	while(!S.empty())
	{
		cout<<S.top()->data<<" ";
		S.pop();
	}
	/*
	if(!root)
		return;
	queue<Tree*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Tree* temp = Q.front();
		Q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
	*/
}
signed  short int FindMax(Tree *root)
{
	if(!root)
		return -1;
	signed  short int max = root->data;
	queue<Tree*> Q;
	Q.push(root);
	while( !Q.empty())
	{
		Tree* temp = Q.front();
		Q.pop();
		if(temp->data > max)
			max = temp->data;
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);

	}
	return max;
}

signed  short int FindMin(Tree *root)
{
	if(!root)
		return -1;
	signed  short int min = root->data;
	queue<Tree*> Q;
	Q.push(root);
	while( !Q.empty())
	{
		Tree* temp = Q.front();
		Q.pop();
		if(temp->data < min)
			min = temp->data;
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);

	}
	return min;
}

bool IsElementFound(Tree* root, int key)
{

	if(!root)
		return false;
	
	queue<Tree*> Q;
	Q.push(root);
	while( !Q.empty())
	{
		Tree* temp = Q.front();
		Q.pop();
		if(temp->data == key)
			return true;
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);

	}
	return false;
}

void DestrcutTree(Tree* root)
{
	if(!root)
		return;
	queue<Tree*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Tree *temp = Q.front();
		Q.pop();
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
		delete temp;
	}
}

Tree* DeepestNode(Tree* root)
{
		if(!root)
		return NULL;
	queue<Tree*> Q;
	Tree *temp;
	Q.push(root);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
		
	}
	return temp;
}
void printPath(Tree* root, int target)
{
 static bool success  = 0;
 if(root==NULL)
return;

 if(root->data == target)
 {
	 success = 1;
	 
	 return ;
 }
 if(1 != success)
 {
	printPath(root->left,target);
 }
  if(1 != success)
 {
	printPath(root->right,target);
 }
  if(1 == success)
 { 
  cout<<root->data<<"->";
  }
}

Tree* cloneTree(Tree* root)
{
	if( NULL == root)
		return NULL ;
	Tree* temp = new Tree(root->data);
	temp->left = cloneTree(root->left);
	temp->right = cloneTree(root->right);
	return temp;
}
Tree* mirrorTree(Tree* root)
{
	if(root == NULL)
		return NULL;
	stack<Tree*> s;
	s.push(root);
	
	while(!s.empty())
	{
		Tree* temp = s.top();
		s.pop();
		swap(temp->left,temp->right);
		if(temp->left)
			s.push(temp->left);
		if(temp->right)
		s.push(temp->right);

	}
	return cloneTree(root);
}
bool mirrorEquals(Tree* bt1, Tree* bt2)
{
	if( bt1 == NULL || bt2 == NULL)
		return (bt1 == NULL && bt2 == NULL);
	return ( bt1->data == bt2->data && mirrorEquals(bt1->left,bt2->right)
									&& mirrorEquals(bt1->right,bt2->left));
}

void doubleTree(Tree* root)
{
	if(NULL == root)
	{
		return;
	}
	doubleTree(root->left);
	doubleTree(root->right);
	Tree *oldleft = root->left;
	root->left= new Tree(root->data);
	root->left->left = oldleft;

}
bool EqualTrees(Tree* bt1, Tree *bt2)
{
	if( NULL == bt1 && NULL == bt2)
	{
		return (true);
	}
	else if( bt1 && bt2)
	{
	return ( (bt1->data == bt2->data) && EqualTrees(bt1->left,bt2->left) && EqualTrees(bt1->right,bt2->right));
	}
	
	return false;
	
	
}
void printleaves(Tree* root)
{
	stack<Tree*> S;
	if(root == NULL)
		return;

	S.push(root);
	while( !S.empty())
	{
		Tree* temp = S.top();
		S.pop();
		if( temp->left == NULL && temp->right == NULL)
		{
			cout<<temp->data<<" ";
		}
		if(temp->right)
			S.push(temp->right);
		if(temp->left)
			S.push(temp->left);
		
	}
}
unsigned int DiameterOfTree(Tree* root)
{
	if(!root)
		return 0;
     int left_height = height(root->left);
	 int right_height = height(root->right);
	int left_max_length = DiameterOfTree(root->left);
	int right_max_length = DiameterOfTree(root->right);
	
	return (max( left_height+right_height+1,max(left_max_length,right_max_length)));

}
/*The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. So, function should be used as follows:
 
   int height = 0;
   struct node *root = SomeFunctionToMakeTree();
   int diameter = diameterOpt(root, &height); */
int diameterOpt(Tree *root, int* height)
{
  /* lh --> Height of left subtree
      rh --> Height of right subtree */
  int lh = 0, rh = 0;
  
  /* ldiameter  --> diameter of left subtree
      rdiameter  --> Diameter of right subtree */
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0; /* diameter is also 0 */
  }
  
  /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);
  
  /* Height of current node is max of heights of left and
     right subtrees plus 1*/
  *height = max(lh, rh) + 1;
  
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}
/* Prototypes for funtions needed in printPaths() */
void printPathsRecur(Tree* node, int path[], int pathLen);
void printArray(int ints[], int len);
 
/*Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.*/
void printPaths(Tree* node)
{
  int path[1000];
  printPathsRecur(node, path, 0);
}
 
/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.*/
void printPathsRecur(Tree* node, int path[], int pathLen)
{
  if (node==NULL)
    return;
 
  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;
 
  /* it's a leaf, so print the path that led to here  */
  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
 
 
/* UTILITY FUNCTIONS */
/* Utility that prints out an array on a line. */
void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++)
  {
    printf("%d ", ints[i]);
  }
  printf("\n");
}   
 

int hasPathSum(Tree* node, int sum) {
  // return true if we run out of tree and sum==0
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  // otherwise check both subtrees
    int subSum = sum - node->data;
    return(hasPathSum(node->left, subSum) ||
           hasPathSum(node->right, subSum));
  }
}
  
string removeDups(string str)
{
	map<char,int> my_map;
	int i=0, len = str.length()-1;
	while(i<=len)
	{
		if(!my_map[str[i]])
		{
			my_map[str[i]] = 1;
			i++	;
		}
		else
		{
			str.erase(i,1);
			len--;
		}
	}
	return str;
}

void connect(Tree* root)
{
	if(!root)
		return;

	if(root->left)
		root->left->nextRight = root->right;
	if(root->right)
		root->right->nextRight = (root->nextRight) ? root->nextRight->left:NULL;
	connect(root->left);
	connect(root->right);
}
void connect_iterative(Tree* root)
{
	if(!root)
	{
		return;
	}
	queue<Tree*> Q;
	Tree* temp;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty())
	{
		temp = Q.front();Q.pop();
		if(temp == NULL)
		{
		}
		else
		{

		}
	}

}
int getIndex(int* arr, int val, int size)

{

    for(int i=0; i<size;i++) {

        if(arr[i] == val) 

            return i;

    }

    return -1;

}

 
Tree* buildTree1( int* preorder, int* inorder,int size)
{
	if( 0 == size)
		return NULL;
	int rootData = preorder[0];
	Tree* root = new Tree(rootData);
	int rootIndex = getIndex(inorder,rootData,size);
	root->left = buildTree1(preorder+1,inorder,rootIndex);
	root->right = buildTree1(preorder+1+rootIndex,inorder+1+rootIndex,size - 1-rootIndex);
	return root;
}

Tree* buildTree( int* postorder, int* inorder,int size)
{
	if( 0 == size)
		return NULL;
	int rootData = postorder[size-1];
	Tree* root = new Tree(rootData);
	int rootIndex = getIndex(inorder,rootData,size);
	root->left = buildTree(postorder,inorder,rootIndex);
	root->right = buildTree(postorder+rootIndex,inorder+1+rootIndex,size - 1-rootIndex);
	return root;
}

//print Ancestors of a given node
bool PrintAncestors(Tree* root, int key)
{
	if( NULL == root)
		return false;
	if( key == root->data)
		return true;
	if( PrintAncestors(root->left,key) || PrintAncestors(root->right,key))
	{
		cout<<" "<<root->data;
		return true;
	}
}
void ZigZagTraversal(Tree* root)
{
	
	stack<Tree*> s1;
	stack<Tree*> s2;
	Tree* current;
	s1.push(root);
	do
	{
		
		while(!s1.empty())
		{
			current = s1.top();s1.pop();
			cout<<current->data<<" ";
			s2.push(current->left);
			s2.push(current->right);
		}
		while(!s2.empty())
		{
			current = s2.top();s2.pop();
			cout<<current->data<<" ";
			s1.push(current->right);
			s1.push(current->left);
		}
	}while(!s1.empty() || !s2.empty());

  
}
void compute_vertical_sum(Tree*node, int index,int vertical_sum[])
{
if( node == NULL ) return;
vertical_sum[index] += node->data;
compute_vertical_sum( node->left, index-1,vertical_sum);
compute_vertical_sum( node->right, index+1,vertical_sum);
}
unsigned int sumofallgreaternodes(Tree*  node, int sum)
{
	if( NULL == node)
		return sum;
	sum += node->data;
	int right_sum = sumofallgreaternodes(node->right,sum);
    
	int left_sum = sumofallgreaternodes(node->left,sum);
	
}

void printVertical(Tree *root)
{
	if( NULL == root)
	{
		cout << " Tree is Empty";
	}

	

}

class X
{
public:
	X()
	{
		cout << " X's constructor " <<"\n";
	}
	X(const X& rhs)
	{
		cout << "X's copy constructor" <<"\n";
	}
	X& operator=(const X& rhs)
	{
         cout << "X's Assignment operator" <<"\n";
		
		return *this;
	}
	void display()
	{
		cout << "Display()"<<endl;
	}
	X* operator->()
	{
     return this;
	}
	~X()
	{
		cout << "X's Destructor" << "\n";
	}
};

class A{};
int wwejoke()
{
	
   



	int preorder[] = { 1,2,4,5,3};
	int inorder[] = { 4,2,5,1,3};


Tree* root= buildTree1(preorder,inorder,5);
		
			printPretty(root,3,3,cout);
			/*
 int h=height(root);
  int max_width_possible=2*h+1;

  compute_vertical_sum(root, h,vertical_sum);
 
  for(int i=0; i <max_width_possible; i++)
     if ( vertical_sum[i] > 0 )
          printf("%d  ",vertical_sum[i]);
		  */

	



	cout<<"\n";

	/*
	cout<<"\n Height:"<<height(root)<<"\n";
	cout<<"Number of Nodes in Binary Tree:"<<size(root)<<"\n";
	cout<<"Height of the Tree:"<<height(root);
	cout<<"\nPreorder Traversal:\n";
	preordertraversal_nonrecursive(root);
	cout<<"\nIneorder Traversal:\n";
	inordertraversal_nonrecursive(root);
	//cout<<"\nPostorder Traversal:\n";
	//postordertraversal_nonrecursive(root);
	cout<<"\nLevel Order Traversal:\n";
	ReverseLevelOrderTraversal(root);
	cout<<"\n Max Element in the Tree:\n";\
    cout<<FindMax(root)<<"\n";
	cout<<"\n Min Element in the Tree:\n";\
    cout<<FindMin(root)<<"\n";
	if(IsElementFound(root,20))
	{
		cout<<"Element Found\n";
	}
	else
	{
		cout<<"Element Not Found\n";
	}
	Tree* deepnode=DeepestNode(root);
	if(deepnode)
	{
		cout<<"Deepest Node Data:"<<deepnode->data<<"\n";
	}
	cout<<"Print Nodes in the Path:";
	printPath(root,55);

	if(lookup(root,10))
	{
		cout<<"Found\n";
	}
	else
	{
		cout<<"Not Found\n";
    }*/
	
	
	DestrcutTree(root);
	cout<<"\n\n\n";
	return 0;
}
