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
    clock_t time_req;
    for(int i = 10; i <= 1000; i+=10){
        for(int j = 0; j < i; j++){
            vet[j] = i*j;
        }
        time_req = clock();
        for(int k = 0; k < 100; k++){
            int random = std::rand() % i;
            /*
            binary_search(vet, 23, 0, i);
            */
           sequencial_search(vet, random, i);
        }
        time_req = clock()- time_req;
        cout << i << " " << (float)time_req/CLOCKS_PER_SEC << endl;
    }
    /*
    int result_binary = binary_search(vet, 6, 0, size);
    int result_linear = linear_search(vet, 5, size);
    cout << result_linear << endl;
    cout << result_binary << endl;
    */
    
    return 0;
}


