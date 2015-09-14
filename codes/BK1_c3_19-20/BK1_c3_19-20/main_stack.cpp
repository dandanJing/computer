#include<iostream>
#include <string>
#include<stack>
#include <strstream>
using namespace std;
//操作符优先级
int operPriority(char a);
//中缀转后缀
stack<string> MiddleToBack(string in_str);
//后缀转中缀
string BackToMiddle(stack<string> in_stack);
float countBackOperation(stack<string> in_stack);
//判断是否字符串中只有数字
bool isNumber(string a);
int main(){
	string oper_str;
	cout<<"请输入表达式"<<endl;
	cin>>oper_str;
	cout<<"输入表达式为:"<<oper_str<<endl;
	stack<string>result_stack;
	result_stack = MiddleToBack(oper_str);
	
	cout<<"后缀转中缀的表达式为:"<<endl;
	cout<<BackToMiddle(result_stack)<<endl;

	cout<<endl<<"后缀表达式的计算结果为:"<<countBackOperation(result_stack)<<endl;

	system("pause");
	return 0;
}

stack<string> MiddleToBack(string oper_str){
	stack<string>out_stack;
	stack<string>opera_stack;
	string num_str="";
	cout<<"后缀表达式为";
	for(unsigned i=0; i<oper_str.length();i++ ){
		if(oper_str[i]>='0' && oper_str[i]<='9'){//数字
			num_str += oper_str[i];
		}else{//操作符
			if(num_str.length()>0){//把数字先推入栈，因为数字可能是多位的
				out_stack.push(num_str);
				cout<<num_str<<",";
				num_str = "";
			}
			int cur_prio = operPriority(oper_str[i]);
			if(cur_prio==0){
				cout<<"表达式输入有误"<<endl;
				break;
			}else if(oper_str[i]==')'){
				bool is_find = false;
				while(opera_stack.size()){
					if(opera_stack.top()[0]!='('){
						out_stack.push(opera_stack.top());
						cout<<opera_stack.top()<<",";
						opera_stack.pop();
					}else{
						opera_stack.pop();
						is_find = true;
						break;
					}
				}

				if(!is_find){
					cout<<"表达式中()输入有误"<<endl;
					break;
				}
			}else{
				string temp_str;
				int temp_prio;
				while(opera_stack.size()){
					temp_str = opera_stack.top();
					temp_prio = operPriority(temp_str[0]);
					if(temp_prio>=cur_prio && temp_str[0] != '('){
						out_stack.push(temp_str);
						cout<<temp_str<<",";
						opera_stack.pop();
					}else{
						break;
					}
				}
				string op_str = "";
				op_str+= oper_str[i];
				opera_stack.push(op_str);
			}
		}
	}
	if(num_str.length()>0){
		out_stack.push(num_str);
		cout<<num_str<<",";
		num_str = "";
	}
	while(opera_stack.size()){
		out_stack.push(opera_stack.top());
		cout<<opera_stack.top()<<",";
		opera_stack.pop();
	}
	return out_stack;
}

float countValue(float first_num,float second_num,string op_str);
float countBackOperation(stack<string> in_stack){
	float out_result = 0;
	string temp_str="";
	stack<string> temp_stack;
	while(in_stack.size()){
		temp_str=in_stack.top();
		in_stack.pop();
		if(isNumber(temp_str)){
			float cur_num = atof(temp_str.c_str());
			while(temp_stack.size()){ 
				if(isNumber(temp_stack.top())){//当栈顶也存在一个数字时，更新表达式
					float second_num = atof(temp_stack.top().c_str());
					temp_stack.pop();
					string op_temp = temp_stack.top();
					temp_stack.pop();
					out_result = countValue(cur_num,second_num,op_temp);
					temp_str="";
					cur_num = out_result;
				}else{
					if(temp_str==""){
						strstream ss;
						ss << out_result;
						string out_str;
						ss >> out_str;
						temp_stack.push(out_str);//将表达式推入栈
					}else{
						temp_stack.push(temp_str);//将数字推入栈
					}
					
					break;
				}
			}
		}else{
			temp_stack.push(temp_str);//将操作符推入栈
		}
	}
	return out_result;

}

float countValue(float first_num,float second_num,string op_str){
	if(op_str[0]=='+'){
		return first_num+second_num;
	}else if(op_str[0]=='-'){
		return first_num-second_num;
	}else if(op_str[0]=='*'){
		return first_num*second_num;
	}else if(op_str[0]=='/'){
		return first_num/second_num;
	}else if(op_str[0]=='^'){
		return pow(first_num,second_num);
	}
	return 0;
}
//4+9*5^(3+8*(6/908*67-34)+67)
string BackToMiddle(stack<string> in_stack){
	stack<string> temp_stack;
	string temp_str="";
	int last_op_prio=4;
	string out_str="";
	while(in_stack.size()){
		temp_str=in_stack.top();
		in_stack.pop();
		if(temp_str[0]>='0' && temp_str[0]<='9' && temp_stack.size()){
			while(temp_stack.size()){ 
				if(temp_stack.top()[0]>='0' && temp_stack.top()[0]<='9'){//当栈顶也存在一个数字时，更新表达式
					string num_str = temp_stack.top();
					temp_stack.pop();
					string op_temp = temp_stack.top();
					temp_stack.pop();

					int temp_prio = operPriority(op_temp[0]);
					if(temp_str==""){
						if(last_op_prio<temp_prio){
							out_str = "("+out_str +")";
						}
						out_str = out_str+op_temp+num_str;
					}else{
						if(last_op_prio<temp_prio && !isNumber(num_str)){
							num_str = "("+num_str +")";
						}
						out_str = temp_str+op_temp+num_str;
						temp_str="";
					}
					last_op_prio = temp_prio;//记录最后一个操作符的优先级
				}else{
					if(temp_str==""){
						temp_stack.push(out_str);//将表达式推入栈
					}else{
						temp_stack.push(temp_str);//将数字推入栈
					}
					
					break;
				}
			}
		}else{
			temp_stack.push(temp_str);//将操作符推入栈
		}
	}
	return out_str;
}

bool isNumber(string a){
	for(unsigned i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9' || (i==0 && a[i]=='-' && a.length()>1)||a[i]=='.')
			continue;
		else
			return false;
	}
	return true;
}