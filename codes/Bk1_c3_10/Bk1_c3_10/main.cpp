#include<iostream>
using namespace std;
struct Node{
	int NodeValue;
	Node* Next;
};
int main(){
	int M,N;
	cout<<"请输入M"<<endl;
	cin>>M;
	cout<<"请输入N"<<endl;
	cin>>N;
	cout<<"M="<<M<<";N="<<N<<endl;
	//初始化链表
	Node* nodeList = (Node *)(malloc(sizeof(struct Node)));
	Node* temp,*current;
	current = nodeList;
	for(int i=1;i<=N;i++){
		temp = (Node *)(malloc(sizeof(struct Node)));
		if(temp==NULL){
			cout<<"Error malloc"<<endl;
			break;
		}
		temp->NodeValue = i;
		temp->Next = NULL;
		current->Next = temp;
		current = temp;
		//cout<<temp->NodeValue<<endl;
	}
	int remain_num = N, count=0;
	temp = nodeList;
	current = nodeList->Next;
	cout<<"clear value:";
	while(remain_num>1){
		if(current==NULL){
			temp = nodeList;
			current = nodeList->Next;
		}
		if(count==M){
			Node* clearNode = current;
			temp->Next = current->Next;
			cout<<clearNode->NodeValue<<",";
			current = current->Next;
			free(clearNode);
			--remain_num;
			count = 0;
		}else{
			++count;
			temp = current;
			current = current->Next;
		}
	}
	cout<<endl;
	cout<<"remain num:"<<nodeList->Next->NodeValue<<endl;
	
	int f_remain = 0;
	for(int i=2;i<=N;i++){
		f_remain = (f_remain+M+1)%i;
	}
	cout<<"remian num:"<<f_remain+1<<endl;

	system("pause");
	return 0;
}