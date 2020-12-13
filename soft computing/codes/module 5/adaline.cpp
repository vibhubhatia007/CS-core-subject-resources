#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    double x1[4]={1.0,1.0,-1.0,-1.0};
    double x2[4]={1.0,-1.0,1.0,-1.0};
    double t[4]={-1.0,1.0,-1.0,-1.0};
    double w1=0.2,w2=0.2,b=0.2,l=0.2;//l is alpha
    int epoch=2;
    cout<<"  x1   x2     t     yin   t-yin   Δw1    Δw2    Δb     w1     w2     b     error \n";
    for(int i=0;i<epoch;i++)
    {
    	for(int i=0;i<4;i++)
    	{
    	    if(x1[i]>=0)cout<<" ";
    		cout<< fixed << setprecision(1) <<x1[i]<<"  ";
    		if(x2[i]>=0)cout<<" ";
    		cout<< fixed << setprecision(1) <<x2[i]<<"  ";
    		if(t[i]>=0)cout<<" ";
    		cout<< fixed << setprecision(1) <<t[i]<<"  ";
    		double  yin,sw1,sw2,sb,error;
    		yin=w1*x1[i]+w2*x2[i]+b;
    		if(yin>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<yin<<" ";
    		if(t[i]-yin>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<t[i]-yin<<" ";
    		if(t[i]-yin!=0)
    		{
    			sw1=l*(t[i]-yin)*x1[i];
    			sw2=l*(t[i]-yin)*x2[i];
    			sb=l*(t[i]-yin);
    			w1=w1+sw1;
    			w2=w2+sw2;
    			b=b+sb;
    			error=(t[i]-yin)*(t[i]-yin);
    		}
    		if(sw1>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<sw1<<" ";
    		if(sw2>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<sw2<<" ";
    		if(sb>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<sb<<" ";
    		if(w1>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<w1<<" ";
    	    if(w2>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<w2<<" ";
    		if(b>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<b<<" ";
    		if(error>=0)cout<<" ";
    		cout<< fixed << setprecision(3) <<error<<" ";
    		
    	    cout<<"\n";
    	}
    	cout<<"\n";
    }

} 

