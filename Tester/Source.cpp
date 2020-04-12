#include <iostream>

#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"



namespace my_adt {
	namespace stack {
		template <typename T>
		class Stack
		{
		private:
			struct Node
			{
				T data;
				Node* pNext;
			};
			Node* top_;
		public:
			Stack() { top_ = nullptr; }
			Stack(T data_) : Stack()
			{
				push(data_);
			}
			void push(T data_)
			{
				Node* obj = new Node;
				obj->data = data_;
				obj->pNext = top_;
				top_ = obj;
			}
			void pop()
			{
				if (top_ == nullptr) return;
				else
				{
					Node* obj = top_->pNext;
					delete top_;
					top_ = obj;
				}
			}
			T& top() { return top_->data; }
			~Stack() { while (top_ != nullptr) pop(); }
		};
	}
	namespace list {
		template<typename T>
		class List
		{
		private:
			class Node
			{
			public:
				T data;
				Node* pNext;

				Node(T data = T(), Node* pNext = nullptr)
				{
					this->data = data;
					this->pNext = pNext;
				}
			};
			Node* head;
			size_t size_;
		public:
			List()
			{
				size_ = 0;
				head = nullptr;
			}
			List(T data_) : List()
			{
				push_head(data_);
			}
			void push_head(T data)
			{
				head = new Node(data, this->head);
				++size_;
			}
			void push_fornt(T data)
			{
				Node* current = head;
				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				current->pNext = new Node(data);
				++size_;
			}
			void pop_head()
			{
				Node* obj = head;
				head = head->pNext;
				delete obj;
				--size_;
			}
			void insertAtPlusOne(T data, const size_t index)
			{
				size_t counter = 0;
				Node* current = this->head;
				while (current->pNext != nullptr)
				{
					if (counter == index)
					{
						current->pNext = new Node(data, current->pNext);
						++size_;
						return;
					}
					current = current->pNext;
					++counter;
				}
			}
			void removeAt(const size_t index)
			{
				if (index == 0) { pop_head(); }
				else
				{
					Node* prev = this->head;
					for (size_t i = 0; i < index - 1; ++i)
					{
						prev = prev->pNext;
					}
					Node* toDelete = prev->pNext;
					prev->pNext = toDelete->pNext;
					delete toDelete;
					--size_;
				}
			}
			T& operator[](const size_t index)
			{
				size_t counter = 0;
				Node* current = head;
				while (current->pNext != nullptr)
				{
					if (counter == index) return current->data;
					current = current->pNext;
					++counter;
				}
			}
			T& getHead() { return head->data; }
			size_t size() { return size_; }
			~List() { while (size_)	pop_head(); }
		};
	}
	namespace btree
	{
		template<typename T>
		struct Node
		{
			T data;
			Node* left;
			Node* right;
		};

		template<typename T>
		class BTree
		{
		public:
			BTree();
			~BTree();

			void insert(size_t key);
			Node<T>* search(size_t key);
			void destroy_tree();
			void inorder_print();
			void postorder_print();
			void preorder_print();

		private:
			Node<T>* root;

			void destroy_tree(Node<T>* leaf);
			void insert(size_t key, Node<T>* leaf);
			Node<T>* search(size_t key, Node<T>* leaf);
			void inorder_print(Node<T>* leaf);
			void postorder_print(Node<T>* leaf);
			void preorder_print(Node<T>* leaf);

		};


		template<typename T>
		BTree<T>::BTree()
		{
			root = nullptr;
		}

		template<typename T>
		BTree<T>::~BTree()
		{
			destroy_tree();
		}

		template<typename T>
		void BTree<T>::insert(size_t key)
		{
			if (root != nullptr) insert(key, root);
			else
			{
				root = new Node<T>;
				root->data = key;
				root->left = nullptr;
				root->right = nullptr;
			}
		}

		template<typename T>
		Node<T>* BTree<T>::search(size_t key)
		{
			return search(key, root);
		}

		template<typename T>
		void BTree<T>::destroy_tree()
		{
			destroy_tree(root);
		}

		template<typename T>
		void BTree<T>::inorder_print()
		{
			inorder_print(root);
			std::cout << "\n";
		}

		template<typename T>
		void BTree<T>::postorder_print()
		{
			postorder_print(root);
			std::cout << "\n";
		}

		template<typename T>
		void BTree<T>::preorder_print()
		{
			preorder_print(root);
			std::cout << "\n";
		}

		template<typename T>
		void BTree<T>::destroy_tree(Node<T>* leaf)
		{
			if (leaf != nullptr)
			{
				destroy_tree(leaf->left);
				destroy_tree(leaf->right);
				delete leaf;
			}
		}

		template<typename T>
		void BTree<T>::insert(size_t key, Node<T>* leaf)
		{
			if (key < leaf->data) {
				if (leaf->left != nullptr) insert(key, leaf->left);

				else {
					leaf->left = new Node<T>;
					leaf->left->data = key;
					leaf->left->left = nullptr;
					leaf->left->right = nullptr;
				}

			}
			else if (key >= leaf->data)
			{
				if (leaf->right != nullptr) { insert(key, leaf->right); }
				else {
					leaf->right = new Node<T>;
					leaf->right->value = key;
					leaf->right->right = nullptr;
					leaf->right->left = nullptr;
				}
			}




		}

		template<typename T>
		Node<T>* BTree<T>::search(size_t key, Node<T>* leaf)
		{
			if (leaf != nullptr)
			{
				if (key == leaf->data)return leaf;
				if (key < leaf->data) {
					return search(key, leaf->left);
				}
				else
				{
					return search(key, leaf->right);
				}
			}
			else return nullptr;
		}

		template<typename T>
		void BTree<T>::inorder_print(Node<T>* leaf)
		{
			if (leaf != nullptr)
			{
				inorder_print(leaf->left);
				std::cout << leaf->data << ",";
				inorder_print(leaf->right);
			}
		}

		template<typename T>
		void BTree<T>::postorder_print(Node<T>* leaf)
		{
			if (leaf != nullptr)
			{
				inorder_print(leaf->left);
				inorder_print(leaf->right);
				std::cout << leaf->data << ",";
			}
		}

		template<typename T>
		void BTree<T>::preorder_print(Node<T>* leaf)
		{
			if (leaf != nullptr)
			{
				std::cout << leaf->data << ",";
				inorder_print(leaf->left);
				inorder_print(leaf->right);
			}
		}
	}
}



int main(int argc, char** argv)
{
	
	system("pause >> NULL");
	return 0;
}