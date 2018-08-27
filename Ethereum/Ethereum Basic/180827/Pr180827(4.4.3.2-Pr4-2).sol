pragma solidity ^0.4.18;

contract Practice4
{
    int c;
    function setC(int c_input) public
    {
        c = c_input;
    
    }
    function getC() public returns (int)
    {
        (c>50) ? (c=50) : ( (c<10) ? (c=10) : c);
        return c;
    }
}