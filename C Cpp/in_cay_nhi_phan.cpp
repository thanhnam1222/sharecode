/*
Tham khảo :
+ In xoay 90 độ (dễ thực hiện)
      7
   4
5
      1
   3
      8
	  
+ In theo chiều dọc (dễ hình dung hơn)
https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
               1
             2   3
               4   5
    
	//        1
    //       / \ 
    //      2   3
    //         / \  
    //        4   5			   


https://github.com/afkbrb/binary-tree-printer
                        50                        
                       / \                               
                      /   \                                      
                     /     \                                    
                    47     53                                     
                   / \     /                                      
                  /   \   52                                      
                 42   49 /                                        
                / \   / 51                                        
               41 43 48          

+ In theo dạng horizontal tree, giống lệnh tree trong DOS/WIN, Linux
https://www.baeldung.com/java-print-binary-tree-diagram

========================================	
Các bài toán với Cây nhị phân
+https://www.geeksforgeeks.org/binary-tree-data-print_tree/?ref=shm

=====================
Chi tiết

+ In xoay 90 độ (dễ thực hiện)

Cách 1: 
class Node{
   public:
      int data;
      Node* left, *right;
      Node(int data){
         this->data = data;
         this->left = NULL;
         this->right = NULL;
      }
};

void printTree(Node *root, int space){
   if (root == NULL)
      return;
   space += COUNT;
   printTree(root->right, space);
   for (int i = COUNT; i < space; i++)
      cout<<"\t";
   cout<<root->data<<"\n";
   printTree(root->left, space);
}

int main(){
   Node *root = new Node(43);
   root->left = new Node(25);
   root->right = new Node(67);
   root->left->left = new Node(14);
   root->left->right = new Node(51);
   root->right->left = new Node(26);
   root->right->right = new Node(97);
   
   printTree(root, 0);
   return 0;
}

Cách 2
void padding ( char ch, int n )
{
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void print_tree ( struct node *root, int level )
{
  int i;

  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    print_tree ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->info );
    print_tree ( root->left, level + 1 );
  }
}

int main ( void )
{
  struct node *tree = NULL;

  /* insert data ... * /

  print_tree ( tree, 0 );

  /* ... * /
}

===============================================

+ In theo chiều dọc (dễ hình dung hơn)
               1
             2   3
               4   5
    
	//        1
    //       / \ 
    //      2   3
    //         / \  
    //        4   5			   
	
https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/

https://algo.monster/liteproblems/655
Giải pháp: chuyển dữ liệu cây nhị phân sang dạng ma trận (mảng 2 chiều)
=> in ma trận
Ví dụ: Cây nhị phân 
	//        1
    //       / \ 
    //      2   3
    //         / \  
    //        4   5	

Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","","","4","","5"]]

	//        1
    //           
    //      2   3
    //              
    //        4   5	

Tham khảo Chi tiết: https://leetcode.com/problems/print-binary-tree/description/
*/