#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class node {
public:
	T data;
	node<T>* left;
	node<T>* right;

	node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};


// void helper( node<int>* root , bool& pbool , int p , bool& qbool , int q , int& count ){
//     // base case
//     count++;
//     if( root == nullptr ){
//         return;
//     }
//     if( pbool && qbool ){
//         cout << "value found" << endl;
//         cout << count << endl;
//         return;
//     }
    
//     if( root -> val == p ){
//         pbool = true;
//     }
//     if( root -> val == q ){
//         qbool = true;
//     }
//     // recursive case
//     helper( root-> left , pbool , p , qbool , q , count );
//     helper( root-> right , pbool , p , qbool , q , count );
    
    
// }

void helper1( node<int>* root , vector<int>& v ){
        queue<node<int>*> q ;
        q.push(root);
        q.push(NULL);
        cout << root -> data << " ";
        // v.push_back(root->data);
        while(!q.empty()){
            if( q.front() == NULL ){
                node<int>* temp = q.front();
                q.pop();
                
                // v.push_back(0);
                if( q.empty() ){
                    return;
                }else{
                    // node<int> 
                    cout << q.front()->data << " ";
                    q.push(NULL);
                }
            }else{
                node<int>* temp = q.front();
                q.pop();
                // v.push_back(temp->data);
                if( temp -> left ){
                    q.push(temp->left);
                }
                if( temp -> right ){
                    q.push(temp-> right);
                }
            }    
        }
        return;
    }

int main() {

	node<int>* root = NULL; // initially, the tree is empty

	root = new node<int>(10);
	root->left = new node<int>(20);
	root->right= new node<int>(30);
	root->left->left = new node<int>(40);
	root->left->right = new node<int>(50);
	root->right->right =new node<int>(60);
	root->left->right->left = new node<int>(70);

//       10
//     20    30
//  40  50   n  60
// n n 70 n n n n n 
    bool pbool = false ;
    bool qbool = false ;
    int count = 0;
// 	helper( root , pbool , 50 , qbool , 70 , count );

    vector<int> v;
    helper1( root , v );
    
	return 0;
}
