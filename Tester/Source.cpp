#include <iostream>


namespace MY_ADT {
	namespace Stack {
		template <typename Data>
		class Stack
		{
		private:
			struct Node
			{
				Data data;
				Node* pNext;
			};
			Node* top_;
		public:
			Stack() { top_ = nullptr; }
			Stack(Data data_) : Stack()
			{
				push(data_);
			}
			void push(Data data_)
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
			Data& top() { return top_->data; }
			~Stack() { while (top_ != nullptr) pop(); }
		};
	}
	namespace List {
		template<typename Data>
		class List
		{
		private:
			class Node
			{
			public:
				Data data;
				Node* pNext;

				Node(Data data = Data(), Node* pNext = nullptr)
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
			List(Data data_) : List()
			{
				push_head(data_);
			}
			void push_head(Data data)
			{
				head = new Node(data, this->head);
				++size_;
			}
			void push_fornt(Data data)
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
			void insertAtPlusOne(Data data, const size_t index)
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
			Data& operator[](const size_t index)
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
			Data& getHead() { return head->data; }
			size_t size() { return size_; }
			~List() { while (size_)	pop_head(); }
		};
	}
	namespace BTree
	{
		template<typename Data>
		struct Node
		{
			Data data;
			Node* left;
			Node* right;
		};

		template<typename Data>
		class BTree
		{
		public:
			BTree();
			~BTree();

			void insert(size_t key);
			Node<Data>* search(size_t key);
			void destroy_tree();
			void inorder_print();
			void postorder_print();
			void preorder_print();

		private:
			Node<Data>* root;

			void destroy_tree(Node<Data>* leaf);
			void insert(size_t key, Node<Data>* leaf);
			Node<Data>* search(size_t key, Node<Data>* leaf);
			void inorder_print(Node<Data>* leaf);
			void postorder_print(Node<Data>* leaf);
			void preorder_print(Node<Data>* leaf);

		};


		template<typename Data>
		BTree<Data>::BTree()
		{
			root = nullptr;
		}

		template<typename Data>
		BTree<Data>::~BTree()
		{
			destroy_tree();
		}

		template<typename Data>
		void BTree<Data>::insert(size_t key)
		{
			if (root != nullptr) insert(key, root);
			else
			{
				root = new Node<Data>;
				root->data = key;
				root->left = nullptr;
				root->right = nullptr;
			}
		}

		template<typename Data>
		Node<Data>* BTree<Data>::search(size_t key)
		{
			return search(key, root);
		}

		template<typename Data>
		void BTree<Data>::destroy_tree()
		{
			destroy_tree(root);
		}

		template<typename Data>
		void BTree<Data>::inorder_print()
		{
			inorder_print(root);
			std::cout << "\n";
		}

		template<typename Data>
		void BTree<Data>::postorder_print()
		{
			postorder_print(root);
			std::cout << "\n";
		}

		template<typename Data>
		void BTree<Data>::preorder_print()
		{
			preorder_print(root);
			std::cout << "\n";
		}

		template<typename Data>
		void BTree<Data>::destroy_tree(Node<Data>* leaf)
		{
			if (leaf != nullptr)
			{
				destroy_tree(leaf->left);
				destroy_tree(leaf->right);
				delete leaf;
			}
		}

		template<typename Data>
		void BTree<Data>::insert(size_t key, Node<Data>* leaf)
		{
			if (key < leaf->data) {
				if (leaf->left != nullptr) insert(key, leaf->left);

				else {
					leaf->left = new Node<Data>;
					leaf->left->data = key;
					leaf->left->left = nullptr;
					leaf->left->right = nullptr;
				}

			}
			else if (key >= leaf->data)
			{
				if (leaf->right != nullptr) { insert(key, leaf->right); }
				else {
					leaf->right = new Node<Data>;
					leaf->right->value = key;
					leaf->right->right = nullptr;
					leaf->right->left = nullptr;
				}
			}




		}

		template<typename Data>
		Node<Data>* BTree<Data>::search(size_t key, Node<Data>* leaf)
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

		template<typename Data>
		void BTree<Data>::inorder_print(Node<Data>* leaf)
		{
			if (leaf != nullptr)
			{
				inorder_print(leaf->left);
				std::cout << leaf->data << ",";
				inorder_print(leaf->right);
			}
		}

		template<typename Data>
		void BTree<Data>::postorder_print(Node<Data>* leaf)
		{
			if (leaf != nullptr)
			{
				inorder_print(leaf->left);
				inorder_print(leaf->right);
				std::cout << leaf->data << ",";
			}
		}

		template<typename Data>
		void BTree<Data>::preorder_print(Node<Data>* leaf)
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