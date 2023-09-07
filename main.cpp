#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

int binary_search(int nums[], int item, int begin, int end){
    int center = (begin + end)/2;
    if(nums[center] == item){
        return center;
    }
    if(begin > end){
        return -1;
    }
    if(nums[center] < item){
        return binary_search(nums, item, center + 1, end);
    } else {
        return binary_search(nums, item, begin, center - 1);
    }
}


int sequencial_search(int nums[], int item, int size){
    for(int i = 0; i < size; i++){
        if(nums[i] == item){
            return i;
        }
    }
    return -1;
}


int main()
{
    std::srand(std::time(nullptr));
    int vet[200000];
    clock_t start;
    clock_t end;
    float soma_total;
    float tempo;
    for(int i = 100; i <= 200000; i+=100){
        for(int j = 0; j < i; j++){
            vet[j] = i*j;
        }
        
        soma_total = 0.0;
        for(int k = 0; k < 1000; k++){
            int random = std::rand() % i*2;
            
            start = clock();
            binary_search(vet, random, 0, i);
            end = clock();
            /*
            start = clock();
            sequencial_search(vet, random, i);
            end = clock();
            */

            tempo = static_cast<double>(end - start) / CLOCKS_PER_SEC;
           
            soma_total += tempo;
        }
        cout << i << " " << soma_total/1000 << endl;
    }
    return 0;
}