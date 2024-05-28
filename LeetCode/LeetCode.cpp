#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// Time Complexity = O(n) - push, O(1) - pop, peek, empty
// Space Complexity = O(n) - MyQueue Class
// Detyra 1 --------------------------------------------------------------------------------------------------

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }

    void push(int x) {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {

        if (empty()) {
            cout << "Rreshti eshte i zbrazet!" << endl;
            return -1;
        }

        int temp = s1.top();
        s1.pop();

        return temp;

    }

    int peek() {
        if (empty()) {
            cout << "Rreshti eshte i zbrazet!" << endl;
            return -1;
        }

        return s1.top();
    }

    bool empty() {
        return s1.empty();

    }
};


// Time Complexity = O(n) - push, O(1) - pop, top, empty
// Space Complexity = O(n)
// Detyra 2 --------------------------------------------------------------------------------------------------

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {

    }

    void push(int x) {
        que2.push(x);

        while (!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }

        swap(que1, que2);
    }

    int pop() {
        if (empty()) {
            cout << "Rreshti eshte i zbrazet!" << endl;
            return -1;
        }

        int result = que1.front();
        que1.pop();

        return result;
    }

    int top() {
        if (empty()) {
            cout << "Rreshti eshte i zbrazet!" << endl;
            return -1;
        }

        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};



// Time Complexity = O(n * m) - nextGreaterElement, O(n) - findPosition
// Space Complexity = O(n)
// Detyra 3 --------------------------------------------------------------------------------------------------

