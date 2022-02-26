//
//  MagicSquare.hpp
//  HW6
//
//  Created by Zhenyuxi Ji on 2022/2/8.
//

#ifndef MagicSquare_hpp
#define MagicSquare_hpp

#include <stdio.h>
#include<vector>
#include<sstream>
#include<iostream>



class MagicSquare{
private:
    std::vector<std::vector<int> >square;

public:
   
    /**
     a fucntion to check if a given number is already used in the magic square
     @param row the row position of the number
     @param col the colume position of the number
     @return if a given number is already used in the magic square
     */
    bool empty(size_t row, size_t col)const;

    /**
     A function taken to check if a given number is already used in the magic square (it
     would make sense to store the taken positions in an std::set for easy lookup)
     @param num the number to check
     @return if a given number is already used in the magic square
     */
    bool taken(int num)const;

    /**
     A function checkRow that, after each row is filled (except for the last), checks if
     the square could potentially be valid - it will check that the sum of each row is the
     target sum S and that the sum of each partially filled column does not exceed S,
     returning true if the square is valid so far and false if it fails;
     @return returning true if the square is valid so far and false if it fails;
     */
    bool checkRow() const;

    /**
     a function checkValid to check if a complete magic square satisfies the proper
     conditions to be a solution;
     @return returning true if the square is valid so far and false if it fails;
     */
    bool checkValid()const;

    /**
     a recursive function solveSquare that accepts an index tracking the number of
     slots already considered in the recursion, places values, and does the appropriate
     calls to checkValid and checkRow.
     @param index tracking the number of slots already considered in the recursion
     @param value place value
     @param row the row position of the number
     @param col the colume position of the number
     @param square the square the operator reads in
     */
    void solveSquare(int index, int value, size_t row, size_t col, std::vector<std::vector<int> >& square);


};

/**square
  operator to read in the square
  @param in the istream that takes numbers in the input
  @param magicSquare the square the operator reads in
  @return istream that contains the square
  */
std::istream& operator>> (std::istream &in, std::vector< std::vector<int> >& magicSquare);

 /**
  operator to print the square to the console
  @param out the ostream that takes numbers in the output
  @param magicSquare square the operator reads in
  @return ostream that contains the square
  */
std::ostream &operator<<(std::ostream &out, const std::vector< std::vector<int> >& magicSquare);

#endif /* MagicSquare_hpp */
