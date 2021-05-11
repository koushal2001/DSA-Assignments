
#include <bits/stdc++.h>//header file
#include "Stackk.h"
#include "Stackk.cpp"
#include "LL.h"
#include "LL.cpp"

#define MAX 15//defining varaible of size 15

using namespace std;

class expression{
	string infix;		//Class variable for infix expression
	string postfix;		//Class variable for postfix expression
	string prefix;

public:
	void post();			//Display postfix
	void post_prefix();		//Display prefix
	string reverse(string);	//Reverse the string
	void brackets();		//Change brackets
	void conversion();		//expression conversion
	int precedence(char);	//Checking precedence
	int associativity(char);//Checking associativity
	void prefix_conversion();//Converting into prefix
	void pre_conv();		//Performing operations before prefix conversion
	void Postdisplay();		//Display postfix
	void evaluate_postfix();//Evaluating postfix expression
	void evaluate_prefix(); //Evaluating prefix expression
	int operation(int a, int b, char c);//Performing operations while evaluating
	void input();			//Input string
};

void expression::post(){	//postfix display during operations

	for(int i=0; postfix[i]!='\0'; i++){
		cout << postfix[i];
	}
}

void expression::post_prefix(){		//prefix display during operations

	for(int i=0; prefix[i]!='\0'; i++){
		cout << prefix[i];
	}
}

void expression::input(){	//Input Infix expression

	infix = "";
	postfix = "";
	prefix = "";

	cout << "\n\t\tEnter expression::		" << endl;
	cin >> infix;
}

int expression::precedence(char c){	//Precedence checking
	switch(c){
	case '+' : ;
	case '-' : return 1;	//lowest precedence for -
	case '*' : ;
	case '/' : ;
	case '%' : return 2;	//precedence for %
	case '^' : return 3;	//highest precedence for ^
	}
	return -1;
}

int expression::associativity(char c){

	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return 1;			//Condition for associativity L to R

	if(c == '^')
		return 2;			//Condition for associativity R to L

	return -1;
}

void expression::conversion(){
	Stack<char> s;				//Stack object
	s.push('N');

	char token, out;			//token for passwise, Out for storing head

	int l = infix.length();		//Length of infix
	postfix = "";

	cout << "\n\t\tInfix  :: " << infix <<endl;

	//Pass wise display
	cout << "\n\n\t\t=============================================================================================";
	cout << "\n\t\tToken\t\tPostfix\t\t\tStack";
	cout << "\n\t\t=============================================================================================";

	//Expression conversion loop
	for(int i=0; i<l; i++ ){
		token = infix[i];

		if((token >= 'a' && token <= 'z')||(token >= 'A' && token <= 'Z')){	//Case of alphabet
			postfix += token;					//Enter alphabet to postfix
			cout<<"\n\t\t" << token << "\t\t";
			post();
			cout << "\t\t";
			s.display();

		}

		else if(token == '('){					//Case of opening bracket

			s.push(token);						//Push into stack

			cout<<"\n\t\t" << token << "\t\t";	//Passwise output
			post();
			cout << "\t\t";
			s.display();

		}

		else if(token == ')'){ //Case of closing bracket

			while(s.peep() != '(' && (!s.isempty())){

				out = s.peep();
				postfix += out; //Add the remaining elements to postfix
				s.pop();		//pop them from the stack

			}

			if(s.peep() == '(') //Pop the opening bracket
				s.pop();

			cout<<"\n\t\t" << token << "\t\t";
			post();
			cout << "\t\t";
			s.display();
		}
		else {

			//Case of operator
			if(s.peep()== '(' || s.isempty() || precedence(token) > precedence(s.peep()) ){

				s.push(token);					//Pushing into stack if the operator precedence is greater than the top

				cout<<"\n\t\t" << token << "\t\t";
				post();
				cout << "\t\t";
				s.display();
			}

			else if(precedence(token) < precedence(s.peep())){//When precedence is less than the top

				while(precedence(token) <= precedence(s.peep()) && (!(s.isempty()))){

					out = s.peep();				//Add it to postfix

					postfix += out;
					s.pop();					//Pop it
				}

				s.push(token);				//then push the operator

				cout<<"\n\t\t" << token << "\t\t";
				post();
				cout << "\t\t";
				s.display();
			}
			else {
					//check associativity if the operator has same precedence
					if(associativity(token) == 1){		//L to R

						out = s.peep();		//Store the top value in out
						postfix += out;		//And add the value to the postfix

						s.pop();			//Pop the top element

						s.push(token);		//Push the token

						cout<<"\n\t\t" << token << "\t\t";
						post();
						cout << "\t\t";
						s.display();
					}

					if(associativity(token) == 2){		//R to L

						s.push(token);		//Push the token

						cout<<"\n\t\t" << token << "\t\t";
						post();
						cout << "\t\t |";
						s.display();
						cout << " |";
					}
			}

		}


	}
	//Add remaining elements in the stack to the postfix
	while(s.peep() != 'N'){
		//Pop the top and store in postfix
		out = s.peep();
		postfix += out;
		s.pop();

	}
	postfix += '\0';

}

