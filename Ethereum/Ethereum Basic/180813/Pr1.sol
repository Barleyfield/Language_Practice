pragma solidity ^0.4.18;

contract Calculation
{
    int n1 = 10;
    int n2 = 5;
    int storedNum;
    
    function Add() public constant returns (int)
    {
        return n1 + n2;
    }
    
    function Sub() public constant returns (int)
    {
        return n1 - n2;
    }
    
    function Mul() public constant returns (int)
    {
        return n1 * n2;
    }
    
    function Div() public constant returns (int)
    {
        return n1 / n2;
    }
    
    function numberSet(int x) public
    {
        storedNum = x;
    }
    function Add_numberSet() public constant returns (int)
    {
        return n1 + storedNum;
    }
}
