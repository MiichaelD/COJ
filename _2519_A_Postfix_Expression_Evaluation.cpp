#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
int main(){
	int t;
	scanf("%d%*c",&t);
	while(t--){
		stack<int> p;
		queue<int> c;
		priority_queue<int> pc;
		char cad[101],tam;
		int i,j,x,y,z;
		scanf("%[^\n]%*c",cad);
		tam=strlen(cad);
		for(i=0;i<tam;i++){
			if(cad[i]!=' '){
				if(cad[i]!='+' && cad[i]!='-' && cad[i]!='*'){
					sscanf(cad+i,"%d",&z);
					while(cad[i]>='0' && cad[i]<='9')i++;
					i--;
					p.push(z);
					c.push(z);
					pc.push((z)*-1);
				}else{
					switch(cad[i]){
						case '+':
							x=p.top();
							p.pop();
							y=p.top();
							p.pop();
							p.push(y+x);
							
							x=c.front();
							c.pop();
							y=c.front();
							c.pop();
							c.push(y+x);
							
							x=-pc.top();
							pc.pop();
							y=-pc.top();
							pc.pop();
							pc.push((y+x)*-1);
							break;
						case '-':
							x=p.top();
							p.pop();
							y=p.top();
							p.pop();
							p.push(y-x);
							
							x=c.front();
							c.pop();
							y=c.front();
							c.pop();
							c.push(y-x);
							
							x=-pc.top();
							pc.pop();
							y=-pc.top();
							pc.pop();
							pc.push((y-x)*-1);
							break;
						default:
							x=p.top();
							p.pop();
							y=p.top();
							p.pop();
							p.push(y*x);
							
							x=c.front();
							c.pop();
							y=c.front();
							c.pop();
							c.push(y*x);
							
							x=-pc.top();
							pc.pop();
							y=-pc.top();
							pc.pop();
							pc.push(y*x*-1);
							break;
					}
				}
			}
		}
		printf("%d %d %d\n",p.top(),c.front(),-pc.top());
	}
	return 0;
}
