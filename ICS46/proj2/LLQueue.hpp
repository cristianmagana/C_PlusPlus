#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};



template<typename Object>
class LLQueue
{
private:
	// fill in private member data here
	struct Node {
		Node* next;
		Object data;
	};


public:
	LLQueue();

//	These are copy constructors and  assignment operators. 
	// These should be "deep copies" -- copy the contents, not just a pointer to the front. 
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st);
	~LLQueue();


	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two front() for the same reason the Stack in lecture week 2 had two top() functions.
	// If you do not know why there are two, your FIRST step needs to be to review your notes from that lecture.

	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

// does not return anything.  Just removes. 
	void dequeue();
private:

	Node * head;
	Node * rear;
	Node * prev;
	Node * temp;
	size_t count;

};

// TODO:  Fill in the functions here. 
// Queue implementation:
// 0. Default Constructor + The Big Three 
// 1. Size
// 2. Enqueue
// 3. Dequeue 
// 4. Front 
// 5. Peek
// 6. isEmpty
// 7. isFull -- No Need to worry on this project

template<typename Object>
LLQueue<Object>::LLQueue()
{
	count = 0;
	head = nullptr;
	rear = nullptr;
}

template<typename Object>
LLQueue<Object>::LLQueue(const LLQueue & llq)
{
	if(llq.head == nullptr)
	{
		return;
	}

	temp = llq.head; //Creates the temp to iterate over the list. 

	head = new Node; //Creates the head of the new list.
	head->data = temp->data; //Copy the original head data.
	head->next = nullptr; //Set head to null by default. 
	rear = head; //Set head and rear to first initialized node on list.
	temp = temp->next; //Start moving along to build the new list. 

	// Deep Copy of Linked List Process //
	while(temp!=nullptr)
	{
		rear->next = new Node; 
		rear = rear->next; 
		rear->data = temp->data; 
		rear->next = nullptr;
		temp = temp->next;
	}
}

template<typename Object>
LLQueue<Object> &LLQueue<Object>::operator=(const LLQueue & llq)
{
	auto addrllq = std::addressof(llq);
	if(addrllq == this) 
	{
		return *this;
	}
	else
	{
		this->~LLQueue();
		new (this) LLQueue(llq);	
	}
	return *this;
}

template<typename Object>
LLQueue<Object>::~LLQueue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template<typename Object>
size_t LLQueue<Object>::size() const noexcept
{
	return count;
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object & elem)
{
	temp = new Node;
	temp->data = elem;
	temp->next = nullptr;

	if(isEmpty())
	{
		head =temp;
		rear = temp;
	}

	else
	{
		prev = rear;
		rear->next =temp;
		rear=temp;
	}
	//delete temp;
	count++;
}

template<typename Object>
void LLQueue<Object>::dequeue()
{
	if(head == nullptr)
	{
		throw QueueEmptyException("Queue is Empty");
		return;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	count--;
}

template<typename Object>
const Object & LLQueue<Object>::front() const
{
	if( isEmpty() )
		throw QueueEmptyException("Queue is Empty");
	else
		return head->data;
}

template<typename Object>
Object & LLQueue<Object>::front()
{
	if( isEmpty() )
		throw QueueEmptyException("Queue is Empty");
	else
		return head->data;
}

template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept
{
	if(head == nullptr)
		return true;
	else
		return false;
}

#endif 
