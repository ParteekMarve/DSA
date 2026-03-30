#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {

public:

    // ================= BRUTE FORCE =================
    ListNode* bruteForce(ListNode* headA, ListNode* headB){

        ListNode* tempB = headB;

        while(tempB != NULL){

            ListNode* tempA = headA;

            while(tempA != NULL){

                if(tempA == tempB)
                    return tempA;

                tempA = tempA->next;
            }

            tempB = tempB->next;
        }

        return NULL;
    }


    // ================= BETTER (USING SET) =================
    ListNode* better(ListNode* headA, ListNode* headB){

        unordered_set<ListNode*> st;

        while(headA){

            st.insert(headA);
            headA = headA->next;
        }

        while(headB){

            if(st.find(headB) != st.end())
                return headB;

            headB = headB->next;
        }

        return NULL;
    }


    // ================= OPTIMAL-1 (LENGTH METHOD) =================
    int length(ListNode* head){

        int len = 0;

        while(head){

            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* optimal1(ListNode* headA, ListNode* headB){

        int lenA = length(headA);
        int lenB = length(headB);

        while(lenA > lenB){

            headA = headA->next;
            lenA--;
        }

        while(lenB > lenA){

            headB = headB->next;
            lenB--;
        }

        while(headA && headB){

            if(headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }


    // ================= OPTIMAL-2 (BEST APPROACH) ⭐ =================
    ListNode* optimal2(ListNode* headA, ListNode* headB){

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){

            tempA = tempA ? tempA->next : headB;
            tempB = tempB ? tempB->next : headA;
        }

        return tempA;
    }
};


int main(){

    // Creating intersection part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3 -> 6 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = common;

    // List B: 4 -> 8 -> 10
    ListNode* headB = new ListNode(4);
    headB->next = common;

    Solution obj;


    // Testing BRUTE FORCE
    ListNode* ans1 = obj.bruteForce(headA, headB);
    cout << "Brute Force: ";
    if(ans1) cout << ans1->val << endl;
    else cout << "No intersection\n";


    // Testing BETTER
    ListNode* ans2 = obj.better(headA, headB);
    cout << "Better (Set): ";
    if(ans2) cout << ans2->val << endl;
    else cout << "No intersection\n";


    // Testing OPTIMAL-1
    ListNode* ans3 = obj.optimal1(headA, headB);
    cout << "Optimal-1 (Length Method): ";
    if(ans3) cout << ans3->val << endl;
    else cout << "No intersection\n";


    // Testing OPTIMAL-2
    ListNode* ans4 = obj.optimal2(headA, headB);
    cout << "Optimal-2 (Two Pointer Switch): ";
    if(ans4) cout << ans4->val << endl;
    else cout << "No intersection\n";


    return 0;
}