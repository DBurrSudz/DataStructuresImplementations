
#include <iostream>
#include <queue>

/**
 * @class BTArray
 * @author Daniel Burrell
 * @date 21/05/2020
 * @file main.cpp
 * @brief Creates an empty Binary Tree using an encapsulated array implementation.
 */
template <typename T, int N>
class BTArray{
    private:
    int count;
    T tree[N];

    /**
     * @brief Prints the tree by level using a queue data structure.
     * @param root The root of the tree.
     */
    void traverseBFS(int root){
        if(tree[root] == '\0' || root > count){
            return;
        }
        else{
            std::queue<int> q;
            q.push(root);
            while(!q.empty()){
                int frontValue = q.front();
                q.pop();
                std::cout << tree[frontValue] << " ";
                if(tree[(frontValue * 2) + 1] != '\0' && (frontValue * 2) + 1 < count) q.push((frontValue * 2) + 1);
                if(tree[(frontValue * 2) + 2] != '\0' && (frontValue * 2) + 2 < count) q.push((frontValue * 2) + 2);
            }
        }
    }


    /**
     * @brief Recursively traverses the tree from Root -> Left -> Right
     * @param root The root of tree.
     */
    void preorderTraversal(int root){
        if(tree[root] == '\0' || root > this->count){
            return;
        }
        else{
            std::cout << tree[root] << " ";
            preorderTraversal((root * 2) + 1); //Passing in the index of the left child of the root/parent.
            preorderTraversal((root * 2) + 2); //Passing in the index of the right child of the root/parent.
        }
    }


    /**
     * @brief Recursively traverses the tree from Left -> Root -> Right
     * @param root The root of the tree.
     */
    void inorderTraversal(int root){
        if(tree[root] == '\0' || root > this->count){
            return;
        }
        else{
            inorderTraversal((root * 2) + 1); //Passing in the index of the left child of the root/parent.
            std::cout << tree[root] << " ";
            inorderTraversal((root * 2) + 2); //Passing in the index of the right child of the root/parent.
        }
    }


    /**
     * @brief Recursively traverses the tree from Left -> Right -> Root
     * @param root The root of the tree.
     */
    void postorderTraversal(int root){
        if(tree[root] == '\0' || root > this->count){
            return;
        }
        else{
            postorderTraversal((root * 2) + 1); //Passing in the index of the left child of the root/parent.
            postorderTraversal((root * 2) + 2); //Passing in the index of the right child of the root/parent.
            std::cout << tree[root] << " ";
        }
    }


    public:
    BTArray(){
        this->count = N;
        for(int i = 0; i < N;i++){
            tree[i] = '\0';
        }
    }

    /**
     * @brief Inserts the root of the tree if one is not present.
     * @param value The value to be inserted in the root of the tree.
     */
    void addRoot(const T value){
        if(tree[0] == '\0'){
            tree[0] = value;
            std::cout << "Root of the tree successfully added." << std::endl;
        }
        else{
            std::cout << "Unable to add the root of the tree." << std::endl;
            return;
        }
    }

    /**
     *
     * @brief Returns the root of the entire tree if one is present.
     * @return The root of the tree.
     */
    const T getTreeRoot(){
        if(tree[0] != '\0') return tree[0];
        else{
            std::cout << "Unable to get the root of this tree." << std::endl;
            return -1;
        }
    }


    /**
     * @brief Adds the left child of a node.
     * @param value The value to be added.
     * @param parentIndx The index of the parent for the child node.
     */
    void addLeftChild(const T value, int parentIndx){
        if(tree[parentIndx] != '\0' && (parentIndx * 2) + 1 < count && tree[(parentIndx * 2) + 1] == '\0' && parentIndx < count){
            tree[(parentIndx * 2) + 1] = value;
            std::cout << "Child Added." << std::endl;
        }
        else{
            std::cout << "Unable to add left child of this parent node." << std::endl;
        }
    }


