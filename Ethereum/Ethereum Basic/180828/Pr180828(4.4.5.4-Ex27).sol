pragma solidity ^0.4.24;

contract Example27
{
    function byteExample() public returns (byte[] result)
    {
        bytes memory bArray = new bytes(5);
        bArray = "Hello";
        
        result = new byte[](5);
        result[0] = bArray[0];
        result[1] = bArray[1];
        result[2] = bArray[2];
        result[3] = bArray[3];
        result[4] = bArray[4];
    }
}