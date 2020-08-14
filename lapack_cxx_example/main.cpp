/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Example calling Lapack from C++
 *
 *        Version:  1.0
 *        Created:  09/27/2018 01:51:29 PM
 *       Revision:  none
 *       Compiler:  clang++/g++
 *
 *         Author:  Daniel (dmc)
 *
 * =====================================================================================
 */

#include <iostream>
#include "include/lapacke.h"
 
using namespace std;
 
int main()
{
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    char    TRANS = 'N';
    int     INFO=3;
    int     LDA = 3;
    int     LDB = 3;
    int     N = 3;
    int     NRHS = 1;
    int     IPIV[3] ;
 
    double  A[9] = // vectorized
    {
    1, 2, 3,
    2, 3, 4,
    3, 4, 1
    };
 
    double B[3] =
    {
    -4,
    -1,
    -2
    };
// end of declarations
 
    cout << "compute the LU factorization..." << endl << endl;
    //void LAPACK_dgetrf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda, lapack_int* ipiv, lapack_int *info );
    LAPACK_dgetrf(&N,&N,A,&LDA,IPIV,&INFO);
 
    // checks INFO, if INFO != 0 something goes wrong, for more information see the MAN page of dgetrf.
    if(INFO)
    {
        cout << "an error occured : "<< INFO << endl << endl;
    }else{
        cout << "solving the system..."<< endl << endl;
        // void LAPACK_dgetrs( char* trans, lapack_int* n, lapack_int* nrhs, const double* a, lapack_int* lda, const lapack_int* ipiv,double* b, lapack_int* ldb, lapack_int *info );
        dgetrs_(&TRANS,&N,&NRHS,A,&LDA,IPIV,B,&LDB,&INFO);
        if(INFO)
        {
            // checks INFO, if INFO != 0 something goes wrong, for more information see the MAN page of dgetrs.
            cout << "an error occured : "<< INFO << endl << endl;
        }else{
            cout << "print the result : {";
            int i;
            for (i=0;i<N;i++)
            {
                cout << B[i] << " ";
            }
            cout << "}" << endl << endl;
        }
    }
 
    cout << "program terminated." << endl << endl;
    return 0;
}
