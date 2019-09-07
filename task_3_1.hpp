
#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

#ifndef TASK_3_1_HPP
#define TASK_3_1_HPP

namespace task3

{
template<std::size_t N>
class BigNum{
private:
    //const static int N = 2; // (N+1) - число "слов" в нашем разряде
    //T Num;
    std::uint32_t words[N];

public:
    BigNum (std::uint32_t Num): words{Num} {
        words[0] = Num;
        for (int i = 1; i <= N; ++i){
            words[i] = 0;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const BigNum& object){
        int mas[8]; // массив для хранения одного "слова" в шестнадцатеричной системе счисления
        int ostatok = 0b1111;
        //bool value = true; // нужно для отбрасывания нулей
        for (int i = N; i >= 0; --i){
            //while (object.words[i] == 0)
             //value = false;
            //if (value == true){
            std::uint32_t timevalue = object.words[i];

            for ( int j = 0; j < 8; ++j){
                mas[j] = timevalue & ostatok;
                timevalue = timevalue >> 4;
            }

            for (int j = 7; j >= 0; --j){

                std::cout << mas[j] << " ";
            }
        }
        //}
        return os;
    }
    friend BigNum operator+ (const BigNum& obj1, const BigNum& obj2){
        BigNum obj3(0);
        int ostatok = 0b1111;
        for (int i = 0; i < N; --i){
            unsigned long timevalue = obj2.words[i] + obj1.words[i];
            obj3.words[i] = timevalue & ostatok;
            obj3.words[i+1] = timevalue >> 4;
        }
        return obj3;
    }
    //template<std::size_t M,std::size_t N>
    //friend BigNum<M+N-1> operator*(const BigNum<M>& a,const BigNum<N>& b);
};

//template<std::size_t R = 0,std::size_t M,std::size_t N>
//BigNum<R?R:M+N> operator*(const BigNum<M>& a,const BigNum<N>& b) какое правильное значение??
//{

//}

}
#endif

