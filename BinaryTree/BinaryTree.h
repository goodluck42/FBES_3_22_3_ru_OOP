#pragma once

template<typename T>
class BinaryTree
{
private:
	struct Node
	{
		Node(const T& value) : value(value) {}
		T value;
		Node* right = nullptr;
		Node* left = nullptr;
	};
	Node* m_root;
	size_t m_size;
public:
	~BinaryTree()
	{
		// TODO: Implement destructor
	}
	BinaryTree()
	{
		m_root = nullptr;
	}
	size_t size()
	{
		return m_size;
	}
	void insert(const T& value)
	{
		if (m_root == nullptr)
		{
			m_root = new Node{ value };
			++m_size;

			return;
		}

		Node* current = m_root;

		while (true)
		{
			if (value > current->value)
			{
				if (current->right == nullptr) // вставка вправо
				{
					current->right = new Node{ value };
					++m_size;

					break;
				}

				current = current->right;
			}
			else if (value < current->value)
			{
				if (current->left == nullptr) // вставка влево
				{
					current->left = new Node{ value };
					++m_size;

					break;
				}

				current = current->left;
			}
		}
	}
private:
	void DestroyNode(...)
	{

	}
};