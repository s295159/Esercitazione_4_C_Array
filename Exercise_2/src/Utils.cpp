#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   double& S,
                   double*& w, double*& r)
{
    // Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // Get S
    string line;
    getline(file,line,';'); // legge fino al ;
    file >> S;
    file.ignore();

    // Get n
    getline(file,line,';');
    file >> n;
    file.ignore();

    w = new double[n];
    r = new double[n];
    char puntoVirgola;

    for(unsigned int i = 0; i < n; i++ )
    {
        getline(file,line);
        file >> w[i] >> puntoVirgola >> r[i];
    }


    // Close File
    file.close();

    return true;
}

double ComputePortfolioRateOfReturn(const double* w, const double* r, size_t n)
{
    double rateOfReturn = 0.0;
    for (unsigned int i = 0; i < n; i++)
    {
        rateOfReturn += w[i] * r[i];
    }
    return rateOfReturn;
}
double ComputePortfolioValue(double S, double rateOfReturn)
{
    return S * (1 + rateOfReturn);
}

bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
                  const double& valuePortfolio)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2);
    file<< "S = " << S << ", n = " << n << endl;


    file<< "w = [";
    for (unsigned int i = 0; i < n; i++)
    {
        file<< w[i];
        if (i != n - 1 )
        {
            file << " ";
        }
    }

    file<< "]" << endl;

    file<< "r = [";
    for (unsigned int i = 0; i < n; i++)
    {
        file<< r[i];
        if (i != n - 1 )
        {
            file << " ";
        }
    }

    file<< "]" << endl;


    file<< "Rate of return of the portfolio : "<< rateOfReturn << endl;
    file<< "V = " << valuePortfolio << endl;

    // Close File
    file.close();

    return true;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

