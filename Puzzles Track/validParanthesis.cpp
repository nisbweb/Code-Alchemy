/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.
    - Every close bracket has a corresponding open bracket of the same type.

    Example 1:
    Input: s = "()"
    Output: true

    Example 2:
    Input: s = "()[]{}"
    Output: true

    Example 3:
    Input: s = "(]"
    Output: false

    Example 4:
    Input: s = "([])"
    Output: true

*/

// WRITE YOUR CODE HERE



 bool isValid(string s) {
       stack <char> container;
       for (int i=0;i<s.size();i++)
       {
        if((s[i]=='[') || (s[i]== '{') || (s[i]=='(') ){
            container.push(s[i]);
        }
        else{
            if((s[i]==')') && (!container.empty())){
                char c = container.top();
                if(c!='(')
                    return false;
                else
                    container.pop();
            }
            else if((s[i]=='}') && (!container.empty())){
                char c = container.top();
                if(c!='{')
                    return false;
                else
                    container.pop();
            }
            else if((s[i]==']') && (!container.empty())){
                char c = container.top();
                if(c!='[')
                    return false;
                else
                    container.pop();
            }
            else
                return false;
        }
       } 
       if (container.empty())
        return true;
       return false;
        
    }


int main()
{
	string s;
	cout<<"Enter the string";
	cin>>s;
	bool ans = isValid(s);
	if(ans)
		cout<<"It is a valid paranthesis";
	else
		cout<<"It is not a valid paranthesis";
	return 0;
}