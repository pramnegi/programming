#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *next;
};
struct node *head = NULL;
int c = 1;
struct node *add_beginning(int val) {
  struct node *temp = (struct node *)malloc(sizeof(node));
  temp->data = val;
  temp->next = head;
  // head=temp;
  return temp;
}
struct node *add_end(int val) {
  if (head == NULL) {
    head = add_beginning(val);
    return head;
  } else {
    struct node *temp = head;
    while ((temp->next != NULL)) {
      temp = temp->next;
    }

    struct node *tempu = (struct node *)malloc(sizeof(node));
    tempu->data = val;
    tempu->next = NULL;
    temp->next = tempu;
    return head;
  }
}
void delete_beginning() {
  if (head == NULL) {
    cout << "hey the list is empty" << endl;
    return;
  } else {
    head = head->next;
    return;
  }
}
void length() {
  struct node *tempu = (struct node *)malloc(sizeof(node));
  tempu = head;
  if (head == NULL) cout << "list is empty" << endl;

  while (tempu->next != NULL) {
    c += 1;
    tempu = tempu->next;
  }
  // cout<<"length  of list is \t"<<c<<endl;
}
void check_palindrome() {
  int n, mid, flag = 0;
  struct node *tempu = (struct node *)malloc(sizeof(node));
  tempu = head;
  length();
  n = c;
  int arr[n];
  if (c % 2 == 0)
    mid = c / 2;
  else
    mid = (c / 2) + 1;
  for (int i = 0; i < n; i++) {
    arr[i] = tempu->data;
    tempu = tempu->next;
  }

  for (int i = 0; i < n / 2; i++) {
    if (arr[i] != arr[mid]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    cout << "list is palindrome" << endl;
  else
    cout << "not palindrome" << endl;
}

void traverse() {
  struct node *temp = head;
  if (head == NULL) {
    cout << "hey the link list is empty" << endl;
  }
  while (temp) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << endl;
}

int printTerm(int x) {
  if (head == NULL) {
    cout << "list is empty" << endl;
  } else {
    int i = 1;
    while (i < x) {
      head = head->next;
      i += 1;
    }
    cout << head->data << endl;
  }
}
void print_reverse(struct node *ulta) {
  stack<int> s;
  while (ulta) {
    s.push(ulta->data);
    ulta = ulta->next;
  }
  while (!s.empty()) {
    cout << s.top() << "\t";
    s.pop();
  }
  cout << endl;
}

int main() {
  head = NULL;
  while (1) {
    cout << "1  :: add at beginning \n";
    cout << "2  :: add at end \n";
    cout << "3  :: delete from beginning \n";
    cout << "4  :: print the current link list  \n";
    cout << "5  :: print the current link list in reverse order \n";
    cout << "6  :: print x th term\n";
    cout << "7  :: check length of list\n";
    cout << "8  :: check palindrome\n";
    cout << "9  :: exit\n";
    cout << "enter the option  -- >> ";
    int num;
    cin >> num;
    switch (num) {
      case 1: {
        int value;
        cin >> value;
        head = add_beginning(value);
        break;
      }
      case 2: {
        int value;
        cin >> value;
        head = add_end(value);
        break;
      }
      case 3: {
        delete_beginning();
        break;
      }
      case 4: {
        traverse();
        break;
      }
      case 5: {
        struct node *temp = head;
        print_reverse(temp);
        break;
      }
      case 6: {
        int x;
        cout << "enter the index of term to be printed\n" << endl;
        cin >> x;
        printTerm(x);
        break;
      }
      case 7: {
        length();
        cout << "length of list is\t" << c << endl;
        break;
      }
      case 8: {
        check_palindrome();
        break;
      }
      case 9: {
        return 0;
        break;
      }

      default: {
        cout << "enter the correct option" << endl << endl;
        break;
      }
    }
  }
  return 0;
}
