void inorderTraversal(){
    stack<Node*> st;
    Node* currentNode=root;
    while(currentNode || !st.empty()){
        while(currentNode){
            st.push(currentNode);
            currentNode=currentNode->left;
        }
        currentNode=st.top();
        st.pop();
        cout<<currentNode->value<<" ";
        currentNode=currentNode->right;
    }
}