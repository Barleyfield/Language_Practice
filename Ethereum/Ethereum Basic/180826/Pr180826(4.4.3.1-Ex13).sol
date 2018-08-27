pragma solidity ^0.4.11;

contract Example4
{
    function ifExample() public pure returns (uint)
    {
        uint n = 50;

        if(n > 25)
        {
            n++;
        }
        else if (n == 25)
        {
            n += 10;
        }
        else
        {
            n--;
        }
        return n;
    }
}