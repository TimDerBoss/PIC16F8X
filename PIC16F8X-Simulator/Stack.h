#pragma once

class Stack {
public:
	Stack() {
		values.clear();
	}
	int pop() {
		auto tmp = values.back();
		values.pop_back();
		return tmp;
	}
	void push(int value) {
		if (values.size() == 8)
			values.erase(values.begin());
		values.push_back(value);
	}
	int at(int idx) {
		return values.at(idx);
	}
	int top() {
		return values.back();
	}
	void clear() {
		values.clear();
	}
	inline int Size() { return static_cast<int>(values.size()); }
private:
	std::vector<int> values;
};