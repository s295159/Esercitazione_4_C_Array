#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    size_t n = 0;
    double S = 0.0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportVectors( inputFileName , n , S , w , r ))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
    {
        cout << "Import successful: " << endl;
        cout << " S = "<< S << ", n = "<< n <<endl;
        cout << "w = " << ArrayToString(n, w) << endl;
        cout << " r = " << ArrayToString(n, r)<< endl;
    }

    double rateOfReturn = ComputePortfolioRateOfReturn( w, r , n );
    cout<< "Rate of return of the portfolio: "<< rateOfReturn << endl;

    double valuePortfolio = ComputePortfolioValue(S, rateOfReturn);
    cout << "V = " << valuePortfolio << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r , rateOfReturn , valuePortfolio ))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}



