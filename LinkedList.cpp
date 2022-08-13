// Implementation of LinkedList Data Structure and it's operations

// Header Files
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

// Pre-processors
#define null NULL

// Using Class
// Singly LinkedList
class ClassNode
{
public:
    int classData;
    ClassNode *classNextPointer;

    ClassNode()
    {
        classData = 0;
        classNextPointer = null;
    }

    ClassNode(int value)
    {
        classData = value;
        classNextPointer = null;
    }
};

// Doubly LinkedList
class DllNode
{
public:
    DllNode *nextPointer;
    DllNode *previousPointer;
    int data;

    DllNode()
    {
        data = 0;
        nextPointer = null;
        previousPointer = null;
    }

    DllNode(int value)
    {
        data = value;
        nextPointer = null;
        previousPointer = null;
    }
};

// Node Class for LRU Cache design
class Node
{
public:
    int key;
    int value;
    Node *pre;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        pre = NULL;
        next = NULL;
    }
};

// Using Structure
// Singly LinkedList
struct StructNode
{
    int structData;
    StructNode *structNextPointer;

    StructNode()
    {
        structData = 0;
        structNextPointer = null;
    }

    StructNode(int value)
    {
        structData = value;
        structNextPointer = null;
    }
};

// In this library i'll be using ClassNode for the implementations

// Traversal
class Traversal
{
public:
    // For classNode
    void iterativeTraversalForSll(ClassNode *head)
    {
        ClassNode *temp = head;

        if (temp == null)
        {
            cout << "LinkedList is empty" << endl;
            return;
        }
        else if (temp->classNextPointer == null)
        {
            cout << temp->classData << "->NULL" << endl;
            return;
        }

        while (temp != null)
        {
            cout << temp->classData << "->";
            temp = temp->classNextPointer;
        }

        cout << "NULL" << endl;
    }

    void recursiveTraversalForSll(ClassNode *head)
    {
        ClassNode *temp = head;

        if (temp == null)
            return;

        cout << temp->classData << "->";
        recursiveTraversalForSll(temp->classNextPointer);
    }

    void traversalForCll(ClassNode *head)
    {
        ClassNode *temp = head;

        if (temp == null)
            return;

        // Using for loop
        /*cout << head->classData << "->";
        for (temp = head->classNextPointer; temp != head; temp = temp->classNextPointer)
        {
            cout << temp->classData << "->";
        }
        cout << "HEAD" << endl;*/

        // Using do-while loop
        do
        {
            cout << temp->classData << "->";
            temp = temp->classNextPointer;
        } while (temp != head);

        cout << "HEAD" << endl;
    }

    void forwardTraversalForDll(DllNode *head)
    {
        DllNode *temp = head;

        if (temp == null)
            return;

        cout << "NULL<-";
        while (temp->nextPointer != null)
        {
            cout << temp->data << "<->";
            temp = temp->nextPointer;
        }

        cout << temp->data << "->NULL" << endl;
    }

    void backwardTraversalForDll(DllNode *head)
    {
        DllNode *temp = head;

        if (temp == null)
            return;

        cout << "NULL<-";
        while (temp->previousPointer != null)
        {
            cout << temp->data << "<->";
            temp = temp->previousPointer;
        }

        cout << temp->data << "->NULL" << endl;
    }
};

// Search
class Search
{
public:
    // For ClassNode
    void iterativeSearchInSll(ClassNode *head, int target)
    {
        ClassNode *temp = head;

        if (temp == null)
        {
            cout << "Invalid Input" << endl;
            return;
        }

        int count = 1;
        while (temp != null)
        {
            if (temp->classData == target)
            {
                cout << target << " found" << endl;
                cout << "The position of " << target << " is: " << count << endl;
                return;
            }

            temp = temp->classNextPointer;
            count++;
        }

        if (temp == null)
            cout << target << " not found" << endl;
    }

