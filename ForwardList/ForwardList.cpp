#include "ForwardList.h"

ForwardList::ForwardList() {
	m_first = nullptr;
	m_last = nullptr;
	m_size = 0;
}

ForwardList::~ForwardList() { 
	Node* it = m_first;
	while (it != nullptr) {
		Node* del = it;
		it = it->m_next;
		delete del;
	}
}

void ForwardList::PushBack(int value) {
	Node* n = new Node();
	n->m_value = value;

	if (IsEmpty()) {
		m_first = n;
		m_last = n;
		m_size++;
	}
	else {
		n->m_next = m_first;
		m_first = n;
		m_size++;
	}
}

void ForwardList::PopBack() {

	if (IsEmpty()) { return; }
	Node* del = m_first;
	if (m_size == 1) {
		m_first = nullptr;
		m_last = nullptr;
	}
	else {
		m_first = m_first->m_next;
	}

	m_size--;
	delete del;
}

void ForwardList::PushFront(int value) {
	Node* n = new Node();
	n->m_value = value;

	if (IsEmpty()) {
		m_first = n;
		m_last = n;
		m_size++;
	}
	else {
		m_last->m_next = n;
		m_last = n;
		m_size++;
	}
}

void ForwardList::PopFront() {

	if (IsEmpty()) { return; }
	Node* del = m_last;
	if (m_size == 1) {
		m_first = nullptr;
		m_last = nullptr;
	}
	else {
		Node* it = m_first;
		while (it->m_next != m_last) { it = it->m_next; }
		m_last = it;
		m_last->m_next = nullptr;
	}

	m_size--;
	delete del;
}

bool ForwardList::IsEmpty() const{
	return m_size == 0 && m_first == nullptr && m_last == nullptr;
}

int ForwardList::Front() const {
	return m_first->m_value;
}

int ForwardList::Back() const{
	return m_last->m_value;
}

int ForwardList::Size() const {
	return m_size;
}

void ForwardList::Insert(int value, int position) {
	if (position < 0) return; // invalid position

	Node* n = new Node();
	n->m_value = value;

	if (IsEmpty()) {
		m_first = n;
		m_last = n;
		m_size++;
	}
	else {
		int currentPos = 0; // 0 is first position 
		Node* it = m_first;

		while (currentPos <= position) {
			if (it == m_last) { // if there are not enough positions
				it->m_next = n;
				m_last = n;
				m_size++;
				break; 
			}
			else {
				if (currentPos == position) { // arrive at position

					if (it == m_first) { // if its firts
						n->m_next = m_first;
						m_first = n;
					}
					else {
						n->m_next = it->m_next;
						it->m_next = n;
					}
					m_size++;
					break;
				}
				it = it->m_next;
				currentPos++;
			}
		}
	}
}

void ForwardList::Erase(int value) {
	if (IsEmpty()) { return; } // return if is empty

	Node* it = m_first;
	Node* prev = nullptr;


	while (it != nullptr) { // iterate 
		if (it->m_value == value) { 
			Node* del = it; // save to delete later

			if (it == m_first && it == m_last) { // is the only node 
				m_first = nullptr;
				m_last = nullptr;
				it = nullptr;
			}
			else if (it == m_first) { // is first
				prev = it;
				m_first = it->m_next;
				it = m_first; // start from the start
			}
			else if (it == m_last) { // is last
				prev->m_next = nullptr;
				m_last = prev;
				it = nullptr;
			}
			else { // is not last and is not first
				prev->m_next = it->m_next;

				prev = it;
				it = it->m_next;
			}
			 delete del; // delete node
			 m_size--;
		}
		else {
			prev = it;
			it = it->m_next;
		}
	}
}

void ForwardList::PushBackAverageNode() {
	if (IsEmpty()) { 
		PushBack(0); // avreage is 0 cause is empty
	} 
	else {
		Node* it = m_first;
		int sumOfValues = 0;
		while (it != nullptr) { // get the value of all nodes
			sumOfValues += it->m_value;
			it = it->m_next;
		}

		int avrg = sumOfValues / Size();

		PushBack(avrg);
	}
}

bool operator==(const ForwardList& l1, const ForwardList& l2) {

	if (l1.IsEmpty() && l2.IsEmpty()) {
		return true;
	}
	
	if (l1.m_size != l2.m_size) {
			return false;
	}


	ForwardList::Node* it1 = l1.m_first;
	ForwardList::Node* it2 = l2.m_first;

	while (it1 != nullptr && it2 != nullptr) {
		if (it1->m_value != it2->m_value) {
			return false;
		}
		it1 = it1->m_next;
		it2 = it2->m_next;
	}

	return true;
}

ForwardList ForwardList::operator+(const ForwardList& l) {
	ForwardList result;

	ForwardList::Node* it = m_first;
	while (it != nullptr) {
		result.PushBack(it->m_value);
		it = it->m_next;
	}

	it = l.m_first;
	while (it != nullptr) {
		result.PushBack(it->m_value);
		it = it->m_next;
	}

	return result;
}

std::ostream& operator<<(std::ostream& o, const ForwardList& l) {
	if (l.IsEmpty()) {
		o << "[]";
		return o;
	}

	o << "[";
	ForwardList::Node* it = l.m_first;

	while (it != nullptr) {
		o << it->m_value;
		if (it->m_next != nullptr) {
			o << ", ";
		}
		it = it->m_next;
	}

	o << "]";
	return o;
}