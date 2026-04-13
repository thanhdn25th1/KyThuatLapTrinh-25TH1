
template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct LinkedList {
	Node<T>* head;
	void Show();
	void Add(T item);
};

template <typename T>
void LinkedList<T> ::Show() {
	if (head == NULL) {
		cout << "No data available" << endl;
		return;
	}
	Node* item = head;
	while (item != NULL) {
		//cout << item->data;
		item = item->next;
	}
}

