/*
 * Operating Systems Project 1
 * Program compiled and built by Chester Condray
 * Banker's algorithm referenced from "geeksforgeeks" website
 * Referenced algorithm: http://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
 * Further assistance received from course TA
 */

#ifndef BANKER_H
#define BANKER_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*
 * Const to go here
 */

class Banker{
    /*
     * Private items
     */

public:
    Banker(int proc, int res, int* matrixM, int* matrixA) {

        // Find need of each process
        void calculateNeed(int need[proc][res], int maxm[proc][res],
                           int matrixA[proc][res])
        {
            // Calculate need of processes
            for (int i=0; i<proc; i++)
                for (int j=0; j<res; j++)
                    need[i][j] = maxm[i][j] - matrixA[i][j];
        }

        // Find is system is in safe state
        bool isSafe(int processes[], int avail[], int matrixM[][res],
                    int matrixA[][res])
        {
            int need[proc][res];

            // Calculate need matrix
            calculateNeed(need, matrixM, matrixA);

            // Mark processes unfinished
            bool finish[proc] = {0};

            // Store safe sequence
            int safeSeq[proc];

            // Make copy of available resources
            int work[res];
            for (int i=0; i<res ; i++)
                work[i] = avail[i];

            // System unsafe until all processes finished
            int count = 0;
            while (count < proc)
            {
                // Find unfinished process that can be satisfied with
                // available resources
                bool found = false;
                for (int i=0; i<proc; i++)
                {
                    // Check if process is finished
                    if (finish[i] == 0)
                    {
                        // Check if need is less than available
                        int j;
                        for (j=0; j<res; j++)
                            if (need[i][j] > work[j])
                                break;

                        // Check if needs are met
                        if (j == res)
                        {
                            // Free resources
                            for (int k=0; k<res ; k++)
                                work[k] += matrixA[i][k];

                            // Add process to safe
                            safeSeq[count++] = i;

                            // Mark as finished
                            finish[i] = 1;

                            found = true;
                        }
                    }
                }

                // If no process in safe is found return false
                if (found == false)
                {
                    //cout << "System is not in safe state";
                    return false;
                }
            }

            // If system is safe, return true
//            cout << "System is in safe state.\nSafe"
//                    " sequence is: ";
//            for (int i=0; i<proc ; i++)
//                cout << safeSeq[i] << " ";

            return true;
        }

    }
};

#endif


















