
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Stack{
	private:
		int array[5];
		int top;

	public:
		Stack(){
			top = -1;
			for (int x = 0; x <= 5; x++){
				array[x] = 0;
			}
		}

		/**
		 * @brief Checks if the stack is empty.
		 * @return If the stack is empty.
		 */
		bool isEmpty(){
			if (top == -1) return true;
			else return false;
		}

		/**
		 * @brief Checks if the stack is full.
		 * @returns If the stack is full.
		 */
		bool isFull(){
			if (top == 4) return true;
			else return false;
		}


		/**
		 * @brief Pushes data onto the stack.
		 * @param data The data to be added to the stack.
		 */
		void push(int data){
			if (isFull()){
				cout << "Stack Is Full" << endl;
			}
			else{
				top++;
				array[top] = data;
			}
		}


		/**
		 * @brief Removes the data from the top of the stack.
		 * @return Data that was removed from the stack.
		 */
		int pop(){
			if (isEmpty()){
				cout << "The Stack is already empty." << endl;
				return 0;
			}
			else{
				int dataOut = array[top];
				array[top] = 0;
				top--;
				return dataOut;
			}
		}


		/**
		 * @brief Gets the total number of items in the stack.
		 * @return The total number of items in the stack.
		 */
		int count(){
			return top + 1;
		}

		/**
		 * @brief Retrieves the value at the specified position.
		 * @param pos The position of the value
		 * @return The value at the position.
		 */
		int peek (int pos){
			if (isEmpty()){
				cout << "The Stack is already empty." << endl;
				return 0;
			}
			return array[pos];
		}


		/**
		 * @brief Change the value at a position
		 * @param pos The position of the data.
		 * @param data The data to be added.
		 */
		void change(int pos, int data){
			array[pos] = data;
			cout << "Value changed at Index" << pos << endl;
		}


		/**
		 * @brief Prints the entire stack
		 */
		void printStack(){
			if (isEmpty()){
				cout << "The Stack is already empty. " << endl;
			}
			else{
				int tempTop = top;
				while (tempTop >= 0){
					cout << array[tempTop] << " ";
					tempTop--;
				}
			}
		}
};

	