#pragma once

template <typename T>
class Node
{
public:
	Node()
	{
		next = prev = nullptr;
	}

	Node(const T& a_value) : value(a_value) { }

	T value;
	Node* next;
	Node* prev;
};