void preorderTraversal(){
    stack<Node*> st;
    st.push(root);
    while(st.size() > 0){
        Node* currentNode = st.top();
        st.pop();
        cout<<currentNode->value<<" ";
        if(currentNode->right) st.push(currentNode->right);
        if(currentNode->left) st.push(currentNode->left);
    }
}
