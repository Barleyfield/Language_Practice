pragma solidity ^0.4.18;

contract Example4
{
    function operation() public returns (uint result)
    {
        result = sum(5,10);
    }

    function sum(uint a, uint b) public returns (uint)
    {
        uint result = a + b;
        return result;
    }
}