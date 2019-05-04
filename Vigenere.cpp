#include <iostream>
#include <string>
using namespace std;
const int N=26;
char v[N][N]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}};
int number(char x)//把行号字母对应到数字
{
	char y='a';
	for(int i=0;i<N;i++)
	{
		if(x==(y+i)) return i;
	}
	return x;
}
void encryption(string m,string k)//加密
{
	cout<<"明文:";
	cin>>m;
	cout<<"密钥:";
	cin>>k;
	int mlen,klen;
	mlen=m.length();
	klen=k.length();
	char *p,*q,*t;//明文，初始密钥，密钥串。把string换成char
	p=new char[m.length()+1];
	strcpy(p,m.c_str());
	q=new char[k.length()+1];
	strcpy(q,k.c_str());
	t=new char[m.length()+1];
	int j=0;
	for(int i=0;i<mlen;i++)
	{
		t[i]=q[j];
		j++;
		j=j%klen;
	}//生成密钥
	cout<<"密文:";
	for(int i=0;i<mlen;i++)
		cout<<v[number(t[i])][number(p[i])];
	cout<<endl;
}
void disencryption(string c,string k)//解密
{
	cout<<"密文:";
	cin>>c;
	cout<<"密钥:";
	cin>>k;
	int clen,klen;
	clen=c.length();
	klen=k.length();
	char *p,*q,*t;//密文，初始密钥，密钥串。把string换成char
	p=new char[c.length()+1];
	strcpy(p,c.c_str());
	q=new char[k.length()+1];
	strcpy(q,k.c_str());
	t=new char[c.length()+1];
	int j=0;
	for(int i=0;i<clen;i++)
	{
		t[i]=q[j];
		j++;
		j=j%klen;
	}//生成密钥
	cout<<"明文:";
	for(int i=0;i<clen;i++)
		for(int j=0;j<N;j++)
			if(v[number(t[i])][j]==p[i]) {cout<<char(j+97);break;}
	cout<<endl;
}
int main()
{
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			v[i][j]=v[i-1][(j+1)%N];
		}//方阵初始化
	}
	cout<<"欢迎使用维吉尼亚加密!"<<endl<<endl;
	cout<<"请选择要进行的操作"<<endl;
	int flag;
	do{
		cout<<"1.加密2.解密3.结束:";
		cin>>flag;
		string m,k;
		if(flag==1)encryption(m,k);
		else if(flag==2) disencryption(m,k);
		else if(flag!=1&&flag!=2&&flag!=3) cout<<"输入错误，请重新输入!";
	}while(flag!=3);
	return 0;
}
