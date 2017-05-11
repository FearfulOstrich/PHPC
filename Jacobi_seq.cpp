#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
    cout.precision(9);
    cout.setf(ios::fixed);
    int n, i, j, k, flag=0, count=0;

    cout << "\nEnter the no. of equations : ";           

    cin >> n;                    //Input no. of equations

    double a[n][n+1];            //declare a 2d array for storing the elements of the augmented matrix
    double x[n], xx[n];                 //declare an array to store the values of variables
    double y[n];                 //declare an array to store the ground truth
    double eps, yy;
    double temp;


   srand(time(NULL));

    // Initialize matrix with random numbers
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            a[i][j] = 10*((double)rand()/RAND_MAX-0.5);

    // Transform the matrix so that it is diagonal dominant
    for (i=0; i<n; i++) {
        temp = 0;
        for (j = 0; j < n; j++) temp += abs(a[i][j])+0.5;
        a[i][i] = temp;
    }

    // Initialize solution
    for (i = 0; i < n; i++) x[i]=10*((double)rand()/RAND_MAX-0.5);

    // Compute right hand side
    for (i=0; i<n; i++) {
        a[i][n] = 0;
	    for (j = 0; j < n; j++) a[i][n] += a[i][j]*x[j];
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j] << " - ";
	    }
        cout << "b[" << i << "]: " << a[i][n] << endl;
    }

    // Initialize null solution
    for (i = 0; i < n; i++) {
        y[i] = x[i];
        x[i] = 0;
        xx[i] = 0;
    }

    cout<<"\nEnter the accuracy upto which you want the solution: ";
    cin >> eps;
    cout << "\n";
    do {                          //Perform iterations to calculate x1,x2,...xn
        for (i=0; i<n; i++) {              //Loop that calculates x1,x2,...xn
            yy = x[i];
            x[i] = a[i][n];
            for (j=0; j<n; j++) {
                if (j != i) x[i] = x[i] - a[i][j]*xx[j];
            }
            x[i] = x[i]/a[i][i];
            if (abs(x[i]-yy) <= eps)            //Compare the ne value with the last value
                flag++;
        }
        for (i=0; i<n; i++) xx[i]=x[i];

        count++;   
      // If the values of all the variables don't differ from their previious values with error more than eps then flag must be n and hence stop the loop
    } while(flag < n);
   
    cout<<"\n The solution is as follows:\n";
    for (i=0; i<n; i++)
        cout << "x" << i << " = " << x[i] << endl;    //Print the contents of x[]
    cout << "\n ended in : " << count << " iterations." << endl;       
    
    temp = 0;
    for (i=0; i<n; i++) temp += pow((x[i] -  y[i]), 2);

    cout << "\n Residual is: " << temp << endl;       

    return 0;
}
