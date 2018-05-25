#include <functional>
#include <iostream>
#include <random>
#include <algorithm>

template <class T> class btree;

template <class T> struct node
{
public:
  friend class btree<T>;

private:
  T *data;
  node *left;
  node *right;
};

template <class T> class btree
{
public:
  btree (std::function<int(const T&, const T&)> cmp);
  ~btree ();

  void insert (const T& data);
  void foreach (std::function<void(T&)> func) const;
  void foreach2 (std::function<void(T&)> func) const;
  int length () const;
  void remove (const T& data);

private:
  node<T> *root;
  std::function<int(const T&, const T&)> cmp;

  void foreach (node <T>* node, std::function<void(T&)> func) const;
  int length (node<T> *node, int len) const;
};

template <class T>
btree<T>::btree (std::function<int(const T&, const T&)> cmp)
{
  root = nullptr;
  this->cmp = cmp;
}

template <class T>
btree<T>::~btree ()
{
}

template <class T>
int btree<T>::length () const
{
  return length (root, 0);
}

template <class T>
int btree<T>::length (node<T> *node, int len) const
{
  if (node != NULL) {
    int l1, l2;
    l1 = length (node->left, len + 1);
    l2 = length (node->right, len + 1);

    return std::max (l1, l2);
  }

  return len;
}

template <class T>
void btree<T>::foreach (std::function<void(T&)> func) const
{
  foreach (root, func);
}

template <class T>
void btree<T>::foreach (node<T> *node, std::function<void(T&)> func) const
{
  if (node != NULL) {
    foreach (node->left, func);
    func (*node->data);
    foreach (node->right, func);
  }
}

template <class T>
void btree<T>::remove (const T& data)
{
  node<T> *i = root;
  node<T> *p = nullptr;
  node<T> *s = nullptr;
  int val;

  while (i != nullptr && (val = cmp (data, *i->data)) != 0) {
    p = i;
    if (val > 0) {
      i = i->right;
    } else {
      i = i->left;
    }
  }

  if (i == nullptr) return;

  if (i->left == nullptr) {
    s = i->right;
  } else if (i->right == nullptr) {
    s = i->left;
  } else {
    node<T> *b = i;
    s = i->right;

    while (s->left != nullptr) {
      b = s;
      s = s->left;
    }

    if (b->left == s) {
      b->left = s->right;
    } else {
      b->right = s->right;
    }

    s->left = i->left;
    s->right = i->right;
  }

  if (p == nullptr) {
    root = s;
  } else if (p->left == i) {
    p->left = s;
  } else {
    p->right = s;
  }

  delete i->data;
  delete i;
}

template <class T>
void btree<T>::foreach2 (std::function<void(T&)> func) const
{
  node<T> *i = root;

  while (i != nullptr) {
    if (i->left != nullptr) {
      node<T> *r = i->left;

      while (r->right != nullptr && r->right != i) {
        r = r->right;
      }

      if (r->right == nullptr) {
        r->right = i;
        i = i->left;
        continue;
      } else {
        r->right = nullptr;
      }
    }

    func (*i->data);
    i = i->right;
  }
}

template <class T>
void btree<T>::insert (const T& data)
{
  node<T> *n = new node<T>;
  n->data = new T (data);
  n->left = nullptr;
  n->right = nullptr;

  node<T> *i = root;
  node<T> *p = nullptr;

  while (i != nullptr) {
    p = i;
    if (cmp (*i->data, *n->data) >= 0) {
      i = i->left;
    } else {
      i = i->right;
    }
  }

  if (p == nullptr) {
    root = n;
  } else if (cmp (*p->data, *n->data) >= 0) {
      p->left = n;
  } else {
      p->right = n;
  }
}

int main ()
{
  std::random_device rd;
  std::uniform_int_distribution<int> dist (0, 1000);

  std::cout << "testing..." << std::endl;
  btree<int> bt([] (const int &a, const int &b) -> int { return (a - b); });
  int num;
  for (int i = 0; i < 50; i ++) {
    num = dist (rd);
    bt.insert (num);
  }

  bt.foreach ([] (int& d) { std::cout << d << " "; });
  std::cout << std::endl;

  bt.foreach2 ([] (int& d) { std::cout << d << " "; });
  std::cout << std::endl;
  std::cout << "length: " << bt.length () << std::endl;

  std::cout << "testing delete..." << std::endl;
  btree<int> bt2([] (const int &a, const int &b) -> int { return (a - b); });
  int vals[] = { 12, 20, 8, 10, 4, 3, 2, 1 };
  for (unsigned int i = 0; i < sizeof (vals)/sizeof (vals[0]); i++) {
    bt2.insert (vals[i]);
  }
  bt2.foreach2 ([] (int& d) { std::cout << d << " "; });
  std::cout << std::endl;
  bt2.remove (8);
  bt2.foreach2 ([] (int& d) { std::cout << d << " "; });
  std::cout << std::endl;
  bt2.remove (12);
  bt2.foreach2 ([] (int& d) { std::cout << d << " "; });
  std::cout << std::endl;
}