class Solution3 {
public:
    int findPosition(vector<int> nums2, int key)
    {
        int n = nums2.size();
        for (int i = 0; i < n; i++)
        {
            if (nums2[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int elementi = nums1[i];
            int vlera = -1;
            int pozita = findPosition(nums2, elementi);
            for (int j = pozita + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > elementi)
                {
                    vlera = nums2[j];
                    break;
                }
                else continue;
            }
            ans.push_back(vlera);
        }
        return ans;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 4 --------------------------------------------------------------------------------------------------

class Solution4 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> kerkesat(2, 0);
        for (const int& student : students)
            kerkesat[student]++;

        for (const int& sandwich : sandwiches) {
            if (kerkesat[sandwich] == 0)
                return kerkesat[1 - sandwich];
            else
                kerkesat[sandwich]--;
        }

        return 0;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 5 --------------------------------------------------------------------------------------------------

class Solution5 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int rezultati = 0;

        for (int i = 0; i < tickets.size(); ++i) {

            if (i <= k) {
                rezultati += min(tickets[i], tickets[k]);
            }
            else {
                rezultati += min(tickets[i], tickets[k] - 1);
            }

        }
        return rezultati;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 6 --------------------------------------------------------------------------------------------------

struct ListNode6 {
    int val;
    ListNode6 *next;
    ListNode6() : val(0), next(nullptr) {}
    ListNode6(int x) : val(x), next(nullptr) {}
    ListNode6(int x, ListNode6 *next) : val(x), next(next) {}
};
 
class Solution6 {
public:
    ListNode6* middleNode(ListNode6* head) {
        ListNode6* temp = head;
        ListNode6* temp2 = head;

        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
            if (temp != 0)
                temp = temp->next;
            temp2 = temp2->next;

        }
        return temp2;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 7 --------------------------------------------------------------------------------------------------

struct ListNode7 {
    int val;
    ListNode7 *next;
    ListNode7() : val(0), next(nullptr) {}
    ListNode7(int x) : val(x), next(nullptr) {}
    ListNode7(int x, ListNode7 *next) : val(x), next(next) {}
};

class Solution7 {
public:
    ListNode7* reverseList(ListNode7* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode7* before = NULL;
        ListNode7* h2 = reverseList(head->next);

        head->next->next = head;
        head->next = before;

        return h2;
    }

};

void addNode7(ListNode7*& head, int value) {
    ListNode7* newNode = new ListNode7(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode7* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 8 --------------------------------------------------------------------------------------------------

struct ListNode8 {
    int val;
    ListNode8 *next;
    ListNode8(int x) : val(x), next(NULL) {}
};

class Solution8 {
public:
    bool hasCycle(ListNode8* head) {
        ListNode8* slow = head;
        ListNode8* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 9 --------------------------------------------------------------------------------------------------

struct ListNode9 {
    int val;
    ListNode9 *next;
    ListNode9() : val(0), next(nullptr) {}
    ListNode9(int x) : val(x), next(nullptr) {}
    ListNode9(int x, ListNode9 *next) : val(x), next(next) {}
};
 
class Solution9 {
public:
    ListNode9* deleteDuplicates(ListNode9* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        int temp = head->val;
        ListNode9* tempHead = head->next;
        ListNode9* prev = head;

        while (tempHead != NULL) {
            if (tempHead->val != temp) {
                temp = tempHead->val;
                prev = tempHead;
                tempHead = tempHead->next;
            }
            else {
                prev->next = tempHead->next;
                tempHead = prev->next;
            }
        }

        return head;
    }
};

void printList(ListNode9* head) {
    ListNode9* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addNode9(ListNode9*& head, int value) {
    ListNode9* newNode = new ListNode9(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode9* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 10 --------------------------------------------------------------------------------------------------

struct ListNode10 {
    int val;
    ListNode10 *next;
    ListNode10() : val(0), next(nullptr) {}
    ListNode10(int x) : val(x), next(nullptr) {}
    ListNode10(int x, ListNode10 *next) : val(x), next(next) {}
};

class Solution10 {
public:
    ListNode10* removeElements(ListNode10* head, int vlera) {

        while (head && head->val == vlera) {
            head = head->next;
        }

        auto temp = head;
        auto before = head;

        while (temp) {
            if (temp->val == vlera) {
                before->next = temp->next;
            }
            else {
                before = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};

void printList10(ListNode10* head) {
    ListNode10* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addNode10(ListNode10*& head, int value) {
    ListNode10* newNode = new ListNode10(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode10* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool containsValue10(ListNode10* head, int targetValue) {
    ListNode10* temp = head;
    while (temp != nullptr) {
        if (temp->val == targetValue) {
            return true; 
        }
        temp = temp->next;
    }
    return false; 
}



// Time Complexity = O(n)
// Space Complexity = O(h)
// Detyra 11 --------------------------------------------------------------------------------------------------

struct TreeNode11 {
    int val;
    TreeNode11 *left;
    TreeNode11 *right;
    TreeNode11() : val(0), left(nullptr), right(nullptr) {}
    TreeNode11(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode11(int x, TreeNode11 *left, TreeNode11 *right) : val(x), left(left), right(right) {}
};

class Solution11 {
public:
    int rangeSumBST(TreeNode11* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }

        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high)
                + rangeSumBST(root->right, low, high);
        }

        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        return rangeSumBST(root->left, low, high);
    }
};

TreeNode11* insert11(TreeNode11* root, int value) {
    if (root == nullptr)
        return new TreeNode11(value);
    if (value < root->val)
        root->left = insert11(root->left, value);
    else if (value > root->val)
        root->right = insert11(root->right, value);
    return root;
}



// Time Complexity = O(n) (rasti me i keq - pema eshte e njeanshme), O(log(n)) (rasti mesatar, pema e balancuar)
// Space Complexity = O(h) (rasti me i keq - pema eshte e njeanshme), O(log(n)) (rasti mesatar, pema e balancuar)
// Detyra 12 --------------------------------------------------------------------------------------------------

struct TreeNode12 {
    int val;
    TreeNode12 *left;
    TreeNode12 *right;
    TreeNode12() : val(0), left(nullptr), right(nullptr) {}
    TreeNode12(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode12(int x, TreeNode12 *left, TreeNode12 *right) : val(x), left(left), right(right) {}
};

class Solution12 {
public:
    TreeNode12* searchBST(TreeNode12* root, int val) {

        if (root == NULL) {
            return NULL;
        }

        if (root->val == val) {
            return root;
        }

        if (val < root->val) {
            root = searchBST(root->left, val);
        }
        else {
            root = searchBST(root->right, val);
        }

        return root;
    }
};

TreeNode12* insert12(TreeNode12* root, int value) {
    if (root == nullptr)
        return new TreeNode12(value);
    if (value < root->val)
        root->left = insert12(root->left, value);
    else if (value > root->val)
        root->right = insert12(root->right, value);
    return root;
}

void inorder12(TreeNode12* root) {
    if (root == nullptr)
        return;
    inorder12(root->left);
    cout << root->val << " ";
    inorder12(root->right);
}



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 13 --------------------------------------------------------------------------------------------------

struct TreeNode13 {
    int val;
    TreeNode13 *left;
    TreeNode13 *right;
    TreeNode13() : val(0), left(nullptr), right(nullptr) {}
    TreeNode13(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode13(int x, TreeNode13 *left, TreeNode13 *right) : val(x), left(left), right(right) {}
};

class Solution13 {
public:
    void inorder(TreeNode13* root, vector<int>& arr)
    {
        if (root == NULL) {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode13* increasingBST(TreeNode13* root) {
        vector<int> arr;
        inorder(root, arr);

        root->val = arr[0];

        root->left = NULL;
        root->right = NULL;

        TreeNode13* dummy = root;

        for (int i = 1; i < arr.size(); i++) {
            TreeNode13* newNode = new TreeNode13(arr[i]);
            root->right = newNode;
            root = newNode;
        }
        return dummy;
    }
};

TreeNode13* insert13(TreeNode13* root, int value) {
    if (root == nullptr)
        return new TreeNode13(value);
    if (value < root->val)
        root->left = insert13(root->left, value);
    else if (value > root->val)
        root->right = insert13(root->right, value);
    return root;
}

void inorder13(TreeNode13* root) {
    if (root == nullptr)
        return;
    inorder13(root->left);
    cout << root->val << " ";
    inorder13(root->right);
}



// Time Complexity = O(n)
// Space Complexity = O(h) (rasti me i keq, pema e njeanshme), O(log(n)) (rasti mesatar, pema e balancuar)
// Detyra 14 --------------------------------------------------------------------------------------------------

struct TreeNode14 {
    int val;
    TreeNode14 *left;
    TreeNode14 *right;
    TreeNode14() : val(0), left(nullptr), right(nullptr) {}
    TreeNode14(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode14(int x, TreeNode14 *left, TreeNode14 *right) : val(x), left(left), right(right) {}
};

class Solution14 {
public:
    TreeNode14* sort(vector<int>& nums, int low, int high) {

        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode14* root = new TreeNode14(nums[mid]);
            root->left = sort(nums, low, mid - 1);
            root->right = sort(nums, mid + 1, high);
            return root;
        }

        return nullptr;

    }
    TreeNode14* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
};

void printBFS14(TreeNode14* root) {
    if (root == nullptr)
        return;

    queue<TreeNode14*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode14* curr = q.front();
            q.pop();
            cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 15 --------------------------------------------------------------------------------------------------

struct TreeNode15 {
    int val;
    TreeNode15 *left;
    TreeNode15 *right;
    TreeNode15() : val(0), left(nullptr), right(nullptr) {}
    TreeNode15(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode15(int x, TreeNode15 *left, TreeNode15 *right) : val(x), left(left), right(right) {}
};

class Solution15 {
public:
    void inorder(TreeNode15* root, vector<int>& t) {
        if (root != NULL) {
            inorder(root->left, t);
            t.push_back(root->val);
            inorder(root->right, t);
        }
    }

    bool findTarget(TreeNode15* root, int k) {
        vector<int> t;
        inorder(root, t);
        int i = 0; int j = t.size() - 1;

        while (i < j) {
            int temp = t[i] + t[j];
            if (temp == k)
                return true;
            if (temp < k)
                i++;
            else
                j--;
        }
        return false;
    }
};

TreeNode15* insert15(TreeNode15* root, int value) {
    if (root == nullptr)
        return new TreeNode15(value);
    if (value < root->val)
        root->left = insert15(root->left, value);
    else if (value > root->val)
        root->right = insert15(root->right, value);
    return root;
}



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 16 --------------------------------------------------------------------------------------------------

class Solution16 {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> hash_map;

        for (auto x : nums) {
            hash_map[x]++;
        }

        int shuma = 0;
        for (auto x : hash_map) {
            if (x.second == 1) {
                shuma += x.first;
            }
        }

        return shuma;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 17 --------------------------------------------------------------------------------------------------

class Solution17 {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> hash_map;

        for (int i = 0; i < s.length(); i++) {
            if (hash_map.find(s[i]) != hash_map.end()) {
                return s[i];
            }

            hash_map[s[i]] = i;
        }

        return '-1';
    }
};

bool containsNumbers(const string& input) {
    for (char c : input) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 18 --------------------------------------------------------------------------------------------------

class Solution18 {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hash_map;

        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
        }

        int maks = 0;
        for (int i = 0; i < nums.size(); i++) {
            maks = max(maks, hash_map[nums[i]]);
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_map[nums[i]] == maks) {
                count++;
            }
        }

        return count;
    }
};



// Time Complexity = O(n)
// Space Complexity = O(n)
// Detyra 19 --------------------------------------------------------------------------------------------------

class Solution19 {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash_map;

        for (int i = 0; i < arr.size(); i++) {
            hash_map[arr[i]]++;
        }

        set<int> unique_frec;
        for (auto i : hash_map) {
            unique_frec.insert(i.second);
        }

        if (unique_frec.size() != hash_map.size()) {
            return false;
        }
        else {
            return true;
        }
    }
};



// Time Complexity = O(n)
// Space Complexity = O(1)
// Detyra 20 --------------------------------------------------------------------------------------------------

class Solution20 {
public:
    bool digitCount(string num) {
        unordered_map<int, int> hash_map;

        for (auto i : num) {
            hash_map[i - '0']++;
        }

        for (int i = 0; i < num.size(); i++) {
            if (num[i] - '0' != hash_map[i]) {
                return false;
            }
        }

        return true;
    }
};

bool containsNonNumeric(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return true;
        }
    }
    return false;
}




// Funksioni Main --------------------------------------------------------------------------------------------

int main() {

    kthehuFillimiProgramit:
	int zgjidhja;
	cout << "Zgjedhni nje nga algoritmet: " << endl;
    cout << "Implement Queue using Stacks (1)" << endl;
    cout << "Implement Stack using Queues (2)" << endl;
    cout << "Next Greater Element (3)" << endl;
    cout << "Number of Students Unable to Eat Lunch (4)" << endl;
    cout << "Time Needed to Buy Tickets (5)" << endl;
    cout << "Middle of the Linked List (6)" << endl;
    cout << "Reverse Linked List (7)" << endl;
    cout << "Linked List Cycle (8)" << endl;
    cout << "Remove Duplicates from Sorted List (9)" << endl;
    cout << "Remove Linked List Elements (10)" << endl;
    cout << "Range Sum of BST (11)" << endl;
    cout << "Search in a BST (12)" << endl;
    cout << "Increasing Order Search Tree (13)" << endl;
    cout << "Convert Sorted Array to BST (14)" << endl;
    cout << "Two Sum IV - Input is a BST (15)" << endl;
    cout << "Sum of Unique Elements (16)" << endl;
    cout << "First Letter to Appear Twice (17)" << endl;
    cout << "Count Elements With Maximum Frequency (18)" << endl;
    cout << "Unique Number of Ocurrences (19)" << endl;
    cout << "Check if Number Has Equal Digit Count and Digit Value (20)" << endl;
	cin >> zgjidhja;


    // Detyra 1 --------------------
    MyQueue* queue = new MyQueue(); 
    //------------------------------


    // Detyra 2 --------------------
    MyStack* stack = new MyStack(); 
    //------------------------------
    

    // Detyra 3 --------------------
    Solution3* s3 = new Solution3(); 
    vector<int> nums1;
    vector<int> nums2;
    vector<int> rez;
    //------------------------------


    // Detyra 4 --------------------
    Solution4* s4 = new Solution4(); 
    vector<int> studentet;
    vector<int> sandwichet;
    //------------------------------


    // Detyra 5 --------------------
    Solution5* s5 = new Solution5(); 
    vector<int> biletat;
    //------------------------------


    // Detyra 6 --------------------
    Solution6* s6 = new Solution6();
    ListNode6* head6 = nullptr;
    ListNode6* mesi = nullptr;
    //------------------------------


    // Detyra 7 --------------------
    Solution7* s7 = new Solution7();
    ListNode7* head7 = nullptr;
    //------------------------------


    // Detyra 8 --------------------
    Solution8* s8 = new Solution8();
    ListNode8* head8 = nullptr;
    ListNode8* tail8 = nullptr;
    //------------------------------


    // Detyra 9 --------------------
    Solution9* s9 = new Solution9();
    ListNode9* head9 = nullptr;
    ListNode9* rez9 = nullptr;
    //------------------------------


    // Detyra 10 -------------------
    Solution10* s10 = new Solution10();
    ListNode10* head10 = nullptr;
    ListNode10* rez10 = nullptr;
    bool found = false;
    //------------------------------


    // Detyra 11 -------------------
    Solution11* s11 = new Solution11();
    TreeNode11* root11 = nullptr;
    //------------------------------


    // Detyra 12 -------------------
    Solution12* s12 = new Solution12();
    TreeNode12* root12 = nullptr;
    TreeNode12* rez12 = nullptr;
    //------------------------------


    // Detyra 13 -------------------
    Solution13* s13 = new Solution13();
    TreeNode13* root13 = nullptr;
    TreeNode13* rez13 = nullptr;
    //------------------------------


    // Detyra 14 -------------------
    Solution14* s14 = new Solution14();
    TreeNode14* root14 = nullptr;
    vector<int> arr14;
    //------------------------------


    // Detyra 15 -------------------
    Solution15* s15 = new Solution15();
    TreeNode15* root15 = nullptr;
    //------------------------------


    // Detyra 16 -------------------
    Solution16* s16 = new Solution16();
    vector<int> arr16;
    //------------------------------


    // Detyra 17 -------------------
    Solution17* s17 = new Solution17();
    string fjala17;
    //------------------------------

    
    // Detyra 18 -------------------
    Solution18* s18 = new Solution18();
    vector<int> arr18;
    //------------------------------


    // Detyra 19 -------------------
    Solution19* s19 = new Solution19();
    vector<int> arr19;
    string rez19;
    //------------------------------


    // Detyra 20 -------------------
    Solution20* s20 = new Solution20();
    string fjala20;
    string rez20;
    //------------------------------


    // Funksioni switch --------------------
	switch (zgjidhja)
	{
	case 1: // Detyra 1 --------------------
        int numri1;
        int perseritja1;
        int zgjedhF1;

        cout << "Sa numra deshironi te shtoni? ";
        cin >> perseritja1;

        for (int i = 0; i < perseritja1; i++) {
            cout << "Shenoni nje numer: ";
            cin >> numri1;
            queue->push(numri1);
        }
        
        kthehuF1:
        cout << "Deshironi te zgjedhni funksionin pop, peek apo empty? (1, 2, 3)? ";
        cin >> zgjedhF1;

        switch (zgjedhF1) {
        case 1:
            cout << queue->pop() << " u largua nga rreshti." << endl;
            break;
        case 2:
            cout << queue->peek() << " eshte anetari i pare ne rresht." << endl;
            break;
        case 3:
            if (queue->empty()) {
                cout << "Rreshti eshte i zbrazet." << endl;
            }
            else {
                cout << "Rreshti nuk eshte i zbrazet." << endl;
            }
            break;
        default:
            cout << "Zgjedhni 1, 2 ose 3! " << endl;
            goto kthehuF1;
        }

		break;



	case 2: // Detyra 2 --------------------
        int numri2;
        int perseritja2;
        int zgjedhF2;

        cout << "Sa numra deshironi te shtoni? ";
        cin >> perseritja2;

        for (int i = 0; i < perseritja2; i++) {
            cout << "Shenoni nje numer: ";
            cin >> numri2;
            stack->push(numri2);
        }

    kthehuF2:
        cout << "Deshironi te zgjedhni funksionin pop, top apo empty? (1, 2, 3)? ";
        cin >> zgjedhF2;

        switch (zgjedhF2) {
        case 1:
            cout << stack->pop() << " u largua nga steku." << endl;
            break;
        case 2:
            cout << stack->top() << " eshte anetari i fundit ne stek." << endl;
            break;
        case 3:
            if (stack->empty()) {
                cout << "Steku eshte i zbrazet." << endl;
            }
            else {
                cout << "Steku nuk eshte i zbrazet." << endl;
            }
            break;
        default:
            cout << "Zgjedhni 1, 2 ose 3! " << endl;
            goto kthehuF2;
        }
		
		break;



    case 3: // Detyra 3 --------------------
        int numri, nums1size, nums2size;

        cout << "Sa numra deshironi te shtoni ne vektorin e pare? ";
        cin >> nums1size;
        cout << "Shenoni " << nums1size << " numra per vektorin e pare : " << endl;

        for (int i = 0; i < nums1size; i++) {
            cin >> numri;
            nums1.push_back(numri);
        }

        cout << "Sa numra deshironi te shtoni ne vektorin e dyte? ";
        cin >> nums2size;
        cout << "Shenoni " << nums2size << " numra per vektorin e dyte: " << endl;

        for (int i = 0; i < nums2size; i++) {
            cin >> numri;
            nums2.push_back(numri);
        }

        rez = s3->nextGreaterElement(nums1, nums2);

        for (int elementet : rez) {
            cout << elementet << " ";
        }

        cout << endl;
        
        break;



    case 4: // Detyra 4 --------------------
        int studentetSize, sandwichetSize, nrStudenteve, nr;
        cout << "Sa studente dhe sandwiche deshironi te shtoni? ";
        cin >> studentetSize;
        cout << "Shenoni " << studentetSize << " studente (0 - preferon sendwich rrumbullak, 1 - preferon sendwich katror): " << endl;

        for (int i = 0; i < studentetSize; i++) {
            do {
                cin >> nr;
            } while (nr != 0 && nr != 1);
            studentet.push_back(nr);
        }

        cout << "Shenoni " << studentetSize << " sendwiche (0 - sendwich rrumbullak, 1 - sendwich katror): " << endl;

        for (int i = 0; i < studentetSize; i++) {
            do {
                cin >> nr;
            } while (nr != 0 && nr != 1);
            sandwichet.push_back(nr);
        }

        nrStudenteve = s4->countStudents(studentet, sandwichet);

        cout << "Numri i studenteve qe mbesin pa ngrene: " << nrStudenteve << endl;

        break;



    case 5: // Detyra 5 --------------------
        int nrPersonave, nrBiletave, koha, personi;
        cout << "Sa persona deshironi ne rresht? ";
        cin >> nrPersonave;
        cout << "Shenoni " << nrPersonave << " numra te sasise se biletave: " << endl;

        for (int i = 0; i < nrPersonave; i++) {
            cin >> nrBiletave;
         
            biletat.push_back(nrBiletave);
        }

        kthehuPersoni:
        cout << "Shenoni numrin e personit per te cilin deshiron te matesh kohen: ";
        cin >> personi;

        if (personi > biletat.size() || personi < 1) {
            cout << "Zgjedh nje person brenda rreshtit!" << endl;
            goto kthehuPersoni;
        }

        koha = s5->timeRequiredToBuy(biletat, personi - 1);

        cout << "Koha ne sekonda: " << koha << endl;

        break;



    case 6: // Detyra 6 --------------------
        int numElements6;

        cout << "Shenoni numrin e elementeve ne liste: ";
        cin >> numElements6;

        cout << "Shenoni " << numElements6 << " elemente: " << endl;
        for (int i = 0; i < numElements6; ++i) {

            int elementi6;
            cin >> elementi6;

            ListNode6* newNode = new ListNode6(elementi6);
            newNode->next = head6;
            head6 = newNode;
        }

        mesi = s6->middleNode(head6);

        cout << "Elementi i mesit ne liste: " << mesi->val << endl;

        break;



    case 7: // Detyra 7 --------------------
        int numElements7;

        cout << "Shenoni numrin e elementeve ne liste: ";
        cin >> numElements7;

        cout << "Shenoni " << numElements7 << " elemente: " << endl;
        for (int i = 0; i < numElements7; ++i) {
            int elementi7;
            cin >> elementi7;
            addNode7(head7, elementi7);
        }

        head7 = s7->reverseList(head7);

        cout << "Lista reverse: ";
        
        while (head7) {
            cout << head7->val << " ";
            head7 = head7->next;
        }
        cout << endl;

        break;



    case 8: // Detyra 8 --------------------
        int numElements8;
        cout << "Shenoni numrin e elementeve ne liste: ";
        cin >> numElements8;

        cout << "Shenoni " << numElements8 << " elemente: " << endl;
        for (int i = 0; i < numElements8; ++i) {
            int elementi8;
            cin >> elementi8;

            ListNode8* newNode = new ListNode8(elementi8);
            if (!head8) {
                head8 = newNode;
                tail8 = newNode;
            }
            else {
                tail8->next = newNode;
                tail8 = newNode;
            }
        }

        int zgjedh8;
        cout << "Deshironi te keni cikel ne liste (1-PO, 0-JO)? ";
        do {
            cin >> zgjedh8;
        } while (zgjedh8 != 1 && zgjedh8 != 0);

        if (zgjedh8 == 1) {
            int index8;
            cout << "Shenoni indeksin ku deshironi qe cikli te krijohet (elementi i fundit do te pointoje tek ky element): ";
            cin >> index8;

            if (index8 >= 0) {
                ListNode8* current = head8;
                ListNode8* target = nullptr;
                int currentIndex = 0;

                while (current) {
                    if (currentIndex == index8) {
                        target = current;
                        break;
                    }
                    current = current->next;
                    currentIndex++;
                }

                if (target) {
                    tail8->next = target;
                    cout << "Cikli u krijua: elementi i fundit pointon tek elementi " << target->val << endl;
                }
                else {
                    cout << "Indeksi jashte liste." << endl;
                }
            }
        }

        if (s8->hasCycle(head8)) {
            cout << "Cikli u detektua ne liste." << endl;
        }
        else {
            cout << "Nuk ka cikel ne liste." << endl;
        }

        break;



    case 9: // Detyra 9 --------------------
        int numElements9;

        cout << "Shenoni numrin e elementeve ne liste: ";
        cin >> numElements9;

        cout << "Shenoni " << numElements9 << " elemente: " << endl;
        for (int i = 0; i < numElements9; ++i) {
            int elementi9;
            cin >> elementi9;
            addNode9(head9, elementi9);
        }

        rez9 = s9->deleteDuplicates(head9);

        printList(rez9);

        break;



    case 10: // Detyra 10 ------------------
        int numElements10, largo10;

        cout << "Shenoni numrin e elementeve ne liste: ";
        cin >> numElements10;

        cout << "Shenoni " << numElements10 << " elemente: " << endl;
        for (int i = 0; i < numElements10; ++i) {
            int elementi10;
            cin >> elementi10;
            addNode10(head10, elementi10);
        }

        cout << "Shenoni elementin qe deshironi te largoni: ";
        cin >> largo10;

        found = containsValue10(head10, largo10);

        if (!found) {
            cout << "Elementi me vleren " << largo10 << " nuk gjendet ne liste." << endl;
        }
        else {
            rez10 = s10->removeElements(head10, largo10);
            printList10(rez10);
            cout << "Elementi me vleren " << largo10 << " u largua nga lista." << endl;
        }

        break;

    case 11: // Detyra 11 ------------------
        int numValues11, shuma11, low11, high11;

        cout << "Sa nyje deshironi te shtoni ne pemen binare? ";
        cin >> numValues11;

        cout << "Shenoni " << numValues11 << " numra: ";
        for (int i = 0; i < numValues11; ++i) {
            int value11;
            cin >> value11;
            root11 = insert11(root11, value11);
        }

        cout << "Shenoni minimumin: ";
        cin >> low11;

        cout << "Shenoni maksimumin: ";
        cin >> high11;

        shuma11 = s11->rangeSumBST(root11, low11, high11);

        cout << "Shuma e nyjeve mes vlerave "<< low11 << " dhe " << high11 << ": " << shuma11 << endl;

        break;



    case 12: // Detyra 12 ------------------
        int numValues12, vlera12;

        cout << "Sa nyje deshironi te shtoni ne pemen binare? ";
        cin >> numValues12;

        cout << "Shenoni " << numValues12 << " numra: ";
        for (int i = 0; i < numValues12; ++i) {
            int value12;
            cin >> value12;
            root12 = insert12(root12, value12);
        }

        cout << "Shenoni vleren te cilen deshironi te kerkoni ne peme: ";
        cin >> vlera12;

        inorder12(s12->searchBST(root12, vlera12));

        break;



    case 13: // Detyra 13 ------------------
        int numValues13;

        cout << "Sa nyje deshironi te shtoni ne pemen binare? ";
        cin >> numValues13;

        cout << "Shenoni " << numValues13 << " numra: ";
        for (int i = 0; i < numValues13; ++i) {
            int value13;
            cin >> value13;
            root13 = insert13(root13, value13);
        }

        inorder13(s13->increasingBST(root13));

        break;



    case 14: // Detyra 14 ------------------
        int numValues14;

        cout << "Sa anetare deshironi te shtoni ne varg? ";
        cin >> numValues14;

        cout << "Shenoni " << numValues14 << " numra: ";
        for (int i = 0; i < numValues14; i++) {
            int value14;
            cin >> value14;
            arr14.push_back(value14);
        }

        printBFS14(s14->sortedArrayToBST(arr14));

        break;



    case 15: // Detyra 15 ------------------
        int numValues15, shumaKerkuar;

        cout << "Sa nyje deshironi te shtoni ne pemen binare? ";
        cin >> numValues15;

        cout << "Shenoni " << numValues15 << " numra: ";
        for (int i = 0; i < numValues15; ++i) {
            int value15;
            cin >> value15;
            root15 = insert15(root15, value15);
        }

        cout << "Shenoni shumen e kerkuar mes dy nyjeve: ";
        cin >> shumaKerkuar;

        if ((s15->findTarget(root15, shumaKerkuar))) {
            cout << "Shuma ekziston." << endl;
        }
        else {
            cout << "Shuma nuk ekziston." << endl;
        }

        break;



    case 16: // Detyra 16 ------------------
        int numValues16, shuma16;

        cout << "Sa anetare deshironi te shtoni ne varg? ";
        cin >> numValues16;

        cout << "Shenoni " << numValues16 << " numra: ";
        for (int i = 0; i < numValues16; i++) {
            int value16;
            cin >> value16;
            arr16.push_back(value16);
        }

        shuma16 = s16->sumOfUnique(arr16);

        cout << "Shuma e anetareve unik ne varg: " << shuma16 << endl;

        break;



    case 17: // Detyra 17 ------------------
        kthehu17:
        cout << "Shenoni nje fjale te vetme: ";
        cin >> fjala17;

        if (containsNumbers(fjala17)) {
            cout << "Shenoni vetem fjale te vetme, jo numra!" << endl;
            goto kthehu17;
        }
        else {
            cout << "Shkronja e pare qe perseritet dy here: " << s17->repeatedCharacter(fjala17) << endl;
        }

        break;



    case 18: // Detyra 18 ------------------
        int numValues18;

        cout << "Sa anetare deshironi te shtoni ne varg? ";
        cin >> numValues18;

        cout << "Shenoni " << numValues18 << " numra: ";
        for (int i = 0; i < numValues18; i++) {
            int value18;
            cin >> value18;
            arr18.push_back(value18);
        }

        cout << "Frekuencat totale maksimale: "  << s18->maxFrequencyElements(arr18) << endl;

        break;



    case 19: // Detyra 19 ------------------
        int numValues19;

        cout << "Sa anetare deshironi te shtoni ne varg? ";
        cin >> numValues19;

        cout << "Shenoni " << numValues19 << " numra: ";
        for (int i = 0; i < numValues19; i++) {
            int value19;
            cin >> value19;
            arr19.push_back(value19);
        }

        if (s19->uniqueOccurrences(arr19)) {
            rez19 = "E vertete!";
        }
        else {
            rez19 = "E pavertete!";
        }

        cout << "Ka numer unik te frekuencave: " << rez19 << endl;

        break;



    case 20: // Detyra 20 ------------------
        kthehu20:
        cout << "Shenoni nje numer sipas deshires: ";
        cin >> fjala20;

        if (containsNonNumeric(fjala20)) {
            cout << "Shenoni vetem numra!" << endl;
            goto kthehu20;
        }
        else {
            if (s20->digitCount(fjala20)) {
                rez20 = "E vertete!";
            }
            else {
                rez20 = "E pavertete!";
            }
            cout << "Numri ka numer te barabarte shifror dhe vlere shifrore: " << rez20 << endl;
        }

        break;



	default:
		cout << "Funksioni i panjohur!" << endl;
        goto kthehuFillimiProgramit;
		break;
	}

	return 0;
}
