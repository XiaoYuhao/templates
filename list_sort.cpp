#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    struct Node *next;
    Node(int _val){
        val = _val;
        next = nullptr;
    }
};

void print(Node *p){
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}


Node* listMerge(Node *head1, Node *head2){
    Node *p1, *p2;
    p1 = head1;
    p2 = head2;
    Node *head = nullptr, *last;
    while(p1&&p2){
        if(p1->val<p2->val){
            if(!head){
                head = p1;
                last = p1;
            }
            else{
                last->next = p1;
                last = p1;
            }
            p1 = p1->next;
        }
        else{
            if(!head){
                head = p2;
                last = p2;
            }
            else{
                last->next = p2;
                last = p2;
            }
            p2 = p2->next;
        }
    }
    while(p1){
       if(!head){
            head = p1;
            last = p1;
        }
        else{
            last->next = p1;
            last = p1;
        } 
        p1 = p1->next;
    }
    while(p2){
        if(!head){
            head = p2;
            last = p2;
        }
        else{
            last->next = p2;
            last = p2;
        } 
        p2 = p2->next;
    }
    return head;
}

Node *listSort(Node *head){
    if(!head||!head->next) return head;
    int count = 0;
    Node *p = head, *q;
    while(p){
        count++;
        p = p->next;
    }
    count /= 2;
    p = head;
    while(count){
        q = p;
        p = p->next;
        count--;
    }
    q->next = nullptr;
    Node *head1 = listSort(head);
    Node *head2 = listSort(p);
    return listMerge(head1, head2);
}


int main(){
    vector<int> nums = {1,3,5,7,9,2,4,6,8,5,3,2,6,4,9,5};
    Node *head = nullptr;
    Node *last;
    for(int i=0;i<nums.size();i++){
        Node *p = new Node(nums[i]);
        if(!head) {
            head = p;
            last = p;
        }
        else {
            last->next = p;
            last = p;
        }
    }
    print(head);
    head = listSort(head);
    print(head);
    return 0;
}