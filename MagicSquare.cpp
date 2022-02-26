#include "MagicSquare.hpp"
#include<vector>
#include <iostream>
#include<set>

using namespace std;

std::istream& operator>> (std::istream &in, std::vector< std::vector<int> >& magicSquare) {
    int value = 0;
    const size_t dimension = magicSquare.size();//the size of the sqaure
    for(size_t i = 0; i < dimension; ++i){// loop through row
        for(size_t j = 0; j < dimension; ++j) {//loop through col
            in >> value;//read in value
            if (in.fail()) {//if fail to read
                in.clear();//clear the stream
                in.ignore();//ignor the \n
                std::cout <<"can not read";
                continue;//continue
            }
            magicSquare[i].push_back(value);//make each charactor in the square to 0
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const std::vector< std::vector<int> >& magicSquare) {
    const size_t dimension = magicSquare.size();//size of the sqaure
    for(size_t row = 0; row < dimension; ++row){//loop through the row
        for(size_t col = 0; col < dimension; ++col){//loop through the col
            out << magicSquare[row][col] << " ";
            //write out each charactor with whitespace in between
        }
        out <<"\n";//start a new line
    }
    return out;
}

bool MagicSquare::empty(size_t row, size_t col)const{
    return(square[row][col] == 0);//return if the sqaure is empty
}

bool MagicSquare::taken(int num)const{
    bool taken = false;
    const size_t dimension = square.size();//size of the square
    for(size_t row = 0; row < dimension; ++row){//loop through the row
        for(size_t col = 0; col < dimension; ++col){//loop throught the col
            if(square[row][col] == num){//if num already has a spot
                taken = true;// num is taken
            }
        }
    }
    return taken;
}

bool MagicSquare::checkRow()const{
    size_t N = square.size();//size of the sqaure
    size_t S = N * (N * N + 1)/2;//sum of each row col and diag
    for(size_t row = 0; row < N; ++row){//loop through row
        int checkRow = 0;//sum of row
        int checkCol = 0;//sum of col
        for(size_t col = 0; col < N; ++col){
            if(empty(row, col)){// if is not filled
                if(checkCol < S){//if is less than S
                    return true;//true
                }
            }
            checkRow += square[row][col];//add all row numbers
            checkCol+= square[row][col];//add all col numbers
        }
        if(checkRow != S){//if row sum is not S
            return false;// false;
        }
    }
    return true;
}

bool MagicSquare::checkValid()const{
    bool valid = true;
    size_t N = square.size();
    size_t S = N * (N * N + 1)/2;
    //check row sum
    for(size_t row = 0; row < N; ++row){//loop through row
        int rowSum = 0;
        for(size_t col = 0; col < N; ++col){//loop through column
            rowSum += square[row][col];//add up row sum
            if(rowSum != S){// row sum is not S
                valid = false;//false
            }
        }
    }
    //check col sum
    for(size_t col = 0; col < N; ++col){//loop through col
        int colSum = 0;
        for(size_t row = 0; row < N; ++row){//loop through row
            colSum += square[row][col];//add up col sum
            if(colSum != S){//col sum is not S
                valid = false;// false
            }
        }
    }
    //check diag sum
    for(size_t i = 0; i < N; ++i){// loop through row
        int digSum1 = 0;
        int digSum2 = 0;
        digSum1 += square[i][i];// add diag sum from left to right
        digSum2 += square[N - 1 - i][i];//add diag sum from right to left
        if(digSum1 != S || digSum2 != S){//if either of them are not S
            valid = false;//return false;
        }
    }
    return valid;
}