void expression::Postdisplay(){ //Displaying postfix

	cout<<"\n\n\t\tInfix expression is::		";
	for(int i=0; infix[i]!='\0'; i++){
		cout << infix[i];
	}
	cout << "\n\t\tPostfix expression::		";
	for(int i=0; postfix[i]!='\0'; i++){
			cout << postfix[i];
		}

}
string expression::reverse(string exp){		//Reversing the string
	int size = exp.size();
	  int j = size, i = 0;
	  char temp[size];						//Create a new temp to store the new string

	  temp[j--] = '\0';						//Assign to null
	  while (exp[i] != '\0')
	    {
	      temp[j] = exp[i];					//Store the first value in the expression in the last os temp
	      j--;								//Decrement temp counter
	      i++;								//Increment expression counter
	    }
	  exp = temp;							//Exp = temp

	  return exp;

}

void expression::brackets(){
	int l = infix.size();
	for (int i = 0; i < l; i++) { 		 //Changing  ( to ) and vice versa
		    if (infix[i] == '(') {
		        infix[i] = ')';
		            i++;
		    }
		    else if (infix[i] == ')') {
		        infix[i] = '(';
		        i++;
		    }
		}
}

void expression::pre_conv(){
	Stack<char> s;				//Stack object
		s.push('N');			//Push null character into the stack

		char token, out; 		//Token is the character for evaluation

		int l = infix.length();
		prefix = "";

		cout << "\t\tPrefix conversion of :: " << infix ;

		cout << "\n\n\t\t=============================================================================================";
		cout << "\n\t\tToken\t\tPostfix\t\t\tStack";
		cout << "\n\t\t=============================================================================================";

		for(int i=0; i<l; i++ ){
			token = infix[i];						//Token is the first element of the string

			if((token >= 'a' && token <= 'z')||(token >= 'A' && token <= 'Z')){	//Check for alphabet

				prefix += token;					//Enter alphabet to prefix

				cout<<"\n\t\t" << token << "\t\t";
				post_prefix();
				cout << "\t\t";
				s.display();

			}

			else if(token == '('){					//Case of opening bracket

				s.push(token);						//Push into stack

				cout<<"\n\t\t" << token << "\t\t";
				post_prefix();
				cout << "\t\t";
				s.display();
			}

			else if(token == ')'){					//Case for closing bracket

				while(s.peep() != '(' && (!s.isempty())){

					out = s.peep();					//Storing top element in the stack
					prefix += out;					//Adding it to prefix
					s.pop();						//Then popping it
				}

				if(s.peep() == '(')					//Pop the bracket
					s.pop();

				cout<<"\n\t\t" << token << "\t\t";
				post_prefix();
				cout << "\t\t";
				s.display();
			}

			else {
				//Case of operator
				if(s.peep()== '(' || s.isempty() || precedence(token) > precedence(s.peep()) ){

					s.push(token);					//Pushing into stack if the operator precedence is greater than the top

					cout<<"\n\t\t" << token << "\t\t";
					post_prefix();
					cout << "\t\t";
					s.display();
				}

				else if(precedence(token) < precedence(s.peep())){	//When precedence is less than top

					while(precedence(token) <= precedence(s.peep()) && (!(s.isempty()))){

						out = s.peep();
						prefix += out;
						s.pop();
					}

					s.push(token);				//then push the operator
					cout<<"\n\t\t" << token << "\t\t";
					post_prefix();
					cout << "\t\t";
					s.display();

				}
				else {
					if(precedence(token) == precedence(s.peep())){ //check associativity if the operator has same precedence

						if(associativity(token) == 2){		//R to L

							out = s.peep();
							prefix += out;
							s.pop();

							s.push(token);

							cout<<"\n\t\t" << token << "\t\t";
							post_prefix();
							cout << "\t\t";
							s.display();

						}
						if(associativity(token) == 1){		//L to R

							s.push(token);
							cout<<"\n\t\t" << token << "\t\t";
							post_prefix();
							cout << "\t\t";
							s.display();

						}
					}

				}

			}


		}

		while(s.peep() != 'N'){		//popping the remaining elements and adding them to prefix
			out = s.peep();
			prefix += out;
			s.pop();
		}

}
void expression::prefix_conversion(){	//Conversion of infix into postfix
	infix = reverse(infix);		//Reverse infix
	brackets();					//Convert the brackets
	pre_conv();					//Convertion into prefix
	prefix = reverse(prefix);	//Again reversing the prefix operation

	cout << "\n\t\tPrefix expression::	";	//Displaying the prefix expression
		for(int i=0; prefix[i]!='\0'; i++){
				cout << prefix[i];
			}

}
int expression::operation(int a, int b, char op){		//Function for carrying out operations
	switch(op){
	case '+': return (b+a);		//Add
	case '-': return (b-a);		//Subtract
	case '*': return (b*a);		//Multiply
	case '/': return (b/a);		//Divide
	case '%': return (b%a);		//Modulo
	case '^': return (b^a);		//Exponent
	}
	return -1;
}
void expression::evaluate_postfix(){		//Evaluation of postfix
	int i;
	int a, b, c;
	int res;
	Stack<int> s;
	cout << "\n\t\tEnter postfix expression:: " << endl;
	cin >> postfix;			//Input postfix expression

	int l = postfix.length();

	for( i =0; i < l; i++){
		//if operator is found
		cout << "\n\t\tToken :: " << postfix[i] << endl;
		if((postfix[i]=='+') || (postfix[i]=='-') || (postfix[i]=='*') || (postfix[i]=='/') || (postfix[i]=='%') || (postfix[i]=='^'))
		{
			cout << "\n\t\tCase operator" << endl;
			a = s.peep();		//store top value in a
			s.pop();			//Pop it
			b = s.peep();		//Store another value in b
			s.pop();			//pop

			c = operation((int)a, (int)b, postfix[i]);	//call the operation function
			cout << "\n\t\tAnswer" << c << endl;
			s.push(c);			//push the answer

		}
		else if(postfix[i] == ','){
			continue;
		}
		else{
			cout << "\t\tCase Digit" << endl;
			s.push(postfix[i] - '0');
		}
	}
	res = s.peep();		//Result is the remaining element in the stack
	s.pop();			//pop it
	cout << "\n\t\tpostfix expression:: " << postfix;
	cout << "\n\t\tThe evaluation is:: " << res << endl;//display
}
void expression::evaluate_prefix(){
	int a, b, c;
	int res;
	Stack<int> s;
	cout << "\n\t\tEnter prefix expression:: " << endl;
	cin >> prefix;
	prefix = reverse(prefix);//First reverse the expression

	int l = prefix.length();

	for(int i =0; i < l; i++){
		//Case of an operator
		cout << "\n\t\tToken :: " << prefix[i] << endl;
		if((prefix[i]=='+') || (prefix[i]=='-') || (prefix[i]=='*') || (prefix[i]=='/') || (prefix[i]=='%') || (prefix[i]=='^'))
		{
			cout << "\t\tCase Operator";
			a = s.peep();		//Store the digit at the top
			s.pop();			//pop it
			b = s.peep();		//Store the next digit
			s.pop();			//pop it

			c = operation((int)b, (int)a, prefix[i]);//perform operations and store in c
			s.push(c);		//push it into stack
			cout << "\n\t\tAnswer:: " << c << endl;
		}
		else{//Case of a digit
			cout << "\t\tCase Digit" << endl;
			s.push(prefix[i] - '0');

		}
	}
	//Getting the result from the stack
	res = s.peep();
	s.pop();
	prefix = reverse(prefix);
	//Displaying the result
	cout << "\n\t\tPrefix:: " << prefix;
	cout << "\n\t\tThe evaluation is:: " << res << endl;


}

int main() {

	expression ex;	//object
	int ch;			//Choice

	do{
		cout << "\n\t\t-------MENU-------" << endl;
		cout <<	"\n\t\t1) Convert to postfix"
				"\n\t\t2) Convert to prefix"
				"\n\t\t3) Evaluate postfix"
				"\n\t\t4) Evaluate prefix"
				"\n\t\t5) Exit"
				"\n\t\t------------------" << endl;
		cout << "\t\tEnter choice:: " << endl;
		cin >> ch;
		switch(ch){
		case 1:			//Postfix conversion
			ex.input();
			ex.conversion();
			ex.Postdisplay();
			break;

		case 2:			//Prefix conversion
			ex.input();
			ex.prefix_conversion();
			break;

		case 3:			//Evaluation of postfix
			ex.evaluate_postfix();
			break;

		case 4:			//Evaluation of prefix
			ex.evaluate_prefix();
			break;

		case 5:			//Exit from the loop
			int x;
			cout << "\n\t\tPress 0 to exit OR 1 to continue" << endl;
			cin >> x;
			if (x==0)
				return 0;
			else
				break;

		default:
			cout << "\n\t\tWrong Choice entered" << endl;

		}

	}while(1);
	return 0;
}
