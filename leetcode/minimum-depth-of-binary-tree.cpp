//minimum - depth - of - binary - tree
class Solution {
public:
	int run(TreeNode *root) {
		if (root == nullptr) return 0;
		int level = 1;
		TreeNode *last = root;
		TreeNode *cur = nullptr;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			int size = q.size();
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
			if (size == q.size()) break;
			if (last == cur)
			{
				level++;
				last = q.back();
			}
		}
		return level;
	}
};