    int recursiveSearchInSll(ClassNode *head, int target)
    {
        ClassNode *temp = head;

        if (temp == null)
            return -1;

        if (temp->classData == target)
            return 1;
        else
        {
            int res = recursiveSearchInSll(temp->classNextPointer, target);
            if (res == -1)
                return -1;
            else
                return res + 1;
        }
    }
};

// Adding or inserting a node
class AddNode
{
public:
    ClassNode *addNodeAtBeginOfSll(ClassNode *head, int value)
    {
        ClassNode *newNode = new ClassNode(value);

        newNode->classNextPointer = head;
        return newNode;
    }

    ClassNode *addNodeAtEndOfSll(ClassNode *head, int value)
    {
        ClassNode *newNode = new ClassNode(value);

        if (head == null)
            return newNode;

        ClassNode *temp = head;

        while (temp->classNextPointer != null)
            temp = temp->classNextPointer;

        temp->classNextPointer = newNode;
        return head;
    }

    ClassNode *addNodeAtPositionOfSll(ClassNode *head, int value, int position)
    {
        ClassNode *newNode = new ClassNode(value);

        int counter = 1;
        ClassNode *temp = head;

        if (position == 1)
            return addNodeAtBeginOfSll(head, value);

        while (counter <= position - 2 && temp != null)
        {
            temp = temp->classNextPointer;
            counter++;
        }

        if (temp == null)
            return head;

        newNode->classNextPointer = temp->classNextPointer;
        temp->classNextPointer = newNode;
        return head;
    }

    ClassNode *addNodeAtBeginOfCll(ClassNode *head, int value)
    {
        ClassNode *newNode = new ClassNode(value);

        if (head == null)
        {
            newNode->classNextPointer = newNode;
            return newNode;
        }

        // Naive Approach
        /*ClassNode *temp = head;

        while (temp->classNextPointer != head)
            temp = temp->classNextPointer;

        newNode->classNextPointer = head;
        temp->classNextPointer = newNode;
        return newNode;*/

        // Efficient approach
        newNode->classNextPointer = head->classNextPointer;
        head->classNextPointer = newNode;
        int t = head->classData;
        head->classData = newNode->classData;
        newNode->classData = t;
        return head;
    }

    ClassNode *addNodeAtEndOfCll(ClassNode *head, int value)
    {
        ClassNode *newNode = new ClassNode(value);

        if (head == null)
        {
            newNode->classNextPointer = newNode;
            return newNode;
        }

        // Naive Approach O(n)
        /*ClassNode *temp = head;

        while (temp->classNextPointer != head)
            temp = temp->classNextPointer;

        temp->classNextPointer = newNode;
        newNode->classNextPointer = head;
        return head;*/

        // Efficient Approach O(1)
        newNode->classNextPointer = head->classNextPointer;
        head->classNextPointer = newNode;
        int t = head->classData;
        head->classData = newNode->classData;
        newNode->classData = t;
        return newNode;
    }

    DllNode *addAtBeginOfDll(DllNode *head, int value)
    {
        DllNode *newNode = new DllNode(value);

        if (head == null)
            return newNode;

        newNode->nextPointer = head;
        head->previousPointer = newNode;
        return newNode;
    }

    DllNode *addAtEndOfDll(DllNode *head, int value)
    {
        DllNode *newNode = new DllNode(value);
        DllNode *temp = head;

        if (temp == null)
            return newNode;

        while (temp->nextPointer != null)
            temp = temp->nextPointer;

        temp->nextPointer = newNode;
        newNode->previousPointer = temp;
        /*
        If you want the backward traversal to work then
        you have to return the newNode from here as tail and
        have to update the tail in place of the lastNode of your DLL in main function
        */
        return newNode;
    }
};

// Deleting a node
class DeleteNode
{
public:
    ClassNode *deleteFromBeginOfSll(ClassNode *head)
    {
        ClassNode *temp = head;

        if (temp == null)
            return head;

        temp = temp->classNextPointer;

        return temp;
    }

    ClassNode *deleteFromEndOfSll(ClassNode *head)
    {
        ClassNode *temp = head;

        if (temp == null)
            return head;
        else if (temp->classNextPointer == null)
            return null;

        while (temp->classNextPointer->classNextPointer != null)
        {
            temp = temp->classNextPointer;
        }

        temp->classNextPointer = null;

        return head;
    }

