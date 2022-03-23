#pragma once

#include <iostream>


template<typename T>
class List{
	template<typename T>

	struct Node {
		T value;
		Node* next;
		Node() : value(), next(nullptr) {};
		Node(const T& value) : value(value), next(nullptr) {};
	};


public:
	List() : head(nullptr) {}
	List(const List<T> &other)
	{
		head = new Node<T>(other.head->value);
		Node<T>* node1 = head;
		Node<T>* node2 = other.head;
		while (node2->next != nullptr)
		{
			node2 = node2->next;
			Node<T>* tmp = new Node<T>(node2->value);
			node1->next = tmp;
			node1 = tmp;
		}
	}
	Node<T>* head;
	void addNode(const T& value);
	void sort();
	bool isEmpty();
	T& getHead();

	friend std::ostream& operator<<(std::ostream& out, const List& list)
	{
		Node<T>* tmp = list.head;
		while (tmp != nullptr)
		{
			//out << tmp << ": " << tmp->value << std::endl;
			out << tmp->value;
			tmp = tmp->next;
		}
		out << std::endl;
		return out;
	}

};

template<typename T>
void List<T>::addNode(const T& value) {
	Node<T>* tmp = new Node<T>(value);
	if (head != nullptr)
		tmp->next = head;
	head = tmp;
}

template<typename T>
T& List<T>::getHead() {
	if (isEmpty())
		throw "list is empty!";
	return head->value;
}

template<typename T>
bool List<T>::isEmpty() {
	if (head == nullptr)
		return true;
	return false;
}

template<typename T>
void List<T>::sort() {
	Node<T>* min = head;  
	T temp = min->value;
	Node<T>* tmp1 = head;
	while (tmp1 != nullptr)
	{
		min = tmp1;

		Node<T>* tmp2 = tmp1->next;
		while (tmp2 != nullptr)
		{
			if (min->value < tmp2->value)
				min = tmp2;     
			tmp2 = tmp2->next;
		}
		temp = tmp1->value;     
		tmp1->value = min->value;
		min->value = temp;
		tmp1 = tmp1->next;
	}
}