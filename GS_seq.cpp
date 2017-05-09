#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

using namespace std;
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,j,k,temp=0,flag=0,count=0;
    cout<<"\nEnter the no. of equations : ";           
    cin>>n;                    //Input no. of equations
    double a[n][n+1];            //declare a 2d array for storing the elements of the augmented matrix
    double x[n];                //declare an array to store the values of variables
    double eps,y;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            a[i][j]=10*((rand()/RAND_MAX)-0.5);
    for (i = 0; i < n; i++)
    {
        temp=0;
        for (j=0;j<n; j++)
        {
            if (i!=j)
                temp = temp+abs(a[i][j]);
        }
        a[i][i]=temp;
    }
    for (i=0;i<n;i++)
        x[i]=100*((rand()/RAND_MAX)-0.5);
    cout<<"\nEnter the accuracy upto which you want the solution: ";
    cin>>eps;
    cout<<"\n";
    do                            //Perform iterations to calculate x1,x2,...xn
    {
        for (i=0;i<n;i++)                //Loop that calculates x1,x2,...xn
        {
            y=x[i];
            x[i]=a[i][n];
            for (j=0;j<n;j++)
            {
                if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
            }
            x[i]=x[i]/a[i][i];
            if (abs(x[i]-y)<=eps)            //Compare the ne value with the last value
                flag++;
        }
        count++;   
    }while(flag<n);                        //If the values of all the variables don't differ from their previious values with error more than eps then flag must be n and hence stop the loop
   
    cout<<"\n The solution is as follows:\n";
    for (i=0;i<n;i++)
        cout<<"x"<<i<<" = "<<x[i]<<endl;    //Print the contents of x[]
    cout << "\n ended in : " << count << " iterations.";       
    return 0;
}