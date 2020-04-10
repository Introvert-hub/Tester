#include <iostream>

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
		if (head == nullptr) {
			head = new Node(data);
			++size_; 
		}
		else
		{
			head = new Node(data, this->head);
			++size_;
		}
	}
	void push_fornt(Data data)
	{

	}
	Data& operator[](const size_t index)
	{
		size_t counter = 0;
		Node* current = head;
		while (current->pNext != nullptr)
		{
			if (counter == index) return current->data;
			current = current->pNext;
		}
	}
	size_t size() { return size_; }
};


int main(int argc, char** argv)
{
	List<int16_t>lst(25);
	lst.push_head(-354);
	lst.push_head(255);
	lst.push_head(226);
	for(size_t i = 0; i < lst.size(); ++i)
	{
		std::cout << lst[i] << " ";
	}

	system("pause >> NULL");
	return 0;
}