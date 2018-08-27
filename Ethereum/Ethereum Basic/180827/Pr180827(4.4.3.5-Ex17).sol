pragma solidity ^0.4.18;

contract Example17
{
    function forExample() public pure returns (uint)
    {
        uint n = 0;

        for(uint i=1; i<=10; i++)
        {
            if(i%3 == 0)
                continue;
    
            n += i;
        }
        return n;
    }
}