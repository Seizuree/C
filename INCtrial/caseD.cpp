#include<bits/stdc++.h>

using namespace std;

#define lli long long int

#define mod 10000007
	int main()
	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a[n];int s=0;int sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	int avg=sum/2;
	int x=-1;
	if(n==1){
		if(a[0]==2)
		cout << "YES";
		else
		cout << "NO";
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
			s+=a[i]+a[j];
				if(s==avg || a[i]==avg || a[j]==avg){
				x=0;
				break;
				}
			}
		s=0;
			if(x==0)break;
		}
		if(x==-1)
		cout << "NO\n";
		else
		cout << "YES\n";
	}
		return 0;
	}