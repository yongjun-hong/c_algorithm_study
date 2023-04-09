Tree23Node *tree23_search(Tree23Node* root, int key)
{
	if (root == NULL)			// Ʈ���� ��� ������
		return FALSE;
	else if (key == root->data)// ��Ʈ�� Ű==Ž��Ű 
		return TRUE;
	else if (root->type == TWO_NODE) {  // 2-���
		if (key < root->key)
			return tree23_search(root->left, key);
		else
			return tree23_search(root->right, key);
	}
	else {										// 3-���
		if (key < root->key1)
			return tree23_search(root->left, key);
		else if (key > root->key2)
			return tree23_search(root->right, key);
		else
			return tree23_search(root->middle, key);
	}
}