    ClassNode *deleteAnyNodeFromSll(ClassNode *head, int target)
    {
        ClassNode *temp = head;

        if (temp == null)
            return head;

        if (temp->classData == target)
        {
            head = deleteFromBeginOfSll(head);
            return head;
        }

        while (temp->classNextPointer->classData != target && temp->classNextPointer != null)
        {
            temp = temp->classNextPointer;
        }

        if (temp == null || temp->classNextPointer == null)
        {
            cout << "The target value is not found in the LinkedList" << endl;
            return head;
        }

        temp->classNextPointer = temp->classNextPointer->classNextPointer;

        return head;
    }

    ClassNode *deleteAtBeginOfCll(ClassNode *head)
    {
        // Naive Approach
        /*if (head == null)
            return null;

        ClassNode *newHead = head->classNextPointer;
        ClassNode *temp = head;

        while (temp->classNextPointer != head)
            temp = temp->classNextPointer;

        temp->classNextPointer = newHead;
        delete (head);
        return newHead;*/

        // Efficient Approach
        if (head == NULL)
            return NULL;
        if (head->classNextPointer == head)
        {
            delete head;
            return NULL;
        }
        head->classData = head->classNextPointer->classData;
        ClassNode *temp = head->classNextPointer;
        head->classNextPointer = head->classNextPointer->classNextPointer;
        delete temp;
        return head;
    }

    ClassNode *deleteKthOfCll(ClassNode *head, int k)
    {
        if (head == null)
            return null;

        if (k == 1)
            deleteAtBeginOfCll(head);

        ClassNode *curr = head;
        for (int i = 0; i < k - 2; i++)
            curr = curr->classNextPointer;

        ClassNode *temp = curr->classNextPointer;
        curr->classNextPointer = curr->classNextPointer->classNextPointer;
        delete temp;
        return head;
    }
};

// Important functions for operations and implementations
class ImportantFunctions
{
public:
    // To find the intersection point of two lists
    int getCount(ClassNode *head)
    {
        ClassNode *curr = head;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->classNextPointer;
        }
        return count;
    }

    int _getIntersection(int d, ClassNode *head1, ClassNode *head2)
    {
        ClassNode *current1 = head1;
        ClassNode *current2 = head2;

        for (int i = 0; i < d; i++)
        {
            if (current1 == NULL)
            {
                return -1;
            }
            current1 = current1->classNextPointer;
        }

        while (current1 != NULL && current2 != NULL)
        {
            if (current1 == current2)
                return current1->classData;

            current1 = current1->classNextPointer;
            current2 = current2->classNextPointer;
        }

        return -1;
    }

    ClassNode *reverseList(ClassNode *head)
    {
        if (head == NULL || head->classNextPointer == NULL)
            return head;
        ClassNode *rest_head = reverseList(head->classNextPointer);
        ClassNode *rest_tail = head->classNextPointer;
        rest_tail->classNextPointer = head;
        head->classNextPointer = NULL;
        return rest_head;
    }
};

// Other problems or operations
class Operations : public ImportantFunctions
{
public:
    ClassNode *sortedInsertInSll(ClassNode *head, int value)
    {
        ClassNode *temp = head;

        ClassNode *newNode = new ClassNode(value);

        if (temp == null)
            return newNode;

        if (temp->classData > value)
        {
            newNode->classNextPointer = temp;
            return newNode;
        }

        while (temp->classNextPointer != null && temp->classNextPointer->classData < value)
        {
            temp = temp->classNextPointer;
        }

        newNode->classNextPointer = temp->classNextPointer;
        temp->classNextPointer = newNode;

        return head;
    }

