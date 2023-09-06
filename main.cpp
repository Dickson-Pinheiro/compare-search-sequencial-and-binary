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
    int vet[1000];
    vet[0] = 1;
    clock_t start;
    clock_t end;
    float soma_total;
    clock_t time_req;
    float tempo;
    for(int i = 10; i <= 1000; i+=10){
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
            sequencial_search(vet, random, i);
            */
            
           
            tempo = static_cast<double>(end - start) / CLOCKS_PER_SEC;
           
            soma_total += tempo;
        }
        
        cout << i << " " << soma_total / 1000 << endl;
    }
    /*
    int result_binary = binary_search(vet, 6, 0, size);
    int result_linear = linear_search(vet, 5, size);
    cout << result_linear << endl;
    cout << result_binary << endl;
    */
    
    return 0;
}