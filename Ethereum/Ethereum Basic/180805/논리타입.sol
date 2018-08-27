pragma solidity ^0.4.24;

contract Booleans
{
    function getTrue() public pure returns (bool)
    {
        //a가 참이므로 b의 값과 상관없이 true 리턴.
        bool a = true;
        bool b = false;
        return a || b;
    }
    
    function getFalse() public pure returns (bool)
    {
        bool a = false;
        bool b = true;
        return a && b;
    }

    
}