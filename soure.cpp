#include<iostream>
#include<math.h>
using namespace std;

void convert_display(int k);
void sub(int n,int m)
{
  cout<<"taking 10's complement of the second number"<<endl;	
  int a[10],b[10],sub[10],c[10],d[10];
	int z=n;
	int i=0,cf=0;
	while(z>0)
	{
		a[i]=z%10;
	 	z=z/10;
	 	cf++;
	 	i++;

	}
	int  nin=0;
  for(int i=0;i<cf;i++)
  nin=nin+9*pow(10,i);
  
  int k=nin-m;
  k=k+1;
  //cout<<"value of k is"<<k<<endl;
	convert_display(k);
	//cout<<"adding the corresponding 4 bits"<<endl;
	
	
	int g=cf;
	for(int i=0;i<cf;i++)
	{
		d[i]=a[g-1];
		g--;
	} 
	
	int cs=0,j=0;
	
    int o=k;

while(o>0)
	{
		b[j]=o%10;
	 	o=o/10;
	 	cs++;
	 	j++;
	 	//cout<<cs;
	}
	int f=0,t=cs;
	for(int i=0;i<cs;i++)
	{
		c[i]=b[t-1];
		t--;
	}
   
   cout<<endl;
     	
   int flag=0,ff=0;
   for(int i=cf-1;i>=0;i--)
   {
   	//cout<<"value of flag is"<<flag<<endl;
   	 if(flag==1){
   	 sub[i]=d[i]+c[i]+1;
   }
     else if(flag==0)
     sub[i]=d[i]+c[i];
     
     //cout<<"initial value"<<sub[i]<<endl<<endl;;
     if(sub[i]>=10)
     {
     	sub[i]=sub[i]-10;
     	flag=1;
     }
     else if(sub[i]<10)
     flag=0;
     
     //cout<<"final value "<<sub[i]<<endl<<endl;
   }
   cout<<endl<<endl;
   int sum=0,dq=0;	
   for(int i=cf-1;i>=0;i--){
   
   sum=sum+sub[i]*pow(10,dq);
   dq++;
}
   
   cout<<"sub is"<<endl<<sum<<endl<<endl;
   cout<<"The final result is "<<endl;
   convert_display(sum);
}


void convert_display(int k)
{
	 int a[10],i=0,count=0;
	 int z=k;
     string s[10]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001"};	
	 int c;
	 while(z>0)
	 {
	 	a[i]=z%10;
	 	z=z/10;
	 	count++;
	 	i++;
	 }
	 for(int j=count-1;j>=0;j--)
	 cout<<s[a[j]]<<"     ";
	 cout<<endl<<endl;
	 return;
}


void case1(int n,int m)
{
	convert_display(n);
	convert_display(m);
	sub(n,m);
}


void sub2(int n,int m)
{
	int a[10],b[10],sub[10],c[10],d[10];
	int cs=0,j=0;
	int o=m;
	int temp,nin=0;
  
  while(o>0)
	{
		temp=o%10;
	 	o=o/10;
	 	cs++;
	 	
	}
	
	
	for(int i=0;i<cs;i++)
      nin=nin+9*pow(10,i);
	  
	  cout<<"The value of nin is"<<nin<<endl;	
	
	cout<<"taking 9's complement of the second number"<<endl;	
  int k=nin-m;
  convert_display(k);
  cs=0;
  
  while(k>0)
	{
		b[j]=k%10;
	 	k=k/10;
	 	cs++;
	 	j++;
	 	
	}

   
   cout<<endl;
	
	int f=0,t=cs;
	for(int i=0;i<cs;i++)
	{
		c[i]=b[t-1];
		t--;
	}
	
	int z=n;
	int i=0,cf=0;
	while(z>0)
	{
		a[i]=z%10;
	 	z=z/10;
	 	cf++;
	 	i++;

	}
	int g=cf;
	for(int i=0;i<cf;i++)
	{
		d[i]=a[g-1];
		g--;
	} 	
   
     int e[10];
     for(int i=0;i<cf;i++)
     e[i]=d[i];
   
   if(cs>cf)
   {
   	
   	int x=cs-cf;
   	//cout<<"the value of x is"<<x<<endl;
	for(i=x;i<=cf+x-1;i++)
	{
		d[i]=e[i-x];
	}
	for(int i=0;i<x;i++)
	d[i]=0; 
   }
   
     	
   int flag=0,ff=0;
   for(int i=cs-1;i>=0;i--)
   {
   	
   	 if(flag==1){
   	 sub[i]=d[i]+c[i]+1;
   }
     else if(flag==0)
     sub[i]=d[i]+c[i];
     
     //cout<<"initial value"<<sub[i]<<endl<<endl;;
     if(sub[i]>=10)
     {
     	sub[i]=sub[i]-10;
     	flag=1;
     }
     else if(sub[i]<10)
     flag=0;
     
     //cout<<"final value "<<sub[i]<<endl<<endl;
   }
   cout<<endl<<endl;
   int sum=0,dq=0;	
   
   //taking 9's of the digit at the last as the answer is negative
   
   
   for(int i=cs-1;i>=0;i--){
   sub[i]=9-sub[i];
   sum=sum+sub[i]*pow(10,dq);
   dq++;
   
   
	
}
cout<<endl;
convert_display(sum);
cout<<"The difference is "<<"-"<<sum<<endl;
}

void case2(int n,int m)
{
	convert_display(n);
	convert_display(m);
	sub2(n,m);
	}



main()
{
	int n,m;
	//aim-to calculate n-m
	cout<<"Enter the 1st number"<<endl;
	cin>>n;
	cout<<"Enter the 2nd number"<<endl;
	cin>>m;
	//two cases
	if(n>m)	
	{
		case1(n,m);
	}
	else 
	case2(n,m);
}
