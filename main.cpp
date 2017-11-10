/*
 * Operating Systems Project 1
 * Program compiled and built by Chester Condray
 * Banker's algorithm referenced from "geeksforgeeks" website
 * Referenced algorithm: http://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
 * Further assistance received from course TA
 */

/*
 * Includes go here
 */
#include <iostream>
#include "banker.h"
#include <fstream>

using namespace std;

/*
 * Function declarations go here
 */



int main(int argc, char* argv[]) {
    //Make sure appropriate number of arguments
    if (argc != 2){
        ifstream fin(argv[1]);
        //Retrieve process and resource count and vector
        int processes = fin.get();
        int resources = fin.get();

        int vector[4];
        for(int i=0; i<4; i++){
            vector[i] = fin.get();
        }

        cout<<processes<<" "<<resources<<endl;

        //Make matrices to hold input from file
        int matrixM[processes][resources];
        int matrixA[processes][resources];

        fin.close();
    }
    //If inappropriate number of arguments, reply with error
    else{
        cerr<<"I'm sorry, an inappropriate number of arguments"
                " has been provided."<<endl;
        return 1;
    }
    return 0;
}

/*
 * Function bodies go here
 */
