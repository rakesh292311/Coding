#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>

using namespace std;
int N=1000;
static int i = 0;
mutex mtx;
binary_semaphore smpProducerToConsumer{0},smpConsumerToProducer{0}; 
void printEven()
{
    unique_lock<std::mutex> lck(mtx);
    while(1)
    {
        smpConsumerToProducer.acquire();
        smpProducerToConsumer.release();
        if(i <= N)
            i++;
        else
            exit(0);
    }

}
void printOdd()
{
    unique_lock<std::mutex> lck(mtx);
    while(1)
    {
        smpConsumerToProducer.acquire();
        smpProducerToConsumer.release();
        if(i <= N)
            i++;
        else
            exit(0);
    }

}
void consume ()
{
    while(true)
    {   
        smpConsumerToProducer.release();
        smpProducerToConsumer.acquire();
        cout << i << " ";
        if(i==N) 
            exit(0);
    }
}
int main(int argc, const char *argv[])
{
    thread t1(printEven);
    thread t2(printOdd);
    thread t3(consume);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}