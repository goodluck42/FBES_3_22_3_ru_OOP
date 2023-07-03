#pragma once
#include "Node.h"
#include <list>

template <typename T> class LinkedList
{
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	size_t m_size;
public:
	~LinkedList()
	{
		/*Node<T>* current = m_head;

		while (current->next != nullptr)
		{
			current = current->next;

			delete current->prev;
		}

		delete m_tail;*/

		Node<T>* current = m_head;
		std::stack<Node<T>*> stack;

 		while (current != nullptr)
		{
			stack.push(current);
			current = current->next;
		}

		while (!stack.empty())
		{
			delete stack.top();
			stack.pop();
		}
	}
	LinkedList()
	{
		m_size = 0;
		m_head = m_tail = nullptr;
	}

	void push_front(const T& elem)
	{

	}
	void push_back(const T& elem)
	{
		if (m_size == 0)
		{
			m_head = m_tail = new Node<T> { elem };

			++m_size;

			return;
		}

		Node<T>* node = new Node<T>{ elem };

		m_tail->next = node;
		m_tail->next->prev = m_tail;
		m_tail = node;

		++m_size;
	}
};