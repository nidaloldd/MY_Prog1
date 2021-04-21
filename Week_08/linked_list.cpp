#include <iostream>

template<typename Elem>
struct Link
{
	Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
		: prev(p), succ(s), val(v) {}

	Link* prev;
	Link* succ;
	Elem val;
};

template<typename Elem> 
class my_list
{
public:
	Link<Elem>* first;
	Link<Elem>* last;

	my_list(): first(new Link<Elem>()), last(first) {}

	class iterator;

	iterator begin() { return iterator(first); }
	iterator end() { return iterator(last); }

	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);

	void push_back(const Elem& v);
	void push_front(const Elem& v);
	void pop_front();
	void pop_back();

	Elem& front();
	Elem& back();
};

template<typename Elem>
class my_list<Elem>::iterator{
	Link<Elem>* curr;

public:
	iterator(Link<Elem>* p) : curr{p} {}

	iterator& operator++() { curr = curr->succ; return *this; }
	iterator& operator--() { curr = curr->prev; return *this; }
	Elem& operator*() { return curr->val; }

	bool operator==(const iterator& b) const { return curr==b.curr; }
	bool operator!=(const iterator& b) const { return curr!=b.curr; }
};

template<typename Iter>
Iter high(Iter first, Iter last)
{
	Iter high = first;
	for (Iter p = first; p!=last; ++p)
		if (*high<*p) high = p;

	return high;
}

template<typename Elem>
void my_list<Elem>::push_front(const Elem& v)
{	
	first = new Link<Elem>(v, 0, first);
}

void f()
{
	my_list<int> lst;
	for (int x = 0; std::cin >> x;)
		lst.push_front(x);

	my_list<int>::iterator p = high(lst.begin(), lst.end());
	std::cout << "the highest value was " << *p << '\n';
}

int main()
{
	f();

	return 0;
}
