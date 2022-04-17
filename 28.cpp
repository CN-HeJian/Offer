//
// Created by admin on 2022/4/16.
//
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


vector<Node*> vec;

void dfs(Node* head){
    if(head==nullptr){
        return ;
    }
    vec.push_back(head);
    dfs(head->child);
    dfs(head->next);
}

Node* flatten(Node* head) {
    dfs(head);
    int n = vec.size();
    for(int i=0;i<n;i++){
        if(i<n-1){
            vec[i]->next = vec[i+1];
        }
        if(i>0){
            vec[i]->prev = vec[i-1];
        }
        vec[i]->child = nullptr;
    }
    return head;
}