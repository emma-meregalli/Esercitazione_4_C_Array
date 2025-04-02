#pragma once
#include <iostream>
using namespace std;

bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& v1, double*& v2);
        
double dot(double*& v1, double*& v2, size_t n);

bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double& ror, double*& v1, double*& v2);


                     