    void middleOfSll(ClassNode *head)
    {
        // Using count method
        /*ClassNode *temp = head;

        if(temp == null)
            return;

        int count = 0;
        while(temp != null)
        {
            count++;
            temp = temp->classNextPointer;
        }

        temp = head;
        for (int i = 0; i < count / 2; i++)
        {
            temp = temp->classNextPointer;
        }

        cout << temp->classData;*/

        // Using slow and fast pointers
        if (head == null)
            return;

        ClassNode *slowPointer = head;
        ClassNode *fastPointer = head;

        while (fastPointer != null && fastPointer->classNextPointer != null)
        {
            slowPointer = slowPointer->classNextPointer;
            fastPointer = fastPointer->classNextPointer->classNextPointer;
        }

        cout << slowPointer->classData << endl;
    }

    void nthNodeFromEndOfSll(ClassNode *head, int n)
    {
        // Using length of the LinkedList
        /*ClassNode *temp = head;

        if (temp == null)
            return;

        int counter = 0;
        while (temp != null)
        {
            counter++;
            temp = temp->classNextPointer;
        }

        if (counter < n)
            return;

        temp = head;
        for (int i = 0; i < (counter - n); i++)
        {
            temp = temp->classNextPointer;
        }

        cout << temp->classData << endl; */

        // Using Two Pointers

        if (head == null)
            return;

        ClassNode *first = head;
        ClassNode *second = head;

        for (int i = 0; i < n; i++)
        {
            if (second == null)
                return;
            second = second->classNextPointer;
        }

        while (second != null)
        {
            first = first->classNextPointer;
            second = second->classNextPointer;
        }

        cout << first->classData << endl;
    }

    ClassNode *iterativeReverseOfSll(ClassNode *head)
    {
        // Naive Approach (Using an auxilary array changing the data)
        /* vector<int> tempArray;

        ClassNode *temp = head;

        if (temp == null || temp->classNextPointer == null)
            return head;

        while (temp != null)
        {
            tempArray.push_back(temp->classData);
            temp = temp->classNextPointer;
        }

        temp = head;
        while(temp != null)
        {
            temp->classData = tempArray.back();
            tempArray.pop_back();
            temp = temp->classNextPointer;
        }

        return head;*/

        // Efficient Approach (Using two pointer method changing the links between nodes)
        if (head == null || head->classNextPointer == null)
            return head;

        ClassNode *previousNode = null;
        ClassNode *currentNode = head;

        while (currentNode != null)
        {
            ClassNode *temp = currentNode->classNextPointer;
            currentNode->classNextPointer = previousNode;
            previousNode = currentNode;
            currentNode = temp;
        }

        return previousNode;
    }

    // pass the prev parameter as NULL from the main initially
    ClassNode *recursiveReverseOfSll(ClassNode *head, ClassNode *prev)
    {
        // Method 1
        /*ClassNode *temp = head;

        if (temp == null || temp->classNextPointer == null)
            return head;

        ClassNode *restHead = recursiveReverseOfSll(head->classNextPointer);
        ClassNode *restTail = head->classNextPointer;
        restTail->classNextPointer = head;
        head->classNextPointer = null;

        return restHead; */

        // Method 2
        ClassNode *temp = head;

        if (temp == null)
            return prev;

        ClassNode *next = temp->classNextPointer;
        temp->classNextPointer = prev;
        return recursiveReverseOfSll(next, temp);
    }

    ClassNode *removeDuplicatesFromSortedSll(ClassNode *head)
    {
        ClassNode *temp = head, *prev = head;

        while (temp != null)
        {
            if (temp->classData != prev->classData)
            {
                prev->classNextPointer = temp;
                prev = temp;
            }
            temp = temp->classNextPointer;
        }
        if (prev != temp)
            prev->classNextPointer = null;
        return head;
    }

