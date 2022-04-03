//
// Created by wangyu980312 on 30/03/2022.
//

#include <vector>
#include "FifoCons.h"
#include "FifoProd.h"

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

    Fifo<int> fifo;
    double timeProd = 0;
    double timeCons = 0;
    unsigned int numProd = 0;
    unsigned int numCons = 0;

    // Start nProd threads that produce tokens
    std::vector<FifoProd*> fifoProd(nProd);
    for (unsigned int i=0; i<nProd; ++i)
    {
        fifoProd[i] = new FifoProd(&fifo, nTokenPerTask);
        fifoProd[i]->start();
    }

    // Start nCons threads that consume tokens
    std::vector<FifoCons*> fifoCons(nCons);
    for (unsigned int i=0; i<nCons; ++i)
    {
        fifoCons[i] = new FifoCons(&fifo);
        fifoCons[i]->start();
    }

    // Join nProd threads that produce tokens
    for (unsigned int i=0; i<nProd; ++i)
    {
        fifoProd[i]->join();
        timeProd += fifoProd[i]->execTime_ms();
        numProd += fifoProd[i]->getCounter();
    }

    // Join nCons threads that consume tokens
    for (unsigned int i=0; i<nCons; ++i)
    {
        fifoCons[i]->join();
        timeCons += fifoCons[i]->execTime_ms();
        numCons += fifoCons[i]->getCounter();
        std::cout << "Thread (consume) " << i <<" has consumed " << fifoCons[i]->getCounter() << " tokens." << std::endl;
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

