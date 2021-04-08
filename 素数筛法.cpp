#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iomanip>
using namespace std;

const int c=100000005;//��100005��ɸѡ����
int prime[c];//�����������
int vis[c];//��������ı���
int main()
{
	int n;
	cin>>n;
	clock_t start,finsh;
	start=clock();
	int cnt=0;//��¼�����ĸ��� 
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			prime[++cnt]=i;
		for(int j=1;i*prime[j]<=n&&j<=cnt;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
	finsh=clock();
	cout<<setprecision(8)<<fixed<<double(finsh-start)/CLOCKS_PER_SEC<<endl;
	
	for(int i=1;i<=cnt;i++)
		cout<<prime[i]<<endl;
		
	cout<<endl;
	for(int i=2;i<=n;i++)
		if(vis[i]==0)
			cout<<i<<endl;
			
	return 0;
}
