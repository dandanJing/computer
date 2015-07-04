#include<iostream>
#include <string>
#include<vector>
using namespace std;
int operPriority(char a);
//int main(){
//	string oper_str;
//	cout<<"请输入表达式"<<endl;
//	cin>>oper_str;
//	cout<<"输入表达式为:"<<oper_str<<endl;
//	vector<string>result_vec;
//	vector<string>opera_vec;
//	string temp_str="";
//
//	for(unsigned i=0; i<oper_str.length();i++ ){
//		if(oper_str[i]>='0' && oper_str[i]<='9'){//数字
//			temp_str += oper_str[i];
//		}else{
//			if(temp_str.length()>0){
//				result_vec.push_back(temp_str);
//				temp_str = "";
//			}
//			int cur_prio = operPriority(oper_str[i]);
//			if(cur_prio==0){
//				cout<<"表达式输入有误"<<endl;
//				break;
//			}else if(oper_str[i]==')'){
//				bool is_find = false;
//				for(int it=opera_vec.size()-1;it>=0;it--){
//					string temp = opera_vec.at(it);
//					if(temp[0] != '('){
//						result_vec.push_back(temp);
//						opera_vec.pop_back();
//					}else{
//						opera_vec.pop_back();
//						is_find = true;
//						break;
//					}
//				}
//
//				if(!is_find){
//					cout<<"表达式1输入有误"<<endl;
//					break;
//				}
//			}else{
//				for(int it=opera_vec.size()-1;it>=0;it--){
//					string it_str = opera_vec.at(it);
//					int temp_prio = operPriority(it_str[0]);
//					if(temp_prio>=cur_prio){
//						result_vec.push_back(it_str);
//						opera_vec.pop_back();
//					}else{
//						break;
//					}
//				}
//				string op_str = "";
//				op_str+= oper_str[i];
//				opera_vec.push_back(op_str);
//			}
//		}
//	}
//	if(temp_str.length()>0){
//		result_vec.push_back(temp_str);
//		temp_str = "";
//	}
//	for(int it=opera_vec.size()-1;it>=0;it--){
//		result_vec.push_back(opera_vec.at(it));
//		opera_vec.pop_back();
//	}
//	vector<string>::iterator it;
//	cout<<"后缀表达式:";
//	for(it=result_vec.begin();it!=result_vec.end();it++){
//		cout<<*it<<",";
//	}
//	cout<<endl;
//	system("pause");
//	return 0;
//}

int operPriority(char a){
	if(a=='+'||a=='-'){
		return 1;
	}else if(a=='*'||a=='/'){
		return 2;
	}else if(a=='^'){
		return 3;
	}else if(a=='(' || a==')'){
		return 4;
	}else{
		return 0;
	}
}