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

	}
	void pop_front()
	{

	}
	void insertAt(Data data, const size_t index)
	{

	}
	void removeAt(const size_t index)
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
			++counter;
		}
	}
	size_t size() { return size_; }
	~List() { while (size_)	pup_head(); }
};



int main(int argc, char** argv)
{
	List<int16_t>lst(25);
	lst.push_head(-354);
	lst.push_head(255);
	lst.push_head(226);
	lst.push_fornt(-333);
	lst.push_fornt(-322);
	for(size_t i = 0; i < lst.size(); ++i)
	{
		std::cout << lst[i] << " ";
	}

	system("pause >> NULL");
	return 0;
}