    /**
     * @brief Adds the right child of a node.
     * @param value The value to be added.
     * @param parentIndx The index of the parent for the child node.
     */
    void addRightChild(const T value, int parentIndx){
        if(tree[parentIndx] != '\0' && ((parentIndx * 2) + 2) < count && tree[(parentIndx * 2) + 2] == '\0' && parentIndx < count){
            tree[(parentIndx * 2) + 2] = value;
            std::cout << "Child Added." << std::endl;
        }
        else{
            std::cout << "Unable to add right child of this parent node." << std::endl;
        }
    }


    /**
     * @brief Gets the left child of a specified parent.
     * @param parentIndx The index of the parent for the child node.
     * @return Left child of the parent.
     */
    const T getLeftChild(int parentIndx){
        if(tree[parentIndx] != '\0' && ((parentIndx * 2) + 1) < this->count && tree[(parentIndx * 2) + 1] != '\0'){
            return tree[(parentIndx * 2) + 1];
        }
        else{
            std::cout << "Unable to retrieve left child of this parent." << std::endl;
            return -1;
        }
    }


    /**
     * @brief Gets the right child of a specified parent.
     * @param parentIndx The index of the parent for the child node.
     * @return Right child of the parent.
     */
    const T getRightChild(int parentIndx){
        if(tree[parentIndx] != '\0' && ((parentIndx * 2) + 2) < this->count && tree[(parentIndx * 2) + 2] != '\0'){
            return tree[(parentIndx * 2) + 2];
        }
        else{
            std::cout << "Unable to retrieve right child of this parent." << std::endl;
            return -1;
        }
    }


    /**
     * @brief Gets the parent of a specified child.
     * @param childIndx The index of the child in the tree.
     * @return Parent of the child.
     */
    const T getParent(int childIndx){
        if(tree[childIndx] != '\0' && childIndx < this->count && tree[(childIndx - 1)/2] != '\0'){
            return tree[(childIndx - 1) /2];
        }
        else{
            std::cout << "Unable to get the parent of this child." << std::endl;
            return -1;
        }
    }

    /**
     * @brief Traverses the tree by level.
     */
    void traverseBFS(){
        traverseBFS(0);
    }

    /**
     * @brief Traverses the tree in Preorder Fashion (Root -> Left -> Right)
     */
    void preorderTraversal(){
        preorderTraversal(0);
    }

    /**
     * @brief Traverses the tree in Inorder Fashion (Left -> Root -> Right)
     */
    void inorderTraversal(){
        inorderTraversal(0);
    }


    /**
     * @brief Traverses the tree in Postorder Fashion (Left -> Right -> Root)
     */
    void postorderTraversal(){
        postorderTraversal(0);
    }


    /**
     * @brief Gets the binary tree represented in array form.
     * @return A pointer to the binary tree array of values.
     */
    const T * returnTree(){
        return tree;
    }


    /**
     * @brief Gets the value of the node at a certain index in the tree.
     * @param index The index of the node.
     * @return The value at the specified index.
     */
    const T getValue(int index){
        return tree[index];
    }


    /**
     * @brief Gets the size of the array.
     * @return The size of the array.
     */
    const int getSize(){
        return N;
    }


};


int main(){

    BTArray<char,7> tree;
    tree.addRoot('F');
    tree.addLeftChild('C',0);
    tree.addRightChild('I',0);
    tree.addLeftChild('H',2);
    tree.addLeftChild('B',1);
    tree.addRightChild('E',1);
    tree.addRightChild('J',2);
    
    std::cout << "Breadth First Traversal (Level Order) of the tree: " << std::endl;
    tree.traverseBFS();
    std::cout << std::endl;

    std::cout << "Preorder Traversal of the tree: " << std::endl;
    tree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Inorder Traversal of the tree: " << std::endl;
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder Traversal of the tree: " << std::endl;
    tree.postorderTraversal();
    std::cout << std::endl;
}
