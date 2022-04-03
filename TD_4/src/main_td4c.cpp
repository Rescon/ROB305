//
// Created by wangyu980312 on 30/03/2022.
//

#include <vector>
#include "SemsphoreProd.h"
#include "SemsphoreCons.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: number of arguments. 3 expected : <nProd> <nCons> <nTokenPerTask>" << std::endl;
        exit(-1);
    }

    unsigned int nProd = std::stoi(argv[1]);
    unsigned int nCons = std::stoi(argv[2]);
    unsigned int nTokenPerTask = std::stoi(argv[3]);

    Semaphore semaphore;
    double timeProd = 0;
    double timeCons = 0;
    unsigned int numProd = 0;
    unsigned int numCons = 0;

    // Start nProd threads that produce tokens
    std::vector<SemaphoreProd*> semaphoreProd(nProd);
    for (unsigned int i=0; i<nProd; ++i)
    {
        semaphoreProd[i] = new SemaphoreProd(&semaphore, nTokenPerTask);
        semaphoreProd[i]->start();
    }

    // Start nCons threads that consume tokens
    std::vector<SemaphoreCons*> semaphoreCons(nCons);
    for (unsigned int i=0; i<nCons; ++i)
    {
        semaphoreCons[i] = new SemaphoreCons(&semaphore);
        semaphoreCons[i]->start();
    }

    // Join nProd threads that produce tokens
    for (unsigned int i=0; i<nProd; ++i)
    {
        semaphoreProd[i]->join();
        timeProd += semaphoreProd[i]->execTime_ms();
        numProd += semaphoreProd[i]->getCounter();
    }

    // Join nCons threads that consume tokens
    for (unsigned int i=0; i<nCons; ++i)
    {
        semaphoreCons[i]->join();
        timeCons += semaphoreCons[i]->execTime_ms();
        numCons += semaphoreCons[i]->getCounter();
        std::cout << "Thread (consume) " << i <<" has consumed " << semaphoreCons[i]->getCounter() << " tokens." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Total number of tokens produced : " << numProd << std::endl;
    std::cout << "Total number of tokens consumed : " << numCons << std::endl;

    if (numProd == numCons)
    {
        std::cout << "All the tokens generated were consumed." << std::endl;
    }
    else
    {
        std::cout << "Not all of the tokens generated were consumed." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Time taken by all the threads that produce tokens : " << timeProd << " ms." << std::endl;
    std::cout << "Time taken by all the threads that consume tokens : " << timeCons << " ms." << std::endl;

    return 0;
}
