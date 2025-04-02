#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& v1, double*& v2)
{
    ifstream file(inputFilePath);

    if(file.fail())
    {
        cerr << "File open fail" << endl;
        return false;
    }

    std::string tmp;
    std::string Ss;
    std::string ns;
    file>>Ss;  
    size_t pos;
    pos=Ss.find(";");
    S=stod(Ss.substr(pos+1));
    file.ignore();
    file>>ns;
    pos=ns.find(";");
    n=stoi(ns.substr(pos+1));
    file.ignore(); 
    getline(file,tmp);

    v1=new double[n];
    v2=new double[n];
    for (unsigned int i=0; i<n; i++)
    {
        getline(file,tmp);
        pos=tmp.find(";");
        v1[i]=stod(tmp.substr(0,pos));
        v2[i]=stod(tmp.substr(pos+1));
    }

    return true;
}

double dot(double*& v1, double*& v2, size_t n)
{
    double p=0.0;
    for(unsigned int i=0; i<n; i++)
        p+=v1[i]*v2[i];

    return p;
}

bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double& ror, double*& v1, double*& v2)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
    cerr<< "File open failed"<< endl;
    return false;
    }

    file << fixed << setprecision(2);
    file<<"S = "<<S<<", n = "<<n<<endl;

    file<<"w = [ ";
    for (unsigned int i=0; i<n; i++)
    {
        file<<v1[i]<<" ";
    }
    file<<"]"<<endl;

    file<<"r = [ ";
    for (unsigned int i=0; i<n; i++)
    {
        file<<v2[i]<<" ";
    }
    file<<"]"<<endl;

    file<<"Rate of return of the portfolio: "<<setprecision(4)<<fixed<<ror<<resetiosflags(ios::fixed)<<endl;
    file<<"V: "<<setprecision(2)<<fixed<<(1+ror)*S<<resetiosflags(ios::fixed)<<endl;

    file.close();

    return true;
}
