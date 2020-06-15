#include "bstree.h"
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
  tree<int> bs;
  stack<int> st;
  //for(int i = 0; i <= 42; i++){
  //  node<int>*n = new node<int>(i);
  //  bs.treeInsert(n);
  //}
  node<int> *a = new node<int>(9);
  node<int> *b = new node<int>(5);
  node<int> *c = new node<int>(12);
  node<int> *d = new node<int>(8);
  node<int> *e = new node<int>(11);
  node<int> *f = new node<int>(13);
  node<int> *g = new node<int>(7);
  bs.treeInsert(a);
  bs.treeInsert(b);
  bs.treeInsert(c);
  bs.treeInsert(d);
  bs.treeInsert(e);
  bs.treeInsert(f);
  bs.treeInsert(g);

  tree<int> bs2(bs);
  cout << bs.treeDelete(bs.treeSearch(9))->key << endl;
  cout << bs.treeDelete(bs.treeSearch(12))->key << endl;
  cout << bs.treeDelete(bs.treeSearch(13))->key << endl;

  bs.print();
  cout << endl;
  bs2.print();


return 0;
}