    ClassNode *reverseSllInkSizedGroup(ClassNode *head, int k)
    {
        // Recursive Approach
        /* ClassNode *curr = head, *next = NULL, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->classNextPointer;
            curr->classNextPointer = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
        {
            ClassNode *rest_head = reverseSllInkSizedGroup(next, k);
            head->classNextPointer = rest_head;
        }
        return prev; */

        // Iterative Approach
        ClassNode *curr = head, *prevFirst = NULL;
        bool isFirstPass = true;
        while (curr != NULL)
        {
            ClassNode *first = curr, *prev = NULL;
            int count = 0;
            while (curr != NULL && count < k)
            {
                ClassNode *next = curr->classNextPointer;
                curr->classNextPointer = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if (isFirstPass)
            {
                head = prev;
                isFirstPass = false;
            }
            else
            {
                prevFirst->classNextPointer = prev;
            }
            prevFirst = first;
        }
        return head;
    }

    bool detectLoopIn(ClassNode *head)
    {
        // Changing Pointers
        /* ClassNode *temp = new ClassNode(0);
        ClassNode *curr = head;
        while (curr != NULL)
        {
            if (curr->classNextPointer == NULL)
                return false;
            if (curr->classNextPointer == temp)
                return true;
            ClassNode *curr_next = curr->classNextPointer;
            curr->classNextPointer = temp;
            curr = curr_next;
        }
        return false; */

        // Using Hashing
        /* unordered_set<ClassNode *> s;
        for (ClassNode *curr = head; curr != NULL; curr = curr->classNextPointer)
        {
            if (s.find(curr) != s.end())
                return true;
            s.insert(curr);
        }
        return false; */

        // Using Floyd Cycle Detection Algorithm
        ClassNode *slow_p = head, *fast_p = head;

        while (fast_p != NULL && fast_p->classNextPointer != NULL)
        {
            slow_p = slow_p->classNextPointer;
            fast_p = fast_p->classNextPointer->classNextPointer;
            if (slow_p == fast_p)
                return true;
        }
        return false;
    }

    void detectAndRemoveLoopFrom(ClassNode *head)
    {
        // loop detection logic
        ClassNode *slow = head, *fast = head;

        while (fast != NULL && fast->classNextPointer != NULL)
        {
            slow = slow->classNextPointer;
            fast = fast->classNextPointer->classNextPointer;
            if (slow == fast)
            {
                break;
            }
        }
        if (slow != fast)
            return;

        // loop removal logic
        slow = head;
        while (slow->classNextPointer != fast->classNextPointer)
        {
            slow = slow->classNextPointer;
            fast = fast->classNextPointer;
        }
        fast->classNextPointer = NULL;
    }

    // not applicable for the last node of SLL
    void deleteRandom(ClassNode *ptr)
    {
        ClassNode *temp = ptr->classNextPointer;
        ptr->classData = temp->classData;
        ptr->classNextPointer = temp->classNextPointer;
        delete (temp);
    }

    ClassNode *segregateEvenOddFrom(ClassNode *head)
    {
        ClassNode *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;
        for (ClassNode *curr = head; curr != NULL; curr = curr->classNextPointer)
        {
            int x = curr->classData;
            if (x % 2 == 0)
            {
                if (evenStart == NULL)
                {
                    evenStart = curr;
                    evenEnd = evenStart;
                }
                else
                {
                    evenEnd->classNextPointer = curr;
                    evenEnd = evenEnd->classNextPointer;
                }
            }
            else
            {
                if (oddStart == NULL)
                {
                    oddStart = curr;
                    oddEnd = oddStart;
                }
                else
                {
                    oddEnd->classNextPointer = curr;
                    oddEnd = oddEnd->classNextPointer;
                }
            }
        }
        if (oddStart == NULL || evenStart == NULL)
            return head;
        evenEnd->classNextPointer = oddStart;
        oddEnd->classNextPointer = NULL;
        return evenStart;
    }

    int intersectionPointOf(ClassNode *head1, ClassNode *head2)
    {
        // Using Hashing
        /* unordered_set<ClassNode *> s;
        ClassNode *curr = head1;
        while (curr != NULL)
        {
            s.insert(curr);
            curr = curr->classNextPointer;
        }
        curr = head2;
        while (curr != NULL)
        {
            if (s.find(curr) != s.end())
                return curr->classData;
            curr = curr->classNextPointer;
        }
        return -1; */

        // Using Length of lists
        int c1 = getCount(head1);
        int c2 = getCount(head2);
        int d;

        if (c1 > c2)
        {
            d = c1 - c2;
            return _getIntersection(d, head1, head2);
        }
        else
        {
            d = c2 - c1;
            return _getIntersection(d, head2, head1);
        }
    }

    ClassNode *pairSwap(ClassNode *head)
    {
        // Changing data
        /* ClassNode *curr = head;
        while (curr != NULL && curr->classNextPointer != NULL)
        {
            swap(curr->classData, curr->classNextPointer->classData);
            curr = curr->classNextPointer->classNextPointer;
        } */

        // Changing links
        if (head == NULL || head->classNextPointer == NULL)
            return head;

        ClassNode *curr = head->classNextPointer->classNextPointer;
        ClassNode *prev = head;

        head = head->classNextPointer;
        head->classNextPointer = prev;

        while (curr != NULL && curr->classNextPointer != NULL)
        {
            prev->classNextPointer = curr->classNextPointer;
            prev = curr;
            ClassNode *next = curr->classNextPointer->classNextPointer;
            curr->classNextPointer->classNextPointer = curr;
            curr = next;
        }
        prev->classNextPointer = curr;
        return head;
    }

    ClassNode *mergeSorted(ClassNode *head1, ClassNode *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        ClassNode *head = NULL, *tail = NULL;
        if (head1->classData <= head2->classData)
        {
            head = tail = head1;
            head1 = head1->classNextPointer;
        }
        else
        {
            head = tail = head2;
            head2 = head2->classNextPointer;
        }
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->classData <= head2->classData)
            {
                tail->classNextPointer = head1;
                tail = head1;
                head1 = head1->classNextPointer;
            }
            else
            {
                tail->classNextPointer = head2;
                tail = head2;
                head2 = head2->classNextPointer;
            }
        }
        if (head1 == NULL)
        {
            tail->classNextPointer = head2;
        }
        else
        {
            tail->classNextPointer = head1;
        }
        return head;
    }

    bool isPalindrome(ClassNode *head)
    {
        // Naive Approach
        /* stack<char> st;
        for (ClassNode *curr = head; curr != NULL; curr = curr->classNextPointer)
            st.push(curr->classData);
        for (ClassNode *curr = head; curr != NULL; curr = curr->classNextPointer)
        {
            if (st.top() != curr->classData)
                return false;
            st.pop();
        }
        return true; */

        // Efficient Approach
        if (head == NULL)
            return true;
        ClassNode *slow = head, *fast = head;
        while (fast->classNextPointer != NULL && fast->classNextPointer->classNextPointer != NULL)
        {
            slow = slow->classNextPointer;
            fast = fast->classNextPointer->classNextPointer;
        }
        ClassNode *rev = reverseList(slow->classNextPointer);
        ClassNode *curr = head;
        while (rev != NULL)
        {
            if (rev->classData != curr->classData)
                return false;
            rev = rev->classNextPointer;
            curr = curr->classNextPointer;
        }
        return true;
    }
};

// LRU Cache design using ll
class LRUCache
{
public:
    unordered_map<int, Node *> map;
    int capacity, count;
    Node *head, *tail;

    LRUCache(int c)
    {
        capacity = c;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->next = NULL;
        count = 0;
    }

    void deleteNode(Node *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(Node *node)
    {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    int get(int key)
    {
        if (map[key] != NULL)
        {
            Node *node = map[key];
            int result = node->value;
            deleteNode(node);
            addToHead(node);
            cout << "Got the value : " << result << " for the key: " << key << endl;
            return result;
        }
        cout << "Did not get any value"
             << " for the key: " << key << endl;
        return -1;
    }

    void set(int key, int value)
    {
        cout << "Going to set the (key, "
             << "value) : (" << key << ", " << value << ")" << endl;
        if (map[key] != NULL)
        {
            Node *node = map[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            map[key] = node;
            if (count < capacity)
            {
                count++;
                addToHead(node);
            }
            else
            {
                map.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};

int main()
{
    // Modify the main function as you want to test the library
    return 0;
}