pragma solidity ^0.4.18;

contract Example4
{
    uint count;
    address from;
    address to;

    constructor (uint _count, address _from, address _to) public
    {
        count = _count;
        from = _from;
        to = _to;
    }
    
}