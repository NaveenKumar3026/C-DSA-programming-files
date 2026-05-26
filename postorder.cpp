void postorderTraversal(){
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(st1.size()>0){
        Node* currentNode = st1.top();
        st1.pop();
        st2.push(currentNode);
        if(currentNode->left) st1.push(currentNode->left);
        if(currentNode->right) st1.push(currentNode->right);
    }
    while(st2.size()>0){
        cout<<st2.top()->value<<" ";
        st2.pop();
    }
}