#pragma once

#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   double& S,
                   double *&w, double *&r);
// Funzione per calcolare il tasso di rendimento del portafoglio
double ComputePortfolioRateOfReturn(const double* w, const double* r, size_t n);

// Funzione per calcolare il valore finale del portafoglio
double ComputePortfolioValue(double S, double rateOfReturn);

bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
                  const double& valuePortfolio);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);


