pragma solidity ^0.4.18;

contract Example16
{
    function forExample() public pure returns (uint)
    {
        uint n=0;
        for(uint i=0; i<1000; i++)
        {
            n += (i+1);
            if(n == 5050)
                break;
        }
        return n;
    }
}