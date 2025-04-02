#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "src/Utils.hpp"
using namespace std;

int main()
{
    std::string inputFile="data.txt";
    std::string outputFilePath="result.txt";
	size_t n;
    double S;
    double *ptr1=nullptr;
	double *ptr2=nullptr;
	
	ImportVectors(inputFile,S,n,ptr1,ptr2);

    double ror=dot(ptr1,ptr2,n);

    ExportResult(outputFilePath,S,n,ror,ptr1,ptr2);
	
	cout<<"S = "<<setprecision(2)<<fixed<<S<<resetiosflags(ios::fixed)<<", ";
    cout<<"n = "<<n<<endl;

    cout<<"w = [ ";
    for(unsigned int i=0; i<n; i++)
    {
        cout<<ptr1[i]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"r = [ ";
    for(unsigned int i=0; i<n; i++)
    {
        cout<<ptr2[i]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Rate of return of the portfolio: "<<setprecision(4)<<fixed<<ror<<resetiosflags(ios::fixed)<<endl;
    cout<<"V: "<<setprecision(2)<<fixed<<(1+ror)*S<<resetiosflags(ios::fixed)<<endl;

    delete [] ptr1;
	delete [] ptr2;
	
    return 0;
}

