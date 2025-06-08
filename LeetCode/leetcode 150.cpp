class Solution {
   public:
	int evalRPN(vector<string>& tokens) {
		stack<int> ans;
		int a, b;
		for (auto& op : tokens) {
			if (op == "+") {
				b = ans.top();
				ans.pop();
				a = ans.top();
				ans.pop();
				ans.push(a + b);
			} else if (op == "-") {
				b = ans.top();
				ans.pop();
				a = ans.top();
				ans.pop();
				ans.push(a - b);
			} else if (op == "*") {
				b = ans.top();
				ans.pop();
				a = ans.top();
				ans.pop();
				ans.push(a * b);
			} else if (op == "/") {
				b = ans.top();
				ans.pop();
				a = ans.top();
				ans.pop();
				ans.push(a / b);
			} else {
				ans.push(stoi(op));
			}
		}
		return ans.top();
	}
};
