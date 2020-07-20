#include <iostream>
#include <queue>



template <typename T>
class BTPointers{
    private:
        struct Node{
            T key; //Value inside a node
            Node* left;  //Pointer to left subtree
            Node* right; //Pointer to the right subtree
        };
       
        Node* root;

        /**
         * @brief Creates a new node in the tree.
         * @param key Value to be inserted into the node.
         * @return The newly created node.
         */
        Node* getNode(const T key){
            Node* newNode = new Node();
            newNode->key = key;
            newNode->left = NULL;
            newNode->right = NULL;

            return newNode;
        }

    public:


        BTPointers(){
            root = NULL;
        }

        /**
         * @brief Adds a node to the tree at the first available position.
         * @param value The value to be added to the tree.
         */
        void addNode(const T value){
            if(root == NULL){
                root = getNode(value);
            }
            else{
                //Looks through the tree and finds the first available position to add the node
                //From left to right.
                std::queue<Node*> q;
                q.push(root);
                while(!q.empty()){
                    Node* temp = q.front();
                    q.pop();
                    if(temp->left == NULL){
                        temp->left = getNode(value);
                        break;
                    }
                    else if(temp->right == NULL){
                        temp->right = getNode(value);
                        break;
                    }
                    else{
                        q.push(temp->left);
                        q.push(temp->right);
                    }
                }             
            }
            return;
        }

        /**
         * @brief Uses a queue to print the tree with Breadth First Traversal
         */
        void printBFS(){
            if(root == NULL) return;
            else{
                std::queue<Node*> q;
                q.push(root);
                while(!q.empty()){
                    Node* temp = q.front();
                    q.pop();
                    std::cout << temp->key << " ";
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right != NULL) q.push(temp->right);
                }
            }
        }

        /**
         * @brief Prints the farthest right element in the tree.
         */
        void printDeepestRight(){
            if(root == NULL) return;
            else{
                Node* temp = root;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                std::cout << temp->key;
                return;
            }

        }


};


int main(){
    BTPointers<char> tree;
    tree.addNode('F');
    tree.addNode('B');
    tree.addNode('G');
    tree.addNode('K');
    tree.addNode('I');
    tree.addNode('H');
    tree.addNode('L');

    
    

    tree.printBFS();
    std::cout << std::endl;
    tree.printDeepestRight();

    return 0;
}




