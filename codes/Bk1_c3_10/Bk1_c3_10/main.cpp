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
	Node* temp,current;
	cout<<nodeList<<endl;
	//current = nodeList;
	for(int i=1;i<=N;i++){
		temp = (Node *)(malloc(sizeof(struct Node)));
		if(temp==NULL){
			cout<<"Error malloc"<<endl;
			break;
		}
		temp->NodeValue = i;
		temp->Next = NULL;
		nodeList->Next = temp;
		nodeList = temp;
	}
	system("pause");
	return 0;
}