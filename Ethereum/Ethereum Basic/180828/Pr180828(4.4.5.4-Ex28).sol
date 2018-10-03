pragma solidity ^0.4.24;

contract Example28
{
    function byteExample() public pure returns (string result)
    {
        bytes memory bArray = new bytes(5);
        bArray = "Hello";

        result = string(bArray);
    